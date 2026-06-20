__int64 __fastcall sde_hw_ctl_get_reset_status(__int64 result)
{
  if ( result )
    return sde_reg_read(result, 48);
  return result;
}
