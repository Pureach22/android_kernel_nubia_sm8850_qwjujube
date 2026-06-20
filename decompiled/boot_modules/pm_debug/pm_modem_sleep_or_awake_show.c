__int64 __fastcall pm_modem_sleep_or_awake_show(char *a1)
{
  if ( zte_imem_ptr )
  {
    printk(&unk_A27D);
    return snprintf(a1, 8u, "%d", *(_DWORD *)(zte_imem_ptr + 12));
  }
  else
  {
    printk(&unk_9711);
    return 0;
  }
}
