__int64 __fastcall sde_hw_ctl_output_fence_dir_wr_init(__int64 a1, unsigned int a2, char a3, unsigned int a4)
{
  int v8; // w0

  v8 = sde_reg_read(a1, 652);
  sde_reg_write(a1, 652, v8 & 0xFFFFFF8F | (16 * (a3 & 7)), "CTL_OUTPUT_FENCE_DIR_ATTR");
  sde_reg_write(a1, 648, a4, "CTL_OUTPUT_FENCE_DIR_MASK");
  return sde_reg_write(a1, 640, a2, "CTL_OUTPUT_FENCE_DIR_ADDR");
}
