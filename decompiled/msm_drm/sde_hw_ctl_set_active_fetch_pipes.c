__int64 __fastcall sde_hw_ctl_set_active_fetch_pipes(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x2
  __int64 i; // x10

  v2 = 0;
  if ( a2 )
  {
    for ( i = 1; i != 15; ++i )
    {
      if ( ((*a2 >> i) & 1) != 0 )
        v2 = (unsigned int)v2 | (unsigned int)(1LL << pipe_active_tbl[i]);
    }
  }
  return sde_reg_write(a1, 252, v2, "CTL_FETCH_PIPE_ACTIVE");
}
