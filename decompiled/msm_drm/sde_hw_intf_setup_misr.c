__int64 __fastcall sde_hw_intf_setup_misr(__int64 a1, char a2, unsigned __int8 a3)
{
  __int64 v6; // x2

  sde_reg_write(a1, 384, 1024, "INTF_MISR_CTRL");
  __dsb(0xEu);
  if ( (a2 & 1) != 0 )
    v6 = a3 | 0x81000100;
  else
    v6 = 0;
  return sde_reg_write(a1, 384, v6, "INTF_MISR_CTRL");
}
