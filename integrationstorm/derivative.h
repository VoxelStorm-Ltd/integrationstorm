#ifndef INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED
#define INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED

#include "vectorstorm/vector/vector3.h"
#include "vectorstorm/quat/quat.h"

namespace integrationstorm {

template<typename T>
struct derivative {
  /// Derivative values for primary state
  vec3<T> velocity;                                                             // velocity is the derivative of position.
  vec3<T> force;                                                                // force is the derivative of momentum.
  quat<T> spin;                                                                 // spin is the derivative of the orientation quat.
  vec3<T> torque;                                                               // torque is the derivative of angular momentum.
};

}

#endif // INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED
