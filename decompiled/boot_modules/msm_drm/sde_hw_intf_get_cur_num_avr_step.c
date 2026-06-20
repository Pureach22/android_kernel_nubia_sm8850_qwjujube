__int64 __fastcall sde_hw_intf_get_cur_num_avr_step(__int64 result)
{
  if ( result )
    return sde_reg_read(result, 1124);
  return result;
}
