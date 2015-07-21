#include "runge_kutta_4.h"

namespace integrationstorm {

template<typename T>
runge_kutta_4<T>::runge_kutta_4() {
  /// Default constructor
}

template<typename T>
runge_kutta_4<T>::~runge_kutta_4() {
  /// Default destructor
}

template<typename T>
void runge_kutta_4<T>::integrate(Vector3<T> &position,
                                 Vector3<T> &velocity,
                                 T time,
                                 T deltatime) const {
  /// see http://gafferongames.com/game-physics/integration-basics/
  //std::cout << "  DEBUG: integrate before:  pos " << position << " vel " << velocity << std::endl;
  derivative<T> a = evaluate(position, velocity, time);
  derivative<T> b = evaluate(position, velocity, time, deltatime * 0.5, a);
  derivative<T> c = evaluate(position, velocity, time, deltatime * 0.5, b);
  derivative<T> d = evaluate(position, velocity, time, deltatime, c);

  Vector3<T> const dxdt((a.dx + ((b.dx + c.dx) * 2.0) + d.dx) * (1.0 / 6.0));
  Vector3<T> const dvdt((a.dv + ((b.dv + c.dv) * 2.0) + d.dv) * (1.0 / 6.0));

  position += dxdt * deltatime;
  velocity += dvdt * deltatime;
  //std::cout << "  DEBUG: integrate after:   pos " << position << " vel " << velocity << std::endl;
}

template<typename T>
derivative<T> runge_kutta_4<T>::evaluate(Vector3<T> const &position_initial,
                                         Vector3<T> const &velocity_initial,
                                         T time) const {
  /// internal helper function called repeatedly by the integrator - initial version
  derivative<T> output;
  output.dx = velocity_initial;
  output.dv = this->get_acceleration(position_initial, velocity_initial, time);
  return output;
}

template<typename T>
derivative<T> runge_kutta_4<T>::evaluate(Vector3<T> const &position_initial,
                                         Vector3<T> const &velocity_initial,
                                         T time,
                                         T deltatime,
                                         derivative<T> const &d) const {
  /// internal helper function called repeatedly by the integrator
  Vector3<T> const position_new(position_initial + (d.dx * deltatime));
  Vector3<T> const velocity_new(velocity_initial + (d.dv * deltatime));

  derivative<T> output;
  output.dx = velocity_new;
  output.dv = this->get_acceleration(position_new, velocity_new, time + deltatime);
  return output;
}

// explicitly instantiate acceptable templates
template class runge_kutta_4<float>;
template class runge_kutta_4<double>;

}
