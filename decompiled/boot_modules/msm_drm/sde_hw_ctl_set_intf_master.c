__int64 __fastcall sde_hw_ctl_set_intf_master(__int64 a1, char a2)
{
  if ( !a1 )
    return 4294967274LL;
  sde_reg_write(a1, 308, 1LL << (a2 - 1), "CTL_INTF_MASTER");
  return 0;
}
