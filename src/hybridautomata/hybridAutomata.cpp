/*
 * hybridAutomata.cpp
 *
 *  Created on: 22-Sep-2021
 *      Author: amit
 */

#include "hybridAutomata.h"

using namespace std;

hybridAutomata::hybridAutomata() {
	initial_id = 0;
	dimension = 0;
}
/*
hybridAutomata::hybridAutomata(std::map<int, location::ptr>& list_locs, location::ptr init_loc,
		int dim) {
	list_locations = list_locs;	//assigning a map to another map
	initial_loc = init_loc;
	dimension = dim;
}
*/

location::ptr hybridAutomata::getLocation(int Loc_Id){
	//iterate through the transition and find for given input Name that match with the source_location
	assert(list_locations.count(Loc_Id) != 0);

	location::ptr l;
	l = list_locations[Loc_Id];
	return l;
}


void hybridAutomata::addLocation(location::ptr& loc){
	int key = loc->getLocId();
	list_locations[key] = loc;	//storing the loc with the proper loc_id as the key
}

void hybridAutomata::addMapped_Locations_List(std::map<int, location::ptr>& mapped_location_list){
	this->list_locations = mapped_location_list;
}

unsigned int hybridAutomata::getInitialId() const {
	return initial_id;
}

void hybridAutomata::setInitialId(unsigned int initialId) {
	initial_id = initialId;
}

std::map<int, location::ptr> hybridAutomata::getLocation_List(){
	return list_locations;
}

location::ptr& hybridAutomata::getInitial_Location() {
	//Todo check before this creation if 'initial_loc' is already added using addInitial_Location()
	initial_loc = list_locations[initial_id];

	return initial_loc;
}

void hybridAutomata::addInitial_Location(location::ptr& initLoc) {
	initial_loc = initLoc;
}


int hybridAutomata::getDimension() const {
	return dimension;
}

void hybridAutomata::setDimension(int dim) {
	this->dimension = dim;
}

unsigned int hybridAutomata::getLocationID(string search_loc_name){
	unsigned int loc_ID=0, flag=0;
	string location_name;
	for (std::map<int, location::ptr>::iterator it2=list_locations.begin(); it2 != list_locations.end(); it2++) {

		location::ptr loc = it2->second;
		location_name = loc->getName();
		if (location_name == search_loc_name) {
			flag=1;
			loc_ID = loc->getLocId();
			break;
		}
	}
	if (flag)
		return loc_ID;
	else
		throw std::invalid_argument( "Error hybridAutomata::getLocationID(): Invalid search location-name" );
}

string hybridAutomata::getLocationName(unsigned int loc_id) {
	return list_locations[loc_id]->getName();
}


std::list<transition::ptr> hybridAutomata::get_all_transition() {
	std::list<transition::ptr> all_trans;

	for (std::map<int, location::ptr>::iterator it=list_locations.begin(); it != list_locations.end(); it++){
		location::ptr loc = it->second;
		std::list<transition::ptr> trans = loc->getOutGoingTransitions();
		all_trans.insert(all_trans.end(), trans.begin(), trans.end());
	}
	return all_trans;
}
