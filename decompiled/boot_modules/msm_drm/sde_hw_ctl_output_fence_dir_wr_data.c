__int64 __fastcall sde_hw_ctl_output_fence_dir_wr_data(__int64 a1, unsigned int a2)
{
  return sde_reg_write(a1, 644, a2, "CTL_OUTPUT_FENCE_DIR_DATA");
}
