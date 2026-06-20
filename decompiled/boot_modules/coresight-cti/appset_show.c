__int64 __fastcall appset_show(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE *v4; // x21
  __int64 v5; // x8
  int v6; // w0
  __int64 v7; // x8
  int v8; // w20

  v4 = *(_BYTE **)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 56);
  if ( v4[77] == 1 && v4[76] == 1 )
  {
    writel_relaxed_0(0xC5ACCE55, (unsigned int *)(*(_QWORD *)v4 + 4016LL));
    __dsb(0xFu);
    v5 = 20;
    if ( v4[1200] )
      v5 = 4;
    v6 = readl_relaxed_0((unsigned int *)(*(_QWORD *)v4 + v5));
    v7 = *(_QWORD *)v4;
    __dsb(0xFu);
    v8 = v6;
    writel_relaxed_0(0, (unsigned int *)(v7 + 4016));
  }
  else
  {
    v8 = 0;
  }
  raw_spin_unlock(v4 + 56);
  return (int)scnprintf(a3, 4096, "%#x\n", v8);
}
