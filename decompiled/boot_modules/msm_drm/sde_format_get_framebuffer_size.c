__int64 __fastcall sde_format_get_framebuffer_size(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _DWORD *a4,
        __int64 a5)
{
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v10; // [xsp+10h] [xbp-40h]
  __int64 v11; // [xsp+18h] [xbp-38h]
  __int64 v12; // [xsp+20h] [xbp-30h]
  __int64 v13; // [xsp+28h] [xbp-28h]
  __int64 v14; // [xsp+30h] [xbp-20h]
  __int64 v15; // [xsp+38h] [xbp-18h]
  __int64 v16; // [xsp+40h] [xbp-10h]
  __int64 v17; // [xsp+48h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9[1] = 0;
  v10 = 0;
  v9[0] = 0;
  result = sde_get_sde_format_ext(a1, a5);
  if ( result )
  {
    if ( a4 )
    {
      if ( (unsigned int)sde_format_get_plane_sizes(result, a2, a3, (__int64)v9, a4) )
        result = 0;
      else
        result = HIDWORD(v10);
    }
    else
    {
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
