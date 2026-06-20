bool __fastcall sde_hw_wb_setup_clk_force_ctrl(__int64 a1, int a2, char a3)
{
  _BOOL8 result; // x0
  int v6; // w0
  char v7; // w21

  result = 0;
  if ( a1 )
  {
    if ( (unsigned int)(a2 - 15) <= 2 )
    {
      v6 = sde_reg_read(a1, 0x178u);
      v7 = v6;
      sde_reg_write(a1, 0x178u, v6 & 0xFFFFFFFE | a3 & 1, "WB_CLK_CTRL");
      __dsb(0xEu);
      return (v7 & 1) == 0;
    }
  }
  return result;
}
