__int64 __fastcall wlan_hdd_cfg80211_sched_scan_stop(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 driver_state; // x4
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD v47[2]; // [xsp+0h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v47, "wlan_hdd_cfg80211_sched_scan_stop");
  if ( !(_DWORD)result )
  {
    if ( (hdd_get_conparam() & 0xFFFFFFFE) == 4 )
    {
      v12 = jiffies;
      if ( _wlan_hdd_cfg80211_sched_scan_stop___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM/Monitor mode",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "__wlan_hdd_cfg80211_sched_scan_stop");
        _wlan_hdd_cfg80211_sched_scan_stop___last_ticks = v12;
      }
    }
    else
    {
      if ( (cds_get_driver_state(v4, v5, v6, v7, v8, v9, v10, v11) & 8) != 0
        || (cds_get_driver_state(v13, v14, v15, v16, v17, v18, v19, v20) & 0x10) != 0 )
      {
        driver_state = (unsigned int)cds_get_driver_state(v13, v14, v15, v16, v17, v18, v19, v20);
        v38 = "%s: Recovery in Progress. State: 0x%x Ignore!!!";
      }
      else
      {
        if ( (cds_get_driver_state(v13, v14, v15, v16, v17, v18, v19, v20) & 6) == 0 )
        {
          if ( !(unsigned int)_hdd_validate_adapter(
                                a2 + 2688,
                                (__int64)"__wlan_hdd_cfg80211_sched_scan_stop",
                                v21,
                                v22,
                                v23,
                                v24,
                                v25,
                                v26,
                                v27,
                                v28) )
          {
            if ( *(_DWORD *)(a2 + 2728) )
            {
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: Sched scans only supported on STA ifaces",
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                "__wlan_hdd_cfg80211_sched_scan_stop");
            }
            else if ( !(unsigned int)_wlan_hdd_validate_context(
                                       *(_QWORD *)(a2 + 2712),
                                       (__int64)"__wlan_hdd_cfg80211_sched_scan_stop",
                                       v39,
                                       v40,
                                       v41,
                                       v42,
                                       v43,
                                       v44,
                                       v45,
                                       v46) )
            {
              wlan_hdd_sched_scan_stop(a2);
            }
          }
          goto LABEL_11;
        }
        driver_state = (unsigned int)cds_get_driver_state(v21, v22, v23, v24, v25, v26, v27, v28);
        v38 = "%s: Unload/Load in Progress, state: 0x%x.  Ignore!!!";
      }
      qdf_trace_msg(
        0x33u,
        4u,
        v38,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "__wlan_hdd_cfg80211_sched_scan_stop",
        driver_state);
    }
LABEL_11:
    _osif_vdev_sync_op_stop(v47[0], "wlan_hdd_cfg80211_sched_scan_stop");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
