#ifndef NONCOPYABLE_H__
#define NONCOPYABLE_H__
class NonCopyable
{
protected:
    NonCopyable(){}
private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator= (const NonCopyable&);
};

#endif