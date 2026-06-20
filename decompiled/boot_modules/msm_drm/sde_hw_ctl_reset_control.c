__int64 __fastcall sde_hw_ctl_reset_control(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0

  if ( result )
  {
    v1 = result;
    v2 = sde_reg_write(result, 48, 1, "CTL_SW_RESET");
    v3 = ktime_get(v2);
    while ( (sde_reg_read(v1, 48) & 1) != 0 )
    {
      v4 = usleep_range_state(20, 50, 2);
      if ( ktime_get(v4) - v3 - 2000000 >= 0 )
        return 4294967274LL;
    }
    return 0;
  }
  return result;
}
