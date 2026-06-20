__int64 regulatory_exit()
{
  __int64 v0; // x0
  __int64 v1; // x0
  _QWORD *v2; // x0
  _QWORD *v3; // x8
  _QWORD *v4; // x21
  _QWORD *v5; // x9
  _QWORD *v6; // x0
  _QWORD *v7; // x8
  _QWORD *v8; // x21
  _QWORD *v9; // x9
  _QWORD *v10; // x9
  _QWORD *v11; // x8
  _QWORD *v12; // x21

  cancel_work_sync(&reg_work);
  v0 = cancel_delayed_work_sync(&reg_check_chans);
  rtnl_lock(v0);
  v1 = reset_regdomains(1, 0);
  rtnl_unlock(v1);
  *(_BYTE *)(reg_pdev + 76) |= 0x10u;
  platform_device_unregister();
  v2 = reg_pending_beacons;
  if ( reg_pending_beacons != (_UNKNOWN *)&reg_pending_beacons )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      v3 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v3 == v2 && (_QWORD *)v4[1] == v2 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
        v2 = v5;
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      kfree(v2);
      v2 = v4;
    }
    while ( v4 != &reg_pending_beacons );
  }
  v6 = reg_beacon_list;
  if ( reg_beacon_list != (_UNKNOWN *)&reg_beacon_list )
  {
    do
    {
      v8 = (_QWORD *)*v6;
      v7 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v7 == v6 && (_QWORD *)v8[1] == v6 )
      {
        v8[1] = v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
        v6 = v9;
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      kfree(v6);
      v6 = v8;
    }
    while ( v8 != &reg_beacon_list );
  }
  v10 = reg_requests_list;
  if ( reg_requests_list != (_UNKNOWN *)&reg_requests_list )
  {
    do
    {
      v12 = (_QWORD *)*v10;
      v11 = (_QWORD *)v10[1];
      if ( (_QWORD *)*v11 == v10 && (_QWORD *)v12[1] == v10 )
      {
        v12[1] = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
      }
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      kfree(v10 - 6);
      v10 = v12;
    }
    while ( v12 != &reg_requests_list );
  }
  if ( regdb && (unsigned __int64)regdb <= 0xFFFFFFFFFFFFF000LL )
    kfree(regdb);
  if ( cfg80211_user_regdom && (unsigned __int64)cfg80211_user_regdom <= 0xFFFFFFFFFFFFF000LL )
    kfree(cfg80211_user_regdom);
  return key_put(builtin_regdb_keys);
}
