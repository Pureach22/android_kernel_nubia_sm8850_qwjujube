__int64 __fastcall msm_ioctl_gem_cpu_fini(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x0
  unsigned int v5; // w19
  int v11; // w8

  v3 = drm_gem_object_lookup(a3, *a2);
  if ( v3 )
  {
    _X20 = (unsigned int *)v3;
    v5 = msm_gem_cpu_fini();
    __asm { PRFM            #0x11, [X20] }
    do
      v11 = __ldxr(_X20);
    while ( __stlxr(v11 - 1, _X20) );
    if ( v11 == 1 )
    {
      __dmb(9u);
      drm_gem_object_free(_X20);
    }
    else if ( v11 <= 0 )
    {
      refcount_warn_saturate(_X20, 3);
    }
  }
  else
  {
    return (unsigned int)-2;
  }
  return v5;
}
