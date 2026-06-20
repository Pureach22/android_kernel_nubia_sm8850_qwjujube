__int64 __fastcall hdd_send_update_owe_info_event(
        __int64 *a1,
        unsigned __int8 *a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x8
  __int64 v17; // x21
  __int64 v18; // x24
  __int64 vdev_by_user; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x23
  _QWORD *peer_by_mac; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x4
  __int64 v48; // x5
  __int64 v49; // x6
  __int64 v50; // x7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 result; // x0
  __int64 v60; // [xsp+0h] [xbp-30h] BYREF
  __int64 v61; // [xsp+8h] [xbp-28h]
  __int64 v62; // [xsp+10h] [xbp-20h]
  _QWORD v63[2]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v64; // [xsp+28h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *a1;
  v63[0] = 0;
  v63[1] = 0;
  v61 = 0;
  v62 = 0;
  v17 = *(_QWORD *)(v16 + 32);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "hdd_send_update_owe_info_event",
    v17 + 296,
    0,
    0,
    0,
    0,
    0,
    v64);
  qdf_mem_set(&v60, 0x28u, 0);
  qdf_mem_copy(&v60, a2, 6u);
  v18 = *a1;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_ml_sap_owe_fill_ml_info");
  if ( vdev_by_user )
  {
    v28 = vdev_by_user;
    if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v20, v21, v22, v23, v24, v25, v26, v27) & 1) != 0 )
    {
      LODWORD(v63[0]) = *(unsigned __int8 *)(v28 + 93);
      _hdd_objmgr_put_vdev_by_user(v28, 5, "hdd_ml_sap_owe_fill_ml_info");
      peer_by_mac = wlan_objmgr_get_peer_by_mac(**(_QWORD **)(v18 + 24), a2, 5u);
      if ( peer_by_mac )
      {
        v38 = (__int64)peer_by_mac;
        qdf_mem_copy((char *)v63 + 4, peer_by_mac + 99, 6u);
        wlan_objmgr_peer_release_ref(v38, 5u, v39, v40, v41, v42, v43, v44, v45, v46);
      }
      else
      {
        if ( a2 )
        {
          v47 = *a2;
          v48 = a2[1];
          v49 = a2[2];
          v50 = a2[5];
        }
        else
        {
          v49 = 0;
          v47 = 0;
          v48 = 0;
          v50 = 0;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Peer not found with MAC %02x:%02x:%02x:**:**:%02x",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_ml_sap_owe_fill_ml_info",
          v47,
          v48,
          v49,
          v50);
      }
    }
    else
    {
      LODWORD(v63[0]) = -1;
      _hdd_objmgr_put_vdev_by_user(v28, 5, "hdd_ml_sap_owe_fill_ml_info");
    }
  }
  v61 = a3;
  v62 = a4;
  cfg80211_update_owe_info_event(v17, &v60, 3264);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: exit",
             v51,
             v52,
             v53,
             v54,
             v55,
             v56,
             v57,
             v58,
             "hdd_send_update_owe_info_event");
  _ReadStatusReg(SP_EL0);
  return result;
}
