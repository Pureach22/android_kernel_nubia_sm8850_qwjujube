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
  unsigned int v28; // w20
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
  __int64 *v46; // x23
  _QWORD *sta_info_by_id; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _QWORD *v56; // x22
  double station_remote; // d0
  unsigned int v58; // w0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v83[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v84[2]; // [xsp+10h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  result = _osif_vdev_sync_op_start(a2, &v82, "wlan_hdd_cfg80211_dump_station");
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
    _osif_vdev_sync_op_stop(v82, "wlan_hdd_cfg80211_dump_station");
    result = v28;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v83[0] = 0;
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
    }
    else
    {
      v46 = (__int64 *)(a1 + 1536);
      if ( (unsigned int)_wlan_hdd_validate_context(
                           (__int64)v46,
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
                           *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 8LL),
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
        goto LABEL_10;
      }
      if ( (*(_DWORD *)(a2 + 2728) | 2) != 3 )
      {
        if ( a3 )
        {
          v28 = -2;
        }
        else
        {
          qdf_mem_copy(a4, *(const void **)(a2 + 1008), 6u);
          wlan_hdd_is_mlo_connection(*(_QWORD *)(a2 + 55512), v66, v67, v68, v69, v70, v71, v72, v73);
          qdf_trace_msg(0x33u, 8u, "Sending Assoc Link stats", v74, v75, v76, v77, v78, v79, v80, v81);
          wlan_hdd_get_sta_stats(*(_QWORD *)(a2 + 55512), a4, a5);
          v28 = 0;
        }
        goto LABEL_11;
      }
      if ( !(unsigned int)wlan_mlme_get_sap_get_peer_info(*v46, v83) && v83[0] == 1 )
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
        v84[0] = (__int64)sta_info_by_id;
        if ( sta_info_by_id )
        {
          v56 = sta_info_by_id;
          qdf_mem_copy(a4, sta_info_by_id + 4, 6u);
          station_remote = wlan_hdd_get_station_remote(a2, v56, a4, a5);
          v28 = v58;
          hdd_put_sta_info_ref(a2 + 41536, v84, 1, 0x1Fu, station_remote, v59, v60, v61, v62, v63, v64, v65);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: peer idx %d NOT FOUND",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "__wlan_hdd_cfg80211_dump_station",
            a3);
          v28 = -2;
        }
        goto LABEL_11;
      }
      v37 = "%s: sap get peer info disabled!";
    }
    qdf_trace_msg(0x33u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "__wlan_hdd_cfg80211_dump_station");
LABEL_10:
    v28 = -22;
LABEL_11:
    wlan_hdd_qmi_put_suspend(v38, v39, v40, v41, v42, v43, v44, v45);
    goto LABEL_12;
  }
  __break(0x800u);
  return hdd_get_stats();
}
