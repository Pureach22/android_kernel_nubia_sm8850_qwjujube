__int64 __fastcall gpu_client_pf_set(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a2;
  result = adreno_power_cycle(a1, (void (__fastcall *)(__int64, __int64))set_gpu_client_pf, (__int64)v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
