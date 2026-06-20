__int64 __fastcall sde_encoder_phys_wb_done_irq(__int64 a1)
{
  _ReadStatusReg(SP_EL0);
  return sde_encoder_phys_wb_frame_done_helper(a1, 0);
}
