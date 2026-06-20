__int64 __fastcall kgsl_ioctl_sharedmem_flush_cache_compat(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned __int64 v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = *a3;
  result = kgsl_ioctl_sharedmem_flush_cache(a1, a2, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
