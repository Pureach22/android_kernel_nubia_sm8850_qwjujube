__int64 __fastcall hdd_data_stall_process_event(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 **context; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  void (*v29)(void); // x8
  __int64 result; // x0
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 8);
    v31 = 0;
    v2 = *(_DWORD *)(v1 + 4);
    qdf_mem_set(&v31, 4u, 0);
    v31 = v2;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Posting data stall event %x",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_data_stall_send_event",
      v2);
    host_diag_event_report_payload(2874, 4, &v31);
    context = (__int64 **)_cds_get_context(
                            71,
                            (__int64)"hdd_data_stall_send_event",
                            v11,
                            v12,
                            v13,
                            v14,
                            v15,
                            v16,
                            v17,
                            v18);
    if ( context && *context )
    {
      v28 = **context;
      if ( v28 )
      {
        v29 = *(void (**)(void))(v28 + 528);
        if ( v29 )
        {
          if ( *((_DWORD *)v29 - 1) != 358154616 )
            __break(0x8228u);
          v29();
        }
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v20, v21, v22, v23, v24, v25, v26, v27, "cdp_display_stats");
    }
    result = 0;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
