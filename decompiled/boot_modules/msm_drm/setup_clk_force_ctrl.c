bool __fastcall setup_clk_force_ctrl(__int64 a1, int a2, char a3)
{
  _BOOL8 result; // x0
  int v6; // w0
  int v7; // w8
  int v8; // w21

  result = 0;
  if ( a1 && a2 == 18 )
  {
    v6 = sde_reg_read(a1, 0x1F0u);
    if ( (a3 & 1) != 0 )
      v7 = 65537;
    else
      v7 = 0;
    v8 = v6;
    sde_reg_write(a1, 0x1F0u, v6 & 0xFFFEFFFE | v7, "PMU_CLK_CTRL");
    __dsb(0xEu);
    return (v8 & 0x10001) == 0;
  }
  return result;
}
