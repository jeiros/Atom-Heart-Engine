#ifndef TESTOBJECT
#define TESTOBJECT

#include "Base/Object.hpp"

class TestObject : public Object {
public:
  TestObject();
  ~TestObject();

  virtual void update(float deltaTime);
};

#endif
