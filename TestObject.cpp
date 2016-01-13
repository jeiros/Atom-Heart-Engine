#include "TestObject.hpp"
#include "Base/Resources.hpp"

TestObject::TestObject()
  : Object(sf::Vector2f(100,100), Resources::test_texture, sf::Vector2i(1,1)) {
  position = sf::Vector2f(0,0);
}

TestObject::~TestObject() {
}

void TestObject::update(float deltaTime) {

}
