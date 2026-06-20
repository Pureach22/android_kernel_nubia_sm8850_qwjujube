__int64 __fastcall qbt_fd_report_event(_DWORD *a1, const void *a2)
{
  int v4; // w8
  unsigned int v5; // w9
  void *v6; // x0

  mutex_lock(a1 + 90);
  v4 = a1[1572];
  v5 = a1[1574];
  if ( v4 - a1[1573] <= v5 )
  {
    v6 = memmove(&a1[10 * (v5 & v4) + 1578], a2, 0x28u);
    __dmb(0xAu);
    ++a1[1572];
    ktime_get(v6);
    printk(&unk_A081, "qbt_fd_report_event");
  }
  else
  {
    printk(&unk_9CBF, "qbt_fd_report_event");
  }
  mutex_unlock(a1 + 90);
  return _wake_up(a1 + 274, 1, 1, 0);
}
