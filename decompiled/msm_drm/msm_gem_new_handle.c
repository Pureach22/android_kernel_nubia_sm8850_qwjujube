unsigned __int64 __fastcall msm_gem_new_handle(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 result; // x0
  int v10; // w3
  int v11; // w4
  int v12; // w5
  int v13; // w6
  int v14; // w7
  unsigned int v16; // w20
  int v22; // w8
  char vars0; // [xsp+0h] [xbp+0h]

  result = msm_gem_new(a1, a3, a4);
  _X19 = (unsigned int *)result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)result;
  if ( a6 )
    msm_gem_object_set_name(result, "%s", a6, v10, v11, v12, v13, v14, vars0);
  result = drm_gem_handle_create(a2, _X19, a5);
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v22 = __ldxr(_X19);
    while ( __stlxr(v22 - 1, _X19) );
    v16 = result;
    if ( v22 == 1 )
    {
      __dmb(9u);
      drm_gem_object_free(_X19);
    }
    else if ( v22 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    return v16;
  }
  return result;
}
