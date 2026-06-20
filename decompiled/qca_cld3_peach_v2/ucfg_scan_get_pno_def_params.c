__int64 __fastcall ucfg_scan_get_pno_def_params(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x22
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  if ( !a1 || !a2 )
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
      "ucfg_scan_get_pno_def_params",
      a1,
      a2);
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 3u);
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
      "wlan_pdev_get_scan_obj",
      764);
    qdf_trace_msg(0x15u, 2u, "%s: scan is NULL", v42, v43, v44, v45, v46, v47, v48, v49, "ucfg_scan_get_pno_def_params");
    return 4;
  }
  v21 = *(_QWORD *)(a1 + 216);
  if ( v21 && (v22 = *(_QWORD *)(v21 + 80)) != 0 )
  {
    v23 = comp_private_obj;
    v24 = wlan_objmgr_psoc_get_comp_private_obj(v22, 3u);
    if ( v24 )
    {
      *(_DWORD *)(a2 + 40) = *(_DWORD *)(v24 + 1600);
      *(_DWORD *)(a2 + 44) = *(_DWORD *)(v24 + 1632);
      *(_BYTE *)(a2 + 20548) = *(_BYTE *)(v24 + 1716);
      wlan_scan_update_pno_dwell_time(a1, a2, v24 + 1600);
      *(_DWORD *)(a2 + 60) = *(_DWORD *)(v23 + 18348);
      *(_DWORD *)(a2 + 48) = *(unsigned __int8 *)(v23 + 18345);
      *(_DWORD *)(a2 + 52) = *(unsigned __int8 *)(v23 + 18346);
      *(_DWORD *)(a2 + 56) = *(unsigned __int8 *)(v23 + 18347);
      *(_DWORD *)(a2 + 64) = *(_DWORD *)(v23 + 18352);
      *(_BYTE *)(a2 + 20672) = *(_BYTE *)(a1 + 168);
      qdf_mem_copy((void *)(a2 + 20672), (const void *)(v23 + 18608), 0x10u);
      return 0;
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_get_def_params",
      878);
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_scan_psoc_get_def_params");
  }
  qdf_trace_msg(
    0x15u,
    2u,
    "%s: wlan_vdev_get_def_scan_params returned NULL",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "ucfg_scan_get_pno_def_params");
  return 29;
}
