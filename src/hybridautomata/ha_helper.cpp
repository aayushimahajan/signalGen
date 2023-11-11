/*
 * ha_helper.cpp
 *
 *  Created on: 19-May-2023
 *      Author: amit
 */


#include "ha_helper.h"


//Function for Debugging the output of HA
void verifyHA_output(hybridAutomata::ptr &H) {


	cout << "*********Verify HA Output*********"<<endl;
	cout << "Total number of Locations = "<< H->getTotalLocations()<<endl;


	H->print_var_mapping();

	cout<< "Initial Location ID: "<< H->getInitialId() <<endl;

	std::map<int, location::ptr> list_locations;
	list_locations = H->getLocation_List();

	for (std::map<int, location::ptr>::iterator i= list_locations.begin(); i != list_locations.end(); i++) {
		location::ptr loc = (*i).second;	//since our location starts from 0
		cout <<"\n======****** Mode Details ******======"<<endl;
		cout << "Location Name: "<<loc->getName() <<"  ID: "<< loc->getLocId()<<endl;
		std::list<std::string> inv_test = loc->getInvariant();
		for (std::list<std::string>::iterator mod_inv = inv_test.begin(); mod_inv != inv_test.end(); mod_inv++){
			std::cout << "Invariant: " << (*mod_inv) << std::endl;
		}

		list<flow_equation> derivatives = loc->getDerivatives();

		for (list<flow_equation>::iterator it_flow = derivatives.begin(); it_flow != derivatives.end(); it_flow++) {
			std::cout << "Flow: "<<(*it_flow).derivative<< std::endl;
			//cout<<"Flow:varName "<<(*it_flow).varName<<endl;
			//cout<<"Flow:RHS "<<(*it_flow).RHSexpression<<endl;
		}

		list<transition::ptr> trans = loc->getOutGoingTransitions();
		std::cout <<"====== Outgoing transition ======"<< std::endl;
		for (list<transition::ptr>::iterator it_trans = trans.begin(); it_trans != trans.end(); it_trans++) {
			std::cout <<"Transition ID: "<< (*it_trans)->getTransId()<< std::endl;
			std::cout <<"Transition Label: "<< (*it_trans)->getLabel()<< std::endl;
			std::cout <<"Transition Source-ID and Destination-ID:  "<< (*it_trans)->getSourceLocationId() << "  --->   "<< (*it_trans)->getDestinationLocationId()<< std::endl;


			std::list<std::string> guard = (*it_trans)->getGuard();
//			list<std::string>::iterator it_guard = guard.begin();
			std::cout<< "Transition-Guard: "<<endl;
			for (std::list<std::string>::iterator mod_guard=guard.begin(); mod_guard != guard.end(); mod_guard++){
				std::cout << (*mod_guard) << std::endl;
			}

			/*std::list<std::string> guard_modified = (*it_trans)->getGuardModified();
			string guard_changed = (*guard_modified.begin());
			std::cout<< "Transition-Modified Guard: " << std::endl;
			for (std::list<std::string>::iterator mod_guard=guard_modified.begin(); mod_guard != guard_modified.end(); mod_guard++){
				std::cout << (*mod_guard) << std::endl;
			}*/

			std::cout<< "Transition-Reset: "<< std::endl;
			list<reset_equation> reset_eqs = (*it_trans)->getAssignment();
			for (list<reset_equation>::iterator it_reset = reset_eqs.begin(); it_reset != reset_eqs.end(); it_reset++) {
				std::cout << "Reset: " << (*it_reset).reset_expression << std::endl;
				//cout<<"Reset: varName "<<(*it_reset).varName << endl;
				//cout<<"Reset: RHS "<<(*it_reset).RHSexpression << endl;
			}

		}//End of the Transition
	} //End of the Location

}
