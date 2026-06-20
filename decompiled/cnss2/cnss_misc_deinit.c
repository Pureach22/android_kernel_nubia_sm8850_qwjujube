__int64 __fastcall cnss_misc_deinit(__int64 *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0

  cnss_plat_ipc_unregister(1, a1);
  complete_all(a1 + 831);
  complete_all(a1 + 827);
  complete_all(a1 + 793);
  complete_all(a1 + 789);
  complete_all(a1 + 514);
  v2 = *a1;
  device_wakeup_disable(*a1 + 16);
  device_set_wakeup_capable(v2 + 16, 0);
  unregister_reboot_notifier(a1 + 50);
  timer_delete(a1 + 784);
  wakeup_source_unregister(a1[930]);
  v3 = *((unsigned int *)a1 + 1999);
  if ( (v3 & 0x80000000) == 0 )
    gpio_free(v3);
  v4 = *((unsigned int *)a1 + 37);
  if ( (v4 & 0x80000000) == 0 )
    gpio_free(v4);
  if ( (a1[17] & 0x80000000) == 0 )
  {
    free_irq(*((unsigned int *)a1 + 35), a1);
    gpio_free(*((unsigned int *)a1 + 34));
  }
  if ( a1[826] )
  {
    vfree();
    a1[826] = 0;
  }
  return kfree(a1[979]);
}
