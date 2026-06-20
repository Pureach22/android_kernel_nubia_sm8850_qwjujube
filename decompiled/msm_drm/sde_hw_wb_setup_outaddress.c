__int64 __fastcall sde_hw_wb_setup_outaddress(__int64 a1, unsigned int *a2)
{
  sde_reg_write(a1, 0xCu, a2[6], "WB_DST0_ADDR");
  sde_reg_write(a1, 0x10u, a2[7], "WB_DST1_ADDR");
  sde_reg_write(a1, 0x14u, a2[8], "WB_DST2_ADDR");
  return sde_reg_write(a1, 0x18u, a2[9], "WB_DST3_ADDR");
}
