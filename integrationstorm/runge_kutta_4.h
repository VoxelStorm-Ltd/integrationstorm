#ifndef INTEGRATIONSTORM_RUNGE_KUTTA_4_H_INCLUDED
#define INTEGRATIONSTORM_RUNGE_KUTTA_4_H_INCLUDED

#include "base.h"
#include "derivative.h"

namespace integrationstorm {

template<typename T>
class runge_kutta_4 : public base<T, runge_kutta_4> {
public:
  runge_kutta_4();
  ~runge_kutta_4();

public:
  void integrate(Vector3<T> &position, Vector3<T> &velocity, T time, T deltatime) const;
private:
  derivative<T> evaluate(Vector3<T> const &position_initial,
                         Vector3<T> const &velocity_initial,
                         T time) const;
  derivative<T> evaluate(Vector3<T> const &position_initial,
                         Vector3<T> const &velocity_initial,
                         T time,
                         T deltatime,
                         derivative<T> const &d) const;
};

}

#endif // INTEGRATIONSTORM_RUNGE_KUTTA_4_H_INCLUDED
