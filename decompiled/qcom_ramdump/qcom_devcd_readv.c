__int64 __fastcall qcom_devcd_readv(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x3
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a4;
  v6[0] = a2;
  result = memory_read_from_buffer(a1, a3, v6, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
