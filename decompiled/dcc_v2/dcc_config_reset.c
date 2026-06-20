__int64 __fastcall dcc_config_reset(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x10
  int v4; // w11
  _QWORD **v5; // x12
  __int64 v6; // x21
  _QWORD *v7; // x9
  _QWORD *v8; // x8
  _QWORD *v9; // x22

  mutex_lock(a1 + 24);
  v2 = *(_DWORD *)(a1 + 328);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 + 312);
    v4 = 0;
    do
    {
      v5 = (_QWORD **)(v3 + 16LL * v4);
      v6 = v4;
      v7 = *v5;
      if ( *v5 != v5 )
      {
        do
        {
          v9 = (_QWORD *)*v7;
          v8 = (_QWORD *)v7[1];
          if ( (_QWORD *)*v8 == v7 && (_QWORD *)v9[1] == v7 )
          {
            v9[1] = v8;
            *v8 = v9;
          }
          else
          {
            _list_del_entry_valid_or_report(v7);
          }
          *v7 = 0xDEAD000000000100LL;
          v7[1] = 0xDEAD000000000122LL;
          kfree(v7 - 5);
          --*(_DWORD *)(*(_QWORD *)(a1 + 320) + 4 * v6);
          v3 = *(_QWORD *)(a1 + 312);
          v7 = v9;
        }
        while ( v9 != (_QWORD *)(v3 + 16 * v6) );
        v2 = *(_DWORD *)(a1 + 328);
      }
      v4 = v6 + 1;
    }
    while ( (int)v6 + 1 < v2 );
  }
  *(_QWORD *)(a1 + 108) = 0;
  *(_DWORD *)(a1 + 348) = 0;
  return mutex_unlock(a1 + 24);
}
