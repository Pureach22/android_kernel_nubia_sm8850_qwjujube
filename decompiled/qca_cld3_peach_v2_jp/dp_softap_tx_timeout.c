__int64 __fastcall dp_softap_tx_timeout(__int64 a1)
{
  __int64 context; // x19
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  unsigned int v14; // w9
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  _DWORD *v24; // x8

  context = _cds_get_context(71, "dp_softap_tx_timeout");
  result = _cds_get_context(71, "dp_softap_tx_timeout");
  if ( result && *(_QWORD *)result )
  {
    v12 = *(_QWORD *)(*(_QWORD *)result + 112LL);
    if ( v12 )
    {
      v13 = *(__int64 (**)(void))(v12 + 32);
      if ( v13 )
      {
        if ( *((_DWORD *)v13 - 1) != -1106481425 )
          __break(0x8228u);
        result = v13();
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x89u,
               8u,
               "%s: invalid instance",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "cdp_dump_flow_pool_info");
  }
  v14 = *(_DWORD *)(a1 + 2708) + 1;
  ++*(_DWORD *)(a1 + 2704);
  *(_DWORD *)(a1 + 2708) = v14;
  if ( v14 >= 5 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Detected data stall due to continuous TX timeouts",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_softap_tx_timeout");
    *(_DWORD *)(a1 + 2708) = 0;
    result = dp_is_data_stall_event_enabled(0x20000);
    if ( (result & 1) != 0 )
    {
      if ( context && *(_QWORD *)context )
      {
        v23 = *(_QWORD *)(*(_QWORD *)context + 64LL);
        if ( v23 )
        {
          v24 = *(_DWORD **)(v23 + 88);
          if ( v24 )
          {
            if ( *(v24 - 1) != -889045584 )
              __break(0x8228u);
            return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, __int64))v24)(
                     context,
                     1,
                     257,
                     0,
                     255,
                     2);
          }
        }
      }
      else
      {
        return qdf_trace_msg(
                 0x45u,
                 1u,
                 "%s invalid instance",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "cdp_post_data_stall_event");
      }
    }
  }
  return result;
}
