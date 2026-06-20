__int64 __fastcall sde_hw_intf_connect_external_te(__int64 a1, char a2)
{
  unsigned int v4; // w0
  int v5; // w8
  unsigned int v6; // w19

  if ( a1 )
  {
    v4 = sde_reg_read(a1, 648);
    if ( (a2 & 1) != 0 )
      v5 = 0x100000;
    else
      v5 = 0;
    v6 = (v4 >> 20) & 1;
    sde_reg_write(a1, 648, v4 & 0xFFEFFFFF | v5, "INTF_TEAR_SYNC_CONFIG_VSYNC");
  }
  else
  {
    return (unsigned int)-22;
  }
  return v6;
}
