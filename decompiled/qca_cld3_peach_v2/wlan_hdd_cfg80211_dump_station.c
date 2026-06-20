__int64 __fastcall wlan_hdd_cfg80211_dump_station(__int64 a1, __int64 a2, unsigned int a3, void *a4, __int64 a5)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int sync_resume; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD *sta_info_by_id; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _QWORD *v55; // x22
  double station_remote; // d0
  unsigned int v57; // w0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v82[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v83[2]; // [xsp+10h] [xbp-10h] BYREF

  v83[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  result = _osif_vdev_sync_op_start(a2, &v81, "wlan_hdd_cfg80211_dump_station");
  if ( (_DWORD)result )
    goto LABEL_13;
  sync_resume = wlan_hdd_qmi_get_sync_resume(v11, v12, v13, v14, v15, v16, v17, v18);
  if ( sync_resume )
  {
    v28 = sync_resume;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: qmi sync resume failed: %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_hdd_cfg80211_dump_station");
LABEL_12:
    _osif_vdev_sync_op_stop(v81, "wlan_hdd_cfg80211_dump_station");
    result = v28;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v82[0] = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: idx: %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "__wlan_hdd_cfg80211_dump_station",
      a3);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v37 = "%s: Command not allowed in FTM mode";
LABEL_7:
      qdf_trace_msg(0x33u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "__wlan_hdd_cfg80211_dump_station");
      v28 = -22;
LABEL_11:
      wlan_hdd_qmi_put_suspend(v38, v39, v40, v41, v42, v43, v44, v45);
      goto LABEL_12;
    }
    if ( (unsigned int)_wlan_hdd_validate_context(
                         a1 + 1536,
                         (__int64)"__wlan_hdd_cfg80211_dump_station",
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36)
      || (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 8LL),
                         (__int64)"__wlan_hdd_cfg80211_dump_station",
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45) )
    {
      v28 = -22;
      goto LABEL_11;
    }
    if ( (wlan_hdd_is_link_switch_in_progress(*(_QWORD *)(a2 + 55520), v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Link Switch in progress, can't process request",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "__wlan_hdd_cfg80211_dump_station");
      v28 = -16;
      goto LABEL_11;
    }
    if ( (*(_DWORD *)(a2 + 2728) | 2) == 3 )
    {
      if ( !(unsigned int)wlan_mlme_get_sap_get_peer_info(*(_QWORD *)(a1 + 1536), v82) && v82[0] == 1 )
      {
        sta_info_by_id = hdd_get_sta_info_by_id(
                           (_QWORD *)(a2 + 41536),
                           a3,
                           0x1Fu,
                           v29,
                           v30,
                           v31,
                           v32,
                           v33,
                           v34,
                           v35,
                           v36);
        v83[0] = (__int64)sta_info_by_id;
        if ( sta_info_by_id )
        {
          v55 = sta_info_by_id;
          qdf_mem_copy(a4, sta_info_by_id + 4, 6u);
          station_remote = wlan_hdd_get_station_remote(a2, v55, a4, a5);
          v28 = v57;
          hdd_put_sta_info_ref(a2 + 41536, v83, 1, 0x1Fu, station_remote, v58, v59, v60, v61, v62, v63, v64);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: peer idx %d NOT FOUND",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "__wlan_hdd_cfg80211_dump_station",
            a3);
          v28 = -2;
        }
        goto LABEL_11;
      }
      v37 = "%s: sap get peer info disabled!";
      goto LABEL_7;
    }
    if ( a3 )
    {
      v28 = -2;
      goto LABEL_11;
    }
    qdf_mem_copy(a4, *(const void **)(a2 + 1008), 6u);
    if ( (wlan_hdd_is_mlo_connection(*(_QWORD *)(a2 + 55520), v65, v66, v67, v68, v69, v70, v71, v72) & 1) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 9774) & 1) != 0 )
      {
        wlan_hdd_get_mlo_sta_stats(a2 + 2688, a4, a5);
LABEL_30:
        v28 = 0;
        goto LABEL_11;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: mlo per link stats is not supported by FW",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "wlan_hdd_is_per_link_stats_supported");
    }
    qdf_trace_msg(0x33u, 8u, "Sending Assoc Link stats", v73, v74, v75, v76, v77, v78, v79, v80);
    wlan_hdd_get_sta_stats(*(_QWORD *)(a2 + 55520), a4, a5);
    goto LABEL_30;
  }
  __break(0x800u);
  return hdd_get_stats();
}
