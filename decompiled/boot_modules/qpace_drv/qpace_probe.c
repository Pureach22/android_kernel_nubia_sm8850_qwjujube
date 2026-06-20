__int64 __fastcall qpace_probe(__int64 a1)
{
  __int64 v2; // x19
  unsigned int irq; // w20
  unsigned int v4; // w0
  unsigned __int64 v5; // x0
  unsigned int v6; // w0
  __int64 cpu_device; // x0
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x2
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x1
  __int64 v14; // x2
  unsigned int v15; // w0
  __int64 v16; // x2
  const char *v17; // x1
  int v18; // w0
  int v19; // w0
  int v20; // w0
  __int64 v21; // x1
  __int64 v22; // x2
  unsigned int v24; // w0
  __int64 v25; // x2
  unsigned int inited; // w0
  _QWORD *v27; // x8

  v2 = a1 + 16;
  irq = ((__int64 (*)(void))platform_get_irq)();
  if ( (irq & 0x80000000) != 0 )
    goto LABEL_27;
  v4 = devm_request_threaded_irq(v2, irq, event_or_word_error_interrupt_handler, 0, 0, "qpace-event-or-word-err-irq", 0);
  if ( v4 )
  {
LABEL_28:
    irq = v4;
    v17 = "failed to request urgent interrupt\n";
    goto LABEL_29;
  }
  irq = platform_get_irq(a1, 1);
  if ( (irq & 0x80000000) != 0 )
  {
LABEL_27:
    v17 = "Failed to find urgent interrupt\n";
LABEL_29:
    dev_err(v2, v17);
    return irq;
  }
  v4 = devm_request_threaded_irq(v2, irq, urgent_interrupt_handler, 0, 0, "qpace-urgent-irq", 0);
  if ( v4 )
    goto LABEL_28;
  qpace_gen_regs = devm_ioremap(v2, 826277888, 4096);
  if ( !qpace_gen_regs )
    return (unsigned int)-22;
  qpace_gen_core_regs = devm_ioremap(v2, 826281984, 4096);
  if ( !qpace_gen_core_regs )
    return (unsigned int)-22;
  qpace_comp_core_regs = devm_ioremap(v2, 826286080, 4096);
  if ( !qpace_comp_core_regs )
    return (unsigned int)-22;
  qpace_decomp_core_regs = devm_ioremap(v2, 826302464, 4096);
  if ( !qpace_decomp_core_regs )
    return (unsigned int)-22;
  qpace_copy_core_regs = devm_ioremap(v2, 826318848, 4096);
  if ( !qpace_copy_core_regs )
    return (unsigned int)-22;
  qpace_urg_regs = devm_ioremap(v2, 826343424, 0x8000);
  if ( !qpace_urg_regs )
    return (unsigned int)-22;
  qpace_tr_regs = devm_ioremap(v2, 826474496, 0x8000);
  if ( !qpace_tr_regs )
    return (unsigned int)-22;
  qpace_er_regs = devm_ioremap(v2, 826605568, 0x8000);
  if ( !qpace_er_regs )
    return (unsigned int)-22;
  qpace_gen_cmd_regs = devm_ioremap(v2, 826736640, 4096);
  if ( !qpace_gen_cmd_regs )
    return (unsigned int)-22;
  v5 = devm_of_icc_get(v2, 0);
  irq = v5;
  qpace_interconnect = v5;
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_7F41, "qpace_power_on", (unsigned int)v5);
    if ( qpace_interconnect )
    {
      if ( irq )
        return irq;
      goto LABEL_32;
    }
    return (unsigned int)-22;
  }
  device_set_wakeup_capable(v2, 1);
  v6 = device_wakeup_enable(v2);
  if ( v6 )
  {
    irq = v6;
    printk(&unk_7C62, "qpace_power_on", v6);
    return irq;
  }
  cpu_device = get_cpu_device();
  v8 = dev_pm_qos_add_request(cpu_device, &qos_req, 1, 0x7FFFFFFF);
  if ( v8 >= 2 )
  {
    irq = v8;
    printk(&unk_7E76, "qpace_power_on", v8);
LABEL_42:
    device_wakeup_disable(v2);
    device_set_wakeup_capable(v2, 0);
    return irq;
  }
  icc_set_tag(qpace_interconnect, 3);
  v9 = icc_set_bw(qpace_interconnect, 0, 1);
  if ( v9 )
  {
    irq = v9;
    printk(&unk_7E03, v9, v10);
LABEL_40:
    v24 = dev_pm_qos_remove_request(&qos_req);
    if ( v24 >= 2 )
      printk(&unk_7EA5, v24, v25);
    goto LABEL_42;
  }
  writel(1u, (unsigned int *)qpace_gen_core_regs);
  if ( !(unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
  {
    _const_udelay(42950000);
    if ( !(unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
    {
      _const_udelay(42950000);
      if ( !(unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
      {
        _const_udelay(42950000);
        if ( !(unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
        {
          _const_udelay(42950000);
          if ( !(unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
          {
            printk(&unk_7ECC, v11, v12);
            printk(&unk_7E26, v13, v14);
            v15 = icc_set_bw(qpace_interconnect, 0, 0);
            if ( v15 )
              printk(&unk_7D11, v15, v16);
            irq = -22;
            goto LABEL_40;
          }
        }
      }
    }
  }
LABEL_32:
  v18 = readl((unsigned int *)(qpace_gen_regs + 20));
  writel(v18 & 0xFFFC0FFF | 0x1000, (unsigned int *)(qpace_gen_regs + 20));
  v19 = readl((unsigned int *)(qpace_comp_core_regs + 4));
  writel(v19 | 0x1F, (unsigned int *)(qpace_comp_core_regs + 4));
  v20 = readl((unsigned int *)(qpace_gen_core_regs + 8));
  writel(v20 | 8, (unsigned int *)(qpace_gen_core_regs + 8));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 64));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 72));
  writel(0, (unsigned int *)(qpace_urg_regs + 80));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 88));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 4160));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 4168));
  writel(0, (unsigned int *)(qpace_urg_regs + 4176));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 4184));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 8256));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 8264));
  writel(0, (unsigned int *)(qpace_urg_regs + 8272));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 8280));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 12352));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 12360));
  writel(0, (unsigned int *)(qpace_urg_regs + 12368));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 12376));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 16448));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 16456));
  writel(0, (unsigned int *)(qpace_urg_regs + 16464));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 16472));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 20544));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 20552));
  writel(0, (unsigned int *)(qpace_urg_regs + 20560));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 20568));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 24640));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 24648));
  writel(0, (unsigned int *)(qpace_urg_regs + 24656));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 24664));
  writel(0xFFFu, (unsigned int *)(qpace_urg_regs + 28736));
  writel(0x200010u, (unsigned int *)(qpace_urg_regs + 28744));
  writel(0, (unsigned int *)(qpace_urg_regs + 28752));
  writel(0x200020u, (unsigned int *)(qpace_urg_regs + 28760));
  tr_rings = _kmalloc_cache_noprof(panic, 3520, 64);
  if ( tr_rings )
  {
    printk(&unk_7CF3, v21, v22);
    irq = init_transfer_ring(0, 0);
    if ( !irq )
    {
      inited = init_transfer_ring(1, 0);
      if ( inited )
      {
        v27 = (_QWORD *)tr_rings;
        irq = inited;
      }
      else
      {
        ev_rings = _kmalloc_cache_noprof(complete, 3520, 128);
        if ( ev_rings )
        {
          irq = init_event_ring(0, 0);
          if ( !irq )
          {
            irq = init_event_ring(1, 0);
            if ( !irq )
            {
              writel(3u, (unsigned int *)(qpace_gen_cmd_regs + 16));
              qpace_dev = v2;
              return irq;
            }
            _free_pages(
              ((unsigned __int64)(((__int64)(*(_QWORD *)(ev_rings + 32) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
            - 0x140000000LL,
              0);
          }
          kfree(ev_rings);
        }
        else
        {
          irq = -12;
        }
        _free_pages(
          ((unsigned __int64)(((__int64)(*(_QWORD *)tr_rings << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          0);
        v27 = (_QWORD *)(tr_rings + 32);
      }
      _free_pages(((unsigned __int64)(((__int64)(*v27 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL, 0);
    }
    kfree(tr_rings);
  }
  else
  {
    irq = -12;
  }
  qpace_power_off(v2);
  return irq;
}
