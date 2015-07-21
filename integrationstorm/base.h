#ifndef INTEGRATIONSTORM_BASE_H_INCLUDED
#define INTEGRATIONSTORM_BASE_H_INCLUDED

#include "vmath.h"

namespace integrationstorm {

template<typename T, template<typename> class DerivedT>
class base {
protected:
  std::function<Vector3<T>(Vector3<T> const&, Vector3<T> const &, T time)> acceleration_func = [](Vector3<T> const &position __attribute__((__unused__)),
                                                                                                  Vector3<T> const &velocity __attribute__((__unused__)),
                                                                                                  T time                     __attribute__((__unused__))){
    /// pointer to function that calculates acceleration at a given position, velocity and time
    return Vector3<T>({0, 0, 0});
  };

protected:
  base();                                                                       // this base class is not to be instantiated
protected:                                                                      // prevent destruction through base pointer
  ~base();

public:
  Vector3<T> get_acceleration(Vector3<T> const &position, Vector3<T> const &velocity, T time) const;
  void integrate(Vector3<T> &position, Vector3<T> &velocity, T time, T deltatime) const;
};

}

#endif // INTEGRATIONSTORM_BASE_H_INCLUDED
