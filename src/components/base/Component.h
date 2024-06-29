//
// Created by shehbaz on 5/12/2024.
//

#ifndef RUBIKS_CUBE_COMPONENT_H
#define RUBIKS_CUBE_COMPONENT_H

#include <string>

class Actor;

class Component
{
public:
  // constructor - lower the update order, the earlier the component updates
  Component(const std::string &name, Actor* owner, int updateOrder = 100);
  virtual ~Component();
  // update component using delta time
  virtual void Update(float deltaTime);

  // setters/getters
  [[nodiscard]] Actor* GetOwner() const { return mOwner; }
  [[nodiscard]] int GetUpdateOrder() const { return mUpdateOrder; }

protected:
  // the actor that owns this component
  Actor* mOwner;
  // update order of this component
  int mUpdateOrder;
  // name of the component - to be used when using GetComponent() in Actor class
  std::string mName;
};


#endif //RUBIKS_CUBE_COMPONENT_H
