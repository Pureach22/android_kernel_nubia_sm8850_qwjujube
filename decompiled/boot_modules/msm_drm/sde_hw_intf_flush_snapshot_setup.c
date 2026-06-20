__int64 __fastcall sde_hw_intf_flush_snapshot_setup(__int64 result, unsigned int a2, char a3)
{
  __int64 v5; // x21
  int v6; // w0
  unsigned int v7; // w20

  if ( result )
  {
    v5 = result;
    v6 = sde_reg_read(result, 4);
    if ( (a3 & 1) != 0 )
      v7 = v6 | 0x4000;
    else
      v7 = v6 & 0x4000;
    sde_reg_write(v5, 432, a2, "INTF_PROG_FLUSH_SNAPSHOT");
    return sde_reg_write(v5, 4, v7, "INTF_CONFIG");
  }
  return result;
}
