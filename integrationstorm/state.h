#ifndef INTEGRATIONSTORM_STATE_H_INCLUDED
#define INTEGRATIONSTORM_STATE_H_INCLUDED

#include "vectorstorm/vector/vector3.h"
#include "vectorstorm/matrix/matrix3.h"
#include "vectorstorm/quat/quat.h"

namespace integrationstorm {

template<typename T>
struct state {
  /// Physics state for the integrator
  // primary physics state
  vec3<T> position;                                                             // the position of the centre of mass in world coordinates (meters).
  vec3<T> momentum;                                                             // the momentum in kilogram meters per second.
  quat<T> orientation;                                                          // the orientation represented by a unit quat.
  vec3<T> angular_momentum;                                                     // angular momentum vector.

  // secondary state
  vec3<T> velocity;                                                             // velocity in meters per second (calculated from momentum).
  quat<T> spin;                                                                 // quaternion rate of change in orientation.
  vec3<T> angular_velocity;                                                     // angular velocity (calculated from angularMomentum).
  //mat4<T> body_to_world;                                                        // body to world coordinates matrix.
  //mat4<T> world_to_body;                                                        // world to body coordinates matrix.

  // constant state
  T mass = 1.0f;                                                                // total mass of the rigid body, in kg, equivalent of _airplane._model._body._totalMass in yasim
  T mass_inv = 1.0f;                                                            // inverse of the mass used to convert momentum to velocity.
  vec3<T> centre_of_gravity;                                                    // centre of gravity of the rigid body, equivalent of _airplane._model._body._cg in yasim
  ///vec3<T> inertia_tensor;                                                      // inertia tensor
  ///vec3<T> inertia_tensor_inv;                                                  // inverse inertia tensor used to convert angular momentum to angular velocity.
  mat3<T> inertia_tensor;                                                       // inertia tensor, equivalent of _airplane._model._body._tI in yasim
  mat3<T> inertia_tensor_inv;                                                   // cached value of inverted inertia tensor, equivalent of _airplane._model._body._invI in yasim

  /// ///
  // TODO
  float _gyro[3];

  // Externally determined quantities
  float _force[3];
  float _torque[3];
  float _spin[3];


  void recalculate();

  // TODO: interpolate
};

}

#endif // INTEGRATIONSTORM_STATE_H_INCLUDED
