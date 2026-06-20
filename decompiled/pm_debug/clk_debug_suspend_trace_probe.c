void __fastcall clk_debug_suspend_trace_probe(int a1, char *s2, int a3, char a4)
{
  if ( a3 >= 1 && (a4 & 1) != 0 && !strcmp("machine_suspend", s2) )
  {
    glink_count = 3;
    qrtr_count = 3;
    ((void (*)(void))record_sleep_awake_time_vendor)();
    if ( zte_imem_ptr )
      *(_DWORD *)zte_imem_ptr = 170;
    pm_subsystems_resume_suspend(0);
  }
  if ( a3 >= 1 && (a4 & 1) == 0 && !strcmp("dpm_resume", s2) )
  {
    glink_count = 0;
    record_sleep_awake_time_vendor(1);
    if ( zte_imem_ptr )
    {
      *(_DWORD *)zte_imem_ptr = 0;
      printk(&unk_A220);
    }
    pm_subsystems_resume_suspend(1);
  }
}
