double __fastcall sde_hw_intf_avr_trigger(__int64 a1)
{
  double result; // d0

  if ( a1 )
  {
    sde_reg_write(a1, 632, 1, "INTF_AVR_TRIGGER");
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "AVR Triggered\n");
  }
  return result;
}
