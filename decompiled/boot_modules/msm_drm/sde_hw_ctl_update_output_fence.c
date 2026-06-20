__int64 __fastcall sde_hw_ctl_update_output_fence(__int64 a1, unsigned __int16 a2, unsigned __int16 a3)
{
  return sde_reg_write(a1, 608, a3 | (a2 << 16), "CTL_OUTPUT_FENCE_ID");
}
