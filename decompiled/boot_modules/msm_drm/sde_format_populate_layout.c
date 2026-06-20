__int64 __fastcall sde_format_populate_layout(__int64 a1, _DWORD *a2, __int64 *a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  _DWORD *v8; // x4
  unsigned int v9; // w1
  unsigned int v10; // w2
  _DWORD *v11; // x19
  __int64 *v12; // x22
  __int64 v13; // x8
  __int64 *v14; // x2
  __int64 v15; // x11
  _QWORD *v16; // x20
  __int64 v17; // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+10h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  if ( a2 && a3 )
  {
    if ( a2[32] >> 14 || a2[33] >= 0x4000u )
    {
      _drm_err("image dimensions outside max range\n");
      result = 4294967262LL;
    }
    else
    {
      v7 = msm_framebuffer_format(a2);
      *a3 = v7;
      v8 = a2 + 22;
      v9 = a2[32];
      v10 = a2[33];
      v11 = a2;
      v12 = a3;
      result = sde_format_get_plane_sizes(v7, v9, v10, (__int64)a3, v8);
      if ( !(_DWORD)result )
      {
        v13 = *a3;
        if ( (*(_QWORD *)(*a3 + 32) & 0x80) != 0 )
        {
          result = 0;
        }
        else
        {
          v14 = a3;
          v15 = a3[4];
          v16 = a3 + 3;
          v17 = v12[3];
          v18 = v15;
          if ( *(_DWORD *)(v13 + 28) == 2 )
            result = sde_format_populate_addrs_ubwc(a1, v11, v14);
          else
            result = sde_format_populate_addrs_linear(a1, v11, v14);
          if ( !(_DWORD)result )
          {
            if ( v17 ^ *v16 | v18 ^ v12[4] )
              result = 0;
            else
              result = 4294967285LL;
          }
        }
      }
    }
  }
  else
  {
    _drm_err("invalid arguments\n");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
