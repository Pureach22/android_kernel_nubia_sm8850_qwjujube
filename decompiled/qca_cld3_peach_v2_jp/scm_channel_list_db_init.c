__int64 __fastcall scm_channel_list_db_init(__int64 a1)
{
  unsigned int v2; // w19
  unsigned int v3; // w20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w11

  v2 = (unsigned __int16)wlan_reg_min_6ghz_chan_freq();
  v3 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
  qdf_trace_msg(
    0x15u,
    4u,
    "%s: min_freq %d max_freq %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "scm_channel_list_db_init",
    v2,
    v3);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_psoc_get_scan_obj_fl",
      "scm_get_rnr_channel_db",
      68);
    return 4;
  }
  if ( comp_private_obj == -21032 )
    return 4;
  v21 = 0;
  v22 = comp_private_obj + 21076;
  do
  {
    v23 = v2 + v21;
    if ( v2 + (unsigned int)v21 >= v2 && v23 <= v3 )
      *(_DWORD *)(v22 - 44) = v23;
    v21 += 20;
    *(_QWORD *)(v22 - 20) = v22 - 20;
    *(_QWORD *)(v22 - 12) = v22 - 20;
    *(_QWORD *)(v22 - 4) = 0xF00000000LL;
    v22 += 48;
  }
  while ( v21 != 1200 );
  qdf_mutex_create(comp_private_obj + 23920);
  return 0;
}
