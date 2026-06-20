__int64 __fastcall adreno_ioctl_perfcounter_query_compat(__int64 *a1, __int64 a2, unsigned int *a3)
{
  unsigned int v4; // w1
  unsigned __int64 v5; // x2
  unsigned int v6; // w3
  unsigned int v7; // w8
  __int64 v8; // x0
  __int64 result; // x0
  _QWORD v10[3]; // [xsp+18h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v5 = a3[1];
  v6 = a3[2];
  v7 = a3[3];
  v8 = *a1;
  v10[1] = 0;
  HIDWORD(v10[0]) = v7;
  LODWORD(result) = adreno_perfcounter_query_group(v8, v4, v5, v6, (unsigned int *)v10 + 1);
  a3[3] = HIDWORD(v10[0]);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
