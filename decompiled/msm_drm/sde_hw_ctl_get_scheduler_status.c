__int64 __fastcall sde_hw_ctl_get_scheduler_status(__int64 a1)
{
  if ( a1 )
    return sde_reg_read(a1, 100);
  else
    return 4294965390LL;
}
