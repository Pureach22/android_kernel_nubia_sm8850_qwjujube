// positive sp value has been detected, the output may be wrong!
__int64 __fastcall wlan_hdd_wifi_pos_send_pasn_auth_status(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w0
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
  __int64 v37; // x20
  _BYTE *v38; // x0
  __int64 v39; // x20
  __int64 *v40[12]; // [xsp-240h] [xbp-430h] BYREF
  _QWORD v41[46]; // [xsp-1E0h] [xbp-3D0h] BYREF
  __int64 v42; // [xsp-70h] [xbp-260h]
  __int64 v43; // [xsp+10h] [xbp-1E0h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v40[0] = nullptr;
  result = _osif_vdev_sync_op_start(v8, v40, (__int64)"wlan_hdd_wifi_pos_send_pasn_auth_status");
  if ( (_DWORD)result )
    goto LABEL_9;
  if ( !a1 )
    JUMPOUT(0x5FEC78);
  v10 = *(_QWORD *)(a2 + 32);
  memset(v41, 0, sizeof(v41));
  memset(&v40[1], 0, 88);
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Command not allowed in FTM mode",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_hdd_cfg80211_send_pasn_auth_status");
    v19 = -1;
  }
  else
  {
    if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                          *(_BYTE *)(*(_QWORD *)(v10 + 55512) + 8LL),
                          (__int64)"wlan_hdd_cfg80211_send_pasn_auth_status",
                          v11,
                          v12,
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18) )
    {
      v19 = _wlan_hdd_validate_context(
              a1 + 1536,
              (__int64)"wlan_hdd_cfg80211_send_pasn_auth_status",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27);
      if ( v19 )
        goto LABEL_8;
      if ( (unsigned int)_nla_parse(v41, 45, a3, a4, &wifi_pos_pasn_auth_status_policy, 31, 0) )
      {
        v37 = jiffies;
        if ( wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid PASN auth status attributes",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "wlan_hdd_cfg80211_send_pasn_auth_status");
          wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks = v37;
          v19 = -22;
          goto LABEL_8;
        }
      }
      else
      {
        if ( v41[2] )
        {
          v38 = (_BYTE *)_qdf_mem_malloc(0x1204u, "wlan_hdd_cfg80211_send_pasn_auth_status", 146);
          if ( v38 )
          {
            *v38 = *(_BYTE *)(*(_QWORD *)(v10 + 55512) + 8LL);
            if ( (unsigned __int16)(*(_WORD *)v41[2] - 4) >= 4u )
              JUMPOUT(0x5FE8C4);
            JUMPOUT(0x5FEB44);
          }
          v19 = -12;
          goto LABEL_8;
        }
        v39 = jiffies;
        if ( wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks_2 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: No PASN peer",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "wlan_hdd_cfg80211_send_pasn_auth_status");
          wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks_2 = v39;
          v19 = -22;
          goto LABEL_8;
        }
      }
    }
    v19 = -22;
  }
LABEL_8:
  v28 = v19;
  _osif_vdev_sync_op_stop(v43, (__int64)"wlan_hdd_wifi_pos_send_pasn_auth_status");
  result = v28;
LABEL_9:
  if ( *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808) != v42 )
    JUMPOUT(0x5FEC70);
  return result;
}
