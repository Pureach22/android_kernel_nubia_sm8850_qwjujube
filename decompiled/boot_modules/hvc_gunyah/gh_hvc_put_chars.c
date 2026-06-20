__int64 __fastcall gh_hvc_put_chars(int a1, __int64 a2, unsigned int a3)
{
  char *v6; // x23
  __int64 v7; // x22
  int v8; // w19

  if ( (unsigned int)(a1 - 1196317000) > 4 )
    return -22;
  v6 = (char *)&gh_hvc_data + 2144 * (unsigned int)(a1 - 1196317000);
  v7 = raw_spin_lock_irqsave(&fifo_lock);
  v8 = _kfifo_in(v6 + 1064, a2, a3);
  raw_spin_unlock_irqrestore(&fifo_lock, v7);
  if ( v8 >= 1 )
    queue_work_on(32, system_wq, v6 + 2112);
  return v8;
}
