__int64 __fastcall sde_hw_sspp_setup_solidfill_v1(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  int v7; // w10
  int v8; // w8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  result = sspp_subblk_offset(a1, 1, &v9);
  if ( !(_DWORD)result )
  {
    v7 = v9;
    if ( a3 >= 2 )
      v8 = 12288;
    else
      v8 = 4096;
    v9 += v8;
    result = sde_reg_write(a1, v7 + v8 + 12, a2, "SSPP_REC_SRC_CONSTANT_COLOR + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
