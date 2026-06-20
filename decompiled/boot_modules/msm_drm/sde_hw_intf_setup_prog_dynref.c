__int64 __fastcall sde_hw_intf_setup_prog_dynref(__int64 a1, unsigned int a2)
{
  return sde_reg_write(a1, 1056, a2, "INTF_PROG_DR_START");
}
