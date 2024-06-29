//
// Created by shehbaz on 5/12/2024.
//

#include "Component.h"
#include "Actor.h"

Component::Component(const std::string &name, Actor *owner, int updateOrder)
:mOwner(owner)
,mUpdateOrder(updateOrder)
,mName(name)
{
  // Add to actor's vector of components
  mOwner->AddComponent(this);
  mOwner->AddComponentToMap(mName, this);
}

Component::~Component()
{
  mOwner->RemoveComponent(this);
  mOwner->RemoveComponentFromMap(mName);
}

void Component::Update(float deltaTime)
{
}
