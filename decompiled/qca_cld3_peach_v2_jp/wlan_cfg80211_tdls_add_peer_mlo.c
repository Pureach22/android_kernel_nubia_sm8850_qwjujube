__int64 __fastcall wlan_cfg80211_tdls_add_peer_mlo(__int64 a1, unsigned __int8 *a2)
{
  __int64 vdev_by_user; // x0
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
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
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  unsigned int *v47; // x0
  __int64 v48; // x8
  unsigned int *v49; // x21
  _DWORD *v50; // x22
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                   *(_QWORD *)(a1 + 52824),
                   0x57u,
                   (__int64)"wlan_cfg80211_tdls_add_peer_mlo");
  if ( vdev_by_user )
  {
    v4 = vdev_by_user;
    if ( (unsigned int)wlan_vdev_is_up() )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: vdev %d sta is not connected or disconnecting",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_cfg80211_tdls_add_peer_mlo",
        *(unsigned __int8 *)(v4 + 104));
      goto LABEL_4;
    }
    if ( wlan_cm_roaming_in_progress(*(_QWORD *)(v4 + 152), *(_BYTE *)(v4 + 104)) )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: vdev %d Roaming is in progress",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_cfg80211_tdls_add_peer_mlo",
        *(unsigned __int8 *)(v4 + 104));
      v22 = -11;
      goto LABEL_21;
    }
    if ( !(unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
    {
      if ( a2 )
      {
        v43 = *a2;
        v44 = a2[1];
        v45 = a2[2];
        v46 = a2[5];
      }
      else
      {
        v45 = 0;
        v43 = 0;
        v44 = 0;
        v46 = 0;
      }
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: Invalid Mac address %02x:%02x:%02x:**:**:%02x cmd declined.",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wlan_cfg80211_tdls_validate_mac_addr",
        v43,
        v44,
        v45,
        v46);
      goto LABEL_4;
    }
    if ( a2 )
    {
      v39 = *a2;
      v40 = a2[1];
      v41 = a2[2];
      v42 = a2[5];
    }
    else
    {
      v41 = 0;
      v39 = 0;
      v40 = 0;
      v42 = 0;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Add TDLS peer %02x:%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wlan_cfg80211_tdls_add_peer",
      v39,
      v40,
      v41,
      v42);
    v47 = (unsigned int *)_qdf_mem_malloc(0x10u, "wlan_cfg80211_tdls_add_peer", 127);
    if ( !v47 )
    {
LABEL_4:
      v22 = -22;
LABEL_21:
      _hdd_objmgr_put_vdev_by_user(
        v4,
        0x57u,
        (__int64)"wlan_cfg80211_tdls_add_peer_mlo",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21);
      return v22;
    }
    v48 = *(_QWORD *)(v4 + 608);
    v49 = v47;
    if ( v48 && (v50 = *(_DWORD **)(v48 + 16)) != nullptr )
    {
      v47[3] = *(unsigned __int8 *)(v4 + 104);
      qdf_mem_copy(v47, a2, 6u);
      *v50 = 0;
      v59 = ucfg_tdls_add_peer(v4, v49, v51, v52, v53, v54, v55, v56, v57, v58);
      if ( v59 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: ucfg_tdls_add_peer returned err %d",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "wlan_cfg80211_tdls_add_peer",
          v59);
        v22 = -5;
      }
      else
      {
        if ( wait_for_completion_timeout(v50, 1250) )
        {
          if ( !v50[56] )
          {
            v22 = 0;
            goto LABEL_20;
          }
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: tdls add peer failed, status:%d",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "wlan_cfg80211_tdls_add_peer");
        }
        else
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: timeout for tdls add peer indication %ld",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "wlan_cfg80211_tdls_add_peer",
            0);
        }
        v22 = -1;
      }
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: osif_tdls_vdev or osif_priv is NULL for the current vdev",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_cfg80211_tdls_add_peer");
      v22 = -22;
    }
LABEL_20:
    _qdf_mem_free((__int64)v49);
    goto LABEL_21;
  }
  return (unsigned int)-22;
}
