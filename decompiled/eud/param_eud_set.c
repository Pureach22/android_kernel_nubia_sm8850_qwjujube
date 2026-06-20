__int64 __fastcall param_eud_set(const char *a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w9
  __int64 v5; // x21
  __int64 v6; // x20
  int v7; // w0
  int v8; // w0
  __int64 v9; // x19
  unsigned int v10; // w8
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x19
  __int64 v14; // x20
  int v15; // w0
  __int64 v16; // x19
  __int64 v17; // x0
  int v18; // w19
  unsigned int v19; // [xsp+0h] [xbp-10h] BYREF
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( sscanf(a1, "%du", &v19) != 1 || v19 > 1 )
  {
    result = 4294967274LL;
    goto LABEL_28;
  }
  v4 = (unsigned __int8)eud_ready;
  **(_DWORD **)(a2 + 32) = v19;
  if ( v4 != 1 )
    goto LABEL_27;
  if ( !v19 )
  {
    v13 = eud_private;
    v14 = *(_QWORD *)(eud_private + 168);
    if ( *(_BYTE *)(v14 + 665) == 1 )
    {
      extcon_set_state(*(_QWORD *)(v14 + 32), 61, 0);
      extcon_set_state_sync(*(_QWORD *)(v14 + 32), 1, 0);
      writel_relaxed(0, *(_QWORD *)(v14 + 24) + 4116LL);
      if ( *(_BYTE *)(v14 + 624) == 1 && (v15 = qcom_scm_io_writel(*(_QWORD *)(v14 + 632), 0)) != 0 )
      {
        dev_err(v13 + 16, "qcom_scm_io_write failed with rc:%d\n", v15);
        if ( !*(_BYTE *)(v14 + 664) )
          goto LABEL_26;
      }
      else if ( !*(_BYTE *)(v14 + 664) )
      {
LABEL_26:
        usleep_range_state(50, 100, 2);
        extcon_set_state_sync(*(_QWORD *)(v14 + 32), 1, 1);
        v17 = *(_QWORD *)(v14 + 656);
        *(_BYTE *)(v14 + 665) = 0;
        phy_power_off(v17);
        phy_exit(*(_QWORD *)(v14 + 656));
        goto LABEL_27;
      }
      v16 = *(_QWORD *)(v14 + 648);
      clk_disable(v16);
      clk_unprepare(v16);
      *(_BYTE *)(v14 + 664) = 0;
      goto LABEL_26;
    }
LABEL_27:
    result = 0;
    goto LABEL_28;
  }
  if ( v19 != 1 )
    goto LABEL_27;
  v5 = eud_private;
  v6 = *(_QWORD *)(eud_private + 168);
  if ( (*(_BYTE *)(v6 + 665) & 1) != 0 )
    goto LABEL_27;
  v7 = phy_init(*(_QWORD *)(v6 + 656));
  if ( v7 )
  {
    v18 = v7;
LABEL_31:
    dev_err(v5 + 16, "Phy enable failed rc:%d\n", v18);
    goto LABEL_27;
  }
  v8 = phy_power_on(*(_QWORD *)(v6 + 656));
  if ( v8 )
  {
    v18 = v8;
    phy_exit(*(_QWORD *)(v6 + 656));
    goto LABEL_31;
  }
  extcon_set_state_sync(*(_QWORD *)(v6 + 32), 1, 1);
  extcon_set_state(*(_QWORD *)(v6 + 32), 61, 0);
  extcon_set_state_sync(*(_QWORD *)(v6 + 32), 1, 0);
  if ( (*(_BYTE *)(v6 + 664) & 1) != 0 )
    goto LABEL_14;
  v9 = *(_QWORD *)(v6 + 648);
  if ( !(unsigned int)clk_prepare(v9) )
  {
    if ( !(unsigned int)clk_enable(v9) )
    {
      *(_BYTE *)(v6 + 664) = 1;
LABEL_14:
      v10 = *(unsigned __int16 *)(v6 + 666);
      if ( !*(_WORD *)(v6 + 666) )
        goto LABEL_16;
      goto LABEL_15;
    }
    clk_unprepare(v9);
  }
  dev_err(*(_QWORD *)v6, "Failed to enable eud_clkref_clk\n");
  v10 = *(unsigned __int16 *)(v6 + 666);
  if ( *(_WORD *)(v6 + 666) )
  {
LABEL_15:
    writew_relaxed(v10 >> 8, *(_QWORD *)(v6 + 24) + 4148LL);
    writew_relaxed(*(unsigned __int8 *)(v6 + 666), *(_QWORD *)(v6 + 24) + 4144LL);
  }
LABEL_16:
  writel_relaxed(1, *(_QWORD *)(v6 + 24) + 4116LL);
  writel_relaxed(28, *(_QWORD *)(v6 + 24) + 36LL);
  __dsb(0xEu);
  if ( *(_BYTE *)(v6 + 624) == 1 )
  {
    v11 = *(_QWORD *)(v6 + 632);
    v20 = 0;
    qcom_scm_io_readl(v11, &v20);
    if ( (v20 & 1) == 0 )
    {
      v12 = qcom_scm_io_writel(*(_QWORD *)(v6 + 632), 1);
      if ( v12 )
        dev_err(v5 + 16, "qcom_scm_io_writel failed with rc:%d\n", v12);
    }
  }
  __dsb(0xEu);
  usleep_range_state(50, 100, 2);
  extcon_set_state_sync(*(_QWORD *)(v6 + 32), 1, 1);
  extcon_set_state_sync(*(_QWORD *)(v6 + 32), 5, 1);
  result = 0;
  *(_BYTE *)(v6 + 665) = 1;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
