__int64 __fastcall cbo_notify(int a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  _QWORD *v6; // x8
  _QWORD *v7; // x21
  _QWORD *v8; // x8
  __int64 v9; // x20
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // x21
  int i; // w22
  __int64 v14; // x24
  unsigned __int64 v15; // x0

  v3 = *(_QWORD *)(a2 + 104);
  mutex_lock(&si_mutex);
  v6 = (_QWORD *)(v3 + 24);
  v7 = (_QWORD *)(v3 + 24);
  do
  {
    v7 = (_QWORD *)*v7;
    if ( v7 == v6 )
      return mutex_unlock(&si_mutex);
  }
  while ( *((_DWORD *)v7 - 13) != a1 );
  v8 = (_QWORD *)v7[1];
  v9 = (__int64)(v7 - 7);
  if ( (_QWORD *)*v8 == v7 && (v10 = *v7, *(_QWORD **)(*v7 + 8LL) == v7) )
  {
    *(_QWORD *)(v10 + 8) = v8;
    *v8 = v10;
  }
  else
  {
    _list_del_entry_valid_or_report(v7);
  }
  *v7 = v7;
  v7[1] = v7;
  result = mutex_unlock(&si_mutex);
  if ( v7 != qword_38 )
  {
    v12 = *(v7 - 4);
    for ( i = 0; ; ++i )
    {
      v14 = v12 + 24LL * i;
      if ( *(_DWORD *)v14 == 4 )
      {
        if ( a3 )
        {
          v15 = *(_QWORD *)(v14 + 8);
          if ( v15 < 2 || *(_DWORD *)(v15 + 12) != 1 )
            put_si_object(v15);
        }
        put_si_object(*(_QWORD *)(v14 + 8));
      }
      else if ( !*(_DWORD *)v14 )
      {
        return put_txn(v9);
      }
    }
  }
  return result;
}
