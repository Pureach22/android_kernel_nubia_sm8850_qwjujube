__int64 __fastcall sde_hw_ctl_trigger_flush_v1(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x2
  __int64 v4; // x2
  __int64 v5; // x2
  int v6; // w8

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 99) & 0x20) != 0 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 32LL) & 0x40) != 0 )
    {
      v2 = *(unsigned int *)(a1 + 132);
      if ( (_DWORD)v2 )
        sde_reg_write(a1, 316, v2, "CTL_DSPP_0_FLUSH + (i * 4)");
      v3 = *(unsigned int *)(a1 + 136);
      if ( (_DWORD)v3 )
        sde_reg_write(a1, 320, v3, "CTL_DSPP_0_FLUSH + (i * 4)");
      v4 = *(unsigned int *)(a1 + 140);
      if ( (_DWORD)v4 )
        sde_reg_write(a1, 324, v4, "CTL_DSPP_0_FLUSH + (i * 4)");
      v5 = *(unsigned int *)(a1 + 144);
      if ( (_DWORD)v5 )
        sde_reg_write(a1, 328, v5, "CTL_DSPP_0_FLUSH + (i * 4)");
    }
    if ( (*(_BYTE *)(a1 + 98) & 1) != 0 )
    {
      sde_reg_write(a1, 264, *(unsigned int *)(a1 + 100), "cfg[i].flush_reg");
      if ( (*(_BYTE *)(a1 + 98) & 0x40) == 0 )
      {
LABEL_14:
        if ( (*(_BYTE *)(a1 + 98) & 0x80) == 0 )
          goto LABEL_15;
        goto LABEL_23;
      }
    }
    else if ( (*(_BYTE *)(a1 + 98) & 0x40) == 0 )
    {
      goto LABEL_14;
    }
    sde_reg_write(a1, 260, *(unsigned int *)(a1 + 104), "cfg[i].flush_reg");
    if ( (*(_BYTE *)(a1 + 98) & 0x80) == 0 )
    {
LABEL_15:
      if ( (*(_BYTE *)(a1 + 99) & 4) == 0 )
        goto LABEL_16;
      goto LABEL_24;
    }
LABEL_23:
    sde_reg_write(a1, 256, *(unsigned int *)(a1 + 112), "cfg[i].flush_reg");
    if ( (*(_BYTE *)(a1 + 99) & 4) == 0 )
    {
LABEL_16:
      if ( (*(_BYTE *)(a1 + 99) & 0x10) == 0 )
        goto LABEL_17;
      goto LABEL_25;
    }
LABEL_24:
    sde_reg_write(a1, 276, *(unsigned int *)(a1 + 116), "cfg[i].flush_reg");
    if ( (*(_BYTE *)(a1 + 99) & 0x10) == 0 )
    {
LABEL_17:
      v6 = *(_DWORD *)(a1 + 96);
      if ( (v6 & 0x40000000) == 0 )
        goto LABEL_18;
      goto LABEL_26;
    }
LABEL_25:
    sde_reg_write(a1, 268, *(unsigned int *)(a1 + 120), "cfg[i].flush_reg");
    v6 = *(_DWORD *)(a1 + 96);
    if ( (v6 & 0x40000000) == 0 )
    {
LABEL_18:
      if ( (v6 & 0x80000000) == 0 )
      {
LABEL_19:
        sde_reg_write(a1, 24, *(unsigned int *)(a1 + 96), "CTL_FLUSH");
        __dsb(0xEu);
        return 0;
      }
LABEL_27:
      sde_reg_write(a1, 272, *(unsigned int *)(a1 + 128), "cfg[i].flush_reg");
      goto LABEL_19;
    }
LABEL_26:
    sde_reg_write(a1, 296, *(unsigned int *)(a1 + 124), "cfg[i].flush_reg");
    if ( (*(_DWORD *)(a1 + 96) & 0x80000000) == 0 )
      goto LABEL_19;
    goto LABEL_27;
  }
  return 4294967274LL;
}
