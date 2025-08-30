// FirePropagationSimulator.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <chrono>

#include "Field.h"

void renderingThread(sf::RenderWindow*, int, int);

int main()
{
    unsigned int width = 1200;
    unsigned int height = 800;
    int field_size_x = width/50;
    int field_size_y = height/50;
   
    sf::RenderWindow window(sf::VideoMode({ width, height }), "Fire Propagation Simulator");
    window.setActive(false);

    std::thread thread(&renderingThread, &window, field_size_x, field_size_y);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                printf("(%d : %d)\n", sf::Mouse::getPosition().x, sf::Mouse::getPosition());
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        }
    }

    thread.join();
    return 0;
}

void renderingThread(sf::RenderWindow* window, int field_size_x, int field_size_y)
{
    window->setActive(true);
    int count = 0;

    Field field(field_size_x, field_size_y);

    while (window->isOpen())
    {
        window->clear();

        for (int i = 0; i < field.getSizeX() * field.getSizeY(); i++)
        {
            window->draw(field.getSTDField()[i].getCells());
        }

        window->display();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
        printf("%d\n", count);
    }
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
