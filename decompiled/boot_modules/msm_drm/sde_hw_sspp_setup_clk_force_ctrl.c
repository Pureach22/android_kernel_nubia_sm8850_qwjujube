bool __fastcall sde_hw_sspp_setup_clk_force_ctrl(__int64 a1, int a2, char a3)
{
  _BOOL8 result; // x0
  int v6; // w0
  char v7; // w21

  result = 0;
  if ( a1 )
  {
    if ( (unsigned int)(a2 - 1) <= 0xD )
    {
      v6 = sde_reg_read(a1, 0x330u);
      v7 = v6;
      sde_reg_write(a1, 0x330u, v6 & 0xFFFFFFFE | a3 & 1, "SSPP_CLK_CTRL");
      __dsb(0xEu);
      return (v7 & 1) == 0;
    }
  }
  return result;
}
