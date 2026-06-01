#ifndef PLIB_STATE_MACHINE_H
#define PLIB_STATE_MACHINE_H

/**
 * @file plib_state_machine.h
 * @brief Machine d'état générique
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-10-06
 */

typedef unsigned char (*ConditionFunc)(void);
typedef void (*ActionFunc)(void);

typedef struct {
    ConditionFunc condition;
    ActionFunc onTransition;
    unsigned char nextState;
}Transition;

typedef struct {
    Transition *transitions;    // Transitions checked each tick
    unsigned char numTransitions;
}State;

typedef struct
{
    const State *states;
    unsigned char currentState;
}StateMachine_t;

void StateMachine_Init(StateMachine_t *sm);

void StateMachine(StateMachine_t *sm);

void StateMachine_SetStateList(StateMachine_t *sm, State *states);

#endif  // PLIB_STATE_MACHINE_H