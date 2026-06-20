__int64 __fastcall sde_hw_ctl_get_intf_master(__int64 a1)
{
  if ( a1 )
    return sde_reg_read(a1, 308);
  else
    return 4294967274LL;
}
