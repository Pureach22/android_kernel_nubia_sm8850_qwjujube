__int64 __fastcall coresight_release_path(_QWORD **a1)
{
  _QWORD *v1; // x20
  _QWORD *v3; // x24
  _QWORD *v4; // x25
  __int64 v5; // x22
  __int64 v6; // x8
  __int64 v7; // x26
  __int64 v8; // x9
  __int64 v9; // x22
  _QWORD *v10; // x8
  _QWORD *v11; // x9

  v1 = *a1;
  if ( *a1 != a1 )
  {
    do
    {
      v3 = (_QWORD *)*v1;
      v4 = (_QWORD *)*(v1 - 1);
      v5 = v4[19];
      _pm_runtime_idle(v5, 4);
      put_device(v5);
      module_put(*(_QWORD *)(*(_QWORD *)(v5 + 136) + 16LL));
      v6 = *v4;
      if ( *(int *)(*v4 + 4LL) >= 1 )
      {
        v7 = 0;
        do
        {
          v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 8 * v7) + 16LL);
          if ( v8 && *(_DWORD *)(v8 + 8) == 4 )
          {
            v9 = *(_QWORD *)(v8 + 152);
            _pm_runtime_idle(v9, 4);
            put_device(v9);
            module_put(*(_QWORD *)(*(_QWORD *)(v9 + 136) + 16LL));
            v6 = *v4;
          }
          ++v7;
        }
        while ( v7 < *(int *)(v6 + 4) );
      }
      v10 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v10 == v1 && (v11 = (_QWORD *)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        v11[1] = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      kfree(v1 - 1);
      v1 = v3;
    }
    while ( v3 != a1 );
  }
  return kfree(a1);
}
