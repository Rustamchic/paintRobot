//============================================================================
// Name        : Ami_Khily.cpp
// Author      : Amirov Mirali & Khilyazov Rustam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<sstream>
#include<string>
using namespace std;
class  CommandStrategy{
public:
    virtual string getCommand() const = 0;
};
class  ConsoleCommandStrategy  : public CommandStrategy {
public:
    virtual string getCommand() const override {
      string cmd;
      cin >> cmd;
      return cmd;
    }
};

class NetCommandStrategy : public CommandStrategy {

  virtual string getCommand() const override {
      string cmd;
      //cmd = receive();
      return cmd;
    }
};


class  OnTestCommandStrategy  : public CommandStrategy {
public:
    virtual string getCommand() const override {
      return string("On");
    }
};
enum class EState {
	Wait_cmd,
	Reverse,
	EOn,
EOff};

class Robot{
public:
  EState state;
    void processEvent(const string& command, EState& state);
    void getCoordinates();
    void reverse(double angle);
    void moveStraight(double distance);
    void clean();
    int R(const string& com);
    CommandStrategy* pcommandprocessor;
       Robot(CommandStrategy* pcommandprocessor) {
       }

       /*string getCommand() const override{
         return pcommandprocessor->getCommand();
       }*/
       string getCommand() {
         string cmd;

         cin >> cmd;
         return cmd;
       }
};
// void Robot::processEvent(ECommand command)  // лучше
/*void Robot::setNextState(EState nstate) {
    cout << "cur state" << state;
    state = Wait_cmd;
    cout << "nex state" << state;
}
void Robot::Wait_cmdEventProcessing(const string &cmd)  {
                if(cmd == "On") {
                   cout << " On";
//                   state =  EOn;
                   setNextState(EOn);
                }
}*/
void Robot::reverse(double angle)
  {
      cout << "Robot turned to " << angle << " degree" << endl;
  };
void Robot::moveStraight(double distance)
{
    cout << "Robot moved straight to " << distance << endl;
};

void Robot::clean()
{
    cout << "Robot cleaned the area" << endl;
};
int Robot::R(const string& com){
	if(com == "Reverse"){
		return 1;
	} else if(com == "Wait_cmd"){
		return 2;
	}
}
void Robot::processEvent(const string& command, EState& state){
	string com;
	        cin >> com;
	        switch (R(com))
	        {
	            case 2:
	                Wait_cmdEventProcessing(command);
	                break;



	            case 1:
	                double angl;
	                cin >> angl;
	                Robot::reverse(angl);
	                state = EState::Wait_cmd;

	                break;
	        }
}

int main(){
	    Robot paintRobot (new NetCommandStrategy());
paintRobot.state = EState::Wait_cmd;
	    while (paintRobot.state == EState::Wait_cmd){
	        string cmd = paintRobot.getCommand();
	        paintRobot.processEvent(cmd, paintRobot.state);
	    }
    return 0;
}
