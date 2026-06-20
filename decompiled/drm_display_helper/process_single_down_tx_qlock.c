__int64 __fastcall process_single_down_tx_qlock(__int64 a1)
{
  __int64 result; // x0
  __int64 *v3; // x20
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 **v6; // x8
  __int64 *v7; // x9

  result = mutex_is_locked(a1 + 936);
  if ( (result & 1) == 0 )
    __break(0x800u);
  v3 = *(__int64 **)(a1 + 984);
  if ( v3 != (__int64 *)(a1 + 984) )
  {
    result = process_single_tx_qlock(a1, v3 - 40, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v4 = *(_QWORD *)(a1 + 104);
      if ( v4 )
        v5 = *(_QWORD *)(v4 + 8);
      else
        v5 = 0;
      _drm_dev_dbg(0, v5, 2, "failed to send msg in q %d\n", result);
      v6 = (__int64 **)v3[1];
      if ( *v6 == v3 && (v7 = (__int64 *)*v3, *(__int64 **)(*v3 + 8) == v3) )
      {
        v7[1] = (__int64)v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      *((_DWORD *)v3 + 5) = 4;
      return _wake_up(a1 + 1000, 3, 0, 0);
    }
  }
  return result;
}
