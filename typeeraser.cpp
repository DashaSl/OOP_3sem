#include "typeeraser.h"

template<typename T>
Erased::Erased(T&& obj) : object(std::make_shared<Model<T>>(std::forward<T>(obj))){}

std::pair<uint8_t, uint8_t> Erased::get_cord() const{
	return object->get_cord();
}

void Erased::move() const{
	return object->move();
}

void Erased::interact() const{
	return object->interact();
}

bool Erased::is_player_reached() const{
	return object->is_player_reached();
}

Erased::Concept::~Concept(){}

template<typename T>
Erased::Model<T>::Model(const T& obj) : object(obj){}

template<typename T>
std::pair<uint8_t, uint8_t> Erased::Model<T>::get_cord() const{
	return object.get_cord();
}

template<typename T>
void Erased::Model<T>::move() const{
	return object.move();
}

template<typename T>
void Erased::Model<T>::interact() const{
	return object.interact();
}


template<typename T>
bool Erased::Model<T>::is_player_reached() const{
	return object.is_player_reached();
}
