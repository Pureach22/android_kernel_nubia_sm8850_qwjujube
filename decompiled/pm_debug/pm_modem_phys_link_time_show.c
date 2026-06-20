__int64 __fastcall pm_modem_phys_link_time_show(char *a1)
{
  if ( zte_imem_ptr )
  {
    printk(&unk_9D39);
    return snprintf(a1, 8u, "%d", *(_DWORD *)(zte_imem_ptr + 16));
  }
  else
  {
    printk(&unk_A1E5);
    return 0;
  }
}
