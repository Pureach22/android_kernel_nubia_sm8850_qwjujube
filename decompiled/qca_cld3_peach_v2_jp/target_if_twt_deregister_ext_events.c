__int64 __fastcall target_if_twt_deregister_ext_events(
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
    v11 = wmi_unified_unregister_event_handler(*(_QWORD **)(v9 + 16), 0xC0u, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( v11 )
    {
      v12 = v11;
      v13 = "%s: Failed to deregister twt add dialog event cb";
    }
    else
    {
      v15 = wmi_unified_unregister_event_handler(v10, 0xC1u, a2, a3, a4, a5, a6, a7, a8, a9);
      if ( v15 )
      {
        v12 = v15;
        v13 = "%s: Failed to deregister twt del dialog event cb";
      }
      else
      {
        v16 = wmi_unified_unregister_event_handler(v10, 0xC2u, a2, a3, a4, a5, a6, a7, a8, a9);
        if ( v16 )
        {
          v12 = v16;
          v13 = "%s: Failed to deregister twt pause dialog event cb";
        }
        else
        {
          v17 = wmi_unified_unregister_event_handler(v10, 0xC3u, a2, a3, a4, a5, a6, a7, a8, a9);
          if ( v17 )
          {
            v12 = v17;
            v13 = "%s: Failed to deregister twt resume dialog event";
          }
          else
          {
            v18 = wmi_unified_unregister_event_handler(v10, 0xC4u, a2, a3, a4, a5, a6, a7, a8, a9);
            if ( v18 )
            {
              v12 = v18;
              v13 = "%s: Failed to deregister twt nudge dialog event cb";
            }
            else
            {
              v19 = wmi_unified_unregister_event_handler(v10, 0xC6u, a2, a3, a4, a5, a6, a7, a8, a9);
              if ( v19 )
              {
                v12 = v19;
                v13 = "%s: Failed to deregister twt notify event cb";
              }
              else
              {
                v12 = wmi_unified_unregister_event_handler(v10, 0xC7u, a2, a3, a4, a5, a6, a7, a8, a9);
                if ( !v12 )
                  return v12;
                v13 = "%s: Failed to deregister twt ack complete event cb";
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v12 = 29;
    v13 = "%s: wmi_handle is null";
  }
  qdf_trace_msg(0x49u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_twt_deregister_ext_events");
  return v12;
}
