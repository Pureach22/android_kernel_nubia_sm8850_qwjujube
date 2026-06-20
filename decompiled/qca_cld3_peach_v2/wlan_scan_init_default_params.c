__int64 __fastcall wlan_scan_init_default_params(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  if ( a1 && a2 )
  {
    v12 = *(_QWORD *)(a1 + 216);
    if ( v12 && (v13 = *(_QWORD *)(v12 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 3u);
      if ( comp_private_obj )
      {
        v23 = comp_private_obj;
        qdf_mem_set(a2, 0x8F0u, 0);
        *a2 = a1;
        v25 = *(unsigned __int8 *)(a1 + 168);
        *((_DWORD *)a2 + 7) = 0;
        *((_DWORD *)a2 + 4) = v25;
        *((_DWORD *)a2 + 6) = *(_DWORD *)(v23 + 1748);
        *((_DWORD *)a2 + 9) = *(_DWORD *)(v23 + 1600);
        *((_DWORD *)a2 + 10) = *(_DWORD *)(v23 + 1608);
        *((_DWORD *)a2 + 12) = *(_DWORD *)(v23 + 1612);
        *((_DWORD *)a2 + 13) = *(_DWORD *)(v23 + 1616);
        *((_DWORD *)a2 + 14) = *(_DWORD *)(v23 + 1620);
        *((_DWORD *)a2 + 11) = *(_DWORD *)(v23 + 1632);
        *((_DWORD *)a2 + 15) = *(_DWORD *)(v23 + 1644);
        *((_DWORD *)a2 + 16) = *(_DWORD *)(v23 + 1636);
        *((_DWORD *)a2 + 17) = *(_DWORD *)(v23 + 1676);
        *((_DWORD *)a2 + 18) = *(_DWORD *)(v23 + 1680);
        *((_DWORD *)a2 + 19) = *(_DWORD *)(v23 + 1648);
        *((_DWORD *)a2 + 20) = *(_DWORD *)(v23 + 1692);
        *((_DWORD *)a2 + 21) = *(_DWORD *)(v23 + 1684);
        *((_DWORD *)a2 + 26) = *(_DWORD *)(v23 + 1688);
        *((_DWORD *)a2 + 29) = *(_DWORD *)(v23 + 1696);
        *((_DWORD *)a2 + 25) = *(_DWORD *)(v23 + 1752);
        *((_DWORD *)a2 + 23) = *(_DWORD *)(v23 + 1776);
        *((_DWORD *)a2 + 8) = *(_DWORD *)(v23 + 1780);
        *((_BYTE *)a2 + 1900) = *(_BYTE *)(v23 + 1716);
        return 0;
      }
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_psoc_get_scan_obj_fl",
        "wlan_scan_psoc_get_def_params",
        878);
    }
    else
    {
      qdf_trace_msg(0x15u, 2u, "%s: null psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_scan_psoc_get_def_params");
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: wlan_vdev_get_def_scan_params returned NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_scan_init_default_params");
    return 29;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: vdev: 0x%pK, req: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_scan_init_default_params",
      a1,
      a2);
    return 4;
  }
}
