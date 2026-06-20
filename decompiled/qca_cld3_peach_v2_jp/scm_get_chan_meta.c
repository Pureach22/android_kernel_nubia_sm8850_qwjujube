__int64 __fastcall scm_get_chan_meta(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x9

  result = 0;
  if ( a1 && a2 )
  {
    if ( !wlan_reg_is_6ghz_chan_freq(a2) )
      return 0;
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_psoc_get_scan_obj_fl",
        "scm_get_rnr_channel_db",
        68);
      return 0;
    }
    v14 = comp_private_obj + 21032;
    if ( comp_private_obj == -21032 )
      return 0;
    v15 = 0;
    while ( *(_DWORD *)(v14 + v15) != a2 )
    {
      v15 += 48;
      if ( v15 == 2880 )
        return 0;
    }
    return v14 + v15;
  }
  return result;
}
