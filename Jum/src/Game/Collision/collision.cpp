
#include "collision.h"


bool isRectToRect(const float& x1, const float& y1,
                  const float& w1, const float& h1,
                  const float& x2, const float& y2,
                  const float& w2, const float& h2) {
  if (x1 + w1 > x2) {
    if (x1 < x2 + w2) {
      if (y1 + h1 > y2) {
        if (y1 < y2 + h2) {
          return true;
        }
      }
    }
  }
  return false;
}


bool isPointToRect(const float& x1, const float& y1,
                   const float& x2, const float& y2,
                   const float& w2, const float& h2) {
  if (x1 > x2) {
    if (x1 < x2 + w2) {
      if (y1 > y2) {
        if (y1 < y2 + h2) {
          return true;
        }
      }
    }
  }
  return false;
}