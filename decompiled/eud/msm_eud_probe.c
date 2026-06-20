unsigned __int64 __fastcall msm_eud_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 *v3; // x0
  __int64 *v4; // x19
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 result; // x0
  __int64 resource_byname; // x0
  int irq_byname; // w0
  __int64 v12; // x8
  __int64 property; // x0
  __int64 *v14; // x0
  __int64 v15; // x0
  unsigned __int64 v16; // x22
  __int64 v17; // x0
  unsigned __int64 v18; // x19
  unsigned __int64 v19; // x0
  __int64 v20; // x1
  unsigned __int64 v21; // x8
  __int64 v22; // x0
  int variable_u16_array; // w22
  __int64 v24; // x9
  __int64 v25; // x0
  int v26; // w8
  __int64 v27; // x9
  _QWORD *v28; // x0
  int v29; // w0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x11
  __int64 v33; // x8
  int v34; // w0
  int v35; // w8
  unsigned __int64 v36; // x19
  __int64 v37; // x21
  unsigned int v38; // w8
  int v39; // w0
  int v40; // w0
  unsigned __int64 v41; // x20
  __int64 v42; // x19
  int v43; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v1 = a1 + 16;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (__int64 *)devm_kmalloc(a1 + 16, 672, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_65;
  }
  v4 = v3;
  *(_QWORD *)(a1 + 168) = v3;
  *v3 = v1;
  v5 = devm_extcon_dev_allocate(v1, &eud_extcon_cable);
  v4[4] = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*v4, "%s: failed to allocate extcon device\n", "msm_eud_probe");
    result = *((unsigned int *)v4 + 8);
    goto LABEL_65;
  }
  v6 = (unsigned int)devm_extcon_dev_register(v1, v5);
  v7 = *v4;
  if ( (_DWORD)v6 )
  {
    v36 = v6;
    dev_err(v7, "%s: failed to register extcon device\n", "msm_eud_probe");
    result = v36;
    goto LABEL_65;
  }
  v8 = devm_phy_optional_get(v7, "usb2-phy");
  v4[82] = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = dev_err_probe(*v4, v8, "no usb2 phy configured\n");
    goto LABEL_65;
  }
  resource_byname = platform_get_resource_byname(a1, 512, "eud_base");
  if ( !resource_byname )
  {
    dev_err(*v4, "%s: failed to get resource eud_base\n", "msm_eud_probe");
    goto LABEL_57;
  }
  result = devm_ioremap_resource(v1, resource_byname);
  v4[3] = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_65;
  irq_byname = platform_get_irq_byname(a1, "eud_irq");
  v12 = *(_QWORD *)(a1 + 760);
  *((_DWORD *)v4 + 2) = irq_byname;
  property = of_find_property(v12, "qcom,secure-eud-en", 0);
  *((_BYTE *)v4 + 624) = property != 0;
  if ( property )
  {
    v14 = (__int64 *)platform_get_resource_byname(a1, 512, "eud_mode_mgr2");
    if ( v14 )
    {
      v4[79] = *v14;
      goto LABEL_12;
    }
    dev_err(*v4, "%s: failed to get resource eud_mode_mgr2\n", "msm_eud_probe");
LABEL_57:
    result = 4294967284LL;
    goto LABEL_65;
  }
LABEL_12:
  v15 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,eud-clock-vote-req", 0);
  *((_BYTE *)v4 + 625) = v15 != 0;
  if ( v15 )
  {
    result = devm_clk_get(v1, "eud_ahb2phy_clk");
    v16 = result;
    v4[80] = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      result = (unsigned int)result;
      goto LABEL_65;
    }
    result = clk_prepare(result);
    if ( (_DWORD)result )
      goto LABEL_65;
    v17 = clk_enable(v16);
    if ( (_DWORD)v17 )
    {
      v18 = v17;
      clk_unprepare(v16);
      result = v18;
      goto LABEL_65;
    }
  }
  v19 = devm_clk_get(v1, "eud_clkref_clk");
  v20 = *((unsigned int *)v4 + 2);
  if ( v19 <= 0xFFFFFFFFFFFFF000LL )
    v21 = v19;
  else
    v21 = 0;
  v4[81] = v21;
  v22 = devm_request_threaded_irq(v1, v20, handle_eud_irq, 0, 4, "eud_irq", v4);
  if ( (_DWORD)v22 )
  {
    v41 = v22;
    dev_err(*v4, "request failed for eud irq\n");
    goto LABEL_61;
  }
  variable_u16_array = of_property_read_variable_u16_array(
                         *(_QWORD *)(a1 + 760),
                         "qcom,eud-utmi-delay",
                         (char *)v4 + 666,
                         1,
                         0);
  if ( variable_u16_array < 0 || *((unsigned __int16 *)v4 + 333) <= 0x1Bu )
    *((_WORD *)v4 + 333) = 0;
  device_set_wakeup_capable(v1, 1);
  device_wakeup_enable(v1);
  irq_set_irq_wake(*((unsigned int *)v4 + 2), 1);
  v4[73] = 0xFFFFFFFE00000LL;
  v4[74] = (__int64)(v4 + 74);
  v4[75] = (__int64)(v4 + 74);
  v4[76] = (__int64)eud_event_notifier;
  v24 = *v4;
  *((_DWORD *)v4 + 84) = 300;
  v25 = *(_QWORD *)(a1 + 760);
  *((_DWORD *)v4 + 57) = 14;
  *((_BYTE *)v4 + 234) = 2;
  v4[39] = 0x10000000;
  v26 = *((_DWORD *)v4 + 2);
  v4[48] = v24;
  v27 = v4[3];
  *((_DWORD *)v4 + 52) = v26;
  v4[7] = v27;
  *(_DWORD *)(a1 + 8) = 0;
  v4[43] = (__int64)eud_uart_ops;
  *((_DWORD *)v4 + 89) = 0;
  if ( of_find_property(v25, "qcom,eud-tcsr-check-enable", 0) )
  {
    v28 = (_QWORD *)platform_get_resource_byname(a1, 512, "eud_tcsr_check_reg");
    if ( !v28 )
    {
      v41 = variable_u16_array & (unsigned int)(variable_u16_array >> 31);
      dev_err(*v4, "Failed to get resource for tcsr check!\n");
      goto LABEL_61;
    }
    v29 = qcom_scm_io_writel(*v28, 1);
    if ( v29 )
      dev_err(v1, "TCSR qcom_scm_io_writel failed with rc:%d\n", v29);
  }
  if ( *((_BYTE *)v4 + 624) == 1 )
  {
    v30 = v4[79];
    v43 = 0;
    qcom_scm_io_readl(v30, &v43);
    if ( (v43 & 1) != 0 )
      enable = 1;
  }
  v31 = uart_add_one_port(&eud_uart_driver, v4 + 5);
  if ( !(_DWORD)v31 )
  {
    v32 = v4[3];
    eud_private = a1;
    eud_ready = 1;
    writel_relaxed(1u, (unsigned int *)(v32 + 4492));
    __dsb(0xEu);
    v43 = 0;
    v33 = *(_QWORD *)(a1 + 168);
    if ( *(_BYTE *)(v33 + 624) == 1 )
    {
      v34 = qcom_scm_io_readl(*(_QWORD *)(v33 + 632), &v43);
      if ( v34 )
      {
        dev_err(v1, "qcom_scm_io_readl failed with rc: %d\n", v34);
        result = 0;
        goto LABEL_65;
      }
      v35 = v43;
    }
    else
    {
      v35 = readl_relaxed(*(_QWORD *)(v33 + 24) + 4116LL) & 1;
    }
    if ( !v35 )
    {
      result = 0;
      goto LABEL_65;
    }
    if ( (v4[83] & 1) == 0 )
    {
      v37 = v4[81];
      if ( !(unsigned int)clk_prepare(v37) )
      {
        if ( !(unsigned int)clk_enable(v37) )
        {
          *((_BYTE *)v4 + 664) = 1;
          goto LABEL_44;
        }
        clk_unprepare(v37);
      }
      dev_err(*v4, "Failed to enable eud_clkref_clk\n");
      v38 = *((unsigned __int16 *)v4 + 333);
      if ( !*((_WORD *)v4 + 333) )
      {
LABEL_46:
        writel_relaxed(0x1Cu, (unsigned int *)(v4[3] + 36));
        __dsb(0xEu);
        if ( !(unsigned int)phy_init(v4[82]) && (unsigned int)phy_power_on(v4[82]) )
          phy_exit(v4[82]);
        v39 = extcon_set_state_sync(v4[4], 1, 1);
        if ( v39 )
          dev_warn(v1, "Failed to set EXTCON_USB (%d)\n", v39);
        v40 = extcon_set_state_sync(v4[4], 5, 1);
        if ( v40 )
          dev_warn(v1, "Failed to set EXTCON_CHG_USB_SDP (%d)\n", v40);
        result = 0;
        *((_BYTE *)v4 + 665) = 1;
        enable = 1;
        goto LABEL_65;
      }
LABEL_45:
      writew_relaxed(v38 >> 8, (unsigned __int16 *)(v4[3] + 4148));
      writew_relaxed(*((unsigned __int8 *)v4 + 666), (unsigned __int16 *)(v4[3] + 4144));
      goto LABEL_46;
    }
LABEL_44:
    v38 = *((unsigned __int16 *)v4 + 333);
    if ( !*((_WORD *)v4 + 333) )
      goto LABEL_46;
    goto LABEL_45;
  }
  v41 = v31;
  dev_err(*v4, "failed to add uart port!\n");
LABEL_61:
  if ( *((_BYTE *)v4 + 625) == 1 )
  {
    v42 = v4[80];
    if ( v42 )
    {
      clk_disable(v42);
      clk_unprepare(v42);
    }
  }
  result = v41;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
