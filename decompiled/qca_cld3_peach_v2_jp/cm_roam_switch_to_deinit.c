__int64 __fastcall cm_roam_switch_to_deinit(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x22
  unsigned int v6; // w20
  int roam_state; // w8
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  const char *v26; // x3
  __int64 v27; // x23
  unsigned int v28; // w0
  __int64 v29; // x0
  __int64 v30; // x1
  unsigned int v31; // w2
  __int64 v32; // x0
  __int64 v33; // x23
  double v34; // d0
  unsigned int *v35; // x8
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  v3 = *(_QWORD *)(a1 + 80);
  v6 = a2;
  roam_state = mlme_get_roam_state(v3, a2);
  result = 0;
  if ( roam_state > 3 )
  {
    if ( (unsigned int)(roam_state - 4) >= 2 )
    {
      if ( roam_state != 6 )
        return result;
      v29 = v3;
      v30 = v6;
      v31 = 0;
LABEL_17:
      mlme_set_roam_state(v29, v30, v31);
      goto LABEL_18;
    }
  }
  else
  {
    if ( roam_state == 1 )
      goto LABEL_18;
    if ( roam_state != 2 )
    {
      if ( roam_state != 3 )
        return result;
      if ( (mlme_get_supplicant_disabled_roaming(v3, v6) & 1) == 0 )
        goto LABEL_18;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev[%d]: supplicant disabled roam. clear roam scan mode",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cm_roam_switch_to_deinit",
        (unsigned __int8)v6);
      if ( !(unsigned int)cm_roam_stop_req(v3, v6, 4u, nullptr, 0) )
        goto LABEL_18;
      v25 = "%s: ROAM: Unable to clear roam scan mode";
      v26 = "cm_roam_switch_to_deinit";
      goto LABEL_13;
    }
  }
  v27 = *(_QWORD *)(a1 + 80);
  v28 = mlme_get_roam_state(v27, v6);
  if ( v28 <= 5 && ((1 << v28) & 0x34) != 0 )
  {
    if ( (unsigned int)cm_roam_stop_req(v27, v6, a3, nullptr, 0) )
    {
      v25 = "%s: ROAM: Unable to switch to RSO STOP State";
      v26 = "cm_roam_switch_to_rso_stop";
LABEL_13:
      qdf_trace_msg(0x68u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, v26);
      goto LABEL_18;
    }
    v29 = v27;
    v30 = v6;
    v31 = 3;
    goto LABEL_17;
  }
LABEL_18:
  result = wlan_cm_tgt_send_roam_offload_init(v3, v6, 0);
  if ( !(_DWORD)result )
  {
    v32 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v3, v6, 2);
    if ( v32 )
    {
      v33 = v32;
      v34 = wlan_cm_clear_roam_offload_bssid();
      wlan_objmgr_vdev_release_ref(v33, 2u, v35, v34, v36, v37, v38, v39, v40, v41, v42);
    }
    mlme_set_roam_state(v3, v6, 0);
    mlme_clear_rso_disabled_bitmap(v3, v6);
    wlan_cm_roam_activate_pcl_per_vdev(v3, v6, 0);
    result = 0;
    if ( (unsigned __int8)a3 != 46 && (unsigned __int8)a3 != 54 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev_id:%d enable roaming on other connected sta - reason:%d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "cm_roam_switch_to_deinit",
        (unsigned __int8)v6,
        (unsigned __int8)a3);
      wlan_cm_enable_roaming_on_connected_sta(a1, v6);
      return 0;
    }
  }
  return result;
}
