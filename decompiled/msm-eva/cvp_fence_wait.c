__int64 __fastcall cvp_fence_wait(__int64 result, __int64 **a2, _DWORD *a3)
{
  __int64 v4; // x19
  int v6; // w8
  __int64 *v7; // x21
  __int64 **v8; // x8
  __int64 *v9; // x9
  __int64 v10; // x2
  __int64 *v11; // x1

  if ( result )
  {
    v4 = result;
    *a2 = nullptr;
    while ( !(unsigned int)mutex_trylock(v4) )
      usleep_range_state(100, 200, 2);
    v6 = *(_DWORD *)(v4 + 48);
    *a3 = v6;
    if ( v6 == 2 )
    {
      v7 = *(__int64 **)(v4 + 56);
      if ( v7 == (__int64 *)(v4 + 56) )
      {
        mutex_unlock(v4);
        return 0;
      }
      v8 = (__int64 **)v7[1];
      if ( *v8 == v7 && (v9 = (__int64 *)*v7, *(__int64 **)(*v7 + 8) == v7) )
      {
        v9[1] = (__int64)v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v4 + 56));
      }
      *v7 = (__int64)v7;
      v10 = v4 + 96;
      v7[1] = (__int64)v7;
      v11 = *(__int64 **)(v4 + 104);
      if ( v7 == (__int64 *)(v4 + 96) || v11 == v7 || *v11 != v10 )
      {
        _list_add_valid_or_report(v7, v11, v10);
      }
      else
      {
        *(_QWORD *)(v4 + 104) = v7;
        *v7 = v10;
        v7[1] = (__int64)v11;
        *v11 = (__int64)v7;
      }
      mutex_unlock(v4);
      *a2 = v7;
    }
    else
    {
      mutex_unlock(v4);
    }
    return 1;
  }
  return result;
}
