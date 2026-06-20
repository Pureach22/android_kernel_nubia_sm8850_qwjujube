__int64 __fastcall ucfg_scan_update_user_config(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x12
  __int64 v25; // x10
  __int64 v26; // x11
  __int64 v27; // x12
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x12
  const char *v31; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      v20 = comp_private_obj;
      *(_QWORD *)(v20 + 18632) = *(_QWORD *)a2;
      v22 = *(_QWORD *)(a2 + 24);
      v23 = *(_QWORD *)(a2 + 8);
      v24 = *(_QWORD *)(a2 + 16);
      *(_QWORD *)(v20 + 18664) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(v20 + 18656) = v22;
      *(_QWORD *)(v20 + 18648) = v24;
      *(_QWORD *)(v20 + 18640) = v23;
      v25 = *(_QWORD *)(a2 + 56);
      v26 = *(_QWORD *)(a2 + 40);
      v27 = *(_QWORD *)(a2 + 48);
      *(_QWORD *)(v20 + 18696) = *(_QWORD *)(a2 + 64);
      *(_QWORD *)(v20 + 18688) = v25;
      *(_QWORD *)(v20 + 18680) = v27;
      *(_QWORD *)(v20 + 18672) = v26;
      v28 = *(_QWORD *)(a2 + 88);
      v29 = *(_QWORD *)(a2 + 72);
      v30 = *(_QWORD *)(a2 + 80);
      *(_QWORD *)(v20 + 18728) = *(_QWORD *)(a2 + 96);
      *(_QWORD *)(v20 + 18720) = v28;
      *(_QWORD *)(v20 + 18712) = v30;
      *(_QWORD *)(v20 + 18704) = v29;
      *(_DWORD *)(v20 + 1640) = *(_DWORD *)(a2 + 104);
      return 0;
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_update_user_config",
      1220);
    v31 = "%s: Failed to get scan object";
  }
  else
  {
    v31 = "%s: null psoc";
  }
  qdf_trace_msg(0x15u, 2u, v31, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_scan_update_user_config");
  return 16;
}
