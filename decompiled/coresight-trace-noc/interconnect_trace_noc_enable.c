__int64 __fastcall interconnect_trace_noc_enable(unsigned int **a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w0
  unsigned int v11; // w9
  unsigned int v18; // w9

  v4 = *((_QWORD *)a1[19] + 19);
  raw_spin_lock(v4 + 24);
  v5 = **a1;
  if ( (int)v5 < 1 )
  {
LABEL_5:
    v7 = readl_relaxed(*(_QWORD *)v4 + 8LL);
    writel_relaxed(v7 | 1u, *(_QWORD *)v4 + 8LL);
    *(_BYTE *)(v4 + 32) = 1;
    _X8 = (unsigned int *)(a2 + 60);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 + 1, _X8) );
    raw_spin_unlock(v4 + 24);
    dev_info(*(_QWORD *)(v4 + 8), "Trace NOC is enabled\n");
  }
  else
  {
    v6 = *((_QWORD *)*a1 + 2);
    while ( !*(_DWORD *)(*(_QWORD *)v6 + 60LL) )
    {
      --v5;
      v6 += 8;
      if ( !v5 )
        goto LABEL_5;
    }
    _X8 = (unsigned int *)(a2 + 60);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 + 1, _X8) );
    raw_spin_unlock(v4 + 24);
  }
  return 0;
}
