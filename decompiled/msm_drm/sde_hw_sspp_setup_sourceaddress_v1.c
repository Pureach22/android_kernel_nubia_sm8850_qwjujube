__int64 __fastcall sde_hw_sspp_setup_sourceaddress_v1(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 result; // x0
  int v7; // w10
  int v8; // w8
  unsigned int v9; // w2
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  result = sspp_subblk_offset(a1, 1, &v10);
  if ( !(_DWORD)result )
  {
    v7 = v10;
    if ( a3 >= 2 )
      v8 = 12288;
    else
      v8 = 4096;
    v9 = a2[6];
    v10 += v8;
    sde_reg_write(a1, v7 + v8 + 76, v9, "SSPP_REC_SRC0_ADDR + idx + i * 0x4");
    sde_reg_write(a1, v10 + 80, a2[7], "SSPP_REC_SRC0_ADDR + idx + i * 0x4");
    sde_reg_write(a1, v10 + 84, a2[8], "SSPP_REC_SRC0_ADDR + idx + i * 0x4");
    result = sde_reg_write(a1, v10 + 88, a2[9], "SSPP_REC_SRC0_ADDR + idx + i * 0x4");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
