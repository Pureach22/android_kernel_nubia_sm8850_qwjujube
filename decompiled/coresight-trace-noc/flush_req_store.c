__int64 __fastcall flush_req_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _BYTE *v6; // x20
  int v7; // w0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v9[0] = 0;
  v6 = *(_BYTE **)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 16, v9) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 24);
    if ( v6[32] == 1 )
    {
      if ( v9[0] )
      {
        v7 = readl_relaxed((unsigned int *)(*(_QWORD *)v6 + 8LL));
        writel_relaxed(v7 | 2, (unsigned int *)(*(_QWORD *)v6 + 8LL));
      }
    }
    else
    {
      a4 = -1;
    }
    raw_spin_unlock(v6 + 24);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
