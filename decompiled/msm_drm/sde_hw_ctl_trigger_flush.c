__int64 __fastcall sde_hw_ctl_trigger_flush(__int64 a1)
{
  if ( !a1 )
    return 4294967274LL;
  sde_reg_write(a1, 24, *(unsigned int *)(a1 + 96), "CTL_FLUSH");
  return 0;
}
