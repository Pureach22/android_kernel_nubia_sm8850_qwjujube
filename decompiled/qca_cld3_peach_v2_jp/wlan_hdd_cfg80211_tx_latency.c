double __fastcall wlan_hdd_cfg80211_tx_latency(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 v9; // x0
  double result; // d0
  __int64 v11; // x22
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
  __int64 v28; // x20
  int v29; // w8
  __int64 v30; // x20
  __int64 v31; // x20
  __int64 v32; // x20
  __int64 v33; // x20
  __int64 v34; // x20
  __int64 v35; // [xsp+8h] [xbp-58h] BYREF
  __int64 v36; // [xsp+10h] [xbp-50h] BYREF
  __int64 v37; // [xsp+18h] [xbp-48h]
  __int64 v38; // [xsp+20h] [xbp-40h]
  __int64 v39; // [xsp+28h] [xbp-38h]
  __int64 v40; // [xsp+30h] [xbp-30h]
  __int64 v41; // [xsp+38h] [xbp-28h]
  _QWORD v42[4]; // [xsp+40h] [xbp-20h] BYREF

  v42[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v35 = 0;
  v9 = _osif_vdev_sync_op_start(v8, &v35, "wlan_hdd_cfg80211_tx_latency");
  if ( (_DWORD)v9 )
  {
LABEL_7:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v11 = *(_QWORD *)(a2 + 32);
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: command not allowed in ftm mode",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "__wlan_hdd_cfg80211_tx_latency");
    }
    else if ( !(unsigned int)_wlan_hdd_validate_context(
                               a1 + 1536,
                               (__int64)"__wlan_hdd_cfg80211_tx_latency",
                               v12,
                               v13,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19) )
    {
      if ( (unsigned int)_nla_parse(&v36, 5, a3, a4, &tx_latency_policy, 31, 0) )
      {
        v28 = jiffies;
        if ( _wlan_hdd_cfg80211_tx_latency___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: invalid attribute",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "__wlan_hdd_cfg80211_tx_latency");
          _wlan_hdd_cfg80211_tx_latency___last_ticks = v28;
        }
      }
      else if ( v37 )
      {
        v29 = *(_DWORD *)(v37 + 4);
        if ( v29 == 2 )
        {
          if ( (*(_BYTE *)(v11 + 60056) & 1) != 0 )
          {
            hdd_tx_latency_get(a1, v11 + 2688, v41);
          }
          else
          {
            v31 = jiffies;
            if ( _wlan_hdd_cfg80211_tx_latency___last_ticks_378 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: please enable the feature first",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                "__wlan_hdd_cfg80211_tx_latency");
              _wlan_hdd_cfg80211_tx_latency___last_ticks_378 = v31;
            }
          }
        }
        else if ( v29 == 1 )
        {
          if ( v39 )
          {
            if ( v40 )
            {
              if ( *(_DWORD *)(v39 + 4) )
              {
                hdd_tx_latency_enable(v11 + 2688);
              }
              else
              {
                v34 = jiffies;
                if ( _wlan_hdd_cfg80211_tx_latency___last_ticks_376 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: invalid period",
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    "__wlan_hdd_cfg80211_tx_latency");
                  _wlan_hdd_cfg80211_tx_latency___last_ticks_376 = v34;
                }
              }
            }
            else
            {
              v33 = jiffies;
              if ( _wlan_hdd_cfg80211_tx_latency___last_ticks_374 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: no attr buckets",
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  "__wlan_hdd_cfg80211_tx_latency");
                _wlan_hdd_cfg80211_tx_latency___last_ticks_374 = v33;
              }
            }
          }
          else
          {
            v32 = jiffies;
            if ( _wlan_hdd_cfg80211_tx_latency___last_ticks_372 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: no attr period",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                "__wlan_hdd_cfg80211_tx_latency");
              _wlan_hdd_cfg80211_tx_latency___last_ticks_372 = v32;
            }
          }
        }
        else if ( !v29 && *(_BYTE *)(v11 + 60056) == 1 )
        {
          memset(v42, 0, 24);
          hdd_tx_latency_set(v11 + 2688, v42);
        }
      }
      else
      {
        v30 = jiffies;
        if ( _wlan_hdd_cfg80211_tx_latency___last_ticks_370 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: no attr action",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "__wlan_hdd_cfg80211_tx_latency");
          _wlan_hdd_cfg80211_tx_latency___last_ticks_370 = v30;
        }
      }
    }
    _osif_vdev_sync_op_stop(v35, "wlan_hdd_cfg80211_tx_latency");
    goto LABEL_7;
  }
  __break(0x800u);
  return hdd_tx_latency_register_cb(v9);
}
