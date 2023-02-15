#include "players.hpp"

extern double multiply;
extern int width;
extern int height;

players::Player::Player(bool It_Is_First_Player){
    this->restart(It_Is_First_Player);
}

void players::Player::move(double time_as_Seconds){
    auto dy = speed*time_as_Seconds;
    if (y + dy > height - this->RectHeight || y + dy < 0) return;
    shape.move(0, dy);
    this->y += dy;
}

void players::Player::restart(bool It_Is_First_Player){
    RectWidth = width/50;
    RectHeight = height/4;

    speed = multiply * height * 0.75;

    shape.setFillColor(Color(255,0,255));
    if (It_Is_First_Player)
    shape.setFillColor(Color(0, 120, 0));

    Vector2f size;
    size.x = RectWidth;
    size.y = RectHeight;
    shape.setSize(size);
    
    if (It_Is_First_Player) shape.setPosition(shape.getPosition().x, height / 2 - RectHeight / 2);
    else shape.setPosition(width - RectWidth, height / 2 - RectHeight / 2);
    x = shape.getPosition().x;
    y = shape.getPosition().y;
}

RectangleShape players::getPlayer1Shape(){ 
    return player1.shape;
}

RectangleShape players::getPlayer2Shape(){ 
    return player2.shape;
}

Vector2f players::getPosition(int NumberOfPlayer){
    if (NumberOfPlayer == 1) return player1.shape.getPosition();
    else return player2.shape.getPosition();
}

void players::Player1move(double time_as_MicroSeconds, int dir){
    double time_asSeconds = time_as_MicroSeconds / 1e6;
    player1.move(time_asSeconds * dir);
}
void players::Player2move(double time_as_MicroSeconds, int dir){
    double time_asSeconds = time_as_MicroSeconds / 1e6;
    player2.move(time_asSeconds * dir);
}
double players::GetRectHeight(){
    return player1.RectHeight;
}
double players::GetRectWidth(){
    return player1.RectWidth;
}

void players::restart(){
    player1.restart(1);
    player2.restart(0);
}