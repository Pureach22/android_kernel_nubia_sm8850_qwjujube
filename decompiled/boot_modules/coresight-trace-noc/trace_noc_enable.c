__int64 __fastcall trace_noc_enable(unsigned int **a1, __int64 a2)
{
  unsigned int *v4; // x21
  __int64 v5; // x0
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x22
  __int64 v11; // x9
  unsigned int system_id; // w20
  unsigned int v14; // w0
  int v15; // w0
  unsigned int v16; // w9
  unsigned int v17; // w0
  unsigned int v18; // w8
  int v19; // w9
  unsigned int v20; // w0
  unsigned int v27; // w9
  unsigned int v30; // w9

  v4 = *((unsigned int **)a1[19] + 19);
  v5 = raw_spin_lock(v4 + 6);
  v6 = (__int64)*a1;
  v7 = **a1;
  if ( (int)v7 <= 0 )
  {
    v10 = *((_QWORD *)a1[19] + 19);
LABEL_10:
    system_id = coresight_trace_id_get_system_id(v5);
    if ( (system_id & 0x80000000) != 0 )
    {
      raw_spin_unlock(v4 + 6);
      return system_id;
    }
    *(_DWORD *)(v10 + 36) = system_id;
  }
  else
  {
    v8 = *(_QWORD *)(v6 + 16);
    v9 = **a1;
    do
    {
      if ( *(_DWORD *)(*(_QWORD *)v8 + 60LL) )
      {
        _X8 = (unsigned int *)(a2 + 60);
        __asm { PRFM            #0x11, [X8] }
        do
          v27 = __ldxr(_X8);
        while ( __stxr(v27 + 1, _X8) );
        raw_spin_unlock(v4 + 6);
        return 0;
      }
      --v9;
      v8 += 8;
    }
    while ( v9 );
    v10 = *((_QWORD *)a1[19] + 19);
    v11 = *(_QWORD *)(v6 + 16);
    while ( !*(_DWORD *)(*(_QWORD *)v11 + 60LL) )
    {
      --v7;
      v11 += 8;
      if ( !v7 )
        goto LABEL_10;
    }
  }
  writel_relaxed(v4[9], (unsigned int *)(*(_QWORD *)v4 + 16LL));
  writel_relaxed(0xFFFFu, (unsigned int *)(*(_QWORD *)v4 + 32LL));
  v14 = v4[10];
  if ( v14 )
    writel_relaxed(v14, (unsigned int *)(*(_QWORD *)v4 + 24LL));
  v15 = readl_relaxed((unsigned int *)(*(_QWORD *)v4 + 8LL));
  v16 = v4[13];
  if ( v4[7] == 1 )
  {
    v17 = v15 & 0xFFFFFEFF | ((v16 == 1) << 8);
    v18 = v17 & 0xFFFFFDFF;
    v19 = v17 | 0x200;
  }
  else
  {
    v20 = v15 & 0xFFFFFF7F | ((v16 == 1) << 7);
    v18 = v20 & 0xFFFFFEFF;
    v19 = v20 | 0x100;
  }
  if ( v4[12] == 1 )
    v18 = v19;
  writel_relaxed(v18 | 1, (unsigned int *)(*(_QWORD *)v4 + 8LL));
  _X8 = (unsigned int *)(a2 + 60);
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 + 1, _X8) );
  *((_BYTE *)v4 + 32) = 1;
  raw_spin_unlock(v4 + 6);
  dev_info(*((_QWORD *)v4 + 1), "Trace NOC is enabled\n");
  return 0;
}
