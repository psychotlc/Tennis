#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics.hpp>
#include "players.hpp"

extern double multiply;
extern int width;
extern int height;

class ball{
private:
    double x;
    double y;
    double Radius;
    double Xspeed;
    double Yspeed;
    CircleShape shape;
public:
    ball();


    int update(double time_asMicroseconds, players Players);

    CircleShape getShape();

    void restart();

    double GetXSpeed();
    double GetYSpeed();
    double GetRadius();

    double Yprediction(players Players);
};
#endif