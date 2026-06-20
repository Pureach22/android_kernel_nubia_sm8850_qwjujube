__int64 __fastcall ipc_log_context_free(__int64 a1)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x19
  __int64 v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x0
  _QWORD *v6; // x9
  __int64 *v7; // x8
  __int64 v8; // x10
  _QWORD *v9; // x9

  v2 = (_QWORD *)(a1 - 128);
  v1 = *(_QWORD **)(a1 - 128);
  v3 = a1 - 200;
  if ( v1 != (_QWORD *)(a1 - 128) )
  {
    do
    {
      v4 = v1 - 6;
      if ( v3 )
        v5 = v4;
      else
        v5 = nullptr;
      v6 = (_QWORD *)v5[7];
      v7 = v5 + 6;
      if ( (_QWORD *)*v6 == v5 + 6 && (v8 = *v7, *(__int64 **)(*v7 + 8) == v7) )
      {
        *(_QWORD *)(v8 + 8) = v6;
        *v6 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v5 + 6);
        v5 = v9;
      }
      v5[6] = 0xDEAD000000000100LL;
      v5[7] = 0xDEAD000000000122LL;
      kfree(v5);
      v1 = (_QWORD *)*v2;
    }
    while ( (_QWORD *)*v2 != v2 );
  }
  return kfree(v3);
}
