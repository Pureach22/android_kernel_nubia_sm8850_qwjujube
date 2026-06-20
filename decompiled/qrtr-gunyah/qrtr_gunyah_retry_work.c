__int64 __fastcall qrtr_gunyah_retry_work(__int64 a1)
{
  __int64 v1; // x0
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 - 16);
  v3[0] = 1;
  result = gh_dbl_send(v1, v3, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
