__int64 __fastcall sde_hw_sspp_set_src_split_order_v1(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  int v7; // w10
  int v8; // w8
  int v9; // w10
  int v10; // w8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  result = sspp_subblk_offset(a1, 1, &v11);
  if ( !(_DWORD)result )
  {
    v7 = v11;
    if ( a2 >= 2 )
      v8 = 12288;
    else
      v8 = 4096;
    v11 += v8;
    v9 = sde_reg_read(a1, v7 + v8 + 8) & 0xFFFFFFEF;
    if ( (a3 & 1) != 0 )
      v10 = 16;
    else
      v10 = 0;
    result = sde_reg_write(a1, v11 + 8, v9 | (unsigned int)v10, "op_mode_off + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
