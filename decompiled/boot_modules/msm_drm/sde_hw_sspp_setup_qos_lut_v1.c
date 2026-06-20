__int64 __fastcall sde_hw_sspp_setup_qos_lut_v1(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  result = sspp_subblk_offset(a1, 1, &v6);
  if ( !(_DWORD)result )
  {
    sde_reg_write(a1, v6 + 44, *a2, "SSPP_CMN_DANGER_LUT + idx");
    result = sde_reg_write(a1, v6 + 48, a2[1], "SSPP_CMN_SAFE_LUT + idx");
    v5 = *(_QWORD *)(a1 + 56);
    if ( v5 )
    {
      if ( (*(_QWORD *)(v5 + 40) & 4) != 0 )
      {
        sde_reg_write(a1, v6 + 52, a2[2], "SSPP_CMN_CREQ_LUT_0 + idx");
        result = sde_reg_write(a1, v6 + 56, a2[3], "SSPP_CMN_CREQ_LUT_1 + idx");
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
