__int64 __fastcall cm_roam_update_config_req(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v4; // w20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  __int64 v26; // x19
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  __int64 rso_config_fl; // x0
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x25
  __int64 v48; // x24
  char is_any_sta_dfs_ap_scc_by_vdev_id; // w0
  char v50; // w8
  char v51; // w9
  unsigned int updated; // w20
  int v53; // w5
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _QWORD v63[4]; // [xsp+0h] [xbp-30h] BYREF
  char v64[4]; // [xsp+20h] [xbp-10h] BYREF
  char v65[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v66; // [xsp+28h] [xbp-8h]

  v4 = a2;
  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v63, 0, sizeof(v63));
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v6 )
  {
    v15 = v6;
    mlme_set_roam_reason_better_ap(v6, 0, v7, v8, v9, v10, v11, v12, v13, v14);
    wlan_objmgr_vdev_release_ref(v15, 2u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  v25 = _qdf_mem_malloc(0x12D0u, "cm_roam_update_config_req", 3737);
  if ( v25 )
  {
    v26 = v25;
    v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v4, 77);
    if ( v27 )
    {
      v36 = v27;
      rso_config_fl = wlan_cm_get_rso_config_fl(v27, "cm_roam_update_config_req", 3747);
      if ( rso_config_fl && (v47 = *(_QWORD *)(v36 + 216)) != 0 )
      {
        v48 = rso_config_fl;
        v65[0] = 0;
        v64[0] = 0;
        *(_DWORD *)v26 = (unsigned __int8)v4;
        wlan_mlme_get_roam_bmiss_first_bcnt(a1, v65);
        wlan_mlme_get_roam_bmiss_final_bcnt(a1, v64);
        is_any_sta_dfs_ap_scc_by_vdev_id = policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(a1, v4);
        v50 = v65[0];
        if ( (is_any_sta_dfs_ap_scc_by_vdev_id & 1) != 0 )
        {
          v51 = v64[0];
          if ( (unsigned __int8)v65[0] >= 2u )
            v50 = 2;
          if ( (unsigned __int8)v64[0] >= 5u )
            v51 = 5;
        }
        else
        {
          v51 = v64[0];
        }
        *(_BYTE *)(v26 + 4) = v50;
        *(_BYTE *)(v26 + 5) = v51;
        v65[0] = 0;
        *(_DWORD *)(v26 + 8) = (unsigned __int8)v4;
        wlan_mlme_get_bmiss_timeout_on_wakeup(a1, v65);
        *(_BYTE *)(v26 + 12) = v65[0];
        wlan_mlme_get_bmiss_timeout_on_sleep(a1, v65);
        *(_BYTE *)(v26 + 13) = v65[0];
        cm_roam_fill_rssi_change_params(a1, v4, (_DWORD *)(v26 + 1536));
        if ( (unsigned int)mlme_get_roam_state(a1, v4) == 2 )
        {
          cm_roam_disconnect_params(a1, v4, v26 + 4540);
          cm_roam_triggers(a1, v4, (_DWORD *)(v26 + 4580));
          *(_DWORD *)(v26 + 4552) = (unsigned __int8)v4;
          wlan_mlme_get_enable_idle_roam(a1, (_BYTE *)(v26 + 4556));
          wlan_mlme_get_idle_roam_rssi_delta(a1, (int *)(v26 + 4564));
          wlan_mlme_get_idle_roam_inactive_time(a1, (int *)(v26 + 4572));
          wlan_mlme_get_idle_data_packet_count(a1, (int *)(v26 + 4576));
          wlan_mlme_get_idle_roam_min_rssi(a1, (int *)(v26 + 4568));
          wlan_mlme_get_idle_roam_band(a1, (_DWORD *)(v26 + 4560));
          if ( (*(_BYTE *)(v26 + 4585) & 0x40) == 0 )
            *(_BYTE *)(v26 + 4556) = 0;
        }
        cm_roam_scan_offload_rssi_thresh(a1, v4, v26 + 4432, v48);
        *(_DWORD *)(v26 + 1504) = (unsigned __int8)v4;
        v53 = *(unsigned __int16 *)(v48 + 146);
        *(_DWORD *)(v26 + 1508) = v53;
        *(_DWORD *)(v26 + 1512) = v53;
        *(_DWORD *)(v26 + 1516) = 3 * v53;
        *(_DWORD *)(v26 + 1520) = *(_DWORD *)(v48 + 196);
        *(_DWORD *)(v26 + 1524) = *(_DWORD *)(v48 + 200);
        *(_DWORD *)(v26 + 1528) = *(_DWORD *)(v48 + 184);
        *(_DWORD *)(v26 + 1532) = *(_DWORD *)(v48 + 216);
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: full_scan_period:%d, empty_scan_refresh_period:%d, roam_periodic_scan_interval %d",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "cm_roam_scan_offload_scan_period");
        cm_roam_scan_offload_ap_profile(a1, v36, v48, v26 + 3508);
        cm_fill_rso_channel_list(a1, v36, v48, v26 + 4020, a3);
        cm_roam_scan_filter(a1, v47, v4, 4, a3, v26 + 16);
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD))cm_roam_scan_offload_fill_rso_configs)(
          a1,
          v36,
          v48,
          v26 + 1552,
          v26 + 4020,
          4,
          a3);
        *(_BYTE *)(v26 + 4804) = wlan_cm_get_roam_rt_stats(a1, 0);
        *(_WORD *)(v26 + 4806) = wlan_cm_roam_get_ho_delay_config(a1);
        *(_BYTE *)(v26 + 4808) = wlan_cm_get_exclude_rm_partial_scan_freq(a1);
        *(_BYTE *)(v26 + 4809) = wlan_cm_roam_get_full_scan_6ghz_on_disc(a1);
        wlan_cm_roam_cfg_get_value(a1, v4, 29, (int)v63);
        *(_BYTE *)(v26 + 4810) = v63[0];
        wlan_cm_roam_cfg_get_value(a1, v4, 30, (int)v63);
        *(_BYTE *)(v26 + 4811) = v63[0];
        updated = wlan_cm_tgt_send_roam_update_req(a1, v4, v26);
        if ( updated )
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: fail to send update config",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "cm_roam_update_config_req");
      }
      else
      {
        updated = 4;
      }
      wlan_objmgr_vdev_release_ref(v36, 0x4Du, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "cm_roam_update_config_req",
        (unsigned __int8)v4);
      updated = 4;
    }
    _qdf_mem_free(v26);
  }
  else
  {
    updated = 2;
  }
  _ReadStatusReg(SP_EL0);
  return updated;
}
