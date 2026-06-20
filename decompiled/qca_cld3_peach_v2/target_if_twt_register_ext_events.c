__int64 __fastcall target_if_twt_register_ext_events(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  _QWORD *v10; // x20
  unsigned int v11; // w0
  unsigned int v12; // w19
  const char *v13; // x2
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    v11 = wmi_unified_register_event_handler(
            *(_QWORD **)(v9 + 16),
            0xC0u,
            (__int64)target_if_twt_setup_complete_event_handler,
            0,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9);
    if ( v11 )
    {
      v12 = v11;
      v13 = "%s: Failed to register twt add dialog event cb";
    }
    else
    {
      v15 = wmi_unified_register_event_handler(
              v10,
              0xC1u,
              (__int64)target_if_twt_teardown_complete_event_handler,
              0,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
      if ( v15 )
      {
        v12 = v15;
        v13 = "%s: Failed to register twt del dialog event cb";
      }
      else
      {
        v16 = wmi_unified_register_event_handler(
                v10,
                0xC2u,
                (__int64)target_if_twt_pause_complete_event_handler,
                0,
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9);
        if ( v16 )
        {
          v12 = v16;
          v13 = "%s: Failed to register twt pause dialog event cb";
        }
        else
        {
          v17 = wmi_unified_register_event_handler(
                  v10,
                  0xC3u,
                  (__int64)target_if_twt_resume_complete_event_handler,
                  0,
                  a2,
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9);
          if ( v17 )
          {
            v12 = v17;
            v13 = "%s: Failed to register twt resume dialog event cb";
          }
          else
          {
            v18 = wmi_unified_register_event_handler(
                    v10,
                    0xC4u,
                    (__int64)target_if_twt_nudge_complete_event_handler,
                    0,
                    a2,
                    a3,
                    a4,
                    a5,
                    a6,
                    a7,
                    a8,
                    a9);
            if ( v18 )
            {
              v12 = v18;
              v13 = "%s: Failed to register twt nudge dialog event cb";
            }
            else
            {
              v19 = wmi_unified_register_event_handler(
                      v10,
                      0xC6u,
                      (__int64)target_if_twt_notify_event_handler,
                      0,
                      a2,
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9);
              if ( v19 )
              {
                v12 = v19;
                v13 = "%s: Failed to register twt notify event cb";
              }
              else
              {
                v12 = wmi_unified_register_event_handler(
                        v10,
                        0xC7u,
                        (__int64)target_if_twt_ack_complete_event_handler,
                        0,
                        a2,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9);
                if ( !v12 )
                  return v12;
                v13 = "%s: Failed to register twt ack event cb";
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v12 = 4;
    v13 = "%s: wmi_handle is null!";
  }
  qdf_trace_msg(0x49u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_twt_register_ext_events");
  return v12;
}
