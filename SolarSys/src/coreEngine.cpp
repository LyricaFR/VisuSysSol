/*
======================================================
=  													 =
=      Made by Kevin QUACH and Dylan DE JESUS	     =
=													 =
=													 =
=  This is the core engine module, it is the         =
=  gathering of the whole system that manages the    =
=  behaviour of the app.                             =
=													 =
=  We can find the main loop that manages the        =
=  simulation.										 =
=													 =
======================================================
*/

#include "include/coreEngine.hpp"




template <typename DataType = PlanetData, typename ShaderType = ShaderManager>
PlanetObject createPlanet(FilePath applicationPath, int nbTextures, unsigned int *textures, float width, float height){
    auto planetData = DataType();
    auto shader = std::make_shared<ShaderType>(applicationPath);
    auto planet = PlanetObject(nbTextures, textures, planetData, shader);
    planet.configureMatrices(width, height);
    return planet;
}


template <typename DataType, typename ShaderType = ShaderManager>
PlanetObject createPlanet(FilePath applicationPath, unsigned int texture, float width, float height){
    auto planetData = DataType();
    auto shader = std::make_shared<ShaderType>(applicationPath);
    auto planet = PlanetObject(texture, planetData, shader);
    planet.configureMatrices(width, height);
    return planet;
}




/**
 * @brief Fills an empty solar sytem with all the information about it (planets...).
 *
 * @param relativePath A path location where the app is ran.
 * @param windowWidth Width of the window.
 * @param windowHeight Height of the window.
 * @param solarSys A SolarSystem object we want to fill.
 ********************************************************************************/
void createSolarSys(char *relativePath, float windowWidth, float windowHeight, SolarSystem *solarSys){

    FilePath applicationPath(relativePath);

    // Textures loading
    auto sunText = RenderEngine::createTexture(PathStorage::PATH_TEXTURE_SUN);
    auto earthText = RenderEngine::createTexture(PathStorage::PATH_TEXTURE_EARTH);
    auto cloudText = RenderEngine::createTexture(PathStorage::PATH_TEXTURE_CLOUDS);

    // Sun
    auto sun = createPlanet<SunData, Shader1Texture>(applicationPath, sunText, windowWidth, windowHeight);    

    // Earth
    unsigned int textures[] = {earthText, cloudText};
    auto earth = createPlanet<EarthData, Shader2Texture>(applicationPath, 2, textures, windowWidth + 1, windowHeight);
    
    solarSys->addPlanet(sun);
    solarSys->addPlanet(earth);
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

    if (!Window::initWindowLib())
    {
        return ERR_INT_CODE;
    }

    auto window = Window(windowWidth, windowHeight, "== * Solar System * ==");

    if (!window.isCreated())
    {
        return ERR_INT_CODE;
    }

    window.configureEvents();

    /********************* GRAPHIC OBJECT CREATION ********************/
    auto solarSys = SolarSystem();

    createSolarSys(relativePath, windowWidth, windowHeight, &solarSys);


    /********************* INITIALIZE THE 3D CONFIGURATION (DEPTH) ********************/
    init3DConfiguration();
    auto renderEng = RenderEngine();
    renderEng.create3DSphere();

    auto planets = solarSys.getAllPlanets();

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

    return SUCCESS_INT_CODE;
}
