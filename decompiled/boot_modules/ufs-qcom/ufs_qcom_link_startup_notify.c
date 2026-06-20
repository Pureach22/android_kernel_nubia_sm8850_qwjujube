__int64 __fastcall ufs_qcom_link_startup_notify(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w19
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x24
  __int64 v6; // x22
  size_t v7; // x0
  const char *v8; // x1
  int attr; // w0
  int v10; // w0
  int v11; // w0
  int v12; // w21
  int v13; // w22
  int v14; // w0
  int v15; // w3
  __int64 v16; // x25
  unsigned int v17; // w23
  __int64 v18; // x3
  __int64 v19; // x0
  __int64 *v20; // x22
  unsigned __int64 v21; // x8
  __int64 v22; // x1
  int v23; // w0
  __int64 v24; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v27; // x23
  __int64 (__fastcall *v28)(__int64, __int64, _QWORD, _QWORD); // x8
  __int64 v29; // x0
  __int64 v30; // t1
  __int64 v31; // x8
  int v32; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v5 = *(_QWORD *)(a1 + 184);
    v2 = a2;
    v3 = a1;
    v4 = *(_QWORD *)(v5 + 8);
    if ( a2 == 1 )
    {
      v33 = 0;
      attr = ufshcd_dme_get_attr(a1, 358678528, &v33, 0);
      if ( attr )
      {
        dev_err(
          *(_QWORD *)(v3 + 64),
          "%s: couldn't read PA_CONNECTEDTXDATALANES %d\n",
          "ufs_qcom_get_connected_tx_lanes",
          attr);
      }
      else
      {
        ufs_qcom_phy_set_tx_lane_enable(v4, v33);
        if ( (*(_BYTE *)(v3 + 138) & 0x80) != 0 && (*(_BYTE *)(v3 + 213) & 8) == 0 )
        {
          v10 = readl((unsigned int *)(*(_QWORD *)v3 + 252LL));
          writel(v10 | 0x3C, (unsigned int *)(*(_QWORD *)v3 + 252LL));
        }
        __dsb(0xFu);
      }
      v32 = 0;
      v11 = ufshcd_dme_get_attr(v3, 358678528, &v32, 0);
      if ( v11 )
      {
        dev_err(
          *(_QWORD *)(v3 + 64),
          "%s: couldn't read PA_CONNECTEDTXDATALANES %d\n",
          "ufs_qcom_get_connected_tx_lanes",
          v11);
        __break(0x800u);
      }
      v12 = v32;
      v13 = *(_DWORD *)(v3 + 2688);
      if ( v32 != v13 )
      {
        dev_err(
          *(_QWORD *)(v3 + 64),
          "%s: Tx lane mismatch [config,reported] [%d,%d]\n",
          "ufs_qcom_validate_link_params",
          v13,
          v32);
        __break(0x800u);
      }
      v32 = 0;
      v14 = ufshcd_dme_get_attr(v3, 360775680, &v32, 0);
      if ( v14 )
      {
        dev_err(
          *(_QWORD *)(v3 + 64),
          "%s: couldn't read PA_CONNECTEDRXDATALANES %d\n",
          "ufs_qcom_get_connected_rx_lanes",
          v14);
        __break(0x800u);
      }
      v15 = *(_DWORD *)(v3 + 2688);
      if ( v32 == v15 )
      {
        if ( v12 == v13 )
          goto LABEL_30;
      }
      else
      {
        dev_err(
          *(_QWORD *)(v3 + 64),
          "%s: Rx lane mismatch [config,reported] [%d,%d]\n",
          "ufs_qcom_validate_link_params",
          v15,
          v32);
        __break(0x800u);
      }
      v16 = 0;
      v33 = 0;
      do
      {
        v17 = *(_DWORD *)((char *)&unk_183B8 + v16);
        v18 = (unsigned int)ufshcd_dme_get_attr(v3, v17 << 16, &v33, 0);
        v19 = *(_QWORD *)(v3 + 64);
        if ( (_DWORD)v18 )
          dev_err(v19, "Failed reading: 0x%04x, ret:%d\n", v17, v18);
        else
          dev_err(v19, "0x%04x: %d\n", v17, v33);
        v16 += 4;
      }
      while ( v16 != 192 );
      goto LABEL_30;
    }
    if ( a2 )
    {
LABEL_30:
      LODWORD(v4) = 0;
LABEL_43:
      v24 = *(_QWORD *)(v5 + 656);
      if ( v24 && *(_BYTE *)(v5 + 664) == 1 )
        ipc_log_string(v24, ",%d,*,%d,%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40), v2, v4);
      goto LABEL_46;
    }
    v6 = *(_QWORD *)(a1 + 64);
    if ( of_find_property(*(_QWORD *)(v6 + 744), "secondary-storage", 0) )
    {
LABEL_31:
      ufs_qcom_cfg_timers(v3, 0);
      ufs_qcom_phy_ctrl_rx_linecfg(v4, 1);
      v20 = *(__int64 **)(v3 + 2664);
      if ( v20 == (__int64 *)(v3 + 2664) )
      {
LABEL_38:
        v22 = 0;
      }
      else
      {
        while ( 1 )
        {
          v21 = v20[2];
          if ( v21 )
          {
            if ( v21 <= 0xFFFFFFFFFFFFF000LL && !strcmp((const char *)v20[3], "core_clk_unipro") )
              break;
          }
          v20 = (__int64 *)*v20;
          if ( v20 == (__int64 *)(v3 + 2664) )
            goto LABEL_38;
        }
        v22 = *((unsigned int *)v20 + 8);
      }
      LODWORD(v4) = ufs_qcom_core_clk_ctrl(v3, v22);
      if ( (_DWORD)v4 )
        goto LABEL_43;
      v23 = readl_relaxed(*(_QWORD *)(v5 + 160));
      writel_relaxed(v23 | 0x80000000, *(_QWORD *)(v5 + 160));
      __dsb(0xEu);
      LODWORD(v4) = ufshcd_dme_set_attr(v3, 358481920, 0, 0, 0);
      if ( (_DWORD)v4 )
        goto LABEL_43;
      if ( *(_BYTE *)(v5 + 417) == 1 )
      {
        LODWORD(v4) = ufs_qcom_bypass_cfgready_signal(v3);
        goto LABEL_43;
      }
      goto LABEL_30;
    }
    v7 = strnlen(android_boot_dev, 0x1Eu);
    if ( v7 >= 0x1F )
    {
      _fortify_panic(2, 30, v7 + 1);
    }
    else
    {
      if ( !v7 )
        goto LABEL_31;
      if ( v7 != 30 )
      {
        v8 = *(const char **)(v6 + 112);
        if ( !v8 )
          v8 = *(const char **)v6;
        if ( strcmp(android_boot_dev, v8) )
        {
          LODWORD(v4) = -19;
          goto LABEL_46;
        }
        goto LABEL_31;
      }
    }
    a1 = _fortify_panic(4, 30, 31);
  }
  __break(0x800u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v27 = qword_176F8;
    if ( qword_176F8 )
    {
      do
      {
        v28 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD))v27;
        v29 = *(_QWORD *)(v27 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v27 - 4LL) != -34095149 )
          __break(0x8228u);
        a1 = v28(v29, v3, v2, (unsigned int)v4);
        v30 = *(_QWORD *)(v27 + 24);
        v27 += 24;
      }
      while ( v30 );
    }
    v31 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v31;
    if ( !v31 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
