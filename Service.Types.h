// Copyright � 2013 Brian Spanton

#pragma once

#include "Basic.Event.h"
#include "Basic.Uri.h"
#include "Basic.SuffixArray.h"
#include "Json.Types.h"

namespace Service
{
	enum EventType
	{
		task_complete_event = 0x4000,
		characters_complete_event,
	};

	struct TaskCompleteEvent : public Basic::IEvent
	{
		Basic::ByteString::Ref cookie; // REF

		virtual uint32 get_type();
	};

	struct CharactersCompleteEvent : public Basic::IEvent
	{
		Basic::ByteString::Ref cookie; // REF

		virtual uint32 get_type();
	};

	typedef Basic::SuffixArray<Json::Object::Ref> Index; // REF
}