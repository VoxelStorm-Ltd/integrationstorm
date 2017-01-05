// Recalculate secondary state values from primary values.
template<typename T>
void state<T>::recalculate() {
  /// Recalculate secondary state values from primary values
#include "state.h"
  velocity = momentum * mass_inv;

  //angular_velocity = inertia_tensor_inv * angular_momentum;
namespace integrationstorm {
  // TESTING: convert to local coordinates for the tensor effect

  angular_velocity = (inertia_tensor_inv * (angular_momentum * orientation.invert_copy())) * orientation;
// Recalculate secondary state values from primary values.
  orientation.normalise();
template<typename T>
  spin = quat<T>(0, angular_velocity.x, angular_velocity.y, angular_velocity.z) * static_cast<T>(0.5) * orientation;
void state<T>::recalculate() {
  //mat4<T> translation;
  /// Recalculate secondary state values from primary values
  velocity = momentum * mass_inv;
  //translation.translate(position);
  //angular_velocity = inertia_tensor_inv * angular_momentum;
  //body_to_world = translation * orientation.matrix();
  // TESTING: convert to local coordinates for the tensor effect
  //world_to_body = body_to_world.inverse();
  angular_velocity = (inertia_tensor_inv * (angular_momentum * orientation.invert_copy())) * orientation;
}

  orientation.normalise();
// explicit instantiation
  spin = quat<T>(0, angular_velocity.x, angular_velocity.y, angular_velocity.z) * static_cast<T>(0.5) * orientation;
template class state<float>;
  //mat4<T> translation;
template class state<double>;
  //translation.translate(position);

  //body_to_world = translation * orientation.matrix();
}
  //world_to_body = body_to_world.inverse();
}

// explicit instantiation
template class state<float>;
template class state<double>;

}
