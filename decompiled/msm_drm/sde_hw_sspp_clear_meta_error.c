__int64 __fastcall sde_hw_sspp_clear_meta_error(__int64 a1, int a2)
{
  const char *v2; // x3
  unsigned int v3; // w1

  if ( a2 == 2 )
  {
    v2 = "SSPP_META_ERROR_STATUS_REC1";
    v3 = 452;
  }
  else
  {
    v2 = "SSPP_META_ERROR_STATUS";
    v3 = 300;
  }
  return sde_reg_write(a1, v3, 0x80000000, v2);
}
