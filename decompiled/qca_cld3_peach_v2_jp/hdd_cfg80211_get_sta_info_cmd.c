__int64 __fastcall hdd_cfg80211_get_sta_info_cmd(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 sync_resume; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19
  __int64 v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x20
  int v46; // w0
  __int64 v47; // x20
  int v48; // w21
  int v49; // w4
  int station_remote; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v67; // w19
  __int64 v68; // x20
  __int64 v69; // x20
  __int64 *v70; // [xsp+8h] [xbp-1D8h] BYREF
  unsigned int v71; // [xsp+10h] [xbp-1D0h] BYREF
  unsigned __int16 v72; // [xsp+14h] [xbp-1CCh]
  _QWORD s[57]; // [xsp+18h] [xbp-1C8h] BYREF

  s[56] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v70 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v70, (__int64)"hdd_cfg80211_get_sta_info_cmd");
  if ( (_DWORD)result )
    goto LABEL_13;
  sync_resume = wlan_hdd_qmi_get_sync_resume(v10, v11, v12, v13, v14, v15, v16, v17);
  if ( (_DWORD)sync_resume )
  {
    v27 = sync_resume;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: qmi sync resume failed: %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_cfg80211_get_sta_info_cmd");
LABEL_12:
    _osif_vdev_sync_op_stop((__int64)v70, (__int64)"hdd_cfg80211_get_sta_info_cmd");
    result = v27;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v28 = *(_QWORD *)(a2 + 32);
    memset(s, 0, 0x1C0u);
    v72 = 0;
    v71 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "__hdd_cfg80211_get_sta_info_cmd",
      v28 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 || (unsigned int)hdd_get_conparam() == 4 )
    {
      v45 = jiffies;
      if ( _hdd_cfg80211_get_sta_info_cmd___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM / Monitor mode",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "__hdd_cfg80211_get_sta_info_cmd");
        _hdd_cfg80211_get_sta_info_cmd___last_ticks = v45;
      }
      v46 = -1;
      goto LABEL_11;
    }
    v46 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__hdd_cfg80211_get_sta_info_cmd",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44);
    if ( v46 )
    {
LABEL_11:
      v27 = v46;
      wlan_hdd_qmi_put_suspend(v37, v38, v39, v40, v41, v42, v43, v44);
      goto LABEL_12;
    }
    v46 = _nla_parse(s, 55, a3, a4, &hdd_get_sta_policy, 31, 0);
    if ( v46 )
    {
      v47 = jiffies;
      if ( _hdd_cfg80211_get_sta_info_cmd___last_ticks_78 - jiffies + 125 < 0 )
      {
        v48 = v46;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid ATTR",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "__hdd_cfg80211_get_sta_info_cmd");
        v46 = v48;
        _hdd_cfg80211_get_sta_info_cmd___last_ticks_78 = v47;
      }
      goto LABEL_11;
    }
    v49 = *(_DWORD *)(v28 + 2728);
    if ( v49 > 1 )
    {
      if ( v49 == 3 )
      {
LABEL_24:
        if ( !s[1] )
        {
          v69 = jiffies;
          if ( _hdd_cfg80211_get_sta_info_cmd___last_ticks_79 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: MAC address is not present",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "__hdd_cfg80211_get_sta_info_cmd");
            _hdd_cfg80211_get_sta_info_cmd___last_ticks_79 = v69;
            v46 = -22;
            goto LABEL_11;
          }
          goto LABEL_30;
        }
        nla_memcpy(&v71, s[1], 6);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: STA %02x:%02x:%02x:**:**:%02x",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "__hdd_cfg80211_get_sta_info_cmd",
          (unsigned __int8)v71,
          BYTE1(v71),
          BYTE2(v71),
          HIBYTE(v72));
        station_remote = hdd_get_station_remote_ex(a1 + 1536, v28 + 2688, v71 | ((unsigned __int64)v72 << 32));
LABEL_26:
        v67 = station_remote;
        qdf_trace_msg(0x33u, 8u, "%s: exit", v51, v52, v53, v54, v55, v56, v57, v58, "__hdd_cfg80211_get_sta_info_cmd");
        v46 = v67;
        goto LABEL_11;
      }
      if ( v49 != 2 )
        goto LABEL_27;
    }
    else if ( v49 )
    {
      if ( v49 != 1 )
      {
LABEL_27:
        v68 = jiffies;
        if ( _hdd_cfg80211_get_sta_info_cmd___last_ticks_82 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid device_mode: %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "__hdd_cfg80211_get_sta_info_cmd");
          _hdd_cfg80211_get_sta_info_cmd___last_ticks_82 = v68;
          v46 = -22;
          goto LABEL_11;
        }
LABEL_30:
        v46 = -22;
        goto LABEL_11;
      }
      goto LABEL_24;
    }
    station_remote = hdd_get_station_info_ex(*(_QWORD *)(v28 + 55512));
    goto LABEL_26;
  }
  __break(0x800u);
  return hdd_get_station_assoc_fail(sync_resume);
}
