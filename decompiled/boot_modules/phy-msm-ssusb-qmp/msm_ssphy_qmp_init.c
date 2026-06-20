__int64 __fastcall msm_ssphy_qmp_init(_QWORD *a1)
{
  int v2; // w0
  int v3; // w8
  int v4; // w23
  unsigned int v5; // w20
  int v6; // w21
  __int64 v8; // x8
  unsigned int v9; // w19
  unsigned int v10; // w8
  int v11; // w8
  _QWORD *v12; // x22
  __int64 v13; // x8
  unsigned int v14; // w8
  __int64 v15; // x8
  int v16; // w20
  unsigned int *v17; // x21
  int v18; // w20
  __int64 v20; // x20
  int v21; // w0
  unsigned int v22; // w20

  if ( (*((_BYTE *)a1 + 17) & 2) != 0 )
  {
    dev_info(*a1, "QMP PHY currently in DP mode\n");
    return 4294967280LL;
  }
  v2 = msm_ssusb_qmp_ldo_enable(a1, 1);
  if ( v2 )
  {
    v8 = *a1;
    v9 = v2;
    dev_err(v8, "msm_ssusb_qmp_ldo_enable(1) failed, ret=%d\n", v2);
    return v9;
  }
  msm_ssphy_qmp_enable_clks(a1, 1);
  if ( *((_DWORD *)a1 + 145) != 2 )
  {
    if ( (unsigned int)reset_control_assert(a1[66]) )
    {
      dev_err(*a1, "phy_phy_reset assert failed\n");
    }
    else
    {
      if ( (unsigned int)reset_control_assert(a1[65]) )
      {
        dev_err(*a1, "phy_reset assert failed\n");
      }
      else
      {
        if ( a1[49] )
          writel_relaxed(0);
        if ( !(unsigned int)reset_control_deassert(a1[65]) )
        {
          if ( !(unsigned int)reset_control_deassert(a1[66]) )
            goto LABEL_20;
          goto LABEL_17;
        }
        dev_err(*a1, "phy_reset deassert failed\n");
      }
      if ( (unsigned int)reset_control_deassert(a1[66]) )
LABEL_17:
        dev_err(*a1, "phy_phy_reset deassert failed\n");
    }
    *((_BYTE *)a1 + 547) = 0;
    v3 = *((_DWORD *)a1 + 4);
    if ( (v3 & 4) == 0 )
      goto LABEL_21;
    goto LABEL_32;
  }
  if ( (*((_BYTE *)a1 + 17) & 4) != 0 )
  {
    if ( (unsigned int)reset_control_assert(a1[65]) )
    {
LABEL_27:
      dev_err(*a1, "phy_reset assert failed\n");
      goto LABEL_74;
    }
    if ( (unsigned int)reset_control_deassert(a1[65]) )
    {
      dev_err(*a1, "phy_reset deassert failed\n");
      goto LABEL_74;
    }
LABEL_20:
    v3 = *((_DWORD *)a1 + 4);
    if ( (v3 & 4) == 0 )
      goto LABEL_21;
LABEL_32:
    v6 = 0;
    v5 = 2;
    goto LABEL_33;
  }
  if ( !(unsigned int)reset_control_assert(a1[67]) )
  {
    if ( !(unsigned int)reset_control_assert(a1[65]) )
    {
      if ( (unsigned int)reset_control_deassert(a1[65]) )
        dev_err(*a1, "phy_reset deassert failed\n");
      if ( (unsigned int)reset_control_deassert(a1[67]) )
      {
        dev_err(*a1, "global_phy_reset deassert failed\n");
        goto LABEL_74;
      }
      goto LABEL_20;
    }
    goto LABEL_27;
  }
  dev_err(*a1, "global_phy_reset assert failed\n");
LABEL_74:
  v3 = *((_DWORD *)a1 + 4);
  if ( (v3 & 4) != 0 )
    goto LABEL_32;
LABEL_21:
  if ( (v3 & 8) == 0 )
  {
    v4 = 0;
    v5 = -22;
    v6 = 1;
    goto LABEL_34;
  }
  v6 = 0;
  v5 = 3;
LABEL_33:
  v4 = 1;
LABEL_34:
  v10 = *((_DWORD *)a1 + 145);
  if ( v10 >= 2 )
  {
    if ( v10 != 2 )
    {
      dev_err(*a1, "phy_powerup: Unknown USB QMP PHY type\n");
      goto LABEL_39;
    }
    writel_relaxed(1);
  }
  writel_relaxed(1);
LABEL_39:
  __dsb(0xFu);
  v11 = *((_DWORD *)a1 + 145);
  if ( v11 == 1 )
  {
    if ( v4 )
    {
      dev_err(*a1, "USB QMP PHY: Update TYPEC CTRL(%d)\n", v5);
      goto LABEL_52;
    }
    goto LABEL_54;
  }
  if ( v11 != 2 )
    goto LABEL_54;
  v12 = a1 + 46;
  writel_relaxed(1);
  writel_relaxed(0);
  v13 = *(unsigned int *)(a1[69] + 52LL);
  if ( (_DWORD)v13 )
    readl_relaxed(*v12 + v13);
  if ( (*((_BYTE *)a1 + 17) & 4) != 0 )
  {
    if ( v4 )
    {
LABEL_45:
      dev_err(*a1, "USB DP QMP PHY: Update TYPEC CTRL(%d)\n", v5);
      writel_relaxed(v5);
      if ( !v6 )
      {
LABEL_50:
        if ( (*((_BYTE *)a1 + 17) & 4) != 0 )
          goto LABEL_54;
        goto LABEL_51;
      }
      goto LABEL_49;
    }
  }
  else
  {
    writel_relaxed(15);
    if ( v4 )
      goto LABEL_45;
  }
  if ( !v6 )
    goto LABEL_50;
LABEL_49:
  if ( *(_QWORD *)(*a1 + 608LL) )
    goto LABEL_50;
  dev_err(*a1, "USB DP QMP PHY: NO SW PORTSELECT\n");
  if ( (*((_BYTE *)a1 + 17) & 4) == 0 )
  {
LABEL_51:
    writel_relaxed(3);
    readl_relaxed(*v12 + *(unsigned int *)(a1[69] + 40LL));
    v5 = 0;
LABEL_52:
    writel_relaxed(v5);
  }
LABEL_54:
  __dsb(0xFu);
  v14 = *((_DWORD *)a1 + 145);
  if ( v14 >= 2 )
  {
    if ( v14 != 2 )
    {
      dev_err(*a1, "phy_powerup: Unknown USB QMP PHY type\n");
      goto LABEL_59;
    }
    writel_relaxed(1);
  }
  writel_relaxed(1);
LABEL_59:
  __dsb(0xFu);
  v15 = a1[71];
  if ( v15 )
  {
    if ( *((int *)a1 + 144) >= 2 )
    {
      v16 = 0;
      v17 = (unsigned int *)(v15 + 4);
      do
      {
        writel_relaxed(*v17);
        ++v16;
        v17 += 2;
      }
      while ( v16 < *((_DWORD *)a1 + 144) / 2 );
    }
    writel_relaxed(0);
    writel_relaxed(3);
    __dsb(0xFu);
    v18 = -1000;
    while ( (readl_relaxed(a1[46] + *(unsigned int *)a1[69]) & 0x40) != 0 )
    {
      usleep_range_state(1, 2, 2);
      if ( __CFADD__(v18++, 1) )
      {
        dev_err(*a1, "QMP PHY initialization timeout\n");
        v20 = *a1;
        v21 = readl_relaxed(a1[46] + *(unsigned int *)a1[69]);
        dev_err(v20, "USB3_PHY_PCS_STATUS:%x\n", v21);
        v22 = -16;
        goto LABEL_70;
      }
    }
    return 0;
  }
  else
  {
    dev_err(*a1, "NULL PHY configuration\n");
    dev_err(*a1, "Failed the main PHY configuration\n");
    v22 = -22;
LABEL_70:
    *((_BYTE *)a1 + 547) = 1;
    writel_relaxed(0);
    msm_ssphy_qmp_enable_clks(a1, 0);
    msm_ssusb_qmp_ldo_enable(a1, 0);
    return v22;
  }
}
