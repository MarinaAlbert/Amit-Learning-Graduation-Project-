/*
 * BIT_MATH.h 
 *
 * Created: 12/15/2023 8:09:17 PM
 *  Author: Marina Albert
 */ 

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define		ASSIGN_PORT(Var , Val)	Var = Val
#define		SET_BIT(Var , BitNo)	Var = Var | (1 << BitNo)
#define		CLEAR_BIT(Var , BitNo)	Var = Var & ~(1 << BitNo)
#define		GET_BIT(Var , BitNo)	( (Var >> BitNo) & 1 )
#define		TOGGLE_BIT(Var , BitNo)	Var = Var ^ (1 << BitNo)
#endif