__int64 __fastcall sde_hw_sspp_setup_secure_v1(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  int v7; // w8
  int v8; // w8
  int v9; // w9
  int v10; // w21
  int v11; // w0
  unsigned int v12; // w2
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  result = sspp_subblk_offset(a1, 1, &v13);
  if ( !(_DWORD)result )
  {
    if ( a2 >= 2 )
      v7 = 12288;
    else
      v7 = 4096;
    v8 = v13 + v7;
    if ( a2 >= 3 )
      v9 = 10;
    else
      v9 = 5;
    v13 = v8;
    if ( a2 )
      v10 = v9;
    else
      v10 = 15;
    v11 = sde_reg_read(a1, v8 + 116);
    if ( (a3 & 1) != 0 )
      v12 = v11 | v10;
    else
      v12 = v11 & ~v10;
    result = sde_reg_write(a1, v13 + 116, v12, "SSPP_REC_SRC_ADDR_SW_STATUS + idx");
    __dsb(0xEu);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
