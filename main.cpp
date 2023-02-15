#include <SFML/Graphics.hpp>
#include <iostream>

int width = 1000;
int height = 640;

double multiply = 1;
using namespace sf;

#include "players.hpp"

#include "ball.hpp"


int main(){
    srand(time(NULL));
    RenderWindow window(VideoMode(width, height), "Tennis");

    srand(time(NULL));

    bool OnePlayerMode = true;
    bool ZeroPlayerMode = false;
    

    players Players = {};

    Font font;
    font.loadFromFile("CyrilicOld.TTF");

    Text text("", font, 50);
    text.setPosition(width/3.5, height/2 - 25);
    text.setFillColor(Color::Red);
    
    ball Ball;

    Clock clock;
    clock.restart();

    bool EndGame = false;

    while (window.isOpen()){
        
        Event event;
        if (window.pollEvent(event)){
            if (event.type == Event::Closed) window.close();
        }

        double time_asMicroseconds = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        window.clear();

        if (Keyboard::isKeyPressed(Keyboard::R) | Keyboard::isKeyPressed(Keyboard::Space)){
            Ball.restart();
            Players.restart();
            EndGame = false;
            text.setString("");
        }

        if (!EndGame){
            double Yprediction = Ball.Yprediction(Players);
            double Rand1, Rand2;
            if (!OnePlayerMode){
                if (Keyboard::isKeyPressed(Keyboard::Up)) Players.Player2move(time_asMicroseconds, -1);
                if (Keyboard::isKeyPressed(Keyboard::Down)) Players.Player2move(time_asMicroseconds, 1);
                
            }
            else {
                
                if (Ball.GetXSpeed() < 0){
                    Rand1 = rand() % (int(Players.GetRectHeight())) - Ball.GetRadius();
                }
                else {

                    if (Players.getPosition(2).y < Yprediction - Rand1){
                        Players.Player2move(time_asMicroseconds, 1);
                    }
                    else {
                        Players.Player2move(time_asMicroseconds, -1);
                    }
                }
            }
            if (!ZeroPlayerMode){
                if (Keyboard::isKeyPressed(Keyboard::W)) Players.Player1move(time_asMicroseconds, -1);
                if (Keyboard::isKeyPressed(Keyboard::S)) Players.Player1move(time_asMicroseconds, 1);
            }
            else{
                if (Ball.GetXSpeed() > 0){
                    Rand2 = rand() % (int(Players.GetRectHeight())) - Ball.GetRadius();
                }
                else {

                    if (Players.getPosition(1).y < Yprediction - Rand2){
                        Players.Player1move(time_asMicroseconds, 1);
                    }
                    else {
                        Players.Player1move(time_asMicroseconds, -1);
                    }
                }
            }

            if(Ball.update(time_asMicroseconds, Players) == 1) {
                text.setString("Second Player Win");
                EndGame = true;
            }
            else if(Ball.update(time_asMicroseconds, Players) == 2) {
                text.setString("First Player Win");
                EndGame = true;
            }
        }
        window.draw(text);
        window.draw(Ball.getShape());
        
        window.draw(Players.getPlayer1Shape());
        window.draw(Players.getPlayer2Shape());
        window.draw(text);

        window.display();
    }
        
}
