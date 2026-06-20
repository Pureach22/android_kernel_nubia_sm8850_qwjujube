__int64 __fastcall hdd_dynamic_mac_address_set(__int64 *a1, __int64 a2, __int64 a3, char a4, char a5)
{
  __int64 v10; // x27
  __int64 v11; // x22
  __int64 vdev_by_user; // x0
  __int64 v13; // x19
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w25
  unsigned int v24; // w25
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x26
  __int64 v35; // x0
  _DWORD *v36; // x28
  int v37; // w8
  unsigned int updated; // w27
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v57; // d0
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  char v67; // [xsp+Ch] [xbp-24h]
  int v68; // [xsp+10h] [xbp-20h]
  unsigned __int16 v69; // [xsp+14h] [xbp-1Ch]
  int v70; // [xsp+18h] [xbp-18h] BYREF
  __int16 v71; // [xsp+1Ch] [xbp-14h]
  __int64 v72; // [xsp+28h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v71 = WORD2(a2);
  v70 = a2;
  v11 = *(_QWORD *)(v10 + 24);
  v69 = WORD2(a3);
  v68 = a3;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_dynamic_mac_address_set");
  if ( vdev_by_user )
  {
    v13 = vdev_by_user;
    if ( (a5 & 1) == 0 && *(_DWORD *)(vdev_by_user + 16) != 7 )
    {
      v14 = ucfg_vdev_mgr_cdp_vdev_detach(vdev_by_user);
      if ( v14 )
      {
        v23 = v14;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to detach CDP vdev. Status:%d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "hdd_dynamic_mac_address_set",
          v14);
        v24 = qdf_status_to_os_return(v23);
LABEL_22:
        _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_dynamic_mac_address_set");
        goto LABEL_23;
      }
    }
    v25 = osif_request_alloc(hdd_dynamic_mac_address_set_params);
    if ( v25 )
    {
      v34 = v25;
      v67 = a4;
      qdf_runtime_pm_prevent_suspend((__int64 *)(v11 + 1712));
      qdf_wake_lock_acquire((__int64)&wlan_wake_lock, 0x1Eu);
      *(_QWORD *)(v10 + 52800) = osif_request_cookie(v34);
      v35 = osif_request_priv(v34);
      v36 = (_DWORD *)v35;
      if ( *(_DWORD *)(v13 + 16) == 7 )
        v37 = 2;
      else
        v37 = 1;
      *(_DWORD *)(v35 + 4) = v37;
      updated = sme_send_set_mac_addr(a2 & 0xFFFFFFFFFFFFLL, a3 & 0xFFFFFFFFFFFFLL, v13);
      qdf_status_to_os_return(updated);
      if ( updated )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "Failed to send set MAC address command. Status:%d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          updated);
        osif_request_put(v34);
      }
      else
      {
        v47 = osif_request_wait_for_response(v34);
        if ( v47 )
        {
          v24 = v47;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Set MAC address response timed out",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "hdd_dynamic_mac_address_set");
        }
        else if ( *v36 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Set MAC address failed in FW. Status: %d",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "hdd_dynamic_mac_address_set");
          v24 = -11;
        }
        else
        {
          v24 = 0;
        }
        osif_request_put(v34);
        updated = sme_update_vdev_mac_addr(
                    v13,
                    a2 & 0xFFFFFFFFFFFFLL,
                    a3 & 0xFFFFFFFFFFFFLL,
                    v67 & 1,
                    (v68 | v69) != 0,
                    v24,
                    a5 & 1);
        if ( !updated )
        {
          if ( v24 || (v58 = ucfg_dp_update_link_mac_addr(v13, &v70, a5 & 1)) == 0 )
          {
            sme_vdev_set_data_tx_callback(v13);
            ucfg_pmo_del_wow_pattern(v13);
            v57 = ucfg_pmo_register_wow_default_patterns(v13);
            hdd_tx_latency_restore_config(a1, v57);
          }
          else
          {
            v24 = qdf_status_to_os_return(v58);
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: DP link MAC update failed",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "hdd_dynamic_mac_address_set");
          }
          goto LABEL_21;
        }
      }
    }
    else
    {
      updated = 2;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: request alloc fail",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_dynamic_mac_address_set");
    }
    v24 = qdf_status_to_os_return(updated);
LABEL_21:
    qdf_wake_lock_release((__int64)&wlan_wake_lock, 0x1Eu);
    qdf_runtime_pm_allow_suspend((__int64 *)(v11 + 1712));
    goto LABEL_22;
  }
  v24 = -22;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v24;
}
