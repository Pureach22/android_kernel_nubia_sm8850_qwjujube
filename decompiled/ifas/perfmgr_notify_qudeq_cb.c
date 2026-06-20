int __fastcall perfmgr_notify_qudeq_cb(int pid, unsigned __int64 identifier)
{
  __int64 *v4; // x8

  if ( ifas_log_enable )
    printk(&unk_EA40, "perfmgr_notify_qudeq_cb");
  mutex_lock(&list_lock);
  v4 = &connected_buffer_list;
  while ( 1 )
  {
    v4 = (__int64 *)*v4;
    if ( v4 == &connected_buffer_list )
      break;
    if ( *(v4 - 11) == identifier )
    {
      perfmgr_notify_qudeq_cb_find_buffer = 1;
      perfmgr_do_policy_cpu(v4 - 22);
      break;
    }
  }
  mutex_unlock(&list_lock);
  if ( (perfmgr_notify_qudeq_cb_find_buffer & 1) == 0 )
    perfmgr_notify_connect(pid, identifier, 1);
  return 0;
}
