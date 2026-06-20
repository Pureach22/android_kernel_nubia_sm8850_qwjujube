__int64 __fastcall qpace_power_off(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x2
  unsigned int v4; // w0
  __int64 v5; // x2
  unsigned int v6; // w0
  __int64 v7; // x2
  __int64 v9; // x1
  __int64 v10; // x2

  writel(0, (unsigned int *)qpace_gen_core_regs);
  if ( (unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
  {
    _const_udelay(42950000);
    if ( (unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
    {
      _const_udelay(42950000);
      if ( (unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
      {
        _const_udelay(42950000);
        if ( (unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
        {
          _const_udelay(42950000);
          if ( (unsigned int)readl((unsigned int *)(qpace_gen_core_regs + 4)) )
          {
            printk(&unk_7ECC, v2, v3);
            printk(&unk_7C8D, v9, v10);
          }
        }
      }
    }
  }
  v4 = icc_set_bw(qpace_interconnect, 0, 0);
  if ( v4 )
    printk(&unk_7F78, v4, v5);
  v6 = dev_pm_qos_remove_request(&qos_req);
  if ( v6 >= 2 )
    printk(&unk_7EA5, v6, v7);
  device_wakeup_disable(a1);
  return device_set_wakeup_capable(a1, 0);
}
