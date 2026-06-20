__int64 __fastcall sde_hw_intf_enable_infinite_vfp(__int64 a1, char a2)
{
  unsigned int v4; // w0
  __int64 v5; // x2

  v4 = sde_reg_read(a1, 628);
  if ( (a2 & 1) != 0 )
    v5 = v4 | 0x200;
  else
    v5 = v4;
  return sde_reg_write(a1, 628, v5, "INTF_AVR_MODE");
}
