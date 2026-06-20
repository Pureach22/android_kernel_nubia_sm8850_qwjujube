__int64 __fastcall wlan_hdd_cfg80211_set_thermal_mitigation_policy(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v9; // x0
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v20; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  int v48; // w8
  int curr_thermal_temperature_val; // w0
  __int64 v50; // x20
  unsigned int v51; // w20
  unsigned int v52; // w0
  __int64 v53; // x20
  __int64 v59; // [xsp+8h] [xbp-38h] BYREF
  __int64 v60; // [xsp+10h] [xbp-30h] BYREF
  __int64 v61; // [xsp+18h] [xbp-28h]
  __int64 v62; // [xsp+20h] [xbp-20h]
  __int64 v63; // [xsp+28h] [xbp-18h]
  __int64 v64; // [xsp+30h] [xbp-10h]
  __int64 v65; // [xsp+38h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 488);
  v59 = 0;
  result = _osif_psoc_sync_op_start(v9, &v59, (__int64)"wlan_hdd_cfg80211_set_thermal_mitigation_policy");
  if ( (_DWORD)result )
    goto LABEL_6;
  if ( a1 )
  {
    v20 = *(_QWORD *)(a2 + 32);
    v63 = 0;
    v64 = 0;
    v61 = 0;
    v62 = 0;
    v60 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
    if ( !(unsigned int)_wlan_hdd_validate_context(
                          a1 + 1536,
                          (__int64)"__wlan_hdd_cfg80211_set_thermal_mitigation_policy",
                          v21,
                          v22,
                          v23,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28) )
    {
      if ( (unsigned int)hdd_get_conparam() == 5 )
      {
        v38 = jiffies;
        if ( _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Command not allowed in FTM mode",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
          _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks = v38;
        }
        v29 = -1;
        goto LABEL_5;
      }
      if ( !(unsigned int)_nla_parse(&v60, 4, a3, a4, &wlan_hdd_thermal_mitigation_policy, 31, 0) )
      {
        if ( !v61 )
        {
          v50 = jiffies;
          if ( _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks_15 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: attr thermal cmd value failed",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
            _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks_15 = v50;
          }
          goto LABEL_4;
        }
        v48 = *(_DWORD *)(v61 + 4);
        curr_thermal_temperature_val = -22;
        if ( v48 <= 4 )
        {
          if ( v48 == 1 )
          {
            curr_thermal_temperature_val = hdd_get_curr_thermal_temperature_val(a1 + 1536, v20 + 2688);
          }
          else if ( v48 == 4 )
          {
            if ( !v62 )
            {
              v53 = jiffies;
              if ( _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks_17 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: attr thermal throttle set failed",
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
                _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks_17 = v53;
              }
              goto LABEL_4;
            }
            v51 = *(_DWORD *)(v62 + 4);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: thermal mitigation level from userspace %d",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "__wlan_hdd_cfg80211_set_thermal_mitigation_policy",
              v51);
            v52 = hdd_send_thermal_mitigation_val((__int64 *)(a1 + 1536), v51, 1);
            curr_thermal_temperature_val = qdf_status_to_os_return(v52);
          }
        }
        else
        {
          switch ( v48 )
          {
            case 5:
              curr_thermal_temperature_val = hdd_get_curr_thermal_throttle_level_val(a1 + 1536);
              break;
            case 6:
              curr_thermal_temperature_val = ((__int64 (__fastcall *)(__int64, __int64))hdd_get_curr_thermal_stats_val)(
                                               a1,
                                               a1 + 1536);
              break;
            case 7:
              curr_thermal_temperature_val = hdd_send_get_thermal_stats_cmd(
                                               (_QWORD *)(a1 + 1536),
                                               v39,
                                               v40,
                                               v41,
                                               v42,
                                               v43,
                                               v44,
                                               v45,
                                               v46);
              if ( curr_thermal_temperature_val )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failure while sending command to fw",
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
                curr_thermal_temperature_val = -22;
              }
              break;
          }
        }
        v29 = curr_thermal_temperature_val;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
        goto LABEL_5;
      }
      v47 = jiffies;
      if ( _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks_13 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid attribute",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "__wlan_hdd_cfg80211_set_thermal_mitigation_policy");
        _wlan_hdd_cfg80211_set_thermal_mitigation_policy___last_ticks_13 = v47;
      }
    }
LABEL_4:
    v29 = -22;
LABEL_5:
    _osif_psoc_sync_op_stop(v59, (__int64)"wlan_hdd_cfg80211_set_thermal_mitigation_policy");
    result = v29;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return wlan_hdd_thermal_config_support();
}
