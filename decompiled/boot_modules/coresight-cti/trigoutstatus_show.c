__int64 __fastcall trigoutstatus_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v6; // x26
  int v7; // w0
  int v8; // w8
  __int64 v9; // x21
  unsigned int v10; // w25
  unsigned int v11; // w28
  int v12; // w23
  int v13; // w9
  int v14; // w8
  unsigned int v15; // w27
  int v16; // w22
  unsigned int v17; // w8
  unsigned int v24; // w10

  v3 = *(_QWORD *)(a1 + 96);
  v6 = *(_QWORD *)(v3 + 152);
  v7 = _pm_runtime_resume(v3, 4);
  if ( v7 < 0 )
  {
    v17 = *(_DWORD *)(v3 + 480);
    do
    {
      if ( !v17 )
        break;
      _X12 = (unsigned int *)(v3 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v24 = __ldxr(_X12);
        if ( v24 != v17 )
          break;
        if ( !__stlxr(v17 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v24 == v17;
      v17 = v24;
    }
    while ( !_ZF );
    return v7;
  }
  raw_spin_lock(v6 + 56);
  if ( *(_BYTE *)(v6 + 77) != 1 )
  {
    v16 = 0;
LABEL_20:
    v9 = 0;
    goto LABEL_21;
  }
  if ( *(_BYTE *)(v6 + 1200) != 1 )
  {
    v16 = readl_relaxed_0((unsigned int *)(*(_QWORD *)v6 + 308LL));
    goto LABEL_20;
  }
  v8 = *(_DWORD *)(v6 + 68);
  v9 = 0;
  v10 = 0;
  v11 = 96;
  v12 = 31;
  v13 = v8 - 1;
  v14 = v8 + 30;
  if ( v13 >= 0 )
    v14 = v13;
  v15 = v14 >> 5;
  do
  {
    v16 = readl_relaxed_0((unsigned int *)(*(_QWORD *)v6 + v11));
    v9 += (int)scnprintf(a3 + v9, 4096 - v9, "%u - %u : 0x%x\n", v10, v12, v16);
    v11 += 4;
    v12 += 32;
    ++v10;
  }
  while ( v10 <= v15 );
LABEL_21:
  raw_spin_unlock(v6 + 56);
  _pm_runtime_idle(*(_QWORD *)(a1 + 96), 4);
  if ( (*(_BYTE *)(v6 + 1200) & 1) == 0 )
    return (int)scnprintf(a3, 4096, "0x%x\n", v16);
  return v9;
}
