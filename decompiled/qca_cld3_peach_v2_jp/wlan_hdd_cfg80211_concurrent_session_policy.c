__int64 __fastcall wlan_hdd_cfg80211_concurrent_session_policy(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x21
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x20
  __int64 v47; // x8
  __int64 v48; // x20
  __int64 v49; // [xsp+8h] [xbp-28h] BYREF
  __int64 v50; // [xsp+10h] [xbp-20h] BYREF
  __int128 v51; // [xsp+18h] [xbp-18h]
  __int64 v52; // [xsp+28h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 32);
  v49 = 0;
  result = _osif_vdev_sync_op_start(v7, &v49, "wlan_hdd_cfg80211_concurrent_session_policy");
  if ( !(_DWORD)result )
  {
    v9 = *(_QWORD *)(a2 + 32);
    v51 = 0u;
    v50 = 0;
    if ( (unsigned int)hdd_get_conparam(result) == 5 )
    {
      v18 = jiffies;
      if ( _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM mode",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "__wlan_hdd_cfg80211_concurrent_session_policy");
        _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks = v18;
      }
      v19 = -1;
    }
    else
    {
      if ( (unsigned int)_hdd_validate_adapter(v9 + 2688, "__wlan_hdd_cfg80211_concurrent_session_policy") )
      {
        v28 = jiffies;
        if ( _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_901 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid adapter",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "__wlan_hdd_cfg80211_concurrent_session_policy");
          _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_901 = v28;
        }
      }
      else if ( (unsigned int)_wlan_hdd_validate_context(
                                *(_QWORD *)(v9 + 2712),
                                "__wlan_hdd_cfg80211_concurrent_session_policy") )
      {
        v37 = jiffies;
        if ( _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_903 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid hdd context",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "__wlan_hdd_cfg80211_concurrent_session_policy");
          _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_903 = v37;
        }
      }
      else if ( (unsigned int)_nla_parse(&v50, 2, a3, a4, &wlan_hdd_set_concurrent_session_policy, 31, 0) )
      {
        v46 = jiffies;
        if ( _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_905 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: nla_parse failed",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "__wlan_hdd_cfg80211_concurrent_session_policy");
          _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_905 = v46;
        }
      }
      else
      {
        v47 = *((_QWORD *)&v51 + 1);
        if ( v51 != 0 )
        {
          if ( (_QWORD)v51 )
          {
            _wlan_hdd_cfg80211_dual_sta_policy(*(_QWORD *)(v9 + 2712), &v50);
            v47 = *((_QWORD *)&v51 + 1);
          }
          if ( v47 )
            _wlan_hdd_cfg80211_ap_policy(v9 + 2688, &v50);
          v19 = 0;
          goto LABEL_24;
        }
        v48 = jiffies;
        if ( _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_906 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: concurrent session policy attr not present",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "__wlan_hdd_cfg80211_concurrent_session_policy");
          _wlan_hdd_cfg80211_concurrent_session_policy___last_ticks_906 = v48;
        }
      }
      v19 = -22;
    }
LABEL_24:
    _osif_vdev_sync_op_stop(v49, "wlan_hdd_cfg80211_concurrent_session_policy");
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
