__int64 __fastcall dynamic_replicator_remove(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x9
  _QWORD *v4; // x8
  __int64 *v5; // x0
  __int64 v6; // x10
  __int64 result; // x0
  _QWORD *v8; // x8
  __int64 *v9; // x0
  __int64 v10; // x9

  v2 = *(_QWORD *)(a1 + 152);
  raw_spin_lock(&delay_lock);
  v3 = *(_QWORD *)(v2 + 40);
  if ( v3 )
  {
    v4 = *(_QWORD **)(v3 + 24);
    v5 = (__int64 *)(v3 + 16);
    if ( *v4 == v3 + 16 && (v6 = *v5, *(__int64 **)(*v5 + 8) == v5) )
    {
      *(_QWORD *)(v6 + 8) = v4;
      *v4 = v6;
    }
    else
    {
      _list_del_entry_valid_or_report(v5);
    }
    *(_QWORD *)(v3 + 16) = 0xDEAD000000000100LL;
    *(_QWORD *)(v3 + 24) = 0xDEAD000000000122LL;
    return raw_spin_unlock(&delay_lock);
  }
  else
  {
    if ( *(_BYTE *)(v2 + 89) == 1 )
    {
      v8 = *(_QWORD **)(v2 + 104);
      v9 = (__int64 *)(v2 + 96);
      if ( *v8 == v2 + 96 && (v10 = *v9, *(__int64 **)(*v9 + 8) == v9) )
      {
        *(_QWORD *)(v10 + 8) = v8;
        *v8 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *(_QWORD *)(v2 + 96) = 0xDEAD000000000100LL;
      *(_QWORD *)(v2 + 104) = 0xDEAD000000000122LL;
    }
    raw_spin_unlock(&delay_lock);
    result = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 24LL);
    if ( result )
      return coresight_unregister();
  }
  return result;
}
