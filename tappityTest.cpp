/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, length_same){
  tappity tap("hello");
  tap.entry("world");
  ASSERT_EQ(0, tap.length_difference());
}

TEST(tappityTest, length_ref5_in0){
  tappity tap("hello");
  tap.entry("");
  ASSERT_EQ(5, tap.length_difference());
}

TEST(tappityTest, length_ref5_in4){
  tappity tap("hello");
  tap.entry("worl");
  ASSERT_EQ(1, tap.length_difference());
}

TEST(tappityTest, length_ref2_in5){
  tappity tap("he");
  tap.entry("world");
  ASSERT_EQ(3, tap.length_difference());
}

TEST(tappityTest, accuracy_match){
  tappity tap("hello world");
  tap.entry("hello world");
  ASSERT_EQ(100.0, tap.accuracy());
}

TEST(tappityTest, accuracy_shorter_input){
  tappity tap("hello");
  tap.entry("hell");
  ASSERT_EQ(80.0, tap.accuracy());
}

TEST(tappityTest, accuracy_longer_input){
  tappity tap("hello");
  tap.entry("helloworld");
  ASSERT_EQ(50.0, tap.accuracy());
}

TEST(tappityTest, accuracy_empty_input){
  tappity tap("hello");
  tap.entry("");
  ASSERT_EQ(0.0, tap.accuracy());
}

TEST(tappityTest, accuracy_end_char_mismatch){
  tappity tap("hello");
  tap.entry("hellp");
  ASSERT_EQ(80.0, tap.accuracy());
}

TEST(tappityTest, accuracy_missed_first_char){
  tappity tap("hello");
  tap.entry("ello");
  ASSERT_EQ(20.0, tap.accuracy());
}

TEST(tappityTest, accuracy_partial_match5_of11){
  tappity tap("hello world");
  tap.entry("hello");
  ASSERT_EQ((double)500/11, tap.accuracy());
}
