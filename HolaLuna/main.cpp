#include <iostream>
#include <Box2d/Box2d.h>

using namespace std;

int main() {
    b2Vec2 gravity(0.0f, -1.62f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;  //Se crea un cuerpo
    groundBodyDef.position.Set(0.0f, -10.0f);  //Se define la posición del cuerpo

    b2Body* groundBody = world.CreateBody(&groundBodyDef); //Se llama al cuerpo al mundo

    b2PolygonShape groundBox; //Se crea una forma a un cuerpo
    groundBox.SetAsBox(50.0f, 10.0f);  //Se establecen las medidas de la forma, en este caso, será un cuadrado

    groundBody->CreateFixture(&groundBox, 0.0f);

    //

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody; //El tipo de cuerpo será dinamico ya que su posición va a variar
    bodyDef.position.Set(0.0f, 16.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef; //Se define una característica
    fixtureDef.shape = &dynamicBox; //Se le aplica la característica a la forma
    fixtureDef.density = 15600.0f; //Característica de densidad
    fixtureDef.friction = 0.0f; //Característica de fricción

    body->CreateFixture(&fixtureDef); //Se le aplican las características anteriores al "body"

    float timeStep = 1.0f; //Determinamos cada cuanto se realiza una acción, interación o lo que sea

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}