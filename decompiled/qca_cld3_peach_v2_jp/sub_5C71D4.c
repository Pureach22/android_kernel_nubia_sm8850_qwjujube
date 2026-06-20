__int64 sub_5C71D4()
{
  __int64 v0; // x28

  if ( (v0 & 0x4000000000LL) != 0 )
    JUMPOUT(0x5CE740);
  return ucfg_tdls_get_current_mode();
}
