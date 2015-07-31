#ifndef INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED
#define INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED

namespace integrationstorm {

template<typename T>
struct derivative {
  /// Derivative values for primary state
  Vector3<T> velocity;                                                          // velocity is the derivative of position.
  Vector3<T> force;                                                             // force is the derivative of momentum.
  Quaternion<T> spin;                                                           // spin is the derivative of the orientation quaternion.
  Vector3<T> torque;                                                            // torque is the derivative of angular momentum.
};

}

#endif // INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED
