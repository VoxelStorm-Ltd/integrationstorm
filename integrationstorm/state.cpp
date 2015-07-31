#include "state.h"

namespace integrationstorm {

// Recalculate secondary state values from primary values.
template<typename T>
void state<T>::recalculate() {
  /// Recalculate secondary state values from primary values
  velocity = momentum * mass_inv;
  angular_velocity = angular_momentum * inertia_tensor_inv;
  orientation.normalise();
  spin = Quaternion<T>(0, angular_velocity.x, angular_velocity.y, angular_velocity.z) * static_cast<T>(0.5) * orientation;
  //Matrix4<T> translation;
  //translation.translate(position);
  //body_to_world = translation * orientation.matrix();
  //world_to_body = body_to_world.inverse();
}

// explicit instantiation
template class state<float>;
template class state<double>;

}
