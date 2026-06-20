__int64 __fastcall altmode_deregister_client(__int64 a1)
{
  unsigned __int64 v1; // x20
  unsigned __int64 *v3; // x9
  unsigned __int64 *v4; // x10
  unsigned __int64 v5; // x11
  unsigned __int64 *v7; // x12
  unsigned __int64 **v8; // x8

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    return 4294967277LL;
  cancel_work_sync(a1 + 64);
  mutex_lock(v1 + 40);
  idr_remove(v1 + 16, *(unsigned __int8 *)(a1 + 56) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 8) << 8));
  v4 = (unsigned __int64 *)(v1 + 104);
  v3 = *(unsigned __int64 **)(v1 + 104);
  if ( v3 != (unsigned __int64 *)(v1 + 104) )
  {
    v5 = 0xDEAD000000000100LL;
    do
    {
      v7 = (unsigned __int64 *)*v3;
      if ( v3 - 5 == (unsigned __int64 *)a1 )
      {
        v8 = (unsigned __int64 **)v3[1];
        if ( *v8 == v3 && (unsigned __int64 *)v7[1] == v3 )
        {
          v7[1] = (unsigned __int64)v8;
          *v8 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
        }
        *v3 = v5;
        v3[1] = v5 + 34;
      }
      v3 = v7;
    }
    while ( v7 != v4 );
  }
  mutex_unlock(v1 + 40);
  kfree(*(_QWORD *)(a1 + 16));
  kfree(a1);
  return 0;
}
