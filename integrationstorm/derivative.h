#ifndef INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED
#define INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED

namespace integrationstorm {

template<typename T>
struct derivative {
  Vector3<T> dx;                                                              // derivative of position: velocity
  Vector3<T> dv;                                                              // derivative of velocity: acceleration
};

}

#endif // INTEGRATIONSTORM_DERIVATIVE_H_INCLUDED
