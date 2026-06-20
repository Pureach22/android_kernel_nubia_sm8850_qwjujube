__int64 __fastcall kgsl_ioctl_device_getproperty_compat(__int64 *a1, __int64 a2, unsigned int *a3)
{
  unsigned int v3; // w8
  __int64 v4; // x10
  __int64 result; // x0
  _QWORD v6[4]; // [xsp+0h] [xbp-20h] BYREF

  v6[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a3;
  v4 = a3[2];
  v6[1] = a3[1];
  v6[0] = v3;
  v6[2] = v4;
  result = kgsl_ioctl_device_getproperty(a1, a2, (int *)v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
