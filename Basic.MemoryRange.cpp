// Copyright © 2013 Brian Spanton

#include "stdafx.h"
#include "Basic.MemoryRange.h"
#include "Basic.Globals.h"

namespace Basic
{
    MemoryRange::MemoryRange() :
        received(0),
        bytes(0),
        count(0)
    {
    }

    MemoryRange::MemoryRange(byte* bytes, uint32 count) :
        received(0),
        bytes(bytes),
        count(count)
    {
    }

    void MemoryRange::reset(byte* bytes, uint32 count)
    {
        this->received = 0;
        this->bytes = bytes;
        this->count = count;
    }

    void MemoryRange::write_elements(const byte* elements, uint32 received)
    {
        uint32 remaining = this->count - this->received;
        if (received > remaining)
            throw FatalError("MemoryRange::write_elements received > remaining");

        CopyMemory(this->bytes + this->received, elements, received);
        this->received += received;
    }

    uint32 MemoryRange::Length()
    {
        return this->received;
    }

    bool MemoryRange::in_progress()
    {
        return this->received < this->count;
    }

    bool MemoryRange::succeeded()
    {
        return this->received == this->count;
    }

    bool MemoryRange::failed()
    {
        return false;
    }
}