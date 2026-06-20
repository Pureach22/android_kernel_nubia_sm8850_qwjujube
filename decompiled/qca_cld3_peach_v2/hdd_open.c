__int64 __fastcall hdd_open(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w22
  __int64 v12; // x21
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  unsigned int v50; // w0
  unsigned int started; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int64 v74; // x9
  _QWORD v75[2]; // [xsp+0h] [xbp-10h] BYREF

  v75[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75[0] = 0;
  v2 = _osif_vdev_sync_trans_start(a1, v75, "hdd_open");
  if ( !v2 )
  {
    v12 = *(_QWORD *)(a1 + 2712);
    v13 = *(_QWORD *)(a1 + 55520);
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v3, v4, v5, v6, v7, v8, v9, v10, "__hdd_open", a1 + 296);
    qdf_mtrace(51, 51, 0, *(_BYTE *)(v13 + 8), *(_DWORD *)(a1 + 2728));
    if ( (cds_get_driver_state(v14, v15, v16, v17, v18, v19, v20, v21) & 4) != 0 )
    {
      v38 = "%s: Driver is unloading can not open the hdd";
    }
    else
    {
      if ( (cds_get_driver_state(v22, v23, v24, v25, v26, v27, v28, v29) & 8) == 0 )
      {
        if ( (cds_get_driver_state(v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0 )
        {
          v40 = _wlan_hdd_validate_context(v12, (__int64)"__hdd_open", v30, v31, v32, v33, v34, v35, v36, v37);
          if ( v40 )
          {
            v11 = v40;
            v49 = "%s: Can't start WLAN module, WiFi Disabled";
          }
          else
          {
            v50 = hdd_trigger_psoc_idle_restart(v12);
            if ( !v50 )
            {
              if ( (*(_QWORD *)(v13 + 5968) & 1) != 0
                || (started = hdd_start_adapter(a1 + 2688, v41, v42, v43, v44, v45, v46, v47, v48)) == 0 )
              {
                _X8 = (unsigned __int64 *)(a1 + 4312);
                __asm { PRFM            #0x11, [X8] }
                do
                  v74 = __ldxr(_X8);
                while ( __stxr(v74 | 4, _X8) );
                if ( hdd_cm_is_vdev_associated((_DWORD *)v13) )
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: vdev %d Enabling queues",
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    "__hdd_open",
                    *(unsigned __int8 *)(v13 + 8));
                  wlan_hdd_netif_queue_control(a1 + 2688, 2, 1);
                }
                if ( *(_DWORD *)(a1 + 2728) == 11 )
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: vdev %d Enabling queues",
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    "__hdd_open",
                    *(unsigned __int8 *)(v13 + 8));
                  wlan_hdd_netif_queue_control(a1 + 2688, 5, 1);
                }
                hdd_populate_wifi_pos_cfg(v12);
                hdd_lpass_notify_start(v13);
                osif_vdev_cache_command(v75[0], 0);
                v11 = 0;
              }
              else
              {
                v11 = started;
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Vdev %d Failed to start adapter :%d",
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  "__hdd_open",
                  *(unsigned __int8 *)(v13 + 8),
                  *(unsigned int *)(a1 + 2728));
              }
              goto LABEL_10;
            }
            v11 = v50;
            v49 = "%s: Failed to start WLAN modules return";
          }
          qdf_trace_msg(0x33u, 2u, v49, v41, v42, v43, v44, v45, v46, v47, v48, "__hdd_open");
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to start the wlan driver!!",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "__hdd_open");
          v11 = -5;
        }
LABEL_10:
        osif_vdev_sync_trans_stop(v75[0]);
        goto LABEL_11;
      }
      v38 = "%s: WLAN is currently recovering; Please try again.";
    }
    qdf_trace_msg(0x33u, 2u, v38, v22, v23, v24, v25, v26, v27, v28, v29, "__hdd_open");
    v11 = -16;
    goto LABEL_10;
  }
  v11 = v2;
  qdf_trace_msg(0x33u, 2u, "%s: VDEV SYNC TRANS start fails %d", v3, v4, v5, v6, v7, v8, v9, v10, "hdd_open", v2);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v11;
}
