__int64 __fastcall sde_hw_ctl_trigger_output_fence_override(__int64 a1)
{
  return sde_reg_write(a1, 636, 1, "CTL_OUTPUT_FENCE_SW_OVERRIDE");
}
