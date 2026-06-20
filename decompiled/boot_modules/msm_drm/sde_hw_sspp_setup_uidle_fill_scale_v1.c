__int64 __fastcall sde_hw_sspp_setup_uidle_fill_scale_v1(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  result = sspp_subblk_offset(a1, 1, &v5);
  if ( !(_DWORD)result )
    result = sde_reg_write(a1, v5 + 60, 65793 * (*(_DWORD *)(a2 + 20) & 0xFu), "SSPP_CMN_FILL_LEVEL_SCALE + idx");
  _ReadStatusReg(SP_EL0);
  return result;
}
