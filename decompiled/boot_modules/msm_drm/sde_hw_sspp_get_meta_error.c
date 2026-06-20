__int64 __fastcall sde_hw_sspp_get_meta_error(__int64 a1, int a2)
{
  unsigned int v2; // w1

  if ( a2 == 2 )
    v2 = 452;
  else
    v2 = 300;
  return sde_reg_read(a1, v2);
}
