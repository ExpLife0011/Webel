// Copyright © 2013 Brian Spanton

#pragma once

#include "Basic.NameValueCollection.h"
#include "Basic.IDecoderFactory.h"
#include "Basic.IEncoderFactory.h"

namespace Basic
{
    struct FatalError
    {
        FatalError(const char* context);
        FatalError(const char* context, uint32 error);
    };

    bool HandleError(const char* context);

    typedef StringMapCaseInsensitive<std::shared_ptr<IEncoderFactory> > EncoderMap;
    typedef StringMapCaseInsensitive<std::shared_ptr<IDecoderFactory> > DecoderMap;
}
