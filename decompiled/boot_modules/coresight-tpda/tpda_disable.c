__int64 __fastcall tpda_disable(unsigned int **a1, __int64 a2)
{
  __int64 *v4; // x21
  int v5; // w20
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x9
  unsigned int v20; // w8
  unsigned int v21; // w8

  v4 = *((__int64 **)a1[19] + 19);
  raw_spin_lock(v4 + 3);
  _X9 = (unsigned int *)(a2 + 60);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v20 = __ldxr(_X9);
    v21 = v20 - 1;
  }
  while ( __stlxr(v21, _X9) );
  __dmb(0xBu);
  if ( !v21 )
  {
    v5 = *(_DWORD *)(a2 + 4);
    writel_relaxed(3316436565LL, *v4 + 4016);
    __dsb(0xFu);
    v6 = 4 * v5 + 4;
    v7 = readl_relaxed(*v4 + v6);
    writel_relaxed(v7 & 0xFFFFFFFE, *v4 + v6);
    v8 = *v4;
    __dsb(0xFu);
    writel_relaxed(0, v8 + 4016);
    --*((_DWORD *)a1 + 244);
  }
  v9 = (__int64)*a1;
  v10 = **a1;
  v11 = *((_QWORD *)a1[19] + 19);
  if ( (int)v10 < 1 )
  {
LABEL_6:
    coresight_trace_id_put_system_id(*(unsigned __int8 *)(v11 + 28));
    *(_BYTE *)(v11 + 28) = 0;
  }
  else
  {
    v12 = *(_QWORD *)(v9 + 16);
    while ( !*(_DWORD *)(*(_QWORD *)v12 + 60LL) )
    {
      --v10;
      v12 += 8;
      if ( !v10 )
        goto LABEL_6;
    }
  }
  return raw_spin_unlock(v4 + 3);
}
