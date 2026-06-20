__int64 __fastcall sde_hw_lm_setup_border_color_10_bits(__int64 result, _DWORD *a2, char a3)
{
  __int64 v4; // x19

  if ( a3 )
  {
    v4 = result;
    sde_reg_write(result, 28, *a2 & 0x3FF | ((a2[1] & 0x3FFu) << 16), "LM_BORDER_COLOR_0_V1");
    return sde_reg_write(v4, 32, a2[2] & 0x3FF | ((a2[3] & 0x3FFu) << 16), "LM_BORDER_COLOR_1_V1");
  }
  return result;
}
