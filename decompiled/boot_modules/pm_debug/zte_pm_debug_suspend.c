__int64 zte_pm_debug_suspend()
{
  printk(&unk_9E78);
  glink_count = 3;
  qrtr_count = 3;
  if ( mEnableRrecordFlag_ZTE )
  {
    record_sleep_awake_time_vendor(0);
    if ( zte_imem_ptr )
      *(_DWORD *)zte_imem_ptr = 170;
  }
  return 0;
}
