#include "euler.h"

namespace integrationstorm {

template<typename T>
euler<T>::euler() {
  /// Default constructor
}

template<typename T>
euler<T>::~euler() {
  /// Default destructor
}

template<typename T>
void euler<T>::integrate(Vector3<T> &position,
                         Vector3<T> &velocity,
                         T time,
                         T deltatime) const {
  /// Very simplistic test integrator
  position += (velocity * deltatime);
  velocity += this->get_acceleration(position, velocity, time) * deltatime;
}

// explicitly instantiate acceptable templates
template class euler<float>;
template class euler<double>;

}
