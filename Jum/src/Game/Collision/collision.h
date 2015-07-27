
#pragma once


// 矩形と矩形のあたり判定
bool isRectToRect(const float& x1, const float& y1,
                  const float& w1, const float& h1,
                  const float& x2, const float& y2,
                  const float& w2, const float& h2);

// 点と矩形のあたり判定
bool isPointToRect(const float& x1, const float& y1,
                   const float& x2, const float& y2,
                   const float& w2, const float& h2);