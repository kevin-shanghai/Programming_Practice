#include <boost/atomic.hpp>
#include <boost/thread/mutex.hpp>

class X {
public:
  static X * instance()
  {
    X * tmp = instance_.load(boost::memory_order_consume);
    if (!tmp) {
      boost::mutex::scoped_lock guard(instantiation_mutex);
      tmp = instance_.load(boost::memory_order_consume);
      if (!tmp) {
        tmp = new X;
        instance_.store(tmp, boost::memory_order_release);
      }
    }
    return tmp;
  }
private:
  static boost::atomic<X *> instance_;
  static boost::mutex instantiation_mutex;
};

boost::atomic<X *> X::instance_(0);

int main()
{
    X *x = X::instance();
}
