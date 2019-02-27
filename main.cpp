#include <stdio.h>

typedef struct State *Pstate;
typedef struct State{
	int x, y;
	Pstate parent;
	int hd;
};

//Kiem tra trang thai dich
bool goalcheck(Pstate s){
	if((s->x == 6) || (s->y == 6))
		return true;
	return false;
}

//Tra ve gia tri nho nhat
int min(int a, int b){
	return (a > b) ? b : a;
}

//Tra ve gia tri lon nhat
int max(int a, int b){
	return (a > b) ? a : b;
}

//Chuyen tu Y sang X
Pstate Cyx(Pstate s){
	if((s->y > 0) && (s->x < 9)){
		Pstate result = new State;
		result->x = min((s->x + s->y), 9);
		result->y = max(s->y + s->x - 9, 0);
		result->parent = s;
		return result;
	}
	return NULL;
}

//Chuyen tu X sang Y
Pstate Cxy(Pstate s){
	if((s->y < 4) && (s->x > 0)){
		Pstate result = new State;
		result->x = max((s->x + s->y), 4);
		result->y = min(s->y + s->x - 4, 0);
		result->parent = s;
		return result;
	}
	return NULL;
}

//Lam day X
Pstate LamdayX(Pstate s){
	if(s->x < 9){
		Pstate result = new State;
		result->x = 9;
		result->y = s->y;
		result->parent = s;
		return result;
	}
	return NULL;
}

//Lam day Y
Pstate LamdayY(Pstate s){
	if(s->y < 4){
		Pstate result = new State;
		result->x = s->x;
		result->y = 4;
		result->parent = s;
		return result;
	}
	return NULL;
}

//Lam rong X
Pstate LamrongX(Pstate s){
	if(s->x > 0){
		Pstate result = new State;
		result->x = 0;
		result->y = s->y;
		result->parent = s;
		return result;
	}
	return NULL;
}

//Lam rong Y
Pstate LamrongY(Pstate s){
	if(s->y > 0){
		Pstate result = new State;
		result->x = s->x;
		result->y = 0;
		result->parent = s;
		return result;
	}
	return NULL;
}

//Thuc hien cac hanh dong
Pstate call_operator(Pstate s, int op_no){
	switch(op_no){
		case 1:
			return Cyx(s);
			break;
		case 2:
			return Cxy(s);
			break;
		case 3:
			return LamdayX(s);
			break;
		case 4:
			return LamdayY(s);
			break;
		case 5:
			return LamrongX(s);
		case 6:
			return LamrongY(s);
			break;
		default:
			return NULL;
	}
}

////Kiem tra trang thai
//bool foundstate(Pstate pstate, vector<Pstate> openlist){
//	for(Pstate tmp : openlist){
//		if(pstate->x == tmp->x && pstate->y == tmp->y){
//			return true;
//		}
//	}
//	return false;
//}

int main(){
//	Trang thai bat dau
	Pstate pStart = new State;
	pStart->x=0;
	pStart->y=0;
	pStart->parent=NULL;
	return 0;
}
