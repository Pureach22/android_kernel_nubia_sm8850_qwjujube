__int64 __fastcall hdd_hostapd_open(__int64 a1)
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
  __int64 v11; // x20
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
  unsigned int v28; // w21
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  unsigned int started; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned __int64 v62; // x9
  _QWORD v63[2]; // [xsp+0h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63[0] = 0;
  result = _osif_vdev_sync_trans_start(a1, v63, "hdd_hostapd_open");
  if ( !(_DWORD)result )
  {
    v11 = *(_QWORD *)(a1 + 2712);
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v3, v4, v5, v6, v7, v8, v9, v10, "__hdd_hostapd_open", a1 + 296);
    qdf_mtrace(51, 51, 0xFu, 0xFFu, 0);
    if ( (cds_get_driver_state(v12, v13, v14, v15, v16, v17, v18, v19) & 4) != 0 )
    {
      v38 = "%s: Driver is unloading can not open the hdd";
    }
    else
    {
      if ( (cds_get_driver_state(v20, v21, v22, v23, v24, v25, v26, v27) & 8) == 0 )
      {
        v28 = _wlan_hdd_validate_context(v11, "__hdd_hostapd_open");
        if ( !v28 )
        {
          v29 = hdd_trigger_psoc_idle_restart(v11);
          if ( v29 )
          {
            v28 = v29;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to start WLAN modules return",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "__hdd_hostapd_open");
          }
          else if ( (hdd_allow_new_intf(v11, *(unsigned int *)(a1 + 2728)) & 1) != 0 )
          {
            started = hdd_start_adapter(a1 + 2688, 1);
            if ( started )
            {
              v28 = started;
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Error Initializing the AP mode: %d",
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                "__hdd_hostapd_open");
            }
            else
            {
              _X8 = (unsigned __int64 *)(a1 + 4312);
              __asm { PRFM            #0x11, [X8] }
              do
                v62 = __ldxr(_X8);
              while ( __stxr(v62 | 4, _X8) );
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: vdev %d Enabling queues",
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                "__hdd_hostapd_open",
                *(unsigned __int8 *)(*(_QWORD *)(a1 + 55512) + 8LL));
              wlan_hdd_netif_queue_control(a1 + 2688, 5, 1);
              qdf_trace_msg(0x33u, 8u, "%s: exit", v48, v49, v50, v51, v52, v53, v54, v55, "__hdd_hostapd_open");
              osif_vdev_cache_command(v63[0], 0);
              v28 = 0;
            }
          }
          else
          {
            v28 = -95;
          }
        }
        goto LABEL_10;
      }
      v38 = "%s: WLAN is currently recovering; Please try again.";
    }
    qdf_trace_msg(0x33u, 2u, v38, v20, v21, v22, v23, v24, v25, v26, v27, "__hdd_hostapd_open");
    v28 = -16;
LABEL_10:
    osif_vdev_sync_trans_stop(v63[0]);
    result = v28;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
