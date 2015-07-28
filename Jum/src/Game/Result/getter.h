
#pragma once
#include "../GameMain/gimic.h"
#include <memory>


class Getter {
public:
  static Getter& get() {
    static Getter getter;
    return getter;
  }

  bool isClear;
  Gimic::PATERN patern;
};