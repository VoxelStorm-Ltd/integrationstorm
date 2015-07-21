#ifndef INTEGRATIONSTORM_EULER_H_INCLUDED
#define INTEGRATIONSTORM_EULER_H_INCLUDED

#include "base.h"

namespace integrationstorm {

template<typename T>
class euler : public base<T, euler> {
public:
  euler();
  ~euler();

public:
  void integrate(Vector3<T> &position, Vector3<T> &velocity, T time, T deltatime) const;
};

}

#endif // INTEGRATIONSTORM_EULER_H_INCLUDED
