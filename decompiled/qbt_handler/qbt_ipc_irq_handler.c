__int64 __fastcall qbt_ipc_irq_handler(__int64 a1, __int64 a2)
{
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 460) == (_DWORD)a1 )
    {
      ktime_get(a1);
      printk(&unk_92FB, "qbt_ipc_irq_handler");
      pm_stay_awake(*(_QWORD *)(a2 + 288));
      queue_work_on(32, system_wq, a2 + 472);
    }
    else
    {
      printk(&unk_9BF6, "qbt_ipc_irq_handler");
    }
  }
  else
  {
    printk(&unk_9A11, "qbt_ipc_irq_handler");
  }
  return 1;
}
