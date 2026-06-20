__int64 __fastcall sde_encoder_phys_cmd_pp_tx_done_irq(__int64 result)
{
  if ( result )
  {
    if ( *(_QWORD *)(result + 496) )
    {
      _ReadStatusReg(SP_EL0);
      return sde_encoder_phys_signal_frame_done();
    }
  }
  return result;
}
