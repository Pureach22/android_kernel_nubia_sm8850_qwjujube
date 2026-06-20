__int64 __fastcall sde_hw_sspp_clear_ubwc_error_v1(__int64 a1, int a2)
{
  const char *v2; // x3
  unsigned int v3; // w1

  if ( a2 == 2 )
  {
    v2 = "SSPP_UBWC_ERROR_STATUS_REC1";
    v3 = 456;
  }
  else
  {
    v2 = "SSPP_UBWC_ERROR_STATUS";
    v3 = 312;
  }
  return sde_reg_write(a1, v3, 0x80000000, v2);
}
