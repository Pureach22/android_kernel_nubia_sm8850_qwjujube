__int64 __fastcall hdd_cm_disconnect_complete(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v24; // x21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  bool is_any_sta_connected; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  bool v42; // w22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x2
  __int64 v52; // x0
  int v53; // w8
  __int64 v54; // x1

  context = _cds_get_context(51, (__int64)"hdd_cm_disconnect_complete", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !a3 )
  {
    v24 = (__int64)context;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Wifi disconnected: vdev id %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_cm_disconnect_complete",
      *(unsigned __int8 *)(a1 + 168));
    is_any_sta_connected = hdd_is_any_sta_connected(v24, v25, v26, v27, v28, v29, v30, v31, v32);
    if ( v24 )
    {
      v42 = is_any_sta_connected;
      if ( _cds_get_context(
             61,
             (__int64)"wlan_hdd_runtime_pm_wow_disconnect_handler",
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41) )
      {
        if ( v42
          || (hif_rtpm_restore_autosuspend_delay(), hdd_is_any_cli_connected(
                                                      v24,
                                                      v43,
                                                      v44,
                                                      v45,
                                                      v46,
                                                      v47,
                                                      v48,
                                                      v49,
                                                      v50)) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: active connections: runtime pm prevented: %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wlan_hdd_runtime_pm_wow_disconnect_handler",
            *(unsigned __int8 *)(v24 + 1224));
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Runtime allowed : %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wlan_hdd_runtime_pm_wow_disconnect_handler",
            *(unsigned __int8 *)(v24 + 1224));
          v52 = raw_spin_lock_irqsave(v24 + 1232);
          v53 = *(unsigned __int8 *)(v24 + 1224);
          v54 = v52;
          *(_QWORD *)(v24 + 1240) = v52;
          if ( v53 == 1 )
          {
            qdf_rtpm_put(4u, 1u);
            v54 = *(_QWORD *)(v24 + 1240);
            *(_BYTE *)(v24 + 1224) = 0;
          }
          raw_spin_unlock_irqrestore(v24 + 1232, v54);
        }
        return hdd_cm_disconnect_complete_post_user_update(a1, a2);
      }
      v51 = "%s: hif_ctx is NULL";
    }
    else
    {
      v51 = "%s: hdd_ctx is NULL";
    }
    qdf_trace_msg(0x33u, 2u, v51, v34, v35, v36, v37, v38, v39, v40, v41, "wlan_hdd_runtime_pm_wow_disconnect_handler");
    return hdd_cm_disconnect_complete_post_user_update(a1, a2);
  }
  if ( a3 == 1 )
    return hdd_cm_disconnect_complete_pre_user_update(a1, a2);
  hdd_cm_disconnect_complete_pre_user_update(a1, a2);
  hdd_cm_disconnect_complete_post_user_update(a1, a2);
  return 0;
}
