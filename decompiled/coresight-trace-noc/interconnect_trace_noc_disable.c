__int64 __fastcall interconnect_trace_noc_disable(unsigned int **a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x9
  unsigned int v14; // w10

  v4 = *((_QWORD *)a1[19] + 19);
  raw_spin_lock(v4 + 24);
  _X8 = (unsigned int *)(a2 + 60);
  __asm { PRFM            #0x11, [X8] }
  do
    v14 = __ldxr(_X8);
  while ( __stxr(v14 - 1, _X8) );
  v5 = **a1;
  if ( (int)v5 < 1 )
  {
LABEL_6:
    writel_relaxed(0, *(_QWORD *)v4 + 8LL);
    *(_BYTE *)(v4 + 32) = 0;
    raw_spin_unlock(v4 + 24);
    return dev_info(*(_QWORD *)(v4 + 8), "Trace NOC is disabled\n");
  }
  else
  {
    v6 = *((_QWORD *)*a1 + 2);
    while ( !*(_DWORD *)(*(_QWORD *)v6 + 60LL) )
    {
      --v5;
      v6 += 8;
      if ( !v5 )
        goto LABEL_6;
    }
    return raw_spin_unlock(v4 + 24);
  }
}
