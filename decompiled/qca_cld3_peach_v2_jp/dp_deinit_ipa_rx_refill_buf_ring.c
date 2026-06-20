__int64 __fastcall dp_deinit_ipa_rx_refill_buf_ring(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x1
  _DWORD *v16; // x8

  result = wlan_cfg_is_ipa_enabled(a1[5]);
  if ( (result & 1) != 0 )
  {
    v15 = a1[2311];
    if ( v15 )
    {
      v16 = (_DWORD *)a1[213];
      if ( v16 )
      {
        if ( *(v16 - 1) != -1607343988 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD *, __int64, _QWORD))v16)(a1, a1 + 2311, 14, 0);
        v15 = a1[2311];
      }
      result = hal_srng_cleanup(a1[141], v15, 0, v3, v4, v5, v6);
      a1[2311] = 0;
    }
    else
    {
      return qdf_trace_msg(
               0x7Cu,
               2u,
               "%s: %pK: Ring type: %d, num:%d not setup",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dp_srng_deinit",
               a1,
               14,
               0);
    }
  }
  return result;
}
