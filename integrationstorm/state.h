#ifndef INTEGRATIONSTORM_STATE_H_INCLUDED
#define INTEGRATIONSTORM_STATE_H_INCLUDED

#include "vmath.h"

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
  T mass = 1.0f;                                                                // total mass of the rigid body, in kg, equivalent of _airplane._model._body._totalMass in yasim
  T mass_inv = 1.0f;                                                            // inverse of the mass used to convert momentum to velocity.
  Vector3<T> centre_of_gravity;                                                 // centre of gravity of the rigid body, equivalent of _airplane._model._body._cg in yasim
  ///Vector3<T> inertia_tensor;                                                    // inertia tensor
  ///Vector3<T> inertia_tensor_inv;                                                // inverse inertia tensor used to convert angular momentum to angular velocity.
  Matrix3<T> inertia_tensor;                                                    // inertia tensor, equivalent of _airplane._model._body._tI in yasim
  Matrix3<T> inertia_tensor_inv;                                                // cached value of inverted inertia tensor, equivalent of _airplane._model._body._invI in yasim

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
