__int64 __fastcall sde_hw_intf_setup_te_config(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned int v5; // w20
  int v6; // w22
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(unsigned __int8 *)(a2 + 32);
    v8 = 0;
    v5 = *(_DWORD *)a2 | ((v2 != 0) << 20);
    raw_spin_lock(&v8);
    v6 = *(_DWORD *)(a2 + 20) + *(_DWORD *)(a2 + 12);
    sde_reg_write(a1, 648, v5, "INTF_TEAR_SYNC_CONFIG_VSYNC");
    __dsb(0xEu);
    sde_reg_write(a1, 652, *(unsigned int *)(a2 + 4), "INTF_TEAR_SYNC_CONFIG_HEIGHT");
    sde_reg_write(a1, 660, *(unsigned int *)(a2 + 8), "INTF_TEAR_VSYNC_INIT_VAL");
    sde_reg_write(a1, 676, *(unsigned int *)(a2 + 24), "INTF_TEAR_RD_PTR_IRQ");
    sde_reg_write(a1, 680, *(unsigned int *)(a2 + 28), "INTF_TEAR_WR_PTR_IRQ");
    sde_reg_write(a1, 672, *(unsigned int *)(a2 + 20), "INTF_TEAR_START_POS");
    sde_reg_write(a1, 696, *(unsigned int *)(a2 + 36), "INTF_TEAR_TEAR_DETECT_CTRL");
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10) != 0 )
      sde_reg_write(
        a1,
        736,
        *(unsigned __int16 *)(a2 + 14) | (*(unsigned __int16 *)(a2 + 18) << 16),
        "INTF_TEAR_SYNC_THRESH_EXT");
    sde_reg_write(
      a1,
      668,
      (unsigned int)*(unsigned __int16 *)(a2 + 12) | (*(_DWORD *)(a2 + 16) << 16),
      "INTF_TEAR_SYNC_THRESH");
    sde_reg_write(a1, 648, v5 | 0x80000, "INTF_TEAR_SYNC_CONFIG_VSYNC");
    __dsb(0xEu);
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10) != 0 )
      sde_reg_write(a1, 740, (unsigned int)(v6 + 1) >> 16, "INTF_TEAR_SYNC_WRCOUNT_EXT");
    sde_reg_write(a1, 656, (unsigned __int16)(v6 + 1), "INTF_TEAR_SYNC_WRCOUNT");
    raw_spin_unlock(&v8);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
