#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

    VideoMode vm(1280, 720);
    RenderWindow window(vm, "Timber Man Game"); //, Style::Fullscreen);
    
    View view(FloatRect(0, 0, 1280, 720));
    window.setView(view);
    
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
    
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(640, 0);
    
    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(540, 640);


    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite cloud1, cloud2, cloud3;
    cloud1.setTexture(textureCloud);
    cloud2.setTexture(textureCloud);
    cloud3.setTexture(textureCloud);

    cloud1.setScale(0.5f, 0.5f);  
    cloud2.setScale(0.5f, 0.75f);  
    cloud3.setScale(0.5f, .75f);
    cloud1.setPosition(-200, 100);
    cloud2.setPosition(0, 100);
    cloud3.setPosition(-100, 200);

    Clock clock;
    
    bool beeActive = false;
    float beeSpeed = 0;
    
    while (window.isOpen()) {
    
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        
        Time dt = clock.restart();
        
        if (!beeActive) {
            srand((int)time(0));
            beeSpeed = (rand() % 200) + 200;
            float height = (rand() % 300) + 300;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        } else {
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
            if (spriteBee.getPosition().x < -50) beeActive = false;
        }

        cloud1.move(25 * dt.asSeconds(), 0); 
        cloud2.move(28 * dt.asSeconds(), 0); 
        cloud3.move(30 * dt.asSeconds(), 0); 
        
        if (cloud1.getPosition().x > 2000) {
            cloud1.setPosition(-100, rand() % 200 + 50);
        }
        if (cloud2.getPosition().x > 2000) {
            cloud2.setPosition(-120, rand() % 200 + 50);
        }
        if (cloud3.getPosition().x > 2000) {
            cloud3.setPosition(-150, rand() % 200 + 50);
        }
        
        window.clear();
        window.draw(spriteBackground);
        window.draw(cloud1);  
        window.draw(cloud2);  
        window.draw(cloud3); 
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();
    }
    
    return 0;
}

