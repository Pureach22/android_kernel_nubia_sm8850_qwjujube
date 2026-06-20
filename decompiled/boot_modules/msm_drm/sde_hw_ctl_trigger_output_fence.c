__int64 __fastcall sde_hw_ctl_trigger_output_fence(__int64 a1, char a2)
{
  return sde_reg_write(a1, 604, (16 * (a2 & 0xF)) | 1u, "CTL_OUTPUT_FENCE_CTRL");
}
