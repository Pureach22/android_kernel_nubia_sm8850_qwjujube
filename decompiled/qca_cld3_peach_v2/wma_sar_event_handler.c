__int64 __fastcall wma_sar_event_handler(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 v23; // x0
  __int64 v24; // x19
  unsigned int sar_limit_event; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  void (__fastcall *v34)(__int64, __int64); // x8
  __int64 v35; // x0

  v13 = 4;
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: handle:%pK event:%pK len:%u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_sar_event_handler",
    a1,
    a2,
    a3);
  if ( !(unsigned int)_wma_validate_handle(a1, "wma_sar_event_handler") )
  {
    v22 = *a1;
    if ( (unsigned int)_wmi_validate_handle(
                         *a1,
                         (__int64)"wma_sar_event_handler",
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21) )
    {
      return 4;
    }
    else
    {
      v23 = _qdf_mem_malloc(0x408u, "wma_sar_event_handler", 5628);
      if ( v23 )
      {
        v24 = v23;
        sar_limit_event = wmi_unified_extract_sar_limit_event(v22, a2, v23);
        if ( sar_limit_event )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Event extract failure: %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "wma_sar_event_handler",
            sar_limit_event);
          v13 = 4;
        }
        else
        {
          v34 = (void (__fastcall *)(__int64, __int64))sar_callback;
          sar_callback = nullptr;
          if ( v34 )
          {
            v35 = sar_context;
            if ( *((_DWORD *)v34 - 1) != -388706469 )
              __break(0x8228u);
            v34(v35, v24);
          }
          v13 = 0;
        }
        _qdf_mem_free(v24);
      }
      else
      {
        return 2;
      }
    }
  }
  return v13;
}
