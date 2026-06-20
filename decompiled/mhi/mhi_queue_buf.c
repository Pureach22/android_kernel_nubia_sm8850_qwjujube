__int64 __fastcall mhi_queue_buf(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _QWORD v5[8]; // [xsp+0h] [xbp-40h] BYREF

  v5[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[5] = a4;
  v5[6] = 0;
  v5[0] = a3;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = a3;
  v5[4] = 0;
  result = mhi_queue(a1, (__int64)v5, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
