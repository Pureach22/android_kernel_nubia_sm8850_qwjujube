__int64 __fastcall msm_framebuffer_create(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 format_info; // x0
  __int64 v7; // x22
  unsigned __int64 v8; // x0
  __int64 v9; // x19
  __int64 v11; // x20
  int v18; // w8
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  __int64 v20; // [xsp+10h] [xbp-20h]
  __int64 v21; // [xsp+18h] [xbp-18h]
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  format_info = drm_get_format_info(a1, a3);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v7 = *(unsigned __int8 *)(format_info + 5);
  if ( *(_BYTE *)(format_info + 5) )
  {
    v19 = drm_gem_object_lookup(a2, a3[5]);
    if ( !v19 )
      goto LABEL_13;
    if ( (_DWORD)v7 == 1 )
      goto LABEL_10;
    v20 = drm_gem_object_lookup(a2, a3[6]);
    if ( !v20 )
      goto LABEL_13;
    if ( (_DWORD)v7 == 2 )
      goto LABEL_10;
    v21 = drm_gem_object_lookup(a2, a3[7]);
    if ( !v21 )
      goto LABEL_13;
    if ( (_DWORD)v7 == 3 )
      goto LABEL_10;
    v22 = drm_gem_object_lookup(a2, a3[8]);
    if ( !v22 )
    {
LABEL_13:
      v9 = -6;
      goto LABEL_14;
    }
    if ( (_DWORD)v7 != 4 )
      goto LABEL_24;
  }
LABEL_10:
  v8 = msm_framebuffer_init(a1, a3, &v19);
  v9 = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    v9 = (int)v8;
    if ( (_DWORD)v7 )
    {
LABEL_14:
      v11 = 0;
      while ( v11 != 32 )
      {
        _X0 = *(unsigned int **)((char *)&v19 + v11);
        if ( _X0 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v18 = __ldxr(_X0);
          while ( __stlxr(v18 - 1, _X0) );
          if ( v18 == 1 )
          {
            __dmb(9u);
            drm_gem_object_free(_X0);
          }
          else if ( v18 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v11 += 8;
        if ( 8 * v7 == v11 )
          goto LABEL_12;
      }
LABEL_24:
      __break(0x5512u);
      __break(1u);
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v9;
}
