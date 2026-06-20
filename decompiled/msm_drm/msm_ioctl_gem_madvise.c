__int64 __fastcall msm_ioctl_gem_madvise(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  unsigned int v9; // w0
  unsigned int v10; // w20
  int v16; // w8

  if ( a2[1] > 1 )
    return 4294967274LL;
  result = mutex_lock_interruptible(a1 + 128);
  if ( !(_DWORD)result )
  {
    v7 = drm_gem_object_lookup(a3, *a2);
    if ( v7 )
    {
      _X19 = (unsigned int *)v7;
      v9 = msm_gem_madvise(v7, a2[1]);
      if ( (v9 & 0x80000000) == 0 )
      {
        a2[2] = v9;
        v9 = 0;
      }
      __asm { PRFM            #0x11, [X19] }
      do
        v16 = __ldxr(_X19);
      while ( __stlxr(v16 - 1, _X19) );
      v10 = v9;
      if ( v16 == 1 )
      {
        __dmb(9u);
        drm_gem_object_free(_X19);
      }
      else if ( v16 <= 0 )
      {
        refcount_warn_saturate(_X19, 3);
      }
    }
    else
    {
      v10 = -2;
    }
    mutex_unlock(a1 + 128);
    return v10;
  }
  return result;
}
