#include "unix_time.h"

namespace UnixTime {

int64_t get_unix_time() {
  auto now{std::chrono::system_clock::now().time_since_epoch()};
  auto miliseconds{std::chrono::duration_cast<std::chrono::milliseconds>(now)};
  return miliseconds.count();
}
} // namespace UnixTime
