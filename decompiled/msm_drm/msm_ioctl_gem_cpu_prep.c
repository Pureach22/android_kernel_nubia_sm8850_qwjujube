__int64 __fastcall msm_ioctl_gem_cpu_prep(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x10
  unsigned int v6; // w1
  __int64 v7; // x9
  bool v8; // cc
  __int64 v9; // x8
  __int64 v10; // x0
  unsigned int v12; // w0
  unsigned int v13; // w20
  __int64 result; // x0
  int v20; // w8
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_QWORD *)a2 + 1);
  v5 = *((_QWORD *)a2 + 2);
  v6 = a2[1];
  v7 = v5 + 1000000000 * v4;
  v8 = v4 <= 0x225C17D03LL;
  v9 = 0x7FFFFFFFFFFFFFFFLL;
  if ( v8 )
    v9 = v7;
  v21[0] = v9;
  if ( v6 >= 0x10 )
  {
    _drm_err("invalid op: %08x\n", v6);
    result = 4294967274LL;
  }
  else
  {
    v10 = drm_gem_object_lookup(a3, *a2);
    if ( v10 )
    {
      _X19 = (unsigned int *)v10;
      v12 = msm_gem_cpu_prep(v10, a2[1], v21);
      __asm { PRFM            #0x11, [X19] }
      do
        v20 = __ldxr(_X19);
      while ( __stlxr(v20 - 1, _X19) );
      v13 = v12;
      if ( v20 == 1 )
      {
        __dmb(9u);
        drm_gem_object_free(_X19);
      }
      else if ( v20 <= 0 )
      {
        refcount_warn_saturate(_X19, 3);
      }
      result = v13;
    }
    else
    {
      result = 4294967294LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
