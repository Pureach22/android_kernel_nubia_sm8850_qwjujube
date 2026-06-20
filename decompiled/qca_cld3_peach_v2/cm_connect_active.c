__int64 __fastcall cm_connect_active(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w0
  __int64 v13; // x1
  int v14; // w22
  __int64 req_by_cm_id_fl; // x0
  __int64 v16; // x20
  unsigned int v17; // w22
  __int64 cmpt_obj; // x0
  __int64 v19; // x23
  __int64 result; // x0
  __int64 v21; // x0
  char v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v12 = if_mgr_deliver_event(*a1, 0x14u, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *a2;
  v14 = v12;
  *((_DWORD *)a1 + 22) = v13;
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, v13, "cm_connect_active", 2503);
  if ( !req_by_cm_id_fl )
  {
    cm_remove_cmd_from_serialization(a1, *a2);
    return 4;
  }
  v16 = req_by_cm_id_fl;
  if ( v14 )
    return cm_send_connect_start_fail(a1, (unsigned int *)(v16 + 24), 5);
  *(_QWORD *)(req_by_cm_id_fl + 1056) = qdf_mc_timer_get_system_time();
  v17 = *(unsigned __int8 *)(v16 + 52);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*a1);
  if ( cmpt_obj )
  {
    if ( v17 > 0x20 )
    {
      LOBYTE(v17) = 0;
    }
    else
    {
      v19 = cmpt_obj;
      qdf_mem_copy((void *)(cmpt_obj + 145), (const void *)(v16 + 53), v17);
      cmpt_obj = v19;
    }
    *(_BYTE *)(cmpt_obj + 178) = v17;
  }
  v21 = *a1;
  if ( (*(_BYTE *)(*a1 + 60) & 2) == 0 )
  {
    mlme_cm_osif_connect_active_notify(*(unsigned __int8 *)(v21 + 168));
    mlo_sta_set_all_vdevs_connect_req_bmap(*a1);
    v22 = wlan_cm_check_mlo_roam_auth_status(*a1);
    v21 = *a1;
    if ( (v22 & 1) == 0 )
    {
      wlan_crypto_free_vdev_key(v21);
      v21 = *a1;
    }
  }
  wlan_crypto_set_vdev_param(v21, 0, *(_DWORD *)(v16 + 108));
  wlan_crypto_set_vdev_param(*a1, 7u, *(_DWORD *)(v16 + 120));
  wlan_crypto_set_vdev_param(*a1, 1u, *(_DWORD *)(v16 + 116));
  wlan_crypto_set_vdev_param(*a1, 2u, *(_DWORD *)(v16 + 112));
  wlan_crypto_set_vdev_param(*a1, 3u, *(_DWORD *)(v16 + 156));
  wlan_crypto_set_vdev_param(*a1, 5u, *(unsigned __int16 *)(v16 + 152));
  v23 = cm_store_wep_key(a1, v16 + 32, *a2);
  if ( (unsigned int)cm_get_valid_candidate(
                       (unsigned __int8 *)a1,
                       v16,
                       nullptr,
                       nullptr,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30) )
    return cm_send_connect_start_fail(a1, (unsigned int *)(v16 + 24), 5);
  result = cm_send_bss_select_ind(a1, (unsigned int *)(v16 + 24));
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 11 && !(unsigned int)cm_update_vdev_mlme_macaddr(a1, (unsigned int *)(v16 + 24)) )
    {
      cm_create_bss_peer(a1, (unsigned int *)(v16 + 24), v31, v32, v33, v34, v35, v36, v37, v38);
      return 0;
    }
    return cm_send_connect_start_fail(a1, (unsigned int *)(v16 + 24), 5);
  }
  return result;
}
