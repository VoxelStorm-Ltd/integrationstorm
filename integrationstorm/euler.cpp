#include "euler.h"
//#include "state.h"
//#include "derivative.h"

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
void euler<T>::integrate(state<T> &thisstate, T time, T delta_time) const {
  /// Very simplistic test integrator
  derivative<T> const d = evaluate(thisstate, time, delta_time);
  thisstate.position         += d.velocity * delta_time;
  thisstate.momentum         += d.force    * delta_time;
  thisstate.orientation      += d.spin     * delta_time;
  thisstate.angular_momentum += d.torque   * delta_time;

  thisstate.recalculate();
}

template<typename T>
derivative<T> euler<T>::evaluate(state<T> const &currentstate,
                                 T time,
                                 T delta_time) const {
  /// internal helper function called repeatedly by the integrator
  derivative<T> output;
  output.velocity = currentstate.velocity;
  output.spin     = currentstate.spin;
  this->get_force(currentstate, time + delta_time, output.force, output.torque);
  return output;
}

// explicitly instantiate acceptable templates
template class euler<float>;
template class euler<double>;

}
