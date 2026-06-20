__int64 __fastcall wlan_hdd_send_mlo_station_stats(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 link_info_by_bssid; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x24
  __int64 vdev_by_user; // x0
  __int64 v35; // x22
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int bss_peer_mld_mac; // w23
  unsigned int *v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v56; // x23
  __int64 result; // x0
  const char *v58; // x2
  const char *v59; // x3
  unsigned int v60; // w1
  __int64 v61; // x20
  __int64 v62; // x20
  __int64 v63; // [xsp+0h] [xbp-10h] BYREF
  __int64 v64; // [xsp+8h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (wlan_hdd_is_mlo_connection(*(_QWORD *)(a1 + 52832), a5, a6, a7, a8, a9, a10, a11, a12) & 1) == 0 )
  {
    qdf_trace_msg(0x33u, 8u, "Fetching station stats for legacy connection", v16, v17, v18, v19, v20, v21, v22, v23);
    link_info_by_bssid = *(_QWORD *)(a1 + 52832);
    goto LABEL_17;
  }
  link_info_by_bssid = hdd_get_link_info_by_bssid(a2, (int *)a3);
  if ( link_info_by_bssid )
  {
LABEL_17:
    wlan_hdd_get_sta_stats(link_info_by_bssid, a3, a4);
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  v33 = *(_QWORD *)(a1 + 24);
  WORD2(v63) = 0;
  LODWORD(v63) = 0;
  if ( !v33 )
  {
    v58 = "%s: invalid hdd_ctx";
    v59 = "wlan_is_mlo_aggregated_stats_allowed";
    v60 = 2;
LABEL_21:
    qdf_trace_msg(0x33u, v60, v58, v25, v26, v27, v28, v29, v30, v31, v32, v59, v63, v64);
    goto LABEL_25;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x51u, (__int64)"wlan_hdd_get_bss_peer_mld_mac");
  if ( !vdev_by_user )
  {
LABEL_23:
    v61 = jiffies;
    if ( wlan_is_mlo_aggregated_stats_allowed___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: mlo_vdev_stats: failed to get bss peer mld mac",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_is_mlo_aggregated_stats_allowed");
      wlan_is_mlo_aggregated_stats_allowed___last_ticks = v61;
    }
    goto LABEL_25;
  }
  v35 = vdev_by_user;
  if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v25, v26, v27, v28, v29, v30, v31, v32) & 1) == 0 )
  {
    _hdd_objmgr_put_vdev_by_user(
      v35,
      0x51u,
      (__int64)"wlan_hdd_get_bss_peer_mld_mac",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44);
    goto LABEL_23;
  }
  bss_peer_mld_mac = wlan_vdev_get_bss_peer_mld_mac(v35, &v63, v37, v38, v39, v40, v41, v42, v43, v44);
  _hdd_objmgr_put_vdev_by_user(
    v35,
    0x51u,
    (__int64)"wlan_hdd_get_bss_peer_mld_mac",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54);
  if ( bss_peer_mld_mac )
    goto LABEL_23;
  if ( (*(_BYTE *)(v33 + 8238) & 1) == 0 )
  {
    v58 = "%s: mlo per link stats is not supported by FW";
    v59 = "wlan_hdd_is_per_link_stats_supported";
    v60 = 8;
    goto LABEL_21;
  }
  if ( (_DWORD)v63 == *(_DWORD *)a3 && WORD2(v63) == *(unsigned __int16 *)(a3 + 4) )
  {
    v56 = jiffies;
    if ( wlan_is_mlo_aggregated_stats_allowed___last_ticks_289 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Fetching Aggregated station stats",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_is_mlo_aggregated_stats_allowed");
      wlan_is_mlo_aggregated_stats_allowed___last_ticks_289 = v56;
    }
    wlan_hdd_get_mlo_sta_stats(a1, a3, a4);
    goto LABEL_18;
  }
LABEL_25:
  v62 = jiffies;
  if ( wlan_hdd_send_mlo_station_stats___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid bssid",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wlan_hdd_send_mlo_station_stats");
    wlan_hdd_send_mlo_station_stats___last_ticks = v62;
  }
  result = 4294967274LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
