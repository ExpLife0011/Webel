// Copyright � 2013 Brian Spanton

#pragma once

#include "Basic.IProcess.h"
#include "Basic.Types.h"
#include "Basic.MemoryRange.h"
#include "Basic.Frame.h"
#include "Basic.IDecoder.h"

namespace Json
{
    using namespace Basic;

    class Parser;

    class ByteStreamDecoder : public Frame
    {
    private:
        enum State
        {
            unconsume_not_initialized_state = Start_State,
            bom_frame_pending_state,
            decoding_byte_stream,
            done_state = Succeeded_State,
            bom_frame_failed,
            could_not_guess_encoding_error,
            could_not_find_decoder_error,
        };

        UnicodeString::Ref encoding; // REF
        UnicodeString::Ref charset; // REF
        Basic::Ref<IStream<Codepoint> > output; // REF
        byte bom[4];
        ByteString::Ref unconsume; // REF
        Basic::Ref<IDecoder> decoder; // REF
        Inline<MemoryRange> bom_frame;

    public:
        typedef Basic::Ref<ByteStreamDecoder, IProcess> Ref;

        void Initialize(UnicodeString::Ref charset, IStream<Codepoint>* output);

        virtual void IProcess::Process(IEvent* event, bool* yield);
    };
}