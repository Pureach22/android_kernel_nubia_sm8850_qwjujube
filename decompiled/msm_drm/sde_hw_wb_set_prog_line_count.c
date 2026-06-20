__int64 __fastcall sde_hw_wb_set_prog_line_count(__int64 a1, unsigned int a2)
{
  return sde_reg_write(a1, 0x188u, a2, "WB_PROG_LINE_COUNT");
}
