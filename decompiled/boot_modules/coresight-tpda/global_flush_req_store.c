__int64 __fastcall global_flush_req_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  unsigned int **v6; // x21
  unsigned int *v7; // x8
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v9[0] = 0;
  v6 = *(unsigned int ***)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 0, v9) )
  {
    a4 = -22;
    goto LABEL_8;
  }
  raw_spin_lock(v6 + 3);
  if ( !v6[2][244] )
  {
    a4 = -1;
    if ( v6 == (unsigned int **)-24LL )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( v9[0] )
  {
    writel_relaxed(0xC5ACCE55, *v6 + 1004);
    __dsb(0xFu);
    v9[0] = (unsigned int)readl_relaxed(*v6) | 1;
    writel_relaxed(v9[0], *v6);
    v7 = *v6;
    __dsb(0xFu);
    writel_relaxed(0, v7 + 1004);
  }
  if ( v6 != (unsigned int **)-24LL )
LABEL_7:
    raw_spin_unlock(v6 + 3);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
