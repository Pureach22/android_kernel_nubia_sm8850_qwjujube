__int64 __fastcall wlan_dnw_timer_callback(
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
  __int64 v10; // x0
  const char *v11; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  const char *v22; // x6
  __int64 v23; // x8
  int v24; // w9
  unsigned __int64 time_of_the_day_ms; // x0
  __int64 v26; // x8
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  if ( !a1 || (v10 = *(_QWORD *)a1) == 0 )
  {
    v11 = "%s: NULL pdev or info";
    return qdf_trace_msg(0x98u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dnw_timer_callback");
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(v10, 0x60u, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v11 = "%s: pdev ref fail";
    return qdf_trace_msg(0x98u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dnw_timer_callback");
  }
  if ( *(_BYTE *)(a1 + 10) == 1 )
  {
    qdf_mc_timer_destroy(a1 + 32);
    *(_BYTE *)(a1 + 10) = 0;
  }
  qdf_trace_msg(
    0x98u,
    8u,
    "%s: Update bw to %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_dnw_timer_callback",
    *(unsigned int *)(a1 + 16));
  v21 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v21 > 3 )
    v22 = "UNKNOWN";
  else
    v22 = off_B2D690[v21];
  qdf_trace_msg(
    0x98u,
    8u,
    "%s: old %d new %d, %s->%s",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_dnw_set_state",
    v21,
    3,
    v22,
    "DNW_STATE_END");
  v23 = *(_QWORD *)(a1 + 12);
  v24 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 28) = 3;
  *(_QWORD *)(a1 + 200) = v23;
  *(_DWORD *)(a1 + 208) = v24;
  time_of_the_day_ms = qdf_get_time_of_the_day_ms();
  v26 = *(_QWORD *)a1;
  *(_QWORD *)(a1 + 216) = time_of_the_day_ms;
  wlan_objmgr_pdev_iterate_obj_list(
    v26,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))dnw_find_vdev_handler,
    a1,
    0,
    0x60u);
  return wlan_objmgr_pdev_release_ref(*(_QWORD *)a1, 0x60u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
}
