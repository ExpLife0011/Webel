// Copyright � 2013 Brian Spanton

#pragma once

#include "Basic.IProcess.h"
#include "Tls.Types.h"
#include "Tls.AlertFrame.h"

namespace Tls
{
    using namespace Basic;

    class RecordLayer;

    class AlertProtocol : public Frame
    {
    protected:
        enum State
        {
            start_state = Start_State,
            alert_frame_pending_state,
            done_state = Succeeded_State,
            alert_frame_failed,
            alert_frame_peer_close_notify_state,
        };

        RecordLayer* session;
        Alert alert;
        std::shared_ptr<AlertFrame> alert_frame;

        virtual void IProcess::consider_event(IEvent* event);

    public:
        AlertProtocol(RecordLayer* session);
    };
}