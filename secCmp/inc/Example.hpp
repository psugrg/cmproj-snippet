#ifndef __INTEXAMPLE_HPP
#define __INTEXAMPLE_HPP

namespace example
{
/**
 * @brief Example class
 */
class Example
{
public:
  Example(const int& a);

  int getA();

private:
  int m_a;
};

}  // namespace example

#endif  // __INTEXAMPLE_HPP