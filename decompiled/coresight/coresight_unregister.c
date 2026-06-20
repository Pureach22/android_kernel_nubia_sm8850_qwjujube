__int64 __fastcall coresight_unregister(__int64 *a1)
{
  void (__fastcall *v2)(_QWORD); // x8
  _DWORD *v3; // x2
  __int64 v4; // x20
  _QWORD *v5; // x21
  unsigned __int64 v6; // x0
  __int64 v7; // x8
  void (*v8)(void); // x8
  unsigned int **v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  _QWORD *v12; // x9
  int v13; // w8
  __int64 v14; // x21
  __int64 v15; // x20

  etm_perf_del_symlink_sink();
  if ( cti_assoc_ops )
  {
    v2 = *(void (__fastcall **)(_QWORD))(cti_assoc_ops + 8);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 538919244 )
        __break(0x8228u);
      v2(a1);
    }
  }
  if ( a1 && *((_DWORD *)a1 + 2) == 3 )
    bus_for_each_dev(&coresight_bustype, 0, a1, coresight_clear_filter_source);
  v3 = (_DWORD *)*a1;
  if ( *(int *)(*a1 + 4) >= 1 )
  {
    v4 = 0;
    do
    {
      v5 = *(_QWORD **)(*((_QWORD *)v3 + 1) + 8 * v4);
      v6 = v5[5];
      if ( v6 )
      {
        v5[6] = 0;
        if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        {
          v7 = *(_QWORD *)(v6 + 8);
          if ( v7 )
          {
            v8 = *(void (**)(void))(v7 + 8);
            if ( v8 )
            {
              if ( *((_DWORD *)v8 - 1) != -643302289 )
                __break(0x8228u);
              v8();
            }
          }
        }
      }
      v9 = (unsigned int **)v5[2];
      if ( v9 )
      {
        v10 = (__int64)*v9;
        v11 = **v9;
        if ( (int)v11 >= 1 )
        {
          v12 = *(_QWORD **)(v10 + 16);
          while ( (_QWORD *)*v12 != v5 )
          {
            --v11;
            ++v12;
            if ( !v11 )
              goto LABEL_12;
          }
          *v12 = 0;
        }
      }
LABEL_12:
      v3 = (_DWORD *)*a1;
      ++v4;
    }
    while ( v4 < *(int *)(*a1 + 4) );
  }
  v13 = *v3;
  if ( (int)*v3 >= 1 )
  {
    v14 = 0;
    do
    {
      v15 = *(_QWORD *)(*((_QWORD *)v3 + 2) + 8 * v14);
      if ( v15 )
      {
        *(_BYTE *)(*(_QWORD *)(v15 + 32) + 980LL) = 1;
        coresight_remove_links(*(_QWORD *)(v15 + 32));
        *(_QWORD *)(v15 + 16) = 0;
        v3 = (_DWORD *)*a1;
        v13 = *(_DWORD *)*a1;
      }
      ++v14;
    }
    while ( v14 < v13 );
  }
  if ( (*((_DWORD *)a1 + 2) | 2) == 2 )
  {
    bus_for_each_dev(&coresight_bustype, 0, a1, coresight_remove_sink_ref);
    v3 = (_DWORD *)*a1;
  }
  coresight_release_platform_data((__int64)a1, a1[19], (__int64)v3);
  return device_unregister(a1 + 7);
}
