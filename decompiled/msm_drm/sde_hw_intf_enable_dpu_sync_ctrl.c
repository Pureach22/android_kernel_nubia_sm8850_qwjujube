__int64 __fastcall sde_hw_intf_enable_dpu_sync_ctrl(__int64 a1, int a2)
{
  int v4; // w20
  __int64 result; // x0

  v4 = sde_reg_read(a1, 400);
  if ( a2 )
    return sde_reg_write(a1, 400, v4 | 1u, "INTF_DPU_SYNC_CTRL");
  sde_reg_write(a1, 0, 1, "INTF_TIMING_ENGINE_EN");
  __dsb(0xEu);
  result = sde_reg_write(a1, 400, v4 & 0xFFFFFFFE, "INTF_DPU_SYNC_CTRL");
  __dsb(0xEu);
  return result;
}
