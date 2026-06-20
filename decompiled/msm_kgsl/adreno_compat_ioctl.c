__int64 __fastcall adreno_compat_ioctl(__int64 a1, unsigned int a2, __int64 a3)
{
  return adreno_ioctl_helper(a1, a2, a3, adreno_compat_ioctl_funcs, 4);
}
