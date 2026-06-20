__int64 __fastcall wlan_hdd_cfg80211_dump_survey(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w0
  __int64 *v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  unsigned int v28; // w1
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w19
  _QWORD v38[2]; // [xsp+0h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v38, "wlan_hdd_cfg80211_dump_survey");
  if ( !(_DWORD)result )
  {
    if ( a3 > 101 )
    {
      v17 = -2;
      goto LABEL_17;
    }
    v18 = *(__int64 **)(a2 + 2712);
    v17 = _wlan_hdd_validate_context(
            (__int64)v18,
            (__int64)"__wlan_hdd_cfg80211_dump_survey",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16);
    if ( v17 )
      goto LABEL_17;
    if ( v18[217] )
    {
      if ( (unsigned int)hdd_get_conparam() != 5 )
      {
        if ( (wlan_scan_is_snr_monitor_enabled(*v18) & 1) != 0 )
        {
          if ( !hdd_cm_is_vdev_roaming(*(_QWORD *)(a2 + 55520)) )
          {
            if ( (wlan_hdd_update_survey_info(a1, a2 + 2688, a4, (unsigned int)a3) & 1) != 0 )
              v17 = 0;
            else
              v17 = -2;
            goto LABEL_17;
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Roaming in progress, hence return",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "__wlan_hdd_cfg80211_dump_survey");
        }
        v17 = -64;
LABEL_17:
        v37 = v17;
        _osif_vdev_sync_op_stop(v38[0], "wlan_hdd_cfg80211_dump_survey");
        result = v37;
        goto LABEL_18;
      }
      v27 = "%s: Command not allowed in FTM mode";
      v28 = 2;
    }
    else
    {
      v27 = "%s: chan_info is NULL";
      v28 = 8;
    }
    qdf_trace_msg(0x33u, v28, v27, v19, v20, v21, v22, v23, v24, v25, v26, "__wlan_hdd_cfg80211_dump_survey");
    v17 = -22;
    goto LABEL_17;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
