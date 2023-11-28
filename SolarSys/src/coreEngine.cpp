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



void createSolarSys(char *relativePath, float windowWidth, float windowHeight, SolarSystem *solarSys){

    auto textureID = createTexture(PathStorage::PATH_TEXTURE_SUN);
    auto textureEarth = createTexture(PathStorage::PATH_TEXTURE_EARTH);
    auto textureClouds = createTexture(PathStorage::PATH_TEXTURE_CLOUDS);

    FilePath applicationPath(relativePath);

    auto sunData = SunData();
    auto shader = Shader1Texture(applicationPath);
    auto sun = PlanetObject(textureID, sunData, &shader);
    sun.configureMatrices(windowWidth, windowHeight);

    auto earthData = EarthData();
    auto earthShader = Shader2Texture(applicationPath);

    unsigned int textures[] = {textureEarth, textureClouds};
    auto earth = PlanetObject(2, textures, earthData, &earthShader);
    earth.configureMatrices(windowWidth + 1, windowHeight);
    
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

    /*************** TEXTURE LOAD *****************/

    // auto textureID = createTexture(PathStorage::PATH_TEXTURE_SUN);
    // auto textureEarth = createTexture(PathStorage::PATH_TEXTURE_EARTH);
    // auto textureClouds = createTexture(PathStorage::PATH_TEXTURE_CLOUDS);

    // FilePath applicationPath(relativePath);

    // auto sunData = SunData();
    // auto shader = Shader1Texture(applicationPath);
    // auto sun = PlanetObject(textureID, sunData, &shader);
    // sun.configureMatrices(windowWidth, windowHeight);

    // auto earthData = EarthData();
    // auto earthShader = Shader2Texture(applicationPath);

    // unsigned int textures[] = {textureEarth, textureClouds};
    // auto earth = PlanetObject(2, textures, earthData, &earthShader);
    // earth.configureMatrices(windowWidth + 1, windowHeight);
    

    // auto solarSys = SolarSystem();
    // solarSys.addPlanet(sun);
    // solarSys.addPlanet(earth);

    




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
