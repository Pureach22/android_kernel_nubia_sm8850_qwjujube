__int64 __fastcall hdd_hostapd_sap_fill_peer_ml_info(__int64 *a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 v4; // x22
  __int64 vdev_by_user; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  _QWORD *peer_by_mac; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7

  v4 = *a1;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_hostapd_sap_fill_peer_ml_info");
  if ( !vdev_by_user )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to get link id, VDEV NULL",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "hdd_hostapd_sap_fill_peer_ml_info");
  v15 = vdev_by_user;
  if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v7, v8, v9, v10, v11, v12, v13, v14) & 1) != 0 )
  {
    *(_BYTE *)(a2 + 226) = *(_BYTE *)(v15 + 93);
    _hdd_objmgr_put_vdev_by_user(v15, 5, "hdd_hostapd_sap_fill_peer_ml_info");
    peer_by_mac = wlan_objmgr_get_peer_by_mac(**(_QWORD **)(v4 + 24), a3, 5u);
    if ( peer_by_mac )
    {
      v25 = (__int64)peer_by_mac;
      qdf_mem_copy((void *)(a2 + 228), peer_by_mac + 99, 6u);
      wlan_mlme_peer_get_assoc_rsp_ies(v25, (_QWORD *)(a2 + 240), (_QWORD *)(a2 + 248));
      result = wlan_objmgr_peer_release_ref(v25, 5u, v26, v27, v28, v29, v30, v31, v32, v33);
      *(_BYTE *)(a2 + 225) = 1;
    }
    else
    {
      if ( a3 )
      {
        v35 = *a3;
        v36 = a3[1];
        v37 = a3[2];
        v38 = a3[5];
      }
      else
      {
        v37 = 0;
        v35 = 0;
        v36 = 0;
        v38 = 0;
      }
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Peer not found with MAC %02x:%02x:%02x:**:**:%02x",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "hdd_hostapd_sap_fill_peer_ml_info",
               v35,
               v36,
               v37,
               v38);
    }
  }
  else
  {
    *(_BYTE *)(a2 + 226) = -1;
    return _hdd_objmgr_put_vdev_by_user(v15, 5, "hdd_hostapd_sap_fill_peer_ml_info");
  }
  return result;
}
