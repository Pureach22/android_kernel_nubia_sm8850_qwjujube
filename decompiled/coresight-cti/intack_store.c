__int64 __fastcall intack_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  if ( (unsigned int)kstrtoull(a3, 0, v7) )
    a4 = -22;
  else
    cti_write_intack(a1, v7[0]);
  _ReadStatusReg(SP_EL0);
  return a4;
}
