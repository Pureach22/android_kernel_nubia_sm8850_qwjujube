__int64 zte_pm_debug_probe()
{
  record_sleep_awake_time_vendor(1);
  if ( zte_imem_ptr )
  {
    *(_DWORD *)zte_imem_ptr = 0;
    printk(&unk_A220);
  }
  printk(&unk_9F69);
  return 0;
}
