__int64 __fastcall ucfg_scan_cancel_sync(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  int v10; // w8
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w23
  int v29; // w22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x19
  int v48; // w23
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7

  if ( !a1 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: req or vdev within req is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_scan_cancel_sync");
    return 29;
  }
  v9 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: req or vdev within req is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_scan_cancel_sync");
    _qdf_mem_free(a1);
    return 29;
  }
  v10 = *(_DWORD *)(a1 + 20);
  if ( v10 == 2 )
    goto LABEL_6;
  if ( v10 != 3 )
  {
    if ( v10 != 4 )
      return wlan_scan_cancel((__int64 *)a1, a2, a3, a4, a5, a6, a7, a8, a9);
LABEL_6:
    result = wlan_scan_cancel((__int64 *)a1, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( !(_DWORD)result )
    {
      result = wlan_get_vdev_status(v9, v12, v13, v14, v15, v16, v17, v18, v19);
      if ( (_DWORD)result )
      {
        v28 = 600;
        do
        {
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: wait for all vdev scan to get complete",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "ucfg_scan_cancel_sync");
          qdf_sleep();
          v29 = v28 - 1;
          if ( !(unsigned int)wlan_get_vdev_status(v9, v30, v31, v32, v33, v34, v35, v36, v37) )
            break;
          --v28;
        }
        while ( v28 );
LABEL_19:
        if ( v29 )
          return 0;
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: Failed to wait for scans to get complete",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "ucfg_scan_cancel_sync");
        return 15;
      }
    }
    return result;
  }
  result = wlan_scan_cancel((__int64 *)a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    v47 = *(_QWORD *)(v9 + 152);
    result = wlan_get_pdev_status(v47, v39, v40, v41, v42, v43, v44, v45, v46);
    if ( (_DWORD)result )
    {
      v48 = 600;
      do
      {
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: wait for all pdev scan to get complete",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "ucfg_scan_cancel_sync");
        qdf_sleep();
        v29 = v48 - 1;
        if ( !(unsigned int)wlan_get_pdev_status(v47, v49, v50, v51, v52, v53, v54, v55, v56) )
          break;
        --v48;
      }
      while ( v48 );
      goto LABEL_19;
    }
  }
  return result;
}
