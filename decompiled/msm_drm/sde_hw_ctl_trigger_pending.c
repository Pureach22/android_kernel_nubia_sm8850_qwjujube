__int64 __fastcall sde_hw_ctl_trigger_pending(__int64 a1)
{
  if ( !a1 )
    return 4294967274LL;
  sde_reg_write(a1, 208, 1, "CTL_PREPARE");
  return 0;
}
