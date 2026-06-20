__int64 __fastcall wlan_hdd_cfg80211_change_beacon(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 v24; // x20
  const char *v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w1
  unsigned int v44; // w19
  __int64 v45; // x21
  __int64 v46; // x1
  int v47; // w2
  int started; // w19
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v58[2]; // [xsp+10h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  result = _osif_vdev_sync_op_start(a2, &v57, "wlan_hdd_cfg80211_change_beacon");
  if ( !(_DWORD)result )
  {
    v14 = qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "__wlan_hdd_cfg80211_change_beacon");
    if ( (unsigned int)hdd_get_conparam(v14) == 5 )
    {
      v23 = "%s: Command not allowed in FTM mode";
    }
    else
    {
      v24 = *(_QWORD *)(a2 + 55520);
      if ( v24 )
      {
        if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                             *(unsigned __int8 *)(v24 + 8),
                             "__wlan_hdd_cfg80211_change_beacon") )
        {
LABEL_14:
          v34 = -22;
          goto LABEL_15;
        }
        qdf_mtrace(51, 51, 0x1Bu, *(_BYTE *)(v24 + 8), *(_DWORD *)(a2 + 2728));
        v25 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Device_mode %s(%d)",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "__wlan_hdd_cfg80211_change_beacon",
          v25,
          *(unsigned int *)(a2 + 2728));
        v34 = _wlan_hdd_validate_context(*(_QWORD *)(a2 + 2712), "__wlan_hdd_cfg80211_change_beacon");
        if ( v34 )
        {
LABEL_15:
          v44 = v34;
          _osif_vdev_sync_op_stop(v57, "wlan_hdd_cfg80211_change_beacon");
          result = v44;
          goto LABEL_16;
        }
        if ( (*(_DWORD *)(a2 + 2728) | 2) != 3 )
        {
          v34 = -95;
          goto LABEL_15;
        }
        if ( !*(_QWORD *)(v24 + 2432) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: session id: %d beacon data points to NULL",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "__wlan_hdd_cfg80211_change_beacon",
            *(unsigned __int8 *)(v24 + 8));
          goto LABEL_14;
        }
        v58[0] = 0;
        if ( !(unsigned int)wlan_hdd_cfg80211_alloc_new_beacon(v24, v58, a3, 0) )
        {
          v45 = v58[0];
          *(_QWORD *)(v24 + 2432) = v58[0];
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: update beacon for P2P GO/SAP",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "__wlan_hdd_cfg80211_change_beacon");
          if ( *(_DWORD *)(a2 + 2728) != 3
            || (v47 = *(_DWORD *)((char *)&off_20 + v45 + 4)) == 0
            || !(unsigned int)ucfg_p2p_extract_ap_assist_dfs_params(
                                *(_QWORD *)(v24 + 32),
                                *(__int64 *)((char *)&qword_8 + v45),
                                v47,
                                1,
                                *(_DWORD *)(v24 + 720),
                                1) )
          {
            started = wlan_hdd_cfg80211_start_bss(v24, v15, v16, v17, v18, v19, v20, v21, v22, v46, nullptr, 0, 0, 0);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "__wlan_hdd_cfg80211_change_beacon");
            v34 = started;
            goto LABEL_15;
          }
          v23 = "%s: Failed parsing P2P2 IE";
          v43 = 8;
          goto LABEL_13;
        }
        v23 = "%s: new beacon alloc failed";
      }
      else
      {
        v23 = "%s: invalid link_info";
      }
    }
    v43 = 2;
LABEL_13:
    qdf_trace_msg(0x33u, v43, v23, v15, v16, v17, v18, v19, v20, v21, v22, "__wlan_hdd_cfg80211_change_beacon");
    goto LABEL_14;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
