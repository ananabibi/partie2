/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 * STEP 2 version
 */

#include <Application.hpp>
#include <Env/Obstacle.hpp>
#include <Tests/UnitTests/CheckUtility.hpp>
#include "../catch/catch.hpp"

#include <iostream>
size_t test_count(0);


class DummyObstacle : public Obstacle
{
	
public:
  DummyObstacle(const Vec2d& pos, double rad, bool isTraversable=true)
    :  Obstacle(pos, rad, isTraversable)
  {}
	
/*  double getRadius() const override
  {
    return Obstacle::getRadius();
  }

  Vec2d getCenter() const override {
    return Obstacle::getCenter();
  }
todo Why are these here??? */
};


SCENARIO("Obstacle Constructor", "Obstacle")
{

  GIVEN("A Obstacle constructed at world_size.x()/2, with radius 10")
    {
      ++test_count;
      auto const world_size(getApp().getEnvSize());
      std::cerr << "Test(ctor)#" << test_count
		<< " world size="
		<<  world_size
		<< std::endl;
      auto const position(world_size/2);
      auto const radius(10);
      DummyObstacle c(position, radius) ;

      THEN("coordinates returned by getCenter() must be world_size/2\
              and radius returned by getRadius() must be 10")
        {
	  auto p (c.getCenter());
	  CHECK_APPROX_EQUAL(p.x(), position.x());
	  CHECK_APPROX_EQUAL(p.y(), position.y());
	  CHECK_APPROX_EQUAL(c.getRadius(), radius);
        }
    }
    
  GIVEN("A Obstacle constructed at world_size.x()/4, with radius 15")
    {
      ++test_count;
      auto const world_size(getApp().getEnvSize());
      std::cerr << "Test(ctor)#" << test_count
		<< " world size="
		<<  world_size
		<< std::endl;
     
      auto const position(world_size/4);
      auto const radius(15);
      DummyObstacle c(position, radius) ;

      THEN("coordinates returned by getCenter() must be world_size/4\
              and radius returned by getRadius() must be 15")
        {
	  auto p (c.getCenter());
	  CHECK_APPROX_EQUAL(p.x(), position.x());
	  CHECK_APPROX_EQUAL(p.y(), position.y());
	  CHECK_APPROX_EQUAL(c.getRadius(), radius);
        }
    }
  
  GIVEN("A Obstacle constructed at world_size.x(), with radius 15.5")
    {
      ++test_count;
      auto const world_size(getApp().getEnvSize());
      std::cerr << "Test(ctor)#" << test_count
		<< " world size="
		<<  world_size
		<< std::endl;
     
      auto const radius(15.5);
      DummyObstacle c(world_size, radius) ;

      THEN("coordinates returned by getCenter() must (0,0) due to clamping\
              and radius returned by getRadius() must be 15.5")
        {
	  auto p (c.getCenter());
	  CHECK_APPROX_EQUAL(p.x(), 0.);
	  CHECK_APPROX_EQUAL(p.y(), 0.);
	  CHECK_APPROX_EQUAL(c.getRadius(), radius);
        }
    }
  GIVEN("A Obstacle constructed at world size.x()+10, world size.y()-10, radius 15")
    {
      ++test_count;
      auto const world_size(getApp().getEnvSize());
      std::cerr << "Test(ctor)#" << test_count
		<< " world size="
		<<  world_size
		<< std::endl;

      auto position(Vec2d(world_size.x()+10, world_size.y()-10));
      auto const radius(15);
      DummyObstacle c(position, radius) ;

      THEN("coordinates returned by getCenter() must \
              (10,world_size.y()-10) due to clamping\
              and radius returned by getRadius() must be 15")
        {
	  auto p (c.getCenter());
	  CHECK_APPROX_EQUAL(p.x(), 10.);
	  CHECK_APPROX_EQUAL(p.y(), world_size.y()-10.0);
	  CHECK_APPROX_EQUAL(c.getRadius(), radius);
        }
    }
}
SCENARIO("Collision", "[Obstacle]")
{
  GIVEN("Two identical Obstacles")
    {
      ++test_count;
      std::cerr << "Test(collision)#" << test_count
		<< std::endl;
      DummyObstacle o1({ 1, 1 }, 4);
      DummyObstacle o2({ 1, 1 }, 4, false);

      THEN("they are properly constructed and they collide")
             {
           CHECK(o1.getCenter() == Vec2d(1,1));
           CHECK (o1.getRadius() == 4);
           CHECK(o1.isTraversable());
           CHECK_FALSE(o2.isTraversable());
           CHECK(o1.isColliding(o2));
           CHECK(o2.isColliding(o1));
           CHECK((o1 | o2));
           CHECK((o2 | o1));
             }

      THEN("they have the same bounding circle")
        {
	  CHECK(o1.getCenter() == o2.getCenter());
	  CHECK(o1.getRadius() == o2.getRadius());
        }
    }

  GIVEN("An obstacle inside the other, with different centers and radius")
    {
      ++test_count;
      std::cerr << "Test(collision)#" << test_count
		<< std::endl;
      DummyObstacle o1({ 0, 0 }, 4);
      DummyObstacle o2({ 1, 1 }, 3);

      THEN("the two obstacles collide")
        {
	  CHECK(o1.isColliding(o2));
	  CHECK(o2.isColliding(o1));
	  CHECK((o1 | o2));
	  CHECK((o2 | o1));
        }
		
      THEN("their bounding circles are not the same")
        {
	  CHECK_FALSE(o1.getRadius() == o2.getRadius());
	  CHECK_FALSE(o1.getCenter() == o2.getCenter());
        }
    }

  GIVEN("Obstacles that overlap but are not inside of each other")
    {
      ++test_count;
      std::cerr << "Test(collision)#" << test_count
		<< std::endl;
      
      DummyObstacle o1 ({ 0, 0 }, 4);
      DummyObstacle o2 ({ 1, 1 }, 3);
      DummyObstacle o3 ({ 5, 5 }, 4);

      THEN("they collide")
        {
	  CHECK(o1.isColliding(o3));
	  CHECK(o3.isColliding(o1));
	  CHECK(o2.isColliding(o3));
	  CHECK(o3.isColliding(o2));
	  CHECK((o1 | o3));
	  CHECK((o3 | o1));
	  CHECK((o2 | o3));
	  CHECK((o3 | o2));
        }
    }
	

  GIVEN("Obstacles that don't overlap ")
    {
      ++test_count;
      std::cerr << "Test(collision)#" << test_count
		<< std::endl;
      DummyObstacle o1({ 0, 0 }, 4);
      DummyObstacle o2({ 1, 1 }, 3);
      DummyObstacle o3({ 5, 5 }, 4);
      DummyObstacle o4({-9,-9 }, 4);

      THEN("they don't collide")
        {
	  CHECK_FALSE(o1.isColliding(o4));
	  CHECK_FALSE(o4.isColliding(o1));
	  CHECK_FALSE(o2.isColliding(o4));
	  CHECK_FALSE(o4.isColliding(o2));
	  CHECK_FALSE(o3.isColliding(o4));
	  CHECK_FALSE(o4.isColliding(o3));
	  CHECK_FALSE((o1 | o4));
	  CHECK_FALSE((o4 | o1));
	  CHECK_FALSE((o2 | o4));
	  CHECK_FALSE((o4 | o2));
	  CHECK_FALSE((o3 | o4));
	  CHECK_FALSE((o4 | o3));
        }
    }
	
  GIVEN("An Obstacle and two points, one inside and one outside")
    {
      ++test_count;
      std::cerr << "Test(collision)#" << test_count
		<< std::endl;
      DummyObstacle o ({ 0, 0 }, 5);
      auto p1 = Vec2d(0, 0);
      auto p2 = Vec2d(6, 0);

      THEN("only one point is inside")
        {
	  CHECK(o.isPointInside(p1));
	  CHECK(o > p1);
	  CHECK_FALSE(o.isPointInside(p2));
	  CHECK_FALSE(o > p2);
        }
    }
	
}

	
