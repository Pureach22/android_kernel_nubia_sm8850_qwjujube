__int64 __fastcall _tmc_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x9
  _QWORD *v3; // x8
  __int64 *v4; // x0
  __int64 v5; // x10
  __int64 result; // x0
  _QWORD *v7; // x8
  __int64 *v8; // x0
  __int64 v9; // x9
  __int64 v10; // x0

  v1 = *(_QWORD *)(a1 + 152);
  raw_spin_lock(&delay_lock);
  v2 = *(_QWORD *)(v1 + 352);
  if ( v2 )
  {
    v3 = *(_QWORD **)(v2 + 24);
    v4 = (__int64 *)(v2 + 16);
    if ( *v3 == v2 + 16 && (v5 = *v4, *(__int64 **)(*v4 + 8) == v4) )
    {
      *(_QWORD *)(v5 + 8) = v3;
      *v3 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v4);
    }
    *(_QWORD *)(v2 + 16) = 0xDEAD000000000100LL;
    *(_QWORD *)(v2 + 24) = 0xDEAD000000000122LL;
    return raw_spin_unlock(&delay_lock);
  }
  else
  {
    if ( *(_BYTE *)(v1 + 409) == 1 )
    {
      v7 = *(_QWORD **)(v1 + 424);
      v8 = (__int64 *)(v1 + 416);
      if ( *v7 == v1 + 416 && (v9 = *v8, *(__int64 **)(*v8 + 8) == v8) )
      {
        *(_QWORD *)(v9 + 8) = v7;
        *v7 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *(_QWORD *)(v1 + 416) = 0xDEAD000000000100LL;
      *(_QWORD *)(v1 + 424) = 0xDEAD000000000122LL;
    }
    result = raw_spin_unlock(&delay_lock);
    if ( *(_QWORD *)(v1 + 16) )
    {
      if ( *(_DWORD *)(v1 + 140) == 1 )
      {
        v10 = *(_QWORD *)(v1 + 304);
        if ( v10 )
          byte_cntr_remove(v10);
      }
      misc_deregister(v1 + 24);
      return coresight_unregister(*(_QWORD *)(v1 + 16));
    }
  }
  return result;
}
