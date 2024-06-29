//
// Created by shehbaz on 5/29/2024.
//

#ifndef RUBIKS_CUBE_DRAWCOMPONENT_H
#define RUBIKS_CUBE_DRAWCOMPONENT_H

#include "Component.h"

class Actor;

class DrawComponent : public Component
{
public:
  DrawComponent(const std::string& name, Actor* owner, int drawOrder = 100);
  ~DrawComponent() override;

  virtual void Draw() = 0;

  void SetDrawOrder(int drawOrder) { mDrawOrder = drawOrder; }
  void SetIsShow(bool isShow) { mIsShow = isShow; }

  [[nodiscard]] int GetDrawOrder() const { return mDrawOrder; }
  [[nodiscard]] bool GetIsShow() const { return mIsShow; }

private:
  int mDrawOrder;
  bool mIsShow;
};


#endif //RUBIKS_CUBE_DRAWCOMPONENT_H
