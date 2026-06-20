__int64 zte_pm_debug_resume()
{
  void *v1; // x0

  printk(&unk_A50A);
  glink_count = 0;
  if ( !mEnableRrecordFlag_ZTE )
  {
    v1 = &unk_A85C;
LABEL_6:
    printk(v1);
    return 0;
  }
  record_sleep_awake_time_vendor(1);
  if ( zte_imem_ptr )
  {
    v1 = &unk_A220;
    *(_DWORD *)zte_imem_ptr = 0;
    goto LABEL_6;
  }
  return 0;
}
