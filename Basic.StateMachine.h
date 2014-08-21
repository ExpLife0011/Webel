// Copyright © 2013 Brian Spanton

#pragma once

namespace Basic
{
    class StateMachine
    {
    private:
        uint32 state;

    protected:
        void switch_to_state(uint32 state);
        void reset();

    public:
        static const uint32 Start_State = 0;
        static const uint32 Succeeded_State = 0x10000;

        StateMachine();

        uint32 get_state();

        virtual bool in_progress();
        virtual bool succeeded();
        virtual bool failed();
    };
}