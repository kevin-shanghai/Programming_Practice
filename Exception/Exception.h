#include <iostream>
using namespace std;

class Exception
{
public:
	explicit Exception(const char* what);
	explicit Exception(const string what);
	virtual ~Exception() throw();
	virtual const char* what() const throw();
	const char* StackTrace() const throw();

private:
	void FillStacktrace();


private:
	string m_sMessage;
	string m_sStack;
};