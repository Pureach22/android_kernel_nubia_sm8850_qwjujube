__int64 __fastcall qcom_wdt_bark_handler(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x23
  int v5; // w8
  __int64 v6; // x0

  v3 = sched_clock(a1);
  v4 = *(_QWORD *)(a2 + 40);
  dev_info(*(_QWORD *)(a2 + 8), "QCOM Apps Watchdog bark! Now = %lu.%06lu\n", v3 / 0x3B9ACA00, v3 % 0x3B9ACA00 / 0x3E8);
  dev_info(*(_QWORD *)(a2 + 8), "QCOM Apps Watchdog last pet at %lu.%06lu\n", v4 / 0x3B9ACA00, v4 % 0x3B9ACA00 / 0x3E8);
  v5 = zte_ramdisk_reboot_write(&wdt_char_str, 1);
  v6 = *(_QWORD *)(a2 + 8);
  if ( v5 )
    dev_err(v6, "ztedbg write wdt failed\n");
  else
    dev_info(v6, "ztedbg write wdt flag\n");
  if ( *(_BYTE *)(a2 + 36) == 1 )
  {
    scnprintf(qcom_wdt_dump_cpu_alive_mask_alive_mask_buf, 32, "%*pb1", nr_cpu_ids, (const void *)(a2 + 48));
    dev_info(*(_QWORD *)(a2 + 8), "cpu alive mask from last pet %s\n", qcom_wdt_dump_cpu_alive_mask_alive_mask_buf);
  }
  if ( *(_BYTE *)(a2 + 952) == 1 )
    dev_info(*(_QWORD *)(a2 + 8), "Suspend in progress\n");
  md_dump_process();
  qcom_wdt_trigger_bite();
  return 1;
}
