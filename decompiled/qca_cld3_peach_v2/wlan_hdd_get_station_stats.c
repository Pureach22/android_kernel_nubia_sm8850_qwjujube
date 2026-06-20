__int64 __fastcall wlan_hdd_get_station_stats(_QWORD *a1)
{
  __int64 vdev_by_user; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 result; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *station_stats; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD *v33; // x20
  __int64 v34; // x9
  __int64 v35; // x22
  const char *v36; // x5
  const char *v37; // x4
  const char *v38; // x6
  const char *v39; // x7
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user((__int64)a1, 0x51u, (__int64)"wlan_hdd_get_station_stats");
  if ( vdev_by_user )
  {
    v11 = vdev_by_user;
    if ( (get_station_fw_request_needed & 1) != 0
      || ((v12 = *(_QWORD *)(vdev_by_user + 216)) == 0 ? (v13 = 0) : (v13 = *(_QWORD *)(v12 + 80)),
          (ucfg_mc_cp_stats_is_req_pending(v13, 1) & 1) != 0) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: return cached get_station stats",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "wlan_hdd_get_station_stats");
      _hdd_objmgr_put_vdev_by_user(
        v11,
        0x51u,
        (__int64)"wlan_hdd_get_station_stats",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23);
      result = 0;
      goto LABEL_31;
    }
    station_stats = (_QWORD *)wlan_cfg80211_mc_cp_stats_get_station_stats(v11, &v49);
    v33 = station_stats;
    if ( !v49 && station_stats )
    {
      v34 = station_stats[16];
      if ( station_stats[12] )
      {
        if ( v34 )
        {
          if ( station_stats[7] && station_stats[1] )
          {
            v35 = *a1;
            *(_DWORD *)(v35 + 1656) = jiffies_to_msecs(jiffies);
            hdd_update_link_state_cached_timestamp(*a1);
            copy_station_stats_to_adapter(a1, v33);
LABEL_30:
            wlan_cfg80211_mc_cp_stats_free_stats_event(v33);
            _hdd_objmgr_put_vdev_by_user(
              v11,
              0x51u,
              (__int64)"wlan_hdd_get_station_stats",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48);
            result = v49;
            goto LABEL_31;
          }
          v36 = (const char *)&unk_98C763;
          v37 = (const char *)&unk_98C763;
        }
        else
        {
          v37 = (const char *)&unk_98C763;
          v36 = " vdev_chain_rssi";
        }
      }
      else
      {
        if ( v34 )
          v36 = (const char *)&unk_98C763;
        else
          v36 = " vdev_chain_rssi";
        v37 = " vdev_summary_stats";
      }
      if ( station_stats[7] )
        v38 = (const char *)&unk_98C763;
      else
        v38 = " peer_adv_stats";
      if ( station_stats[1] )
        v39 = (const char *)&unk_98C763;
      else
        v39 = " pdev_stats";
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid:%s%s%s%s",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_hdd_get_station_stats",
        v37,
        v36,
        v38,
        v39);
      v49 = -22;
      goto LABEL_30;
    }
    qdf_trace_msg(0x33u, 2u, "%s: Invalid stats", v25, v26, v27, v28, v29, v30, v31, v32, "wlan_hdd_get_station_stats");
    goto LABEL_30;
  }
  result = 4294967274LL;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
