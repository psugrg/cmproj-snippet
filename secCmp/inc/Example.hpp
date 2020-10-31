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
  /**
   * @brief Construct a new Example object
   *
   * @param a integer parameter
   */
  Example(const int& a);

  int getA();

private:
  int m_a;
};

}  // namespace example

#endif  // __INTEXAMPLE_HPP