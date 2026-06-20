__int64 __fastcall sde_hw_ctl_wait_reset_status(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0

  if ( result )
  {
    v1 = result;
    v2 = sde_reg_read(result, 48);
    if ( (v2 & 1) != 0 )
    {
      v3 = ktime_get(v2);
      while ( (sde_reg_read(v1, 48) & 1) != 0 )
      {
        v4 = usleep_range_state(20, 50, 2);
        if ( ktime_get(v4) - v3 - 100000000 >= 0 )
        {
          printk(&unk_216AEE, "sde_hw_ctl_wait_reset_status");
          return 4294967274LL;
        }
      }
    }
    return 0;
  }
  return result;
}
