__int64 __fastcall coresight_grab_device(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v3; // x21
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v8; // x21
  __int64 v10; // x8
  __int64 v11; // x20

  v1 = *a1;
  if ( *(int *)(*a1 + 4LL) >= 1 )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 8 * v3) + 16LL);
      if ( v4 && *(_DWORD *)(v4 + 8) == 4 )
      {
        v5 = *(_QWORD *)(v4 + 152);
        if ( (try_module_get(*(_QWORD *)(*(_QWORD *)(v5 + 136) + 16LL)) & 1) == 0 )
          goto LABEL_11;
        get_device(v5);
        _pm_runtime_resume(v5, 4);
        v1 = *a1;
      }
      if ( ++v3 >= *(int *)(v1 + 4) )
        goto LABEL_9;
    }
  }
  LODWORD(v3) = 0;
LABEL_9:
  v6 = a1[19];
  if ( (try_module_get(*(_QWORD *)(*(_QWORD *)(v6 + 136) + 16LL)) & 1) != 0 )
  {
    get_device(v6);
    _pm_runtime_resume(v6, 4);
    return 0;
  }
  else
  {
LABEL_11:
    v8 = (unsigned int)(v3 - 1);
    if ( (int)v8 >= 0 )
    {
      do
      {
        v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*a1 + 8LL) + 8 * v8) + 16LL);
        if ( v10 )
        {
          if ( *(_DWORD *)(v10 + 8) == 4 )
          {
            v11 = *(_QWORD *)(v10 + 152);
            _pm_runtime_idle(v11, 4);
            put_device(v11);
            module_put(*(_QWORD *)(*(_QWORD *)(v11 + 136) + 16LL));
          }
        }
      }
      while ( v8-- > 0 );
    }
    return 4294967277LL;
  }
}
