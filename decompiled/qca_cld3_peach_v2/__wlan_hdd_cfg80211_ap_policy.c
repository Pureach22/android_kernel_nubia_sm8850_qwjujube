__int64 __fastcall _wlan_hdd_cfg80211_ap_policy(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned int v5; // w21
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  __int64 v26; // x20
  unsigned __int8 v27; // w0
  unsigned int v28; // w20
  unsigned __int8 v29; // w22
  unsigned int v30; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int ap_policy; // w21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  char v56; // w2
  const char *v57; // x2
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL);
  v5 = *(unsigned __int8 *)(v4 + 168);
  result = hdd_get_device_mode(*(unsigned __int8 *)(v4 + 168));
  if ( (_DWORD)result == 1 )
  {
    v15 = *(_QWORD *)(a2 + 16);
    v16 = *(unsigned __int8 *)(v15 + 4);
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: AP policy : %d",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "__wlan_hdd_cfg80211_ap_policy",
               *(unsigned __int8 *)(v15 + 4));
    if ( v16 >= 4 )
    {
      v25 = jiffies;
      if ( _wlan_hdd_cfg80211_ap_policy___last_ticks_957 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Invalid concurrent policy ap config %d",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "__wlan_hdd_cfg80211_ap_policy",
                   v16);
        _wlan_hdd_cfg80211_ap_policy___last_ticks_957 = v25;
      }
      return result;
    }
    v27 = wlan_mlme_convert_ap_policy_config(v16);
    v28 = v27;
    v29 = v27;
    if ( v27 == 3 )
      v30 = 1;
    else
      v30 = 2 * ((unsigned int)v27 - 1 < 2);
    if ( (unsigned int)wma_cli_set_command(v5, 32783, v30, 1) )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Failed to set profile %d",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "__wlan_hdd_cfg80211_ap_policy",
               v30);
    ap_policy = wlan_mlme_get_ap_policy(
                  *(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL),
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Current AP policy %d prev AP policy %d",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_hdd_config_dp_direct_link_profile",
      v28,
      ap_policy);
    if ( ap_policy != 2 )
    {
      if ( ap_policy == 1 )
      {
        if ( (v29 | 2) != 2 )
          goto LABEL_24;
      }
      else
      {
        if ( ap_policy )
          goto LABEL_24;
        if ( v29 != 2 )
        {
          if ( v29 != 1 )
            goto LABEL_24;
          goto LABEL_21;
        }
      }
      v56 = 0;
      goto LABEL_22;
    }
    if ( v28 != 1 )
      goto LABEL_24;
LABEL_21:
    v56 = 1;
LABEL_22:
    if ( (unsigned int)ucfg_dp_config_direct_link(*(_QWORD *)(a1 + 32), 1, v56) )
    {
      v57 = "%s: failed to set DP ap config";
      return qdf_trace_msg(0x33u, 2u, v57, v48, v49, v50, v51, v52, v53, v54, v55, "__wlan_hdd_cfg80211_ap_policy");
    }
LABEL_24:
    if ( (unsigned int)wlan_mlme_get_ap_policy(
                         *(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL),
                         v48,
                         v49,
                         v50,
                         v51,
                         v52,
                         v53,
                         v54,
                         v55) == 2
      || !(unsigned int)wlan_mlme_set_ap_policy(
                          *(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL),
                          v28,
                          v58,
                          v59,
                          v60,
                          v61,
                          v62,
                          v63,
                          v64,
                          v65) )
    {
      result = wlan_mlme_ll_lt_sap_send_oce_flags_fw(*(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL));
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 52832) + 32LL) + 56LL) &= ~0x80000000;
      return result;
    }
    v57 = "%s: failed to set MLME ap config";
    return qdf_trace_msg(0x33u, 2u, v57, v48, v49, v50, v51, v52, v53, v54, v55, "__wlan_hdd_cfg80211_ap_policy");
  }
  v26 = jiffies;
  if ( _wlan_hdd_cfg80211_ap_policy___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: command not allowed in %d mode, vdev_id: %d",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "__wlan_hdd_cfg80211_ap_policy",
               (unsigned int)result,
               v5);
    _wlan_hdd_cfg80211_ap_policy___last_ticks = v26;
  }
  return result;
}
