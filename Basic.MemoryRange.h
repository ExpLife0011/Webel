// Copyright © 2013 Brian Spanton

#pragma once

#include "Basic.IStream.h"
#include "Basic.IStreamWriter.h"

namespace Basic
{
    class MemoryRange : public ArrayStream<byte>
    {
    private:
        uint32 count;
        uint32 received;
        byte* bytes;

    public:
        MemoryRange();
        MemoryRange(byte* bytes, uint32 count);

        void reset(byte* bytes, uint32 count);

        virtual void IStream<byte>::write_elements(const byte* elements, uint32 received);
        virtual void IStream<byte>::write_element(byte element);
        virtual void IStream<byte>::write_eof();

        bool in_progress();
        bool succeeded();
        bool failed();

        uint32 Length();
    };
}