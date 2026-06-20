__int64 __fastcall sde_hw_intf_set_num_avr_step(__int64 result, __int16 a2)
{
  if ( result )
    return sde_reg_write(result, 1120, a2 & 0xFFF, "MDP_INTF_NUM_AVR_STEP");
  return result;
}
