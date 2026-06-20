__int64 __fastcall sde_hw_lm_setup_border_color(__int64 result, _DWORD *a2, char a3)
{
  __int64 v4; // x19

  if ( a3 )
  {
    v4 = result;
    sde_reg_write(result, 8, *a2 & 0xFFF | ((a2[1] & 0xFFFu) << 16), "LM_BORDER_COLOR_0");
    return sde_reg_write(v4, 16, a2[2] & 0xFFF | ((a2[3] & 0xFFFu) << 16), "LM_BORDER_COLOR_1");
  }
  return result;
}
