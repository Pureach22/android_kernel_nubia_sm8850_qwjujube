__int64 __fastcall sde_hw_pp_enable_te(__int64 a1, char a2)
{
  if ( !a1 )
    return 4294967274LL;
  sde_reg_write(a1, 0, a2 & 1, "PP_TEAR_CHECK_EN");
  return 0;
}
