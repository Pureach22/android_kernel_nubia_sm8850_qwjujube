// Alternative name is 'init_module'
__int64 zte_pm_debug_vendor_init()
{
  __int64 compatible_node; // x0
  void *v2; // x0

  if ( (zte_pm_debug_vendor_init_registered & 1) != 0 )
    return 0;
  zte_pm_debug_vendor_init_registered = 1;
  printk(&unk_A80D);
  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-vendor-imem-pm-count-time");
  if ( !compatible_node )
  {
    v2 = &unk_9CAB;
LABEL_11:
    printk(v2);
    goto LABEL_5;
  }
  zte_imem_ptr = of_iomap(compatible_node, 0);
  if ( !zte_imem_ptr )
  {
    v2 = &unk_9FC3;
    goto LABEL_11;
  }
LABEL_5:
  tracepoint_probe_register(&_tracepoint_suspend_resume, clk_debug_suspend_trace_probe, 0);
  if ( tcp_output_debug )
  {
    if ( (gIsNfNetHookRegistered & 1) == 0 )
    {
      nf_register_net_hooks(&init_net, &packet_in_nf_ops, 2);
      nf_register_net_hooks(&init_net, &packet_out_nf_ops, 2);
      gIsNfNetHookRegistered = 1;
    }
  }
  pm_subsystems_init();
  return _platform_driver_register(zte_pm_debug_driver, &_this_module);
}
