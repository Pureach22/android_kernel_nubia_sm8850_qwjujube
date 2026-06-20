__int64 __fastcall sde_hw_sspp_clear_meta_error_v1(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  int v5; // w10
  int v6; // w8
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  result = sspp_subblk_offset(a1, 1, &v7);
  if ( !(_DWORD)result )
  {
    v5 = v7;
    if ( a2 >= 2 )
      v6 = 12288;
    else
      v6 = 4096;
    v7 += v6;
    result = sde_reg_write(a1, v5 + v6 + 204, 0x80000000, "SSPP_REC_META_ERROR_STATUS + idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
