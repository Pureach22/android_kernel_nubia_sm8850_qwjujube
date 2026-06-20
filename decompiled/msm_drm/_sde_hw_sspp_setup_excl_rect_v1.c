__int64 __fastcall sde_hw_sspp_setup_excl_rect_v1(__int64 a1, unsigned int *a2, unsigned int a3)
{
  __int64 result; // x0
  int v7; // w8
  unsigned int v8; // w20
  unsigned int v9; // w21
  int v10; // w8
  int v11; // w0
  const char *v12; // x3
  unsigned int v13; // w1
  __int64 v14; // x0
  unsigned int v15; // w2
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  result = sspp_subblk_offset(a1, 1, &v16);
  if ( a2 && !(_DWORD)result )
  {
    if ( a3 >= 2 )
      v7 = 12288;
    else
      v7 = 4096;
    v8 = *a2;
    v9 = a2[1];
    v10 = v16 + v7;
    v16 = v10;
    if ( a3 )
      v11 = sde_reg_read(a1, v10 + 180);
    else
      v11 = 1;
    v12 = "SSPP_REC_EXCL_REC_CTRL + idx";
    v13 = v16 + 180;
    if ( v9 )
    {
      sde_reg_write(a1, v13, v11 | 1, "SSPP_REC_EXCL_REC_CTRL + idx");
      sde_reg_write(a1, v16 + 184, v9, "SSPP_REC_EXCL_REC_SIZE + idx");
      v12 = "SSPP_REC_EXCL_REC_XY + idx";
      v14 = a1;
      v15 = v8;
      v13 = v16 + 188;
    }
    else
    {
      v15 = v11 & 0xFFFFFFFE;
      v14 = a1;
    }
    result = sde_reg_write(v14, v13, v15, v12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
