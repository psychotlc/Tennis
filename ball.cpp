#include "ball.hpp"

ball::ball(){this->restart();};
int ball::update(double time_asMicroseconds, players Players){
    double time_asSeconds = time_asMicroseconds / 1e6;
        if (this->Xspeed>0){
            Vector2f position = Players.getPosition(2);
            if (this->x + Radius * 2 >= position.x){
                
                if (this->y + 2 * this->Radius >= position.y && this->y <= position.y + Players.GetRectHeight()){
                    this->Yspeed = -4 * (height/2) * ((position.y - Radius + Players.GetRectHeight()/2 - this->y) / Players.GetRectHeight()/2);
                    this->Xspeed*= -1;
                    
                }
                else if(this->x + 2 * Radius >= width) return 2;
            }
        }
        else {
            Vector2f position = Players.getPosition(1);
            if (this->x <= position.x + Players.GetRectWidth()){
                if (this->y + 2 * this->Radius >= position.y && this->y <= position.y + Players.GetRectHeight()){
                    this->Yspeed = multiply * -2 * (height/2) * ((position.y - Radius + Players.GetRectHeight()/2 - this->y) / Players.GetRectHeight()/2);
                    this->Xspeed *= -1;
                }
                else if(this->x <= 0) return 1;
            }
        }

        if (this->y >= height - 2 * this->Radius) {
            this->Yspeed *= -1;
            this->y = height - (this->y + 2 * this->Radius - height) - 2 * this->Radius ;
            shape.setPosition(this->x, this->y);
        }
        else if(this->y <= 0){
            this->Yspeed *= -1;
            this->y *= -1;
            shape.setPosition(this->x, this->y);
        }
        shape.move(Xspeed * time_asSeconds, Yspeed * time_asSeconds);
        this->x = shape.getPosition().x;
        this->y = shape.getPosition().y;
        return 0;
}

CircleShape ball::getShape(){
    return shape;
}

void ball::restart(){
    x = width / 2;
    Xspeed = multiply * 500;
    if (rand() % 2) Xspeed *= -1;
    Yspeed = 0;
    y = height / 2;
    Radius = 30;
    shape.setRadius(Radius);
    shape.setFillColor(Color::Cyan);
    shape.setPosition(x - Radius, y - Radius);
}

double ball::GetXSpeed(){return this->Xspeed;};
double ball::GetYSpeed(){return this->Yspeed;};
double ball::GetRadius(){return this->Radius;};

double ball::Yprediction(players Players){

    double x = this->x;
    double y = this->y;
    double Xspeed = this->Xspeed / multiply;
    double Yspeed = this->Yspeed / multiply; 
        
        
    while (x <= width - Players.GetRectWidth() && x >= Players.GetRectWidth()){
            
        x += 0.001 * Xspeed;
        if (y >= height - 2 * this->Radius) {
            Yspeed *= -1;
            y = height - (y + 2 * this->Radius - height) - 2 * this->Radius ;
        }
        else if(y <= 0){
            Yspeed *= -1;
            y *= -1;
        }
        y += 0.001 * Yspeed;
    } 

    return y;
}