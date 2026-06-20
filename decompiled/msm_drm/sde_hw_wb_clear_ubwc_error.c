__int64 __fastcall sde_hw_wb_clear_ubwc_error(__int64 a1)
{
  return sde_reg_write(a1, 0x2BCu, 0x80000000, "WB_UBWC_ERROR_STATUS");
}
