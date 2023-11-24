#define CATCH_CONFIG_MAIN//για να μην χρειάζεται main
#include "catch.hpp"
#include "base.hpp"
//έλενχοι εισαγωγής δεδομένων
TEST_CASE("set_WorkDuration")
{
    Pomodoro c1;
    c1.set_WorkDuration(5);
    REQUIRE(c1.get_WorkDuration()==5);  
    c1.set_WorkDuration(3); 
    REQUIRE(c1.get_WorkDuration()==3);
    c1.set_WorkDuration(-7);
    REQUIRE(c1.get_WorkDuration()==3);
}

TEST_CASE("get_BreakDuration")
{
    Pomodoro c1;
    c1.set_BreakDuration(5);
    REQUIRE(c1.get_BreakDuration()==5);  
    c1.set_BreakDuration(3); 
    REQUIRE(c1.get_BreakDuration()==3);
    c1.set_BreakDuration(-7);
    REQUIRE(c1.get_BreakDuration()==3);
}

TEST_CASE("add_sessionsCompleted")
{
    Pomodoro c1;
    c1.add_sessionsCompleted();
    REQUIRE(c1.get_sessionsCompleted()==1); 
    c1.add_sessionsCompleted();
    REQUIRE(c1.get_sessionsCompleted()==2);
    c1.add_sessionsCompleted();
    REQUIRE(c1.get_sessionsCompleted()==3);
}

TEST_CASE("add_totalWorkTime")
{
    Pomodoro c1;
    c1.add_totalWorkTime(3);
    REQUIRE(c1.get_totalWorkTime()==3); 
    c1.add_totalWorkTime(5);
    REQUIRE(c1.get_totalWorkTime()==8);
    c1.add_totalWorkTime(-7);
    REQUIRE(c1.get_totalWorkTime()==8);
}