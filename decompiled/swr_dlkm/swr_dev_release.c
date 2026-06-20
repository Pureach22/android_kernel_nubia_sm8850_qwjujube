__int64 __fastcall swr_dev_release(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x0

  if ( result )
  {
    v1 = result;
    v2 = result - 72;
    if ( result != 72 )
    {
      v3 = *(_QWORD *)(result - 40);
      if ( v3 )
      {
        mutex_lock(v3 + 936);
        v4 = *(_QWORD **)(v1 - 16);
        v5 = v1 - 24;
        if ( *v4 == v1 - 24 && (v6 = *(_QWORD *)v5, *(_QWORD *)(*(_QWORD *)v5 + 8LL) == v5) )
        {
          *(_QWORD *)(v6 + 8) = v4;
          *v4 = v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v1 - 24);
        }
        *(_QWORD *)(v1 - 24) = v5;
        *(_QWORD *)(v1 - 16) = v5;
        mutex_unlock(v3 + 936);
        v7 = *(_QWORD *)(v1 - 40);
        if ( v7 )
          put_device(v7);
        return kfree(v2);
      }
    }
  }
  return result;
}
