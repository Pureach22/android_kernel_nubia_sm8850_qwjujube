__int64 __fastcall util_scan_entry_renew_timestamp(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  *(_QWORD *)(a2 + 88) = qdf_mc_timer_get_system_time();
  *(_QWORD *)(a2 + 1296) = ktime_get_with_offset(1);
  result = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
  if ( result )
  {
    v13 = *(__int64 (__fastcall **)(__int64, __int64))(result + 1792);
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != 1826473788 )
        __break(0x8228u);
      return v13(a1, a2);
    }
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_psoc_get_scan_obj_fl",
      "util_scan_entry_renew_timestamp",
      4351);
    return qdf_trace_msg(
             0x15u,
             2u,
             "%s: scan_obj is NULL",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "util_scan_entry_renew_timestamp");
  }
  return result;
}
