__int64 __fastcall sde_hw_intf_enable_te_level_mode(__int64 a1, char a2)
{
  int v4; // w9
  int v5; // w8

  v4 = sde_reg_read(a1, 644) & 0xFFFFFF7F;
  if ( (a2 & 1) != 0 )
    v5 = 128;
  else
    v5 = 0;
  return sde_reg_write(a1, 644, v4 | (unsigned int)v5, "INTF_TEAR_TEAR_CHECK_EN");
}
