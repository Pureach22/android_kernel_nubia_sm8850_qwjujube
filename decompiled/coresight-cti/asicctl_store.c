__int64 __fastcall asicctl_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w1
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v9[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 0, v9) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 56);
    if ( *(_BYTE *)(v6 + 77) == 1 && *(_BYTE *)(v6 + 76) == 1 )
    {
      if ( *(_BYTE *)(v6 + 1200) )
        v7 = 140;
      else
        v7 = 324;
      cti_write_single_reg((__int64 *)v6, v7, v9[0]);
    }
    raw_spin_unlock(v6 + 56);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
