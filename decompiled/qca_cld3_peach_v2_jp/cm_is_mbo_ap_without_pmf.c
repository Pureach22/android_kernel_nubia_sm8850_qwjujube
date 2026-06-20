bool __fastcall cm_is_mbo_ap_without_pmf(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  _BOOL4 is_open_mode; // w20
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *peer_by_mac; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  char peer_pmf_status; // w23
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _BOOL8 result; // x0
  _QWORD v53[4]; // [xsp+20h] [xbp-30h] BYREF
  int v54; // [xsp+40h] [xbp-10h] BYREF
  __int16 v55; // [xsp+44h] [xbp-Ch]
  __int64 v56; // [xsp+48h] [xbp-8h]

  v2 = a2;
  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v54 = 0;
  memset(v53, 0, sizeof(v53));
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v4 )
  {
    v13 = v4;
    is_open_mode = wlan_vdev_is_open_mode(v4);
    wlan_vdev_mgr_get_param_bssid(v13, &v54);
    wlan_objmgr_vdev_release_ref(v13, 0x4Du, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, &v54, 0x4Du);
    if ( peer_by_mac )
    {
      v33 = (__int64)peer_by_mac;
      peer_pmf_status = mlme_get_peer_pmf_status((__int64)peer_by_mac);
      wlan_objmgr_peer_release_ref(v33, 0x4Du, v35, v36, v37, v38, v39, v40, v41, v42);
      wlan_cm_roam_cfg_get_value(a1, v2, 24, (int)v53);
      v43 = v53[0];
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d, is_pmf_enabled %d mbo_oce_enabled_ap:%d is_open_connection: %d for %02x:%02x:%02x:**:**:%02x",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "cm_is_mbo_ap_without_pmf",
        (unsigned __int8)v2,
        peer_pmf_status & 1,
        LODWORD(v53[0]) != 0,
        is_open_mode,
        (unsigned __int8)v54,
        BYTE1(v54),
        BYTE2(v54),
        HIBYTE(v55));
      result = (peer_pmf_status & 1) == 0 && v43 != 0 && !is_open_mode;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Peer of peer_mac %02x:%02x:%02x:**:**:%02x not found",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "cm_is_mbo_ap_without_pmf",
        (unsigned __int8)v54,
        BYTE1(v54),
        BYTE2(v54),
        HIBYTE(v55));
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_is_mbo_ap_without_pmf",
      (unsigned __int8)v2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
