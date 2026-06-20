__int64 __fastcall sde_hw_intf_avr_enable(__int64 result, char a2)
{
  if ( result )
    return sde_reg_write(result, 624, a2 & 1, "INTF_AVR_CONTROL");
  return result;
}
