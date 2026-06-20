__int64 __fastcall sde_hw_intf_prepare_esync(__int64 a1, __int64 a2)
{
  __int64 v4; // x2

  sde_reg_write(a1, 1036, (*(_DWORD *)a2 << 16) | 8u, "INTF_ESYNC_VSYNC_CTL");
  sde_reg_write(
    a1,
    1048,
    (unsigned int)*(unsigned __int16 *)(a2 + 4) | (*(_DWORD *)(a2 + 8) << 16),
    "INTF_ESYNC_EMSYNC_CTL");
  sde_reg_write(
    a1,
    1040,
    (unsigned int)*(unsigned __int16 *)(a2 + 12) | (*(_DWORD *)(a2 + 16) << 16),
    "INTF_ESYNC_HSYNC_CTL");
  sde_reg_write(a1, 1032, *(unsigned __int16 *)(a2 + 24), "INTF_ESYNC_MDP_VSYNC_CTL");
  sde_reg_write(a1, 1052, 0, "INTF_ESYNC_PROG_INIT");
  sde_reg_write(a1, 1044, *(unsigned __int16 *)(a2 + 20), "INTF_ESYNC_SKEW_CTL");
  if ( *(_BYTE *)(a2 + 29) )
    v4 = 1808;
  else
    v4 = 16;
  sde_reg_write(a1, 1028, v4, "INTF_ESYNC_CTRL");
  return sde_reg_write(a1, 1168, 0, "INTF_ESYNC_HYBRID_CTRL");
}
