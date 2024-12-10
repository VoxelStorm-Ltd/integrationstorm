#pragma once

#include "base.h"

namespace integrationstorm {

template<typename T> struct derivative;

template<typename T>
class euler : public base<T, euler> {
public:
  euler();
  ~euler();

public:
  void integrate(state<T> &thisstate, T time, T delta_time) const;

private:
  derivative<T> evaluate(state<T> const &currentstate, T time, T delta_time) const;
};

}
