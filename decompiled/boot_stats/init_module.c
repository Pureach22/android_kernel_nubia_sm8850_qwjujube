__int64 init_module()
{
  __int64 compatible_node; // x0
  __int64 v1; // x1
  __int64 v2; // x0
  __int64 v3; // x19
  void *v4; // x0
  unsigned int v6; // w0
  unsigned int v7; // w0
  int v8; // w19
  int v9; // w0
  unsigned int v10; // w0

  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-boot_stats");
  if ( compatible_node )
  {
    boot_stats = of_iomap(compatible_node, 0);
    if ( boot_stats )
    {
      v2 = of_find_compatible_node(0, 0, "qcom,mpm2-sleep-counter");
      if ( v2 )
      {
        v3 = v2;
        if ( (of_property_read_variable_u32_array(v2, "clock-frequency", &mpm_counter_freq, 1, 0) & 0x80000000) != 0
          || !_of_get_address(v3, 0, 0xFFFFFFFFLL, 0, 0) )
        {
          return 4294967277LL;
        }
        mpm_counter_base = of_iomap(v3, 0);
        if ( mpm_counter_base )
        {
          v6 = readl_relaxed((unsigned int *)boot_stats);
          printk(&unk_63E3, v6);
          v7 = readl_relaxed((unsigned int *)(boot_stats + 4));
          printk(&unk_6350, v7);
          v8 = readl_relaxed((unsigned int *)(boot_stats + 12));
          v9 = readl_relaxed((unsigned int *)(boot_stats + 8));
          printk(&unk_6407, (unsigned int)(v8 - v9));
          v10 = readl_relaxed((unsigned int *)mpm_counter_base);
          printk(&unk_63B1, v10);
          printk(&unk_62EC, (unsigned int)mpm_counter_freq);
          iounmap(boot_stats);
          iounmap(mpm_counter_base);
          return 0;
        }
        v4 = &unk_6431;
      }
      else
      {
        v4 = &unk_6314;
      }
    }
    else
    {
      v4 = &unk_6393;
    }
  }
  else
  {
    v4 = &unk_6372;
  }
  printk(v4, v1);
  return 4294967277LL;
}
