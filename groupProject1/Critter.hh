/*Project: Group Project 1
 *Class: CS162
 *Date: 10/28/2018
 *Description: Header file for the class Critter
 */ 

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {

   priavte:
      //int xPosition;
      //int yPosition;
      int steps;

      //what direction is the insect facing. Will be randomly determined and
      //then will move in that direction when move().
      int position;
      char insectType;

   public:
      //Critter();
      //Critter(int, int); //xPosition, yPosition
      //int getX();
      //void setX();
      //int getY();
      //void setY();
      int getSteps();
      void setSteps();
      int getPosition();
      void changePosition();
      char getInsectType();
      virtual void move();
      virtual void breed();
      //~Critter();
};

#endif //CRITTER_HPP
