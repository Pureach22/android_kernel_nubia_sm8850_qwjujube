__int64 __fastcall appclear_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  unsigned int v7; // w2
  int v8; // w9
  int v9; // w1
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v11[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 0, v11) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 56);
    v7 = v11[0];
    v8 = *(unsigned __int8 *)(v6 + 77);
    *(_DWORD *)(v6 + 132) &= ~LODWORD(v11[0]);
    if ( v8 == 1 && *(_BYTE *)(v6 + 76) == 1 )
    {
      if ( *(_BYTE *)(v6 + 1200) )
        v9 = 24;
      else
        v9 = 8;
      cti_write_single_reg((__int64 *)v6, v9, v7);
    }
    raw_spin_unlock(v6 + 56);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
