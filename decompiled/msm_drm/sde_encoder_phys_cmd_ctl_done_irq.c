__int64 __fastcall sde_encoder_phys_cmd_ctl_done_irq(__int64 result)
{
  if ( result )
  {
    _ReadStatusReg(SP_EL0);
    return sde_encoder_phys_signal_frame_done();
  }
  return result;
}
