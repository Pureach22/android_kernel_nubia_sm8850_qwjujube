__int64 __fastcall qbt_irq_report_event(_DWORD *a1)
{
  _DWORD *v2; // x20
  __int64 v4; // x0
  int v5; // w8
  unsigned int v6; // w9

  if ( !a1 )
    return printk(&unk_9A11, "qbt_irq_report_event");
  v2 = a1 - 16;
  v4 = mutex_lock(a1 - 16);
  v5 = a1[2740];
  v6 = a1[2742];
  if ( v5 - a1[2741] <= v6 )
  {
    a1[(v6 & v5) + 2746] = 3;
    __dmb(0xAu);
    ++a1[2740];
    ktime_get(v4);
    printk(&unk_A285, "qbt_irq_report_event");
  }
  else
  {
    printk(&unk_9776, "qbt_irq_report_event");
  }
  mutex_unlock(v2);
  _wake_up(a1 + 162, 1, 1, 0);
  return pm_relax(*((_QWORD *)a1 - 23));
}
