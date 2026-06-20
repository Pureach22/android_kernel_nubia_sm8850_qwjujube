__int64 __fastcall sde_hw_pp_setup_te_config(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  int v4; // w8

  v2 = -22;
  if ( a1 && a2 )
  {
    if ( *(_BYTE *)(a2 + 32) )
      v4 = 1572864;
    else
      v4 = 0x80000;
    sde_reg_write(a1, 4u, v4 | *(_DWORD *)a2, "PP_SYNC_CONFIG_VSYNC");
    sde_reg_write(a1, 8u, *(_DWORD *)(a2 + 4), "PP_SYNC_CONFIG_HEIGHT");
    sde_reg_write(a1, 0x10u, *(_DWORD *)(a2 + 8), "PP_VSYNC_INIT_VAL");
    sde_reg_write(a1, 0x20u, *(_DWORD *)(a2 + 24), "PP_RD_PTR_IRQ");
    sde_reg_write(a1, 0x24u, *(_DWORD *)(a2 + 28), "PP_WR_PTR_IRQ");
    sde_reg_write(a1, 0x1Cu, *(_DWORD *)(a2 + 20), "PP_START_POS");
    sde_reg_write(a1, 0x18u, *(_DWORD *)(a2 + 12) | (*(_DWORD *)(a2 + 16) << 16), "PP_SYNC_THRESH");
    sde_reg_write(a1, 0xCu, *(_DWORD *)(a2 + 20) + *(_DWORD *)(a2 + 12) + 1, "PP_SYNC_WRCOUNT");
    return 0;
  }
  return v2;
}
