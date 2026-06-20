bool __fastcall policy_mgr_is_6ghz_conc_mode_supported(__int64 a1, int a2)
{
  if ( (a2 & 0xFFFFFFFD) == 0 )
    return 1;
  return a2 == 6 || (a2 & 0xFFFFFFFD) == 1;
}
