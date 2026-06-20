__int64 __fastcall wlan_hdd_get_big_data_station_stats(_DWORD *a1)
{
  __int64 vdev_by_user; // x0
  __int64 v3; // x19
  _DWORD *big_data_stats; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x8
  __int64 result; // x0
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user((__int64)a1, 0x51u, (__int64)"wlan_hdd_get_big_data_station_stats");
  if ( vdev_by_user )
  {
    v3 = vdev_by_user;
    big_data_stats = (_DWORD *)wlan_cfg80211_mc_cp_get_big_data_stats(vdev_by_user, &v15);
    v13 = (unsigned int *)v15;
    if ( v15 || !big_data_stats )
    {
      if ( !big_data_stats )
      {
LABEL_8:
        _hdd_objmgr_put_vdev_by_user(
          v3,
          0x51u,
          (__int64)"wlan_hdd_get_big_data_station_stats",
          v13,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12);
        result = v15;
        goto LABEL_9;
      }
    }
    else
    {
      a1[1160] = *big_data_stats;
      a1[1161] = big_data_stats[1];
      a1[1162] = big_data_stats[2];
      a1[1163] = big_data_stats[3];
      a1[1164] = big_data_stats[4];
      a1[1165] = big_data_stats[5];
      a1[1166] = big_data_stats[6];
      a1[1167] = big_data_stats[7];
    }
    v5 = wlan_cfg80211_mc_cp_stats_free_big_data_stats_event();
    goto LABEL_8;
  }
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
