__int64 __fastcall sde_hw_sspp_setup_line_insertion_v1(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 result; // x0
  int v7; // w11
  int v8; // w8
  int v9; // w8
  unsigned int v10; // w2
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  result = sspp_subblk_offset(a1, 1, &v11);
  if ( a3 && !(_DWORD)result )
  {
    v7 = *(unsigned __int8 *)a3;
    if ( a2 >= 2 )
      v8 = 12288;
    else
      v8 = 4096;
    v9 = v11 + v8;
    v11 = v9;
    if ( v7 == 1 )
      v10 = (a3[1] << 16) | (a3[2] << 8) | a3[3] | 0x80000000;
    else
      v10 = 0;
    sde_reg_write(a1, v9 + 192, v10, "SSPP_REC_LINE_INSERTION_CTRL + idx");
    result = sde_reg_write(a1, v11 + 196, a3[4] << 16, "SSPP_REC_LINE_INSERTION_OUT_SIZE + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
