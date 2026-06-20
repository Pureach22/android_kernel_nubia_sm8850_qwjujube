__int64 __fastcall qbt_gpio_isr(__int64 a1, __int64 a2)
{
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 512) == (_DWORD)a1 )
    {
      ktime_get(a1);
      printk(&unk_A0B9, "qbt_gpio_isr");
      pm_stay_awake(*(_QWORD *)(a2 + 288));
      queue_work_on(32, system_wq, a2 + 520);
    }
    else
    {
      printk(&unk_9BF6, "qbt_gpio_isr");
    }
  }
  else
  {
    printk(&unk_9A11, "qbt_gpio_isr");
  }
  return 1;
}
