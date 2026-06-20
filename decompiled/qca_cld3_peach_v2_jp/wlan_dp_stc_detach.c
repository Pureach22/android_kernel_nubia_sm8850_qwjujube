__int64 __fastcall wlan_dp_stc_detach(
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
  __int64 v9; // x20
  __int64 v11; // x21
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
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7

  v9 = *(_QWORD *)(a1 + 2936);
  if ( v9 )
  {
    v11 = *(_QWORD *)(a1 + 240);
    qdf_trace_msg(0x45u, 5u, "%s: STC: detach", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_stc_detach");
    hrtimer_cancel(v9 + 160);
    qdf_periodic_work_stop_sync(v9 + 16);
    _qdf_periodic_work_destroy(v9 + 16);
    if ( *(_BYTE *)(v9 + 254) == 1 )
    {
      if ( *(_WORD *)(v9 + 252) )
        hif_rtpm_put(4, 0xAu);
      v12 = ((double (__fastcall *)(__int64))hif_rtpm_deregister)(10);
    }
    dp_context_free_mem(v11, 0x13u, *(_QWORD *)(v9 + 6424), v12, v13, v14, v15, v16, v17, v18, v19);
    dp_context_free_mem(v11, 0x12u, *(_QWORD *)(v9 + 6416), v20, v21, v22, v23, v24, v25, v26, v27);
    dp_context_free_mem(v11, 0x11u, *(_QWORD *)(v9 + 6408), v28, v29, v30, v31, v32, v33, v34, v35);
    dp_context_free_mem(v11, 0x10u, *(_QWORD *)(v9 + 6400), v36, v37, v38, v39, v40, v41, v42, v43);
    dp_context_free_mem(v11, 0xFu, v9, v44, v45, v46, v47, v48, v49, v50, v51);
    *(_QWORD *)(a1 + 2936) = 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: module not initialized, skip detach",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_dp_stc_detach");
  }
  return 0;
}
