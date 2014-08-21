// Copyright © 2013 Brian Spanton

#pragma once

namespace Basic
{
    template <typename element_type>
    class IgnoreFrame
    {
    private:
        uint64 expected;
        uint64 received;

    public:
        IgnoreFrame() :
            received(0),
            expected(0xffffffffffffffff)
        {
        }

        void reset(uint64 expected)
        {
            this->received = 0;
            this->expected = expected;
        }

        bool offer_elements(ElementSource<byte>* element_source)
        {
            const byte* elements;
            uint32 count;

            uint64 needed = this->bytes_expected - this->bytes_received;

            element_source->Read(needed > 0xffffffff ? 0xffffffff : (uint32)needed, &elements, &count);

            this->received += count;

            if (this->received != this->expected)
                return false;

            return true;
        }
    };
}