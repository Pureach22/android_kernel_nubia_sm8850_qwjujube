__int64 __fastcall sde_format_check_modified_format(__int64 a1, unsigned int *a2, unsigned int *a3, __int64 *a4)
{
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x11
  unsigned int v12; // w1
  __int64 v13; // x8
  __int64 v14; // x12
  _QWORD v15[2]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v16; // [xsp+10h] [xbp-40h]
  __int64 v17; // [xsp+18h] [xbp-38h]
  __int64 v18; // [xsp+20h] [xbp-30h]
  __int64 v19; // [xsp+28h] [xbp-28h]
  __int64 v20; // [xsp+30h] [xbp-20h]
  __int64 v21; // [xsp+38h] [xbp-18h]
  __int64 v22; // [xsp+40h] [xbp-10h]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15[1] = 0;
  v16 = 0;
  v15[0] = 0;
  if ( !a2 || !a3 || !a4 )
  {
    _drm_err("invalid arguments\n");
    goto LABEL_11;
  }
  v7 = drm_format_info(*a2);
  if ( !v7 )
  {
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v8 = v7;
  result = sde_format_get_plane_sizes((__int64)a2, a3[1], a3[2], (__int64)v15, a3 + 9);
  if ( !(_DWORD)result )
  {
    v10 = *(unsigned __int8 *)(v8 + 5);
    if ( *(_BYTE *)(v8 + 5) )
    {
      v11 = *a4;
      if ( !*a4 )
      {
        LODWORD(v13) = 0;
LABEL_23:
        _drm_err("invalid handle for plane %d\n", v13);
        goto LABEL_11;
      }
      v12 = *(_DWORD *)(v11 + 216);
      if ( (_DWORD)v10 != 1 )
      {
        v13 = 1;
        do
        {
          v14 = a4[v13];
          if ( !v14 )
            goto LABEL_23;
          if ( v14 != v11 )
            v12 += *(_DWORD *)(v14 + 216);
        }
        while ( v10 != ++v13 );
      }
    }
    else
    {
      v12 = 0;
    }
    if ( v12 >= HIDWORD(v16) || (*((_QWORD *)a2 + 4) & 0x80) != 0 )
    {
      result = 0;
      goto LABEL_12;
    }
    _drm_err(
      "buffers total size too small %u expected %u cac_fmt:%d\n",
      v12,
      HIDWORD(v16),
      ((unsigned int)*((_QWORD *)a2 + 4) >> 7) & 1);
    goto LABEL_11;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
