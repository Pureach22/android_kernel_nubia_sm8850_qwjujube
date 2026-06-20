__int64 __fastcall hdd_psoc_idle_shutdown(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD *v17; // x19
  __int64 result; // x0
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x21
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_psoc_idle_shutdown", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v17 = context;
    if ( is_mode_change_psoc_idle_shutdown == 1 )
    {
      is_mode_change_psoc_idle_shutdown = 0;
      result = hdd_wlan_stop_modules(context, 1, v9, v10, v11, v12, v13, v14, v15, v16);
    }
    else
    {
      v54[0] = 0;
      qdf_trace_msg(0x33u, 8u, "%s: enter", v9, v10, v11, v12, v13, v14, v15, v16, "__hdd_psoc_idle_shutdown");
      hdd_reg_wait_for_country_change(v17);
      wlan_hdd_send_idle_shutdown_event(v17, 0);
      v19 = _osif_psoc_sync_trans_start(v17[12], v54, "__hdd_psoc_idle_shutdown");
      if ( v19 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: psoc busy, abort idle shutdown; errno:%d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "__hdd_psoc_idle_shutdown",
          v19);
        v28 = -11;
      }
      else
      {
        osif_psoc_sync_wait_for_ops(v54[0]);
        if ( (hdd_is_any_interface_open((__int64)v17, v29, v30, v31, v32, v33, v34, v35, v36) & 1) != 0 )
        {
          v45 = jiffies;
          if ( _hdd_psoc_idle_shutdown___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: all interfaces are not down, ignore idle shutdown",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "__hdd_psoc_idle_shutdown");
            _hdd_psoc_idle_shutdown___last_ticks = v45;
          }
          v28 = -11;
        }
        else
        {
          v28 = hdd_wlan_stop_modules(v17, 0, v37, v38, v39, v40, v41, v42, v43, v44);
        }
        osif_psoc_sync_trans_stop(v54[0]);
      }
      wlan_hdd_send_idle_shutdown_event(v17, 1);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v46, v47, v48, v49, v50, v51, v52, v53, "__hdd_psoc_idle_shutdown");
      result = v28;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
