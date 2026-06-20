__int64 adci_start()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x19
  __int64 result; // x0

  v0 = kthread_create_on_node(adci_fn, 0, 0xFFFFFFFFLL, "adci_thread");
  v1 = v0;
  if ( v0 > 0xFFFFFFFFFFFFF000LL )
  {
    adci_task = v0;
    return printk(&unk_B25C, v0);
  }
  else
  {
    result = wake_up_process(v0);
    adci_task = v1;
  }
  return result;
}
