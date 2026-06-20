unsigned int *__fastcall msm_gem_address_space_put(unsigned int *result)
{
  unsigned int *v1; // x19
  __int64 v2; // x0
  void (*v3)(void); // x8
  int v9; // w8

  if ( result )
  {
    v1 = result;
    result += 66;
    __asm { PRFM            #0x11, [X0] }
    do
      v9 = __ldxr(result);
    while ( __stlxr(v9 - 1, result) );
    if ( v9 == 1 )
    {
      __dmb(9u);
      drm_mm_takedown(v1 + 2);
      v2 = *((_QWORD *)v1 + 32);
      if ( v2 )
      {
        v3 = *(void (**)(void))(*(_QWORD *)v2 + 64LL);
        if ( *((_DWORD *)v3 - 1) != -1262402125 )
          __break(0x8228u);
        v3();
      }
      return (unsigned int *)kfree(v1);
    }
    else if ( v9 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
