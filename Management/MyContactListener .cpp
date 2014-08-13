#include "MyContactListener.h"

MyContactListener::MyContactListener():_contacts(){

}

MyContactListener::~MyContactListener(){

}

void MyContactListener::BeginContact(b2Contact* contact){
	MyContact mycontact = { contact->GetFixtureA(), contact->GetFixtureB() };
	_contacts.push_back(mycontact);
}


void MyContactListener::EndContact(b2Contact* contact){
	MyContact mycontact = { contact->GetFixtureA(), contact->GetFixtureB() };
	vector<MyContact>::iterator pos;

	pos = find(_contacts.begin(), _contacts.end(), mycontact);
	if (pos != _contacts.end()){
		_contacts.erase(pos);
	}
}

void MyContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){

}


void MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){

}
