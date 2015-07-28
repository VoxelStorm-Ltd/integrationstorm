//#include "base.h"
#include "euler.h"
#include "runge_kutta_4.h"
#include "runge_kutta_fehlberg_54.h"

namespace integrationstorm {

template<typename T, template<typename> class DerivedT>
base<T, DerivedT>::base() {
  /// Default constructor
}

template<typename T, template<typename> class DerivedT>
base<T, DerivedT>::~base() {
  /// Default destructor
}

template<typename T, template<typename> class DerivedT>
Vector3<T> base<T, DerivedT>::get_acceleration(Vector3<T> const &position,
                                               Vector3<T> const &velocity,
                                               T time) const {
  /// CRTP polymorphic passthrough function
  //static_cast<DerivedT<T> const*>(this)->get_acceleration(position, velocity, time);
  return acceleration_func(position, velocity, time);
}

template<typename T, template<typename> class DerivedT>
void base<T, DerivedT>::integrate(Vector3<T> &position,
                                  Vector3<T> &velocity,
                                  T time,
                                  T deltatime) const {
  /// CRTP polymorphic passthrough function
  static_cast<DerivedT<T> const*>(this)->integrate(position, velocity, time, deltatime);
}

// explicitly instantiate acceptable templates
template class base<float,  euler>;
template class base<double, euler>;
template class base<float,  runge_kutta_4>;
template class base<double, runge_kutta_4>;
template class base<float,  runge_kutta_fehlberg_54>;
template class base<double, runge_kutta_fehlberg_54>;

}
