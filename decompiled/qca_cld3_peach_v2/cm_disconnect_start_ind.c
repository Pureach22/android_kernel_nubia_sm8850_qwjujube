__int64 __fastcall cm_disconnect_start_ind(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  __int64 v32; // x4
  const char *v33; // x2
  _QWORD v34[7]; // [xsp+8h] [xbp-38h] BYREF

  v34[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev or req is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "cm_disconnect_start_ind");
LABEL_22:
    result = 4;
    goto LABEL_23;
  }
  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 )
  {
    v32 = *a2;
    v33 = "%s: vdev_id: %d pdev not found";
LABEL_21:
    qdf_trace_msg(0x68u, 2u, v33, a3, a4, a5, a6, a7, a8, a9, a10, "cm_disconnect_start_ind", v32);
    goto LABEL_22;
  }
  v13 = *(_QWORD *)(v11 + 80);
  if ( !v13 )
  {
    v32 = *a2;
    v33 = "%s: vdev_id: %d psoc not found";
    goto LABEL_21;
  }
  ((void (__fastcall *)(__int64))mlo_sta_stop_reconfig_timer)(a1);
  if ( *((_DWORD *)a2 + 1) != 18 )
    ml_nlink_conn_change_notify(v13, *(unsigned __int8 *)(a1 + 168), 8, 0);
  if ( (((__int64 (__fastcall *)(_QWORD))cm_csr_is_ss_wait_for_key)(*a2) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Stop Wait for key timer",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cm_disconnect_start_ind");
    cm_stop_wait_for_key_timer(v13, *a2);
    cm_csr_set_ss_none(*a2);
  }
  v22 = *((_DWORD *)a2 + 1);
  if ( v22 == 18 || v22 == 5 )
  {
    wlan_p2p_cleanup_roc_by_vdev(a1, 0, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( *((_DWORD *)a2 + 1) == 5 )
      wlan_tdls_notify_sta_disconnect(*a2, 0, 1, a1);
  }
  memset(v34, 0, 48);
  qdf_mem_set(v34, 0x30u, 0);
  HIDWORD(v34[0]) = *(unsigned __int8 *)(a1 + 168);
  LOWORD(v34[0]) = 5296;
  if ( (unsigned int)scheduler_post_message_debug(
                       0x1Fu,
                       0x35u,
                       53,
                       (unsigned __int16 *)v34,
                       0x34u,
                       (__int64)"cm_abort_connect_request_timers") )
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: msg CM_ABORT_CONN_TIMER post fail",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "cm_abort_connect_request_timers");
  if ( (*((_DWORD *)a2 + 1) | 2) != 0x12 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Free copied reassoc rsp",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "cm_disconnect_start_ind");
    mlo_roam_free_copied_reassoc_rsp(a1);
  }
  wlan_t2lm_clear_all_tid_mapping(a1);
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
