__int64 __fastcall cm_fw_roam_complete(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned int v13; // w20
  __int64 v14; // x21
  bool is_disable_for_pwrmode; // w8
  __int64 v16; // x0
  unsigned int updated; // w24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  unsigned int v28; // w25
  __int64 v29; // x26
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x24
  double inited; // d0
  unsigned int *v41; // x8
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w2
  unsigned int v74; // w3
  char acs_mode_for_vdev; // w0
  unsigned __int8 rso_pending_disable_req_bitmap; // w0
  unsigned __int8 v77; // w22
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7

  v10 = *(_QWORD *)(*a1 + 216);
  if ( v10 )
  {
    v13 = *(unsigned __int8 *)(*a1 + 168);
    v14 = *(_QWORD *)(v10 + 80);
    is_disable_for_pwrmode = wlan_reg_is_disable_for_pwrmode(
                               *(_QWORD *)(*a1 + 216),
                               *(_DWORD *)(a2 + 64),
                               0,
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10);
    v16 = *a1;
    if ( is_disable_for_pwrmode )
    {
      mlo_disconnect(v16, 10, 65527, 0);
      return 16;
    }
    else
    {
      if ( (*(_BYTE *)(v16 + 60) & 2) != 0 && (policy_mgr_is_hw_dbs_capable(v14) & 1) == 0 )
        goto LABEL_20;
      updated = policy_mgr_update_connection_info(v14, v13);
      if ( updated == 28 )
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))policy_mgr_incr_active_session)(v14, 0, v13, 1);
      v27 = *(unsigned __int8 *)(a2 + 2497);
      if ( *(_BYTE *)(a2 + 2497) )
      {
        while ( 1 )
        {
          if ( *(_DWORD *)(a2 + 2500) == v13 && (*(_DWORD *)(a2 + 2536) & 1) != 0 )
          {
            v28 = updated;
            v29 = a2 + 2500;
            goto LABEL_25;
          }
          if ( v27 == 1 )
            goto LABEL_29;
          if ( *(_DWORD *)(a2 + 2552) == v13 && (*(_DWORD *)(a2 + 2588) & 1) != 0 )
          {
            v28 = updated;
            v29 = a2 + 2552;
            goto LABEL_25;
          }
          if ( v27 == 2 )
            goto LABEL_29;
          if ( *(_DWORD *)(a2 + 2604) == v13 && (*(_DWORD *)(a2 + 2640) & 1) != 0 )
            break;
          if ( v27 != 3 )
          {
            __break(0x5512u);
LABEL_20:
            policy_mgr_move_vdev_from_connection_to_disabled_tbl(v14, v13);
            updated = 0;
            v27 = *(unsigned __int8 *)(a2 + 2497);
            if ( *(_BYTE *)(a2 + 2497) )
              continue;
          }
          goto LABEL_29;
        }
        v28 = updated;
        v29 = a2 + 2604;
LABEL_25:
        qdf_trace_msg(
          0x68u,
          4u,
          "%s: Vdev %d: link id %d flags 0x%x, indicate link disable",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "cm_get_and_disable_link_from_roam_ind",
          v13,
          *(unsigned int *)(v29 + 4));
        policy_mgr_move_vdev_from_connection_to_disabled_tbl(v14, v13);
        v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v14, v13, 1);
        if ( v30 )
        {
          v39 = v30;
          ml_nlink_set_curr_force_inactive_state(v14, v30, (unsigned int)(1 << *(_DWORD *)(v29 + 4)), 2);
          inited = ml_nlink_init_concurrency_link_request(v14, v39);
          wlan_objmgr_vdev_release_ref(v39, 1u, v41, inited, v42, v43, v44, v45, v46, v47, v48);
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: no vdev for id %d",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "cm_get_and_disable_link_from_roam_ind",
            v13);
        }
        updated = v28;
      }
LABEL_29:
      if ( *(_BYTE *)(a2 + 306) == 1 )
        policy_mgr_hw_mode_transition_cb(
          *(_DWORD *)(a2 + 308),
          *(_DWORD *)(a2 + 312),
          *(_DWORD *)(a2 + 316),
          a2 + 320,
          *(_DWORD *)(a2 + 352),
          a2 + 356,
          v14);
      ml_nlink_conn_change_notify(v14, v13, 3, 0);
      if ( *(_DWORD *)(a2 + 172) )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Received pmk in roam sync. Length: %d",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "cm_fw_roam_complete");
        cm_check_and_set_sae_single_pmk_cap(v14, v13, (const void *)(a2 + 176), *(_DWORD *)(a2 + 172));
      }
      cm_csr_send_set_ie(*a1, v49, v50, v51, v52, v53, v54, v55, v56);
      if ( (wlan_cm_is_self_mld_roam_supported(v14, v57, v58, v59, v60, v61, v62, v63, v64) & 1) == 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 64)) )
        {
          wlan_cm_set_disable_hi_rssi(v10, v13, 0);
        }
        else
        {
          wlan_cm_set_disable_hi_rssi(v10, v13, 1);
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Disabling HI_RSSI, AP freq=%d rssi %d vdev id %d",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "cm_fw_roam_complete",
            *(unsigned int *)(a2 + 64),
            (unsigned int)*(char *)(a2 + 60),
            v13);
        }
      }
      policy_mgr_check_n_start_opportunistic_timer(v14);
      wlan_cm_handle_sta_sta_roaming_enablement(v14, v13);
      if ( (*(_BYTE *)(*a1 + 60) & 2) != 0 )
        updated = wlan_cm_roam_state_change(v10, v13, 0, 0x34u);
      if ( *(_DWORD *)(a2 + 56) == 2 )
      {
        v73 = 2;
        v74 = 1;
      }
      else
      {
        v73 = 3;
        v74 = 4;
      }
      wlan_cm_roam_state_change(v10, v13, v73, v74);
      acs_mode_for_vdev = wlan_util_vdev_mgr_get_acs_mode_for_vdev(*a1);
      policy_mgr_check_concurrent_intf_and_restart_sap(v14, acs_mode_for_vdev & 1);
      rso_pending_disable_req_bitmap = mlme_get_rso_pending_disable_req_bitmap(v14, v13);
      if ( rso_pending_disable_req_bitmap )
      {
        v77 = rso_pending_disable_req_bitmap;
        mlme_clear_rso_pending_disable_req_bitmap(v14, v13);
        wlan_cm_disable_rso(v10, v13, v77, 48, v78, v79, v80, v81, v82, v83, v84, v85);
      }
      return updated;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Failed to find pdev", a3, a4, a5, a6, a7, a8, a9, a10, "cm_fw_roam_complete");
    return 16;
  }
}
