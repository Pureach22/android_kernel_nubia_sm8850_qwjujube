__int64 cpu_vendor_hooks_driver_remove()
{
  tracepoint_probe_unregister(&_tracepoint_android_vh_ipi_stop, &trace_ipi_stop, 0);
  tracepoint_probe_unregister(&_tracepoint_android_vh_printk_hotplug, printk_hotplug, 0);
  return tracepoint_probe_unregister(&_tracepoint_android_vh_timer_calc_index, timer_recalc_index, 0);
}
