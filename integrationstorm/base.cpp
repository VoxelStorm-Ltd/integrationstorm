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
void base<T, DerivedT>::set_force_func(std::function<void(state<T> const&, T, vec3<T>&, vec3<T>&)> new_func) {
  force_func = new_func;
}

template<typename T, template<typename> class DerivedT>
void base<T, DerivedT>::get_force_and_torque(state<T> const &thisstate,
                                             T time,
                                             vec3<T> &force,
                                             vec3<T> &torque) const {
  /// Execute the force function
  this->force_func(thisstate, time, force, torque);
}

template<typename T, template<typename> class DerivedT>
void base<T, DerivedT>::integrate(state<T> &thisstate, T time, T delta_time) const {
  /// CRTP polymorphic passthrough function
  static_cast<DerivedT<T> const*>(this)->integrate(thisstate, time, delta_time);
  // static version:
  //DerivedT<T>::integrate(thisstate, time, delta_time);
}

// explicitly instantiate acceptable templates
template class base<float,  euler>;
template class base<double, euler>;
template class base<float,  runge_kutta_4>;
template class base<double, runge_kutta_4>;
template class base<float,  runge_kutta_fehlberg_54>;
template class base<double, runge_kutta_fehlberg_54>;

}
