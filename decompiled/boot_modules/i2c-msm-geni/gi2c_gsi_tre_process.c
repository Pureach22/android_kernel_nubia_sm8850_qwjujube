void __fastcall gi2c_gsi_tre_process(__int64 a1, int a2)
{
  __int64 v2; // x22
  __int64 v3; // x19
  unsigned __int64 v5; // x20
  unsigned int v6; // w25
  unsigned int v7; // w3
  unsigned int v8; // w22
  __int64 v9; // x9
  int v10; // w4
  __int64 v11; // x21
  __int64 v12; // x0

  v2 = *(_QWORD *)(a1 + 5104);
  v3 = a1;
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 5112) )
    {
      v5 = sched_clock(a1);
      a1 = ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "gi2c_gsi_tre_process", v5, v5 / 0x3E8);
      if ( !*(_DWORD *)(v3 + 24) )
        goto LABEL_8;
LABEL_6:
      v6 = *(_DWORD *)(v3 + 1352);
      goto LABEL_9;
    }
    v5 = 0;
    if ( *(_DWORD *)(a1 + 24) )
      goto LABEL_6;
  }
  else
  {
    v5 = -22;
    if ( *(_DWORD *)(a1 + 24) )
      goto LABEL_6;
  }
LABEL_8:
  v6 = *(_DWORD *)(v3 + 1364) << 6;
LABEL_9:
  v7 = *(_DWORD *)(v3 + 1368);
  if ( v7 < v6 )
  {
    v8 = 0;
    while ( v7 != a2 )
    {
      v9 = *(_QWORD *)(v3 + 1344);
      v10 = *(_DWORD *)(v3 + 1356) + 1;
      *(_DWORD *)(v3 + 1356) = v10;
      if ( *(unsigned __int16 *)(v9 + 16LL * v7 + 4) >= 9u )
      {
        v8 = v7 - 448 * ((613566757 * (unsigned __int64)(v7 >> 6)) >> 32);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))gi2c_gsi_tx_unmap)(v3, v7, v8);
        v7 = *(_DWORD *)(v3 + 1368);
        v10 = *(_DWORD *)(v3 + 1356);
      }
      ipc_log_string(
        *(_QWORD *)(v3 + 5096),
        "%s:unmap_cnt %d freed_cnt:%d wr_idx:%d\n",
        "gi2c_gsi_tre_process",
        v7,
        v10,
        v8);
      a1 = *(_QWORD *)v3;
      if ( *(_QWORD *)v3 )
        i2c_trace_log();
      v7 = *(_DWORD *)(v3 + 1368) + 1;
      *(_DWORD *)(v3 + 1368) = v7;
      if ( v7 >= v6 )
        goto LABEL_19;
    }
    ipc_log_string(*(_QWORD *)(v3 + 5096), "%s:last %d msg unmapped\n", "gi2c_gsi_tre_process", a2);
    a1 = *(_QWORD *)v3;
    if ( *(_QWORD *)v3 )
      i2c_trace_log();
  }
LABEL_19:
  v11 = *(_QWORD *)(v3 + 5104);
  if ( v11 && v5 )
  {
    if ( *(_DWORD *)(v3 + 5112) )
    {
      v12 = sched_clock(a1);
      ipc_log_string(v11, "%s:took %llu nsec(%llu usec)\n", "gi2c_gsi_tre_process", v12 - v5, (v12 - v5) / 0x3E8);
    }
  }
}
