__int64 __fastcall cpu_vendor_hooks_driver_probe(__int64 a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w0
  __int64 result; // x0
  unsigned int v5; // w20
  void *v6; // x0
  __int64 (__fastcall *v7)(); // x1

  if ( (debug_symbol_available() & 1) == 0 )
    return 4294966779LL;
  store_kaslr_offset();
  register_syscore_ops(&kaslr_offset_restore_syscore_ops);
  v2 = tracepoint_probe_register(&_tracepoint_android_vh_ipi_stop, &trace_ipi_stop, 0);
  if ( v2 )
  {
    v5 = v2;
    dev_err(a1 + 16, "Failed to register android_vh_ipi_stop hook\n");
    return v5;
  }
  v3 = tracepoint_probe_register(&_tracepoint_android_vh_printk_hotplug, printk_hotplug, 0);
  if ( v3 )
  {
    v5 = v3;
    dev_err(a1 + 16, "Failed to android_vh_printk_hotplug hook\n");
    v6 = &_tracepoint_android_vh_ipi_stop;
    v7 = (__int64 (__fastcall *)())&trace_ipi_stop;
    goto LABEL_10;
  }
  result = tracepoint_probe_register(&_tracepoint_android_vh_timer_calc_index, timer_recalc_index, 0);
  if ( (_DWORD)result )
  {
    v5 = result;
    dev_err(a1 + 16, "Failed to android_vh_timer_calc_index hook\n");
    tracepoint_probe_unregister(&_tracepoint_android_vh_ipi_stop, &trace_ipi_stop, 0);
    v6 = &_tracepoint_android_vh_printk_hotplug;
    v7 = printk_hotplug;
LABEL_10:
    tracepoint_probe_unregister(v6, v7, 0);
    return v5;
  }
  return result;
}
