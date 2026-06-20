__int64 __fastcall wlan_hdd_tsf_deinit(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v2 = result;
    if ( (unsigned int)qdf_event_destroy((__int64)tsf_sync_get_completion_evt, a2) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to destroy tsf_sync_get_completion_evt",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "wlan_hdd_tsf_deinit");
    if ( *(_DWORD *)(v2 + 3232) )
    {
      v11 = *(_QWORD *)v2;
      v12 = 0;
      result = ucfg_fwol_get_tsf_ptp_options(v11, &v12);
      *(_DWORD *)(v2 + 3232) = 0;
      *(_DWORD *)(v2 + 3236) = 0;
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: ready flag not set",
                 v3,
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 "wlan_hdd_tsf_deinit");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
