__int64 __fastcall wlan_hdd_get_rssi(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int driver_state; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 result; // x0
  int v46; // w8
  __int64 v47; // x22
  __int64 peer_rssi; // x21
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w8
  int v59; // w23
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v77; // [xsp+8h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = 0;
  if ( (cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10) & 8) != 0
    || (cds_get_driver_state(v12, v13, v14, v15, v16, v17, v18, v19) & 0x10) != 0 )
  {
    driver_state = cds_get_driver_state(v12, v13, v14, v15, v16, v17, v18, v19);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Recovery in Progress. State: 0x%x Ignore!!!",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_hdd_get_rssi",
      driver_state);
    goto LABEL_7;
  }
  if ( !hdd_cm_is_vdev_associated((_DWORD *)a1) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Not associated!, rssi on disconnect %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_hdd_get_rssi",
      *(unsigned int *)(a1 + 2692));
    v46 = *(_DWORD *)(a1 + 2692);
    result = 0;
    goto LABEL_9;
  }
  if ( hdd_cm_is_vdev_roaming(a1) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Roaming in progress, return cached RSSI",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_hdd_get_rssi");
LABEL_7:
    result = 0;
LABEL_8:
    LOBYTE(v46) = *(_BYTE *)(a1 + 2688);
LABEL_9:
    *a2 = v46;
    goto LABEL_10;
  }
  result = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"wlan_hdd_get_rssi");
  if ( !result )
    goto LABEL_8;
  v47 = result;
  peer_rssi = wlan_cfg80211_mc_cp_stats_get_peer_rssi(result, a1 + 308, &v76);
  _hdd_objmgr_put_vdev_by_user(v47, 0x51u, (__int64)"wlan_hdd_get_rssi", v49, v50, v51, v52, v53, v54, v55, v56, v57);
  if ( v76 || !peer_rssi )
  {
    wlan_cfg80211_mc_cp_stats_free_stats_event(peer_rssi);
    result = v76;
  }
  else if ( *(_DWORD *)(peer_rssi + 32) )
  {
    v58 = 0;
    while ( 1 )
    {
      v59 = v58;
      if ( !(unsigned int)qdf_mem_cmp(
                            (const void *)(*(_QWORD *)(peer_rssi + 40) + 88LL * v58 + 9),
                            (const void *)(a1 + 308),
                            6u) )
        break;
      v58 = v59 + 1;
      if ( (unsigned int)(v59 + 1) >= *(_DWORD *)(peer_rssi + 32) )
        goto LABEL_19;
    }
    *a2 = *(_BYTE *)(*(_QWORD *)(peer_rssi + 40) + 88LL * v59 + 8);
    qdf_trace_msg(0x33u, 8u, "%s: RSSI = %d", v60, v61, v62, v63, v64, v65, v66, v67, "wlan_hdd_get_rssi");
    wlan_cfg80211_mc_cp_stats_free_stats_event(peer_rssi);
    result = 0;
  }
  else
  {
LABEL_19:
    wlan_cfg80211_mc_cp_stats_free_stats_event(peer_rssi);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: bss peer not present in returned result",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "wlan_hdd_get_rssi");
    result = 5;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
