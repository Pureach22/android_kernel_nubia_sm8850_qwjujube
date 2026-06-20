int __fastcall perfmgr_notify_qudeq_gpu_cb(unsigned int startend, int pid, unsigned __int64 identifier)
{
  __int64 v6; // x0
  __int64 *v7; // x22

  if ( ifas_log_enable )
    printk(&unk_FEAB, "perfmgr_notify_qudeq_gpu_cb");
  v6 = mutex_lock(&list_lock);
  v7 = &connected_buffer_list;
  while ( 1 )
  {
    v7 = (__int64 *)*v7;
    if ( v7 == &connected_buffer_list )
      break;
    if ( *(v7 - 11) == identifier )
    {
      perfmgr_notify_qudeq_gpu_cb_find_buffer = 1;
      if ( startend )
      {
        *(v7 - 10) = ktime_get(v6);
      }
      else
      {
        *(v7 - 9) = ktime_get(v6);
        ((void (__fastcall *)(__int64 *))perfmgr_do_policy_gpu)(v7 - 22);
      }
      break;
    }
  }
  mutex_unlock(&list_lock);
  if ( (perfmgr_notify_qudeq_gpu_cb_find_buffer & 1) == 0 )
    perfmgr_notify_connect(pid, identifier, 1);
  return 0;
}
