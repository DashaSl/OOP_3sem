#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "enemy.h"
#ifndef ERASER
#define ERASER
class Erased{
public:
	template<typename T>
	Erased(T&& obj) : object(std::make_shared<Model<T>>(std::forward<T>(obj))){}

	std::pair<uint8_t, uint8_t> get_cord() const{
		return object->get_cord();
	}
	void move() const{
		return object->move();
	}
	void interact() const{
		return object->interact();
	}
	bool is_player_reached() const{
		return object->is_player_reached();
	}

	struct Concept{
		virtual ~Concept(){}
		virtual std::pair<uint8_t, uint8_t> get_cord() const = 0;
		virtual void move() const = 0;
		virtual void interact() const = 0;
		virtual bool is_player_reached() const = 0;
	};

	template<typename T>
	struct Model : Concept{
		Model(const T& obj) : object(obj){}
		std::pair<uint8_t, uint8_t> get_cord() const override{
			return object.get_cord();
		}
		void move() const override{
			return object.move();
		}
		void interact() const override{
			return object.interact();
		}

		bool is_player_reached() const override{
			return object.is_player_reached();
		}

	private:
		T object;
	};

	std::shared_ptr<const Concept> object;


};
#endif

