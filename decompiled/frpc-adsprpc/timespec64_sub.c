__int64 __fastcall timespec64_sub(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v5[1] = 0;
  set_normalized_timespec64(v5, a1 - a3, a2 - a4);
  _ReadStatusReg(SP_EL0);
  return v5[0];
}
