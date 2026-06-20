__int64 __fastcall wlan_cfg80211_tdls_add_peer_mlo(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 vdev_by_user; // x0
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 link_vdev; // x0
  __int64 v53; // x20
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  unsigned int v63; // w0
  unsigned int v64; // w19
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  unsigned int v73; // w0
  unsigned int *v74; // x8
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                   *(_QWORD *)(a1 + 52832),
                   0x57u,
                   (__int64)"wlan_cfg80211_tdls_add_peer_mlo");
  if ( !vdev_by_user )
    return 4294967274LL;
  v7 = vdev_by_user;
  if ( !(unsigned int)wlan_vdev_is_up() )
  {
    if ( wlan_cm_roaming_in_progress(*(_QWORD *)(v7 + 216), *(_BYTE *)(v7 + 168)) )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: vdev %d Roaming is in progress",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_cfg80211_tdls_add_peer_mlo",
        *(unsigned __int8 *)(v7 + 168));
      _hdd_objmgr_put_vdev_by_user(
        v7,
        0x57u,
        (__int64)"wlan_cfg80211_tdls_add_peer_mlo",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42);
      return 4294967285LL;
    }
    if ( (wlan_vdev_mlme_is_mlo_vdev(v7, v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
    {
      _hdd_objmgr_put_vdev_by_user(
        v7,
        0x57u,
        (__int64)"wlan_cfg80211_tdls_add_peer_mlo",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51);
      link_vdev = wlan_key_get_link_vdev(a1, 87, a3);
      if ( !link_vdev )
        return 4294967274LL;
      v53 = link_vdev;
      if ( (ucfg_tdls_link_vdev_is_matching(link_vdev) & 1) == 0 )
      {
        wlan_key_put_link_vdev(v53, 0x57u, v54, v55, v56, v57, v58, v59, v60, v61);
        return 4294967274LL;
      }
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: tdls add peer for vdev %d",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "wlan_cfg80211_tdls_add_peer_mlo",
        *(unsigned __int8 *)(v53 + 168));
      v62 = wlan_cfg80211_tdls_add_peer(v53, a2);
      v64 = v63;
      wlan_key_put_link_vdev(v53, 0x57u, v62, v65, v66, v67, v68, v69, v70, v71);
    }
    else
    {
      v72 = wlan_cfg80211_tdls_add_peer(v7, a2);
      v64 = v73;
      _hdd_objmgr_put_vdev_by_user(
        v7,
        0x57u,
        (__int64)"wlan_cfg80211_tdls_add_peer_mlo",
        v74,
        v72,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81);
    }
    return v64;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: vdev %d sta is not connected or disconnecting",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "wlan_cfg80211_tdls_add_peer_mlo",
    *(unsigned __int8 *)(v7 + 168));
  _hdd_objmgr_put_vdev_by_user(
    v7,
    0x57u,
    (__int64)"wlan_cfg80211_tdls_add_peer_mlo",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24);
  return 4294967274LL;
}
