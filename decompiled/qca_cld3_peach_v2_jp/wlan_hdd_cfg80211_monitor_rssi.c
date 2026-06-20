void __fastcall wlan_hdd_cfg80211_monitor_rssi(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22[2]; // [xsp+8h] [xbp-58h] BYREF
  int v23; // [xsp+18h] [xbp-48h]
  __int64 v24; // [xsp+20h] [xbp-40h]
  __int64 v25; // [xsp+28h] [xbp-38h]
  __int64 v26; // [xsp+30h] [xbp-30h]
  __int64 v27; // [xsp+38h] [xbp-28h]
  __int64 v28; // [xsp+40h] [xbp-20h]
  __int64 v29; // [xsp+48h] [xbp-18h]
  __int64 v30; // [xsp+50h] [xbp-10h]
  __int64 v31; // [xsp+58h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 32);
  v22[0] = nullptr;
  if ( !(unsigned int)_osif_vdev_sync_op_start(v4, v22, (__int64)"wlan_hdd_cfg80211_monitor_rssi") )
  {
    if ( a1 )
    {
      v13 = *(_QWORD *)(a2 + 32) + 296LL;
      v29 = 0;
      v30 = 0;
      v27 = 0;
      v28 = 0;
      v25 = 0;
      v26 = 0;
      v24 = 0;
      v23 = 0;
      v22[1] = nullptr;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: enter(%s)",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "__wlan_hdd_cfg80211_monitor_rssi",
        v13);
      if ( (unsigned int)hdd_get_conparam() == 5 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM mode",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "__wlan_hdd_cfg80211_monitor_rssi");
        JUMPOUT(0x5535C8);
      }
      JUMPOUT(0x553530);
    }
    __break(0x800u);
    JUMPOUT(0x55378C);
  }
  JUMPOUT(0x5535E4);
}
