__int64 __fastcall sde_hw_intf_update_tearcheck_vsync_count(__int64 result, int a2)
{
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    v3 = result;
    v4 = sde_reg_read(result, 648);
    sde_reg_write(v3, 648, v4 & 0xFFEFFFFF, "INTF_TEAR_SYNC_CONFIG_VSYNC");
    result = sde_reg_write(v3, 648, a2 & 0x7FFFF | 0x180000u, "INTF_TEAR_SYNC_CONFIG_VSYNC");
    __dsb(0xEu);
  }
  return result;
}
