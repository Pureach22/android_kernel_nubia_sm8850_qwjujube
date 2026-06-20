__int64 __fastcall msm_ioctl_gem_new(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x3

  v3 = a2[2];
  if ( (v3 & 0xFFF0FFFC) == 0 )
    return msm_gem_new_handle(a1, a3, *a2, v3, a2 + 3, 0);
  _drm_err("invalid flags: %08x\n", v3);
  return 4294967274LL;
}
