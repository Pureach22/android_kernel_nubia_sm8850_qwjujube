__int64 __fastcall pm_modem_sleep_time_show(char *a1)
{
  if ( zte_imem_ptr )
  {
    printk(&unk_9D19);
    return snprintf(a1, 8u, "%d", *(_DWORD *)(zte_imem_ptr + 4) / 0x3E8u);
  }
  else
  {
    printk(&unk_9BE3);
    return 0;
  }
}
