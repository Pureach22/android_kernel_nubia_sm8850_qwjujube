__int64 __fastcall wlan_hdd_delete_mon_link(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x22
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x25
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x25
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x20
  __int64 *v60; // x19
  int v61; // w21
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 adapter; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7

  v3 = *(_QWORD *)(a1 + 24);
  result = _hdd_objmgr_get_vdev_by_user(a2, 36, "wlan_hdd_delete_mon_link");
  if ( result )
  {
    v14 = result;
    if ( _cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", v6, v7, v8, v9, v10, v11, v12, v13) )
      cds_get_conparam();
    else
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: HDD context is NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_hdd_is_session_type_monitor");
    wlan_hdd_scan_abort(a2);
    if ( (unsigned int)hdd_monitor_mode_vdev_status(a1) )
    {
      v31 = jiffies;
      if ( wlan_hdd_delete_mon_link___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: stop failed montior mode",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wlan_hdd_delete_mon_link");
        wlan_hdd_delete_mon_link___last_ticks = v31;
      }
    }
    if ( (unsigned int)qdf_event_reset(a1 + 1704) )
    {
      v40 = jiffies;
      if ( wlan_hdd_delete_mon_link___last_ticks_691 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to reinit vdev stop event",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_hdd_delete_mon_link");
        wlan_hdd_delete_mon_link___last_ticks_691 = v40;
      }
    }
    sme_delete_mon_session(*(_QWORD *)(v3 + 16), a2[8]);
    v41 = qdf_wait_for_event_completion(a1 + 1704, 0x2328u);
    if ( v41 )
    {
      v50 = jiffies;
      if ( wlan_hdd_delete_mon_link___last_ticks_693 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: monitor vdev stop event time out vdev id: %d status %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "wlan_hdd_delete_mon_link",
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL),
          v41);
        wlan_hdd_delete_mon_link___last_ticks_693 = v50;
      }
    }
    _hdd_objmgr_put_vdev_by_user(v14, 36, "wlan_hdd_delete_mon_link");
    hdd_vdev_destroy((__int64)a2, v51, v52, v53, v54, v55, v56, v57, v58);
    v59 = *(_QWORD *)a2;
    v60 = *(__int64 **)(*(_QWORD *)a2 + 24LL);
    v61 = *(unsigned __int8 *)(v59 + 40);
    if ( _cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", v62, v63, v64, v65, v66, v67, v68, v69) )
    {
      result = cds_get_conparam();
      if ( v61 == 6 && (_DWORD)result != 4 )
      {
        if ( (wlan_mlme_is_sta_mon_conc_supported(*v60) & 1) != 0
          || (result = ucfg_dp_is_local_pkt_capture_enabled(), (result & 1) != 0) )
        {
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Release wakelock for STA + monitor mode!",
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            "hdd_monitor_mode_release_wakelock");
          os_if_dp_local_pkt_capture_stop(*v60, *(unsigned int *)(v59 + 40));
          qdf_runtime_pm_allow_suspend(v60 + 211);
          if ( ucfg_dp_is_local_pkt_capture_enabled() )
          {
            ucfg_fwol_configure_global_params(*v60, v60[1]);
            if ( (unsigned int)wma_enable_disable_imps(*(unsigned __int8 *)(v60[1] + 40), 1) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: IMPS feature enable failed",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "hdd_lpc_enable_powersave");
            adapter = hdd_get_adapter((__int64)v60, 0);
            if ( adapter )
            {
              wlan_hdd_lpc_set_bmps(adapter, 1, 0);
              *((_BYTE *)v60 + 8280) = 0;
            }
            else
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: STA adapter does not exist",
                v95,
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                "hdd_lpc_enable_powersave");
            }
          }
          return qdf_wake_lock_release((__int64)(v60 + 411), 0x16u);
        }
      }
    }
    else
    {
      return qdf_trace_msg(
               0x38u,
               2u,
               "%s: HDD context is NULL",
               v70,
               v71,
               v72,
               v73,
               v74,
               v75,
               v76,
               v77,
               "wlan_hdd_is_session_type_monitor");
    }
  }
  return result;
}
