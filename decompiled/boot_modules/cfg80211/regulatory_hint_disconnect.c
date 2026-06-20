__int64 regulatory_hint_disconnect()
{
  __int64 result; // x0
  _QWORD *v1; // x0
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  _QWORD *v4; // x21
  __int64 v5; // x9
  __int64 *v6; // x8
  __int64 v7; // x21

  if ( (is_wiphy_all_set_reg_flag(16) & 1) == 0 )
    return restore_regulatory_settings(0, 1);
  result = is_wiphy_all_set_reg_flag(4);
  if ( (result & 1) == 0 )
  {
    raw_spin_lock_bh(&reg_pending_beacons_lock);
    v1 = reg_pending_beacons;
    if ( reg_pending_beacons != (_UNKNOWN *)&reg_pending_beacons )
    {
      do
      {
        v4 = (_QWORD *)*v1;
        v3 = (_QWORD *)v1[1];
        if ( (_QWORD *)*v3 == v1 && (_QWORD *)v4[1] == v1 )
        {
          v4[1] = v3;
          *v3 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
          v1 = v2;
        }
        *v1 = 0xDEAD000000000100LL;
        v1[1] = 0xDEAD000000000122LL;
        kfree(v1);
        v1 = v4;
      }
      while ( v4 != &reg_pending_beacons );
    }
    raw_spin_unlock_bh(&reg_pending_beacons_lock);
    result = (__int64)reg_beacon_list;
    if ( reg_beacon_list != (_UNKNOWN *)&reg_beacon_list )
    {
      do
      {
        v7 = *(_QWORD *)result;
        v6 = *(__int64 **)(result + 8);
        if ( *v6 == result && *(_QWORD *)(v7 + 8) == result )
        {
          *(_QWORD *)(v7 + 8) = v6;
          *v6 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(result);
          result = v5;
        }
        *(_QWORD *)result = 0xDEAD000000000100LL;
        *(_QWORD *)(result + 8) = 0xDEAD000000000122LL;
        kfree(result);
        result = v7;
      }
      while ( (_UNKNOWN **)v7 != &reg_beacon_list );
    }
  }
  return result;
}
