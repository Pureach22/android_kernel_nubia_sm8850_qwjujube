__int64 __fastcall sde_hw_sspp_setup_pre_downscale_v1(__int64 result, _DWORD *a2)
{
  __int64 v3; // x19
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    if ( a2 )
    {
      v3 = result;
      v4 = 0;
      result = sspp_subblk_offset(result, 1, &v4);
      if ( !(_DWORD)result )
        result = sde_reg_write(
                   v3,
                   v4 + 4168,
                   *a2 | (unsigned int)(16 * a2[1]) | (a2[2] << 8) | (a2[3] << 12),
                   "SSPP_REC_PRE_DOWN_SCALE + SSPP_REC0_OFFSET_FROM_SSPP_CMN + idx");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
