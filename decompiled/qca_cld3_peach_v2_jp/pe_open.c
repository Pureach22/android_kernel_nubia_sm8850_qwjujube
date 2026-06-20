__int64 __fastcall pe_open(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  int v11; // w9
  unsigned int v13; // w8
  char v14; // w10
  __int64 v15; // x0
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  __int64 v26; // x0
  double v27; // d0
  __int64 v28; // x0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x0
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x20
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 (__fastcall *v72)(unsigned int, unsigned __int8 *, double, double, double, double, double, double, double, double); // [xsp+8h] [xbp-C8h] BYREF
  __int64 (__fastcall *v73)(char, double, double, double, double, double, double, double, double); // [xsp+10h] [xbp-C0h]
  __int64 (__fastcall *v74)(); // [xsp+18h] [xbp-B8h]
  __int64 (__fastcall *v75)(); // [xsp+20h] [xbp-B0h]
  __int64 v76; // [xsp+28h] [xbp-A8h]
  __int64 v77; // [xsp+30h] [xbp-A0h]
  __int64 v78; // [xsp+38h] [xbp-98h]
  __int64 v79; // [xsp+40h] [xbp-90h]
  __int64 v80; // [xsp+48h] [xbp-88h]
  __int64 v81; // [xsp+50h] [xbp-80h]
  __int64 v82; // [xsp+58h] [xbp-78h]
  __int64 (__fastcall *v83)(); // [xsp+60h] [xbp-70h]
  __int64 v84; // [xsp+68h] [xbp-68h]
  __int64 (__fastcall *v85)(); // [xsp+70h] [xbp-60h]
  __int64 (__fastcall *v86)(); // [xsp+78h] [xbp-58h]
  __int64 v87; // [xsp+80h] [xbp-50h]
  __int64 v88; // [xsp+88h] [xbp-48h]
  __int64 v89; // [xsp+90h] [xbp-40h]
  __int64 v90; // [xsp+98h] [xbp-38h]
  __int64 v91; // [xsp+A0h] [xbp-30h]
  __int64 v92; // [xsp+A8h] [xbp-28h]
  __int64 v93; // [xsp+B0h] [xbp-20h]
  __int64 v94; // [xsp+B8h] [xbp-18h]
  __int64 v95; // [xsp+C0h] [xbp-10h]
  __int64 v96; // [xsp+C8h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((_DWORD *)a2 + 2) != 1 )
  {
    v11 = a2[1];
    *(_WORD *)(a1 + 3992) = v11;
    v13 = *a2;
    *(_DWORD *)(a1 + 12744) = 0;
    *(_QWORD *)(a1 + 12752) = 0;
    *(_WORD *)(a1 + 3990) = v13;
    if ( v13 >= 0x20 )
      v14 = 32;
    else
      v14 = v13;
    *(_BYTE *)(a1 + 12272) = v14;
    if ( !v11 || !v13 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: max number of Bssid or Stations cannot be zero!",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "pe_open");
      result = 16;
      goto LABEL_16;
    }
    v15 = _qdf_mem_malloc(264LL * v13 + 264, "pe_open", 1041);
    *(_QWORD *)(a1 + 1336) = v15;
    if ( !v15 )
    {
      result = 2;
      goto LABEL_16;
    }
    v16 = _qdf_mem_malloc(10792LL * *(unsigned __int16 *)(a1 + 3992), "pe_open", 1048);
    *(_QWORD *)(a1 + 12264) = v16;
    if ( v16 )
    {
      if ( !(unsigned int)lim_initialize(a1) )
      {
        lim_trace_init(a1);
        ((void (__fastcall *)(__int64, __int64 (__fastcall *)()))qdf_register_debug_callback)(53, lim_state_info_dump);
        v26 = *(_QWORD *)(a1 + 21552);
        v82 = 0;
        v83 = lim_add_ndi_peer_converged;
        v94 = 0;
        v95 = 0;
        v92 = 0;
        v93 = 0;
        v90 = 0;
        v91 = 0;
        v88 = 0;
        v89 = 0;
        v87 = 0;
        v84 = 0;
        v80 = 0;
        v81 = 0;
        v78 = 0;
        v79 = 0;
        v76 = 0;
        v77 = 0;
        v74 = nullptr;
        v75 = nullptr;
        v85 = lim_ndp_delete_peers_converged;
        v86 = lim_ndp_delete_peers_by_addr_converged;
        v72 = nullptr;
        v73 = nullptr;
        v27 = ucfg_nan_register_lim_callbacks(v26, &v72);
        v28 = *(_QWORD *)(a1 + 21552);
        v72 = is_mgmt_protected;
        v73 = (__int64 (__fastcall *)(char, double, double, double, double, double, double, double, double))lim_process_ap_assist_dfs_group_p2p_bmiss_notify;
        v74 = lim_process_p2p_group_chan_switch_req;
        v75 = lim_process_ap_assist_dfs_group_p2p_fw_monitor_update;
        ucfg_p2p_register_callbacks(v28, (__int64 *)&v72, v27, v29, v30, v31, v32, v33, v34, v35);
        v36 = *(_QWORD *)(a1 + 21552);
        v72 = (__int64 (__fastcall *)(unsigned int, unsigned __int8 *, double, double, double, double, double, double, double, double))lim_delete_all_tdls_peers;
        wlan_tdls_register_lim_callbacks(v36, &v72);
        v37 = wlan_scan_register_mbssid_cb(*(_QWORD *)(a1 + 21552), (__int64)lim_handle_frame_genby_mbssid);
        if ( v37 )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: failed with status code %08d [x%08x]",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "lim_register_scan_mbssid_callback",
            v37,
            v37);
        v46 = ucfg_scan_register_bcn_cb(*(_QWORD *)(a1 + 21552), (__int64)lim_handle_sap_beacon, 1u);
        if ( v46 )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: failed with status code %08d [x%08x]",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "lim_register_sap_bcn_callback",
            v46,
            v46);
        wlan_reg_register_ctry_change_callback(*(_QWORD *)(a1 + 21552), (__int64)lim_update_tx_pwr_on_ctry_change_cb);
        wlan_reg_register_c2c_detect_callback(*(_QWORD *)(a1 + 21552), (__int64)lim_update_tpc_bcn_on_c2c_detect_cb);
        wlan_reg_register_is_chan_connected_callback(*(_QWORD *)(a1 + 21552), (__int64)lim_get_connected_chan_for_mode);
        v55 = *(_QWORD *)(a1 + 21552);
        v72 = nullptr;
        v73 = nullptr;
        qdf_mem_set(&v72, 0x10u, 0);
        v72 = (__int64 (__fastcall *)(unsigned int, unsigned __int8 *, double, double, double, double, double, double, double, double))lim_send_conc_params_update;
        v73 = lim_check_ap_assist_dfs_p2p_group;
        if ( (unsigned int)policy_mgr_register_conc_cb(v55, &v72) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: failed to register policy manager callbacks",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "lim_register_policy_mgr_callback");
        if ( (unsigned int)cds_shutdown_notifier_register((__int64)pe_shutdown_notifier_cb, a1) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Shutdown notifier register failed",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "pe_open");
        qword_14C98 = a1;
        qdf_hang_event_register_notifier(&pe_hang_event_notifier);
        goto LABEL_2;
      }
      qdf_trace_msg(0x35u, 2u, "%s: lim_initialize failed!", v17, v18, v19, v20, v21, v22, v23, v24, "pe_open");
      _qdf_mem_free(*(_QWORD *)(a1 + 12264));
      v25 = 16;
      *(_QWORD *)(a1 + 12264) = 0;
    }
    else
    {
      v25 = 2;
    }
    _qdf_mem_free(*(_QWORD *)(a1 + 1336));
    *(_QWORD *)(a1 + 1336) = 0;
    result = v25;
    goto LABEL_16;
  }
LABEL_2:
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
