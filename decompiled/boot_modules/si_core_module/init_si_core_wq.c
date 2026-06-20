__int64 init_si_core_wq()
{
  __int64 v0; // x1

  si_core_wq = alloc_workqueue("si_core_wq", 131074, 1);
  if ( si_core_wq )
    return 0;
  printk(&unk_B5A9, v0);
  return 4294967284LL;
}
