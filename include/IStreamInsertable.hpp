#ifndef I_STREAM_INSERTABLE_HPP
#define I_STREAM_INSERTABLE_HPP

#include <ostream>

class IStreamInsertable {
  friend std::ostream &operator<<(std::ostream &os,
                                  const IStreamInsertable &si);

public:
  virtual void stream_insert(std::ostream &os) const = 0;
};

#endif