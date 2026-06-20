__int64 __fastcall wlan_hdd_cfg80211_sched_scan_start(__int64 a1, __int64 a2, __int64 a3)
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
  __int64 v14; // x20
  int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 *v27; // x21
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 vdev_by_user; // x0
  __int64 v37; // x20
  char scan_backoff_multiplier; // w0
  int v39; // w19
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _QWORD v49[2]; // [xsp+0h] [xbp-10h] BYREF

  v49[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v49, "wlan_hdd_cfg80211_sched_scan_start");
  if ( !(_DWORD)result )
  {
    if ( (hdd_get_conparam() & 0xFFFFFFFE) == 4 )
    {
      v14 = jiffies;
      if ( _wlan_hdd_cfg80211_sched_scan_start___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM/Monitor mode",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "__wlan_hdd_cfg80211_sched_scan_start");
        _wlan_hdd_cfg80211_sched_scan_start___last_ticks = v14;
        v15 = -22;
LABEL_7:
        v24 = v15;
        _osif_vdev_sync_op_stop(v49[0], "wlan_hdd_cfg80211_sched_scan_start");
        result = v24;
        goto LABEL_8;
      }
    }
    else if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                               *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 8LL),
                               (__int64)"__wlan_hdd_cfg80211_sched_scan_start",
                               v6,
                               v7,
                               v8,
                               v9,
                               v10,
                               v11,
                               v12,
                               v13) )
    {
      if ( *(_DWORD *)(a2 + 2728) )
      {
        v25 = "%s: Sched scans only supported on STA ifaces";
        v26 = 4;
      }
      else
      {
        v27 = *(__int64 **)(a2 + 2712);
        v15 = _wlan_hdd_validate_context(
                (__int64)v27,
                (__int64)"__wlan_hdd_cfg80211_sched_scan_start",
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23);
        if ( v15 )
          goto LABEL_7;
        if ( (ucfg_scan_is_pno_offload_enabled(*v27) & 1) != 0 )
        {
          if ( (ucfg_scan_is_connected_scan_enabled(*v27) & 1) == 0
            && hdd_cm_is_vdev_associated(*(_DWORD **)(a2 + 55520)) )
          {
            qdf_trace_msg(
              0x33u,
              4u,
              "%s: enable_connected_scan is false, Aborting scan",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "__wlan_hdd_cfg80211_sched_scan_start");
            v15 = -16;
            goto LABEL_7;
          }
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                           *(_QWORD *)(a2 + 55520),
                           0x4Fu,
                           (__int64)"__wlan_hdd_cfg80211_sched_scan_start");
          if ( vdev_by_user )
          {
            v37 = vdev_by_user;
            scan_backoff_multiplier = ucfg_get_scan_backoff_multiplier(*v27);
            v39 = wlan_cfg80211_sched_scan_start(v37, a3, scan_backoff_multiplier);
            _hdd_objmgr_put_vdev_by_user(
              v37,
              0x4Fu,
              (__int64)"__wlan_hdd_cfg80211_sched_scan_start",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48);
            v15 = v39;
            goto LABEL_7;
          }
          goto LABEL_6;
        }
        v25 = "%s: Pno Offload is not enabled";
        v26 = 8;
      }
      qdf_trace_msg(0x33u, v26, v25, v16, v17, v18, v19, v20, v21, v22, v23, "__wlan_hdd_cfg80211_sched_scan_start");
      v15 = -22;
      goto LABEL_7;
    }
LABEL_6:
    v15 = -22;
    goto LABEL_7;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
