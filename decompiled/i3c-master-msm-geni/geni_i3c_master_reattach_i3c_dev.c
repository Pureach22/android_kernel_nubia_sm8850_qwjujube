__int64 __fastcall geni_i3c_master_reattach_i3c_dev(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned __int64 v4; // x20
  _QWORD *v5; // x8
  __int64 v6; // x10
  __int64 v7; // x19
  __int64 v8; // x0

  v1 = *(_QWORD *)(a1 + 16);
  v2 = a1;
  v3 = *(_QWORD *)(v1 + 2424);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v4 = sched_clock(a1);
      a1 = ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_reattach_i3c_dev", v4, v4 / 0x3E8);
      if ( *(_QWORD *)(v2 + 120) )
        goto LABEL_13;
    }
    else
    {
      v4 = 0;
      if ( *(_QWORD *)(a1 + 120) )
        goto LABEL_13;
    }
  }
  else
  {
    v4 = -22;
    if ( *(_QWORD *)(a1 + 120) )
      goto LABEL_13;
  }
  v5 = *(_QWORD **)(v1 + 2176);
  if ( v5 != (_QWORD *)(v1 + 2176) )
  {
    v6 = *(_QWORD *)(v2 + 32);
    do
    {
      if ( v6 == v5[3] )
        *(_QWORD *)(v2 + 120) = v5;
      v5 = (_QWORD *)*v5;
    }
    while ( v5 != (_QWORD *)(v1 + 2176) );
  }
LABEL_13:
  v7 = *(_QWORD *)(v1 + 2424);
  if ( v7 && v4 && *(_DWORD *)(v1 + 2432) )
  {
    v8 = sched_clock(a1);
    ipc_log_string(v7, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_master_reattach_i3c_dev", v8 - v4, (v8 - v4) / 0x3E8);
  }
  return 0;
}
