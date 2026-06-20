__int64 __fastcall geni_i3c_master_attach_i3c_dev(_QWORD *a1)
{
  __int64 v1; // x22
  __int64 v3; // x21
  unsigned __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x9
  __int64 v7; // x20
  __int64 result; // x0
  __int64 v9; // x0
  _QWORD *v10; // x8
  __int64 v11; // x10

  v1 = a1[2];
  v3 = *(_QWORD *)(v1 + 2424);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_attach_i3c_dev", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  v5 = devm_kmalloc(*(_QWORD *)(v1 - 104), 16, 3520);
  if ( v5 )
  {
    v6 = a1[15];
    a1[3] = v5;
    *(_WORD *)(v5 + 2) = -1;
    if ( !v6 )
    {
      v10 = *(_QWORD **)(v1 + 2176);
      if ( v10 != (_QWORD *)(v1 + 2176) )
      {
        v11 = a1[4];
        do
        {
          if ( v11 == v10[3] )
            a1[15] = v10;
          v10 = (_QWORD *)*v10;
        }
        while ( v10 != (_QWORD *)(v1 + 2176) );
      }
    }
    ipc_log_string(*(_QWORD *)(v1 + 2416), "%s %d\n", "geni_i3c_master_attach_i3c_dev", 1);
    if ( *(_QWORD *)(v1 - 104) )
      i3c_trace_log();
    v7 = *(_QWORD *)(v1 + 2424);
    if ( !v7 )
      return 0;
    result = 0;
    if ( v4 && *(_DWORD *)(v1 + 2432) )
    {
      v9 = sched_clock(0);
      ipc_log_string(v7, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_master_attach_i3c_dev", v9 - v4, (v9 - v4) / 0x3E8);
      return 0;
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(v1 + 2416), "%s alloc fail return\n", "geni_i3c_master_attach_i3c_dev");
    if ( *(_QWORD *)(v1 - 104) )
      i3c_trace_log();
    return 4294967284LL;
  }
  return result;
}
