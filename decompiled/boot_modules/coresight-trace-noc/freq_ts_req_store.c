__int64 __fastcall freq_ts_req_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w0
  int v8; // w8
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v10[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 16, v10) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 24);
    if ( *(_BYTE *)(v6 + 32) == 1 )
    {
      if ( v10[0] )
      {
        v7 = readl_relaxed((unsigned int *)(*(_QWORD *)v6 + 8LL));
        if ( *(_DWORD *)(v6 + 28) == 1 )
          v8 = 64;
        else
          v8 = 32;
        writel_relaxed(v8 | v7, (unsigned int *)(*(_QWORD *)v6 + 8LL));
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
