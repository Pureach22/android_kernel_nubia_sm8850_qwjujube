__int64 __fastcall swr_unregister_master(__int64 a1)
{
  __int64 v2; // x21
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  _QWORD *v6; // x9

  mutex_lock(&swr_lock);
  v2 = idr_find(&master_idr, *(unsigned int *)(a1 + 928));
  result = mutex_unlock(&swr_lock);
  if ( v2 == a1 )
  {
    mutex_lock(&board_lock);
    v4 = *(_QWORD *)(a1 + 912);
    v5 = a1 + 912;
    if ( v4 != a1 + 912 )
    {
      v6 = *(_QWORD **)(a1 + 920);
      if ( *v6 == v5 && *(_QWORD *)(v4 + 8) == v5 )
      {
        *(_QWORD *)(v4 + 8) = v6;
        *v6 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      *(_QWORD *)(a1 + 912) = 0xDEAD000000000100LL;
      *(_QWORD *)(a1 + 920) = 0xDEAD000000000122LL;
    }
    mutex_unlock(&board_lock);
    mutex_lock(&swr_lock);
    idr_remove(&master_idr, *(unsigned int *)(a1 + 928));
    mutex_unlock(&swr_lock);
    device_for_each_child(a1, 0, _unregister);
    return device_unregister(a1);
  }
  return result;
}
