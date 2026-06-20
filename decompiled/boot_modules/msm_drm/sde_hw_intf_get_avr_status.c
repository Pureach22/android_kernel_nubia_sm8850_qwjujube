__int64 __fastcall sde_hw_intf_get_avr_status(__int64 result)
{
  if ( result )
    return (unsigned int)sde_reg_read(result, 624) >> 31;
  return result;
}
