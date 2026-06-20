__int64 __fastcall sde_hw_ctl_hard_reset(__int64 result, char a2)
{
  if ( result )
    return sde_reg_write(result, 96, a2 & 1, "CTL_SW_RESET_OVERRIDE");
  return result;
}
