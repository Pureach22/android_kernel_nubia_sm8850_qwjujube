__int64 __fastcall simple_amp_func_configuration(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x20
  _QWORD *v10; // x21
  __int64 v11; // x8
  int v12; // w2
  int v13; // w22
  __int64 v14; // x23
  int i; // w24
  int v16; // w0
  int v17; // w22
  __int64 v18; // x23
  int v19; // w24
  int v20; // w20
  __int64 j; // x21
  _DWORD *v22; // x22
  __int64 result; // x0
  int v24; // w3
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  __int64 v27; // [xsp+10h] [xbp-10h] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v9 = 0;
  v10 = a1 + 6;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 116;
  v27 = 156;
  v25 = 112;
  do
  {
    v11 = v10[v9];
    if ( v11 )
    {
      v12 = *((_DWORD *)a1 + 151);
      if ( v12 == 1 )
      {
        v17 = *(_DWORD *)(v11 + 600);
        if ( v17 >= 1 )
        {
          v18 = *(_QWORD *)(v11 + 592);
          v19 = 0;
          while ( 1 )
          {
            v16 = regmap_write(*a1, *(unsigned int *)(v18 + 4LL * v19));
            if ( v16 )
              break;
            v19 += 2;
            if ( v19 >= v17 )
              goto LABEL_2;
          }
LABEL_21:
          v24 = v16;
LABEL_22:
          dev_err(a1[1], "%s: func init failed ret :%d\n", "simple_amp_func_configuration", v24);
          result = 4294967274LL;
          goto LABEL_23;
        }
      }
      else
      {
        if ( v12 )
        {
          dev_err(a1[1], "Unsupported chip version: %d\n", v12);
          v24 = -22;
          goto LABEL_22;
        }
        v13 = *(_DWORD *)(v11 + 584);
        if ( v13 >= 1 )
        {
          v14 = *(_QWORD *)(v11 + 576);
          for ( i = 0; i < v13; i += 2 )
          {
            v16 = regmap_write(*a1, *(unsigned int *)(v14 + 4LL * i));
            if ( v16 )
              goto LABEL_21;
          }
        }
      }
    }
LABEL_2:
    ++v9;
  }
  while ( v9 != 4 );
  v20 = 1074266112;
  for ( j = 6; j != 10; ++j )
  {
    v22 = (_DWORD *)a1[j];
    if ( v22 )
    {
      regmap_write(*a1, v20 + ((v22[36] << 15) & 0x200000 | ((v22[36] & 0x3Fu) << 7)));
      regmap_write(*a1, v20 + ((*v22 << 15) & 0x200000 | ((*v22 & 0x3Fu) << 7)));
      regmap_write(*a1, v20 + ((*v22 << 15) & 0x200000 | ((*v22 & 0x3Fu) << 7)));
    }
    v20 += 0x400000;
  }
  regmap_update_bits_base(*a1, 1079510051, 4, 4, 0, 0, 0, a8, v25, v26, v27, v28);
  swr_write(a1[2], *(unsigned __int8 *)(a1[2] + 64LL), 92, &v27);
  swr_write(a1[2], *(unsigned __int8 *)(a1[2] + 64LL), 93, &v26);
  swr_write(a1[2], *(unsigned __int8 *)(a1[2] + 64LL), 94, &v25);
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
