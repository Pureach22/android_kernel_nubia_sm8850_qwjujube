__int64 __fastcall sde_hw_intf_reset_counter(__int64 a1)
{
  return sde_reg_write(a1, 176, 0x80000000LL, "INTF_LINE_COUNT");
}
