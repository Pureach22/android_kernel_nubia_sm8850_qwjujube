void __fastcall wlan_hdd_cfg80211_handle_wisa_cmd(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // [xsp+8h] [xbp-28h] BYREF
  __int16 v13; // [xsp+14h] [xbp-1Ch]
  __int64 v14; // [xsp+18h] [xbp-18h]
  __int64 v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v12 = 0;
  if ( !(unsigned int)_osif_vdev_sync_op_start(v3, &v12, "wlan_hdd_cfg80211_handle_wisa_cmd") )
  {
    if ( a1 )
    {
      v14 = 0;
      v15 = 0;
      v13 = 0;
      _cds_get_context(71, (__int64)"__wlan_hdd_cfg80211_handle_wisa_cmd", v4, v5, v6, v7, v8, v9, v10, v11);
      JUMPOUT(0x2DF110);
    }
    __break(0x800u);
    JUMPOUT(0x2DF334);
  }
  JUMPOUT(0x2DF174);
}
