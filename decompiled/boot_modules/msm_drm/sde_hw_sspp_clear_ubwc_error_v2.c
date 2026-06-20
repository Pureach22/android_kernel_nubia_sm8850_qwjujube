__int64 __fastcall sde_hw_sspp_clear_ubwc_error_v2(__int64 a1)
{
  return sde_reg_write(a1, 0xD0u, 0x80000000, "SSPP_REC_UBWC_ERROR_STATUS");
}
