/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This is the core engine module, it gathers        =
=  the whole system that manages the behaviour       =
=  of the app.                                       =
=													 =
=  We can find the main loop that manages the        =
=  simulation.										 =
=													 =
======================================================
*/

#include "include/coreEngine.hpp"



/**
 * @brief Build an object that represent a Planet.
 *  
 * Thanks to IDs, it loads the corresponding textures to fill the planet to
 * create. It also needs information about the Data type we want to put inside
 * it and the type of shader manager.
 * With these information it is possible to create a Planet Object and set its
 * initial matrices.
 * After the call of this function, it will be possible to display this object in
 * a 3D scene.
 * 
 * @tparam DataType A type with information to bind to the planet, must be a PlanetData
 *         or a derived class.
 * @tparam ShaderType A type that gathers information about the shader management of the
 *         planet object, must be a ShaderManager or a derived class.
 * @param applicationPath A FilePath object (class of the glimac folder) to the folder where we find the shader files.
 * @param nbTextures Amount of textures to lload from the given array.
 * @param textures An array of integers that contains textures ids.
 * @param windowWidth Width of the window.
 * @param windowHeight Height of the window.
 * 
 * @return A PlanetObject, the object that is able to be displayed in a 3D scene.
 ********************************************************************************/
template <typename DataType = PlanetData, typename ShaderType = ShaderManager>
PlanetObject createPlanet(FilePath applicationPath, int nbTextures, unsigned int *textures, float windowWidth, float windowHeight){
    auto planetData = DataType();
    auto shader = std::make_shared<ShaderType>(applicationPath); // Need a shared_ptr here to avoid C pointers
    auto planet = PlanetObject(nbTextures, textures, planetData, shader);
    planet.configureMatrices(windowWidth, windowHeight);  // Build the initial matrices linked to this planet
    return planet;
}


/**
 * @brief Build an object that represent a Planet.
 *  
 * Thanks to an ID, it loads the corresponding texture to fill the planet to
 * create. It also needs information about the Data type we want to put inside
 * it and the type of shader manager.
 * With these information it is possible to create a Planet Object and set its
 * initial matrices.
 * After the call of this function, it will be possible to display this object in
 * a 3D scene.
 * 
 * @tparam DataType A type with information to bind to the planet, must be a PlanetData
 *         or a derived class.
 * @tparam ShaderType A type that gathers information about the shader management of the
 *         planet object, must be a ShaderManager or a derived class.
 * @param applicationPath A FilePath object (class of the glimac folder) to the folder where we find the shader files.
 * @param texture An integer ID of the texture we want to bind.
 * @param windowWidth Width of the window.
 * @param windowHeight Height of the window.
 * 
 * @return A PlanetObject, the object that is able to be displayed in a 3D scene.
 ********************************************************************************/
template <typename DataType, typename ShaderType = ShaderManager>
PlanetObject createPlanet(FilePath applicationPath, unsigned int texture, float windowWidth, float windowHeight){
    auto planetData = DataType();
    auto shader = std::make_shared<ShaderType>(applicationPath); // Need a shared_ptr here to avoid C pointers
    auto planet = PlanetObject(texture, planetData, shader);
    planet.configureMatrices(windowWidth, windowHeight);   // Build the initial matrices linked to this planet
    return planet;
}


/**
 * @brief Fills an empty solar sytem with all the information about it (planets...).
 *  
 *  Creates planets and add it insided the given solar system object.
 *  Its starts by creating and loading textures (at the Paths stored in the PathStorage class 
 *  defined in the pathStorage module).
 *  Then, its creates PlanetObject objects (class defined in the planetObject module) and store
 *  it inside a SolarSytem object (defined in the solarSystem module).
 *  
 * @param relativePath A path location where the app is ran.
 * @param windowWidth Width of the window.
 * @param windowHeight Height of the window.
 * @param solarSys A SolarSystem object we want to fill.
 ********************************************************************************/
void createSolarSys(char *relativePath, float windowWidth, float windowHeight, SolarSystem& solarSys){

    FilePath applicationPath(relativePath);

    // Textures loading
    unsigned int sunText = RenderEngine::createTexture(PathStorage::PATH_TEXTURE_SUN);
    unsigned int earthText = RenderEngine::createTexture(PathStorage::PATH_TEXTURE_EARTH);
    unsigned int cloudText = RenderEngine::createTexture(PathStorage::PATH_TEXTURE_CLOUDS);

    // Sun
    auto sun = createPlanet<SunData, Shader1Texture>(applicationPath, sunText, windowWidth, windowHeight);    

    // Earth
    unsigned int textures[] = {earthText, cloudText};
    auto earth = createPlanet<EarthData, Shader2Texture>(applicationPath, 2, textures, windowWidth + 1, windowHeight); // TODO : When the data linking is done, no need to add 1 to the width
    
    // Fill the solar system
    solarSys.addPlanet(sun);
    solarSys.addPlanet(earth);
}


/**
 * @brief Renders the whole 3D simulation
 *
 * Launches the main loop that allows the program to run the 3D simulation.
 * It manages the computations of trasnformations, the window management,
 * and the rendering of a 3D environment.
 *
 * @param relativePath A path location where the app is ran.
 *
 * @return The code error of the core engine part.
 ********************************************************************************/
int render3DScene(char *relativePath)
{
    /*************** WINDOW CREATION *****************/
    float windowWidth = 1000;
    float windowHeight = 1000;

    if (!Window::initWindowLib())  // Initialize the window library
    {
        return ERR_INT_CODE;  // defined inside the tools module
    }
    auto window = Window(windowWidth, windowHeight, "== * Solar System * ==");

    if (!window.isCreated())
    {
        return ERR_INT_CODE;  // defined inside the tools module
    }
    window.configureEvents();

    /********************* GRAPHIC OBJECTS CREATION ********************/
    auto solarSys = SolarSystem();
    createSolarSys(relativePath, windowWidth, windowHeight, solarSys);

    /***************** INITIALIZE THE 3D CONFIGURATION (DEPTH) *******************/
    init3DConfiguration();
    auto renderEng = RenderEngine();
    renderEng.create3DSphere();

    auto planets = solarSys.getAllPlanets();

    /********************* RENDERING LOOP ********************/
    while (window.isWindowOpen())
    {
        clearDisplay();

        for(auto it = planets.begin(); it != planets.end(); it++){
            auto currentPlanet = *it;

            renderEng.start(currentPlanet);
            currentPlanet.updateMatrices(getTime());
            renderEng.draw(currentPlanet);
            renderEng.end(currentPlanet);
        }

        window.manageWindow(); // Make the window active (events) and swap the buffers
    }

    Window::freeCurrentWindow();

    return SUCCESS_INT_CODE;   // defined inside the tools module
}