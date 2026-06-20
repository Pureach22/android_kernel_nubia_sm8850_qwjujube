__int64 __fastcall mlo_mgr_link_switch_connect_done(__int64 a1, int a2)
{
  char is_link_recfg_in_progress; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x9
  __int64 v14; // x21
  char v15; // w20
  __int64 v16; // x8
  __int64 v17; // x10
  unsigned __int64 v18; // x10
  __int64 v19; // x8
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  __int64 v30; // x9
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 assoc_link_vdev; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  is_link_recfg_in_progress = mlo_is_link_recfg_in_progress(a1);
  v13 = *(_QWORD **)(a1 + 1360);
  if ( a2 )
  {
    v14 = v13[485];
    v15 = is_link_recfg_in_progress;
    if ( v13 )
    {
      v16 = v13[278];
      if ( v16 )
      {
        v17 = v13[3];
        if ( v17 && v17 == a1 )
        {
          v18 = *(_QWORD *)(v16 + 8) & 0xFFFFFFFFFFFFFFFELL;
          *(_QWORD *)(v16 + 8) = v18;
          if ( v13[4] != a1 )
            goto LABEL_15;
          goto LABEL_14;
        }
        v30 = v13[4];
        if ( v30 && v30 == a1 )
        {
          v18 = *(_QWORD *)(v16 + 8);
LABEL_14:
          *(_QWORD *)(v16 + 8) = v18 & 0xFFFFFFFFFFFFFFFDLL;
        }
      }
    }
LABEL_15:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV %d link switch connect failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlo_mgr_link_switch_connect_done",
      *(unsigned __int8 *)(v14 + 144));
    result = mlo_mgr_remove_link_switch_cmd(a1);
    if ( (v15 & 1) == 0 )
    {
      assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(a1, v31, v32, v33, v34, v35, v36, v37, v38);
      if ( assoc_link_vdev )
        return wlan_cm_roam_state_change(
                 *(_QWORD *)(assoc_link_vdev + 216),
                 *(unsigned __int8 *)(assoc_link_vdev + 168),
                 2u,
                 1u);
      else
        return qdf_trace_msg(
                 0x8Fu,
                 2u,
                 "%s: VDEV(%d) assoc vdev not found",
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 "mlo_mgr_link_switch_connect_done",
                 *(unsigned __int8 *)(v14 + 144));
    }
    return result;
  }
  qdf_mutex_acquire((__int64)(v13 + 207));
  v19 = *(_QWORD *)(*(_QWORD *)(a1 + 1360) + 3880LL);
  v20 = *(_DWORD *)(v19 + 164);
  *(_DWORD *)(v19 + 164) = 5;
  qdf_mutex_release(*(_QWORD *)(a1 + 1360) + 1656LL);
  if ( v20 != 4 )
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Current link switch state %d changed",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "mlo_mgr_link_switch_connect_success_trans_state",
      v20);
  return mlo_mgr_remove_link_switch_cmd(a1);
}
