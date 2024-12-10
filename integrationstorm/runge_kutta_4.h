#pragma once

#include "base.h"
#include "derivative.h"

namespace integrationstorm {

template<typename T>
class runge_kutta_4 : public base<T, runge_kutta_4> {
public:
  runge_kutta_4();
  ~runge_kutta_4();

public:
  void integrate(state<T> &thisstate, T time, T delta_time) const;

private:
  derivative<T> evaluate(state<T> const &currentstate, T time) const;
  derivative<T> evaluate(state<T> const &currentstate, T time, T delta_time, derivative<T> const &thisderivative) const;
};

}
