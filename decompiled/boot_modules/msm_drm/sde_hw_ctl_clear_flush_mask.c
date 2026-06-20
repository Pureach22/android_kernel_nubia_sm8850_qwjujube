__int64 __fastcall sde_hw_ctl_clear_flush_mask(__int64 a1, int a2)
{
  if ( !a1 )
    return 4294967274LL;
  sde_reg_write(a1, 144, (unsigned int)(a2 << 31 >> 31), "CTL_FLUSH_MASK");
  return 0;
}
