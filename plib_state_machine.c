/**
 * @file plib_state_machine.c
 * @brief Machine d'état générique
 * @author Ramiro Najera
 * @version 1.0.7
 * @date 2025-10-06
 */

#include "plib_state_machine.h"

void StateMachine_Init(StateMachine_t *sm)
{
    sm->currentState = 0;
    sm->entryFlag = 1;
}

void StateMachine(StateMachine_t *sm)
{
    const State *s = &sm->states[sm->currentState];

    if(sm->entryFlag && s->action)
    {
        s->action();
        sm->entryFlag = 0;
    }

    for (int i = 0; i < s->numTransitions; i++)
    {
        Transition *t = &s->transitions[i];

        if (t->condition && t->condition())
        {
            if(t->actions)
                t->actions();
            sm->currentState = t->nextState;
            sm->entryFlag = 1;
            break;
        }
    }
}

void StateMachine_SetStateList(StateMachine_t *sm, State *states)
{
    sm->states = states;
}

void StateMachine_SetState(StateMachine_t *sm, const uint8_t state)
{
    sm->currentState = state;
    sm->entryFlag = 1;
}