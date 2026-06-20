__int64 __fastcall pm_modem_awake_time_show(char *a1)
{
  if ( zte_imem_ptr )
  {
    printk(&unk_9CE1);
    return snprintf(a1, 8u, "%d", *(_DWORD *)(zte_imem_ptr + 8) / 0x3E8u);
  }
  else
  {
    printk(&unk_9640);
    return 0;
  }
}
