// Copyright � 2013 Brian Spanton

#include "stdafx.h"
#include "Html.TagToken.h"

namespace Html
{
    using namespace Basic;

    TagToken::TagToken(Type type) :
        Token(type)
    {
        this->self_closing = false;
        this->acknowledged = false;
        this->name = std::make_shared<UnicodeString>();
    }

    bool TagToken::has_name_of(ElementName* element)
    {
        return equals<UnicodeString, true>(this->name.get(), element->name.get());
    }
}