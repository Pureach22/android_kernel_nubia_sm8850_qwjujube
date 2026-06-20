__int64 __fastcall target_if_vdev_mgr_delete_send(
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
  __int64 v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x22
  __int64 v13; // x20
  unsigned int v14; // w19
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v18; // x0
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w22
  __int64 result; // x0
  const char *v39; // x2
  const char *v40; // x2
  const char *v41; // x2
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _DWORD v58[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v59; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v60)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v61)(); // [xsp+20h] [xbp-20h]
  __int64 v62; // [xsp+28h] [xbp-18h]
  __int64 v63; // [xsp+30h] [xbp-10h]
  __int64 v64; // [xsp+38h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    v39 = "%s: Invalid input";
LABEL_18:
    qdf_trace_msg(0x68u, 2u, v39, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_delete_send");
LABEL_19:
    result = 4;
    goto LABEL_20;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v40 = "%s: PDEV is NULL";
    goto LABEL_17;
  }
  v11 = *(__int64 **)(v10 + 1232);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v40 = "%s: wmi_handle is null";
LABEL_17:
    qdf_trace_msg(0x68u, 2u, v40, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v39 = "%s: Failed to get WMI handle!";
    goto LABEL_18;
  }
  v13 = *(_QWORD *)(v10 + 80);
  v14 = *(unsigned __int8 *)(a1 + 104);
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 2136)) == 0 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_22;
  }
  v16 = *(_DWORD **)(v15 + 1136);
  if ( !v16 )
  {
LABEL_22:
    v41 = "%s: VDEV %d: No Rx Ops";
LABEL_23:
    qdf_trace_msg(0x68u, 2u, v41, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_delete_send", v14);
    goto LABEL_19;
  }
  if ( *(v16 - 1) != -672477040 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD))v16)(v13, v14);
  if ( !v18 )
  {
    v41 = "%s: VDEV %d: No vdev rsp timer";
    goto LABEL_23;
  }
  v19 = v18;
  *(_DWORD *)(v18 + 72) = 8000;
  target_if_vdev_mgr_rsp_timer_start(v13, v18, 3u);
  v20 = target_if_wake_lock_timeout_acquire(v13, 2);
  target_if_acquire_vdev_cmd_rt_lock(v19, v20, v21, v22, v23, v24, v25, v26, v27);
  v28 = wmi_unified_vdev_delete_send(v12, *a2);
  if ( v28 )
  {
    v37 = v28;
    *(_QWORD *)(v19 + 72) = 0x900000000LL;
    target_if_release_vdev_cmd_rt_lock(v13, v14, v29, v30, v31, v32, v33, v34, v35, v36);
    target_if_vdev_mgr_rsp_timer_stop(v13, v19, 3u);
    target_if_wake_lock_timeout_release(v13, 2);
    result = v37;
  }
  else
  {
    if ( (wmi_service_enabled(v12, 110) & 1) == 0 || (*(_BYTE *)(v13 + 31) & 1) != 0 )
    {
      target_if_release_vdev_cmd_rt_lock(v13, v14, v42, v43, v44, v45, v46, v47, v48, v49);
      target_if_vdev_mgr_rsp_timer_stop(v13, v19, 3u);
      v62 = 0;
      v63 = 0;
      v58[0] = 0;
      v59 = v13;
      v58[1] = v14;
      v60 = target_if_vdev_mgr_del_rsp_post_cb;
      v61 = target_if_vdev_mgr_del_rsp_post_flush_cb;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x49u,
                           0x49u,
                           73,
                           (unsigned __int16 *)v58,
                           0x26Du,
                           (__int64)"target_if_vdev_mgr_delete_rsp_post_ctx") )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Failed to enqueue vdev delete response",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "target_if_vdev_mgr_delete_rsp_post_ctx");
    }
    result = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
