
#include "controller.h"

template <typename MoveScheme, typename InteractScheme>
Enemy<MoveScheme, InteractScheme>::Enemy(std::pair<uint8_t, uint8_t> cur_cor, Player& plr, Controller& cont,  MoveScheme m, InteractScheme i): player(plr), controller(cont), M(m), I(i){
	interaction_pause = 0;
	cur_cord = cur_cor;
}
template <typename MoveScheme, typename InteractScheme>
std::pair<uint8_t, uint8_t> Enemy<MoveScheme, InteractScheme>::get_cord(){
	return cur_cord;
}
template <typename MoveScheme, typename InteractScheme>
void Enemy<MoveScheme, InteractScheme>::move(){
	if(!interaction_pause){
		std::pair<uint8_t, uint8_t> new_cord = M.move(controller, cur_cord);
		cur_cord = new_cord;
	}else{
		interaction_pause--;
	}
}
template <typename MoveScheme, typename InteractScheme>
void Enemy<MoveScheme, InteractScheme>::interact(){
	I.interact(player, controller);
	interaction_pause = PAUSE;
}
template <typename MoveScheme, typename InteractScheme>
bool Enemy<MoveScheme, InteractScheme>::is_player_reached(){
	return cur_cord == controller.get_cord();
}

template class Enemy<MovementRandom, InteractionHp>;
template class Enemy<MovementRandom, InteractionTeleport>;
template class Enemy<MovementStalker, InteractionHp>;
template class Enemy<MovementStalker, InteractionTeleport>;
