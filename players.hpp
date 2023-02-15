#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

extern int height;
extern int width;

class players{
private:
    class Player{
    public:
        double RectWidth;
        double RectHeight;
        double x;
        double y;
        double speed;
        RectangleShape shape;

        Player(bool It_Is_First_Player);

        void move(double time_as_Seconds);

        void restart(bool It_Is_First_Player);
    };

    Player player1 = {true};
    Player player2 = {false};
public:

    RectangleShape getPlayer1Shape();
    RectangleShape getPlayer2Shape();

    Vector2f getPosition(int NumberOfPlayer);

    void Player1move(double time_as_MicroSeconds, int dir);
    void Player2move(double time_as_MicroSeconds, int dir);
    double GetRectHeight();
    double GetRectWidth();

    void restart();

};

#endif