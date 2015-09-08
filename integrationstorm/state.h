#ifndef INTEGRATIONSTORM_STATE_H_INCLUDED
#define INTEGRATIONSTORM_STATE_H_INCLUDED

#include "vmath_forward_dec.h"

namespace integrationstorm {

template<typename T>
struct state {
  /// Physics state for the integrator
  // primary physics state
  Vector3<T> position;                                                          // the position of the centre of mass in world coordinates (meters).
  Vector3<T> momentum;                                                          // the momentum in kilogram meters per second.
  Quaternion<T> orientation;                                                    // the orientation represented by a unit quaternion.
  Vector3<T> angular_momentum;                                                  // angular momentum vector.

  // secondary state
  Vector3<T> velocity;                                                          // velocity in meters per second (calculated from momentum).
  Quaternion<T> spin;                                                           // quaternion rate of change in orientation.
  Vector3<T> angular_velocity;                                                  // angular velocity (calculated from angularMomentum).
  //Matrix4<T> body_to_world;                                                     // body to world coordinates matrix.
  //Matrix4<T> world_to_body;                                                     // world to body coordinates matrix.

  // constant state
  T mass;                                                                       // mass of the object in kilograms.
  T mass_inv;                                                                   // inverse of the mass used to convert momentum to velocity.
  Vector3<T> inertia_tensor;                                                    // inertia tensor
  Vector3<T> inertia_tensor_inv;                                                // inverse inertia tensor used to convert angular momentum to angular velocity.

  void recalculate();

	// TODO: interpolate

};

}

#endif // INTEGRATIONSTORM_STATE_H_INCLUDED
