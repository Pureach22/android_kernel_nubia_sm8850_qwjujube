__int64 __fastcall ocla_cfg2_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  __int64 v7; // x21
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v9[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  v7 = *(_QWORD *)(v6 + 64);
  if ( (unsigned int)kstrtoull(a3, 16, v9) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 16);
    *(_QWORD *)(v7 + 376) = v9[0];
    raw_spin_unlock(v6 + 16);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
