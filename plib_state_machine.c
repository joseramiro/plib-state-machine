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
}

void StateMachine(StateMachine_t *sm)
{
    const State *s = &sm->states[sm->currentState];

    for (int i = 0; i < s->numTransitions; i++)
    {
        Transition *t = &s->transitions[i];

        if (t->condition && t->condition())
        {
            if (t->onTransition)
                t->onTransition();

            sm->currentState = t->nextState;
            break;
        }
    }
}