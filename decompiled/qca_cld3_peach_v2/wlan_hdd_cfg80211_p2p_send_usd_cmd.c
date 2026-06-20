__int64 __fastcall wlan_hdd_cfg80211_p2p_send_usd_cmd(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w0
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 *v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  _QWORD v38[2]; // [xsp+0h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 32);
  v38[0] = 0;
  result = _osif_vdev_sync_op_start(v7, v38, "wlan_hdd_cfg80211_p2p_send_usd_cmd");
  if ( !(_DWORD)result )
  {
    v9 = *(_QWORD *)(a2 + 32);
    if ( (unsigned int)hdd_get_conparam() == 5 || (unsigned int)hdd_get_conparam() == 4 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM/Monitor mode",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "__wlan_hdd_cfg80211_p2p_send_usd_cmd");
      v18 = -1;
    }
    else
    {
      v18 = _hdd_validate_adapter(
              v9 + 2688,
              (__int64)"__wlan_hdd_cfg80211_p2p_send_usd_cmd",
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17);
      if ( !v18 )
      {
        v28 = *(__int64 **)(v9 + 2712);
        v18 = _wlan_hdd_validate_context(
                (__int64)v28,
                (__int64)"__wlan_hdd_cfg80211_p2p_send_usd_cmd",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27);
        if ( !v18 )
        {
          v37 = *v28;
          if ( *v28 )
          {
            v28[1061] = v9 + 2688;
            v18 = osif_p2p_send_usd_params(v37, *(unsigned __int8 *)(*(_QWORD *)(v9 + 55520) + 8LL), a3, a4);
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: psoc is null",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "__wlan_hdd_cfg80211_p2p_send_usd_cmd");
            v18 = -22;
          }
        }
      }
    }
    v19 = v18;
    _osif_vdev_sync_op_stop(v38[0], "wlan_hdd_cfg80211_p2p_send_usd_cmd");
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
