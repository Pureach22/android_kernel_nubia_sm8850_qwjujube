__int64 __fastcall sde_hw_intf_prepare_backup_esync(__int64 a1, __int64 a2)
{
  __int64 v4; // x2

  sde_reg_write(a1, 1148, (*(_DWORD *)a2 << 16) | 8u, "INTF_BKUP_ESYNC_VSYNC_CTL");
  sde_reg_write(
    a1,
    1156,
    (unsigned int)*(unsigned __int16 *)(a2 + 4) | (*(_DWORD *)(a2 + 8) << 16),
    "INTF_BKUP_ESYNC_EMSYNC_CTL");
  sde_reg_write(
    a1,
    1152,
    (unsigned int)*(unsigned __int16 *)(a2 + 12) | (*(_DWORD *)(a2 + 16) << 16),
    "INTF_BKUP_ESYNC_HSYNC_CTL");
  if ( *(_BYTE *)(a2 + 29) )
    v4 = 1808;
  else
    v4 = 16;
  sde_reg_write(a1, 1140, v4, "INTF_BKUP_ESYNC_CTRL");
  return sde_reg_write(a1, 1168, 1, "INTF_ESYNC_HYBRID_CTRL");
}
