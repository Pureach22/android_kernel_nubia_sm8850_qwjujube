__int64 __fastcall hdd_mon_open(__int64 *a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21
  __int64 v21; // x9
  int v22; // w8
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int started; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int64 v56; // x9
  __int64 v57; // [xsp+0h] [xbp-20h] BYREF
  __int64 v58; // [xsp+8h] [xbp-18h] BYREF
  int v59; // [xsp+10h] [xbp-10h]
  __int64 v60; // [xsp+18h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  result = _osif_vdev_sync_trans_start(a1, &v57, "hdd_mon_open");
  if ( !(_DWORD)result )
  {
    v11 = (__int64 *)a1[339];
    v59 = 0;
    v58 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v3, v4, v5, v6, v7, v8, v9, v10, "__hdd_mon_open", a1 + 37);
    if ( (a1[539] & 4) != 0 )
    {
      v32 = jiffies;
      if ( _hdd_mon_open___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Monitor interface is already up",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "__hdd_mon_open");
        v20 = 0;
        _hdd_mon_open___last_ticks = v32;
      }
      else
      {
        v20 = 0;
      }
      goto LABEL_12;
    }
    v20 = _wlan_hdd_validate_context((__int64)v11, (__int64)"__hdd_mon_open", v12, v13, v14, v15, v16, v17, v18, v19);
    if ( !v20 )
    {
      a1[2] = 0;
      *((_WORD *)a1 + 272) = 803;
      *((_DWORD *)a1 + 14) = 1500;
      *((_BYTE *)a1 + 824) = 6;
      *((_DWORD *)a1 + 278) = 1000;
      *((_WORD *)a1 + 90) = 14;
      v21 = *a1;
      *((_DWORD *)a1 + 44) = 4098;
      v22 = con_mode;
      *a1 = v21 | 0x800;
      *((_DWORD *)a1 + 260) = -1;
      *((_WORD *)a1 + 522) = -1;
      if ( v22 == 4 || (wlan_mlme_is_sta_mon_conc_supported(*v11) & 1) != 0 || ucfg_dp_is_local_pkt_capture_enabled() )
      {
        v23 = hdd_trigger_psoc_idle_restart((__int64)v11);
        if ( v23 )
        {
          v20 = v23;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to start WLAN modules return",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "__hdd_mon_open");
          goto LABEL_12;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hdd_wlan_start_modules() successful !",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "__hdd_mon_open");
        if ( (*(_QWORD *)(a1[6939] + 4416) & 1) == 0 || (policy_mgr_is_sta_mon_concurrency(*v11) & 1) != 0 )
        {
          started = hdd_start_adapter((__int64)(a1 + 336), v33, v34, v35, v36, v37, v38, v39, v40);
          if ( started )
          {
            v20 = started;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to start adapter :%d",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "__hdd_mon_open",
              *((unsigned int *)a1 + 682));
            goto LABEL_12;
          }
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_start_adapters() successful !",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "__hdd_mon_open");
        }
        ucfg_pmo_set_power_save_mode(*v11, 0);
        ucfg_pmo_set_wow_enable(*v11, 0);
        _X8 = (unsigned __int64 *)(a1 + 539);
        __asm { PRFM            #0x11, [X8] }
        do
          v56 = __ldxr(_X8);
        while ( __stxr(v56 | 4, _X8) );
      }
      v20 = hdd_set_mon_rx_cb(a1);
      if ( !v20 )
      {
        v20 = hdd_enable_monitor_mode(a1);
        if ( !v20 )
        {
          v58 = 0x400000000LL;
          ucfg_dp_bbm_apply_independent_policy(*v11, (__int64)&v58);
          ucfg_dp_set_current_throughput_level(*v11, 5);
        }
      }
    }
LABEL_12:
    osif_vdev_sync_trans_stop(v57);
    result = v20;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
