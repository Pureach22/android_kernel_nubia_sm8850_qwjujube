__int64 __fastcall sde_hw_ctl_trigger_sw_override(__int64 a1)
{
  sde_reg_write(a1, 600, 0, "CTL_INPUT_FENCE_ID");
  return sde_reg_write(a1, 596, 1, "CTL_FENCE_READY_SW_OVERRIDE");
}
