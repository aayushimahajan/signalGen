//============================================================================
// Name        : signalGenerator.cpp
// Author      : Amit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "hybridautomata/hybridAutomata.h"
#include "hybridautomata/ha_helper.h"


using namespace std;

hybridAutomata::ptr create_ha1(){

	hybridAutomata::ptr h1 = hybridAutomata::ptr (new hybridAutomata());

	list<flow_equation> derivatives;
	flow_equation f1;
	f1.isConstant_dynamic = true;
	f1.varName = "x'"; 	f1.RHSexpression = "1";  f1.derivative = "x'=1";
	derivatives.push_back(f1);
	list<string> invariant;
	invariant.push_back("x>=1"); invariant.push_back("x<=10");

	std::list<std::string> guard1, guard2;
	guard1.push_back("x>0");
	std::list<reset_equation> assign_1;
	std::list<reset_equation>  assign_2;
	reset_equation assign1;
	assign1.varName = "x'"; assign1.RHSexpression = "1 * x"; assign1.reset_expression = "x' = 1 * x";
	assign_1.push_back(assign1);
	transition::ptr tran1 = transition::ptr(new transition(1, "t1", 1, 2, guard1, assign_1));
	std::list<transition::ptr> trans1;
	trans1.push_back(tran1);


	location::ptr loc1 = location::ptr(new location(1, "A", derivatives, invariant, trans1)); //new location
	h1->addLocation(loc1);

	guard2.push_back("x<0");

	reset_equation assign2;
	assign2.varName = "x'"; assign2.RHSexpression = "1 * x"; assign2.reset_expression = "x' = 1 * x";
	assign_2.push_back(assign2);
	transition::ptr tran = transition::ptr(new transition(2, "t2", 2, 1, guard2, assign_2));
	std::list<transition::ptr> trans2;
	trans2.push_back(tran);
	location::ptr loc2 = location::ptr(new location(2, "B", derivatives, invariant, trans2)); //new location
	h1->addLocation(loc2);

	h1->setInitialId(1);
	return h1;

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	hybridAutomata::ptr h1 = create_ha1();

	verifyHA_output(h1);


	return 0;
}
