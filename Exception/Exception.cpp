#include "Exception.h"
#include <stdlib.h>
#include <execinfo.h>

Exception::Exception(const char* msg):m_sMessage(msg)
{
	FillStacktrace();
}

Exception::Exception(const string msg):m_sMessage(msg)
{
	FillStacktrace();
}

Exception::~Exception() throw()
{

}

const char* Exception::what() const throw()
{
	return m_sMessage.c_str();
}

const char* Exception::StackTrace() const throw()
{
	return m_sStack.c_str();
}

void Exception::FillStacktrace()
{
  const int len = 200;
  void* buffer[len];
  int nptrs = ::backtrace(buffer, len);
  char** strings = ::backtrace_symbols(buffer, nptrs);
  if (strings)
  {
    for (int i = 0; i < nptrs; ++i)
    {
      // TODO demangle funcion name with abi::__cxa_demangle
      m_sStack.append(strings[i]);
      m_sStack.push_back('\n');
    }
    free(strings);
  }
}

