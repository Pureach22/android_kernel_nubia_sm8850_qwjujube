__int64 __fastcall sde_hw_sspp_ubwc_stats_get_data_v1(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  int v7; // w9
  int v8; // w0
  unsigned int v9; // w8
  int v10; // w0
  unsigned int v11; // w8
  int v12; // w0
  unsigned int v13; // w8
  int v14; // w0
  unsigned int v15; // w8
  int v16; // w0
  unsigned int v17; // w8
  unsigned int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  result = sspp_subblk_offset(a1, 1, &v18);
  if ( !(_DWORD)result )
  {
    if ( a2 >= 2 )
      v7 = 12444;
    else
      v7 = 4252;
    v18 += v7;
    v8 = sde_reg_read(a1, v18);
    v9 = v18;
    *(_WORD *)(a3 + 4) = v8;
    *(_WORD *)(a3 + 10) = HIWORD(v8);
    v10 = sde_reg_read(a1, v9 + 4);
    v11 = v18;
    *(_DWORD *)(a3 + 16) = v10;
    v18 = v11 + 8;
    v12 = sde_reg_read(a1, v11 + 8);
    v13 = v18;
    *(_WORD *)(a3 + 6) = v12;
    *(_WORD *)(a3 + 12) = HIWORD(v12);
    v14 = sde_reg_read(a1, v13 + 4);
    v15 = v18;
    *(_DWORD *)(a3 + 20) = v14;
    v18 = v15 + 8;
    v16 = sde_reg_read(a1, v15 + 8);
    v17 = v18;
    *(_WORD *)(a3 + 8) = v16;
    *(_WORD *)(a3 + 14) = HIWORD(v16);
    result = sde_reg_read(a1, v17 + 4);
    *(_DWORD *)(a3 + 24) = result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
