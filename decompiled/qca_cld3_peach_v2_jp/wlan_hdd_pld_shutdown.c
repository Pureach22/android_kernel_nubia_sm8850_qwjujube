__int64 __fastcall wlan_hdd_pld_shutdown(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD *context; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _QWORD *v52; // x0
  __int64 v53; // x19
  __int64 v54; // x0
  __int64 v55; // x0
  _QWORD v56[2]; // [xsp+0h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_pld_shutdown");
  v56[0] = 0;
  if ( (qdf_is_driver_unloading() & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: driver is unloading, avoid SSR",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_soc_recovery_shutdown",
      v56[0]);
    goto LABEL_4;
  }
  if ( !(unsigned int)_osif_psoc_sync_trans_start_wait(a1, v56, "hdd_soc_recovery_shutdown") )
  {
    ucfg_dp_wait_complete_tasks();
    osif_psoc_sync_wait_for_ops(v56[0]);
    cds_get_driver_state(v27, v28, v29, v30, v31, v32, v33, v34);
    context = _cds_get_context(51, (__int64)"__hdd_soc_recovery_shutdown", v35, v36, v37, v38, v39, v40, v41, v42);
    if ( context )
    {
      if ( is_recovery_cleanup_done )
      {
        is_recovery_cleanup_done = 0;
        if ( (hdd_wait_for_debugfs_threads_completion(context) & 1) != 0 )
        {
LABEL_9:
          v52 = _cds_get_context(61, (__int64)"__hdd_soc_recovery_shutdown", v44, v45, v46, v47, v48, v49, v50, v51);
          if ( v52 )
          {
            v53 = (__int64)v52;
            hif_mask_interrupt_call((__int64)v52);
            if ( (unsigned int)cds_get_conparam() != 8 )
            {
              v54 = hif_disable_isr(v53);
              hdd_wlan_shutdown(v54);
            }
          }
          goto LABEL_4;
        }
      }
      else
      {
        v55 = hdd_soc_recovery_cleanup();
        if ( (hdd_wait_for_debugfs_threads_completion(v55) & 1) != 0 )
          goto LABEL_9;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Debugfs threads are still pending, attempting SSR anyway",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "__hdd_soc_recovery_shutdown",
        v56[0]);
      goto LABEL_9;
    }
  }
LABEL_4:
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v18, v19, v20, v21, v22, v23, v24, v25, "wlan_hdd_pld_shutdown", v56[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
