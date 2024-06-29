//
// Created by shehbaz on 5/29/2024.
//

#include "Actor.h"
#include "DrawComponent.h"

DrawComponent::DrawComponent(const std::string &name, Actor *owner, int drawOrder)
:Component(name, owner)
,mDrawOrder(drawOrder)
{
  mOwner->GetGame()->AddDraw(this);
  mIsShow = true;
}

DrawComponent::~DrawComponent()
{
  mOwner->GetGame()->RemoveDraw(this);
}
