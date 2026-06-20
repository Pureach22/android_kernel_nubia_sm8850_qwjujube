void __fastcall perfmgr_notifer_wq_cb(work_struct *psWork)
{
  __int64 v1; // x1
  work_struct *v2; // x19
  int counter; // w2
  int next; // w20
  list_head *prev; // x21
  __int64 *v6; // x8
  work_struct *v7; // x21

  v2 = psWork - 1;
  if ( psWork == (work_struct *)&unk_20 )
  {
    printk(&unk_FAD8, "perfmgr_notifer_wq_cb");
  }
  else
  {
    if ( ifas_log_enable )
    {
      v7 = psWork;
      printk(&unk_FAF5, "perfmgr_notifer_wq_cb");
      psWork = v7;
    }
    counter = v2->data.counter;
    if ( LODWORD(v2->data.counter) == 3 )
    {
      perfmgr_notify_qudeq_gpu_cb(
        HIDWORD(psWork[-1].data.counter),
        (int)psWork[-1].entry.next,
        (unsigned __int64)psWork[-1].entry.prev);
    }
    else if ( counter == 2 )
    {
      perfmgr_notify_connect_cb(
        (int)psWork[-1].entry.next,
        (unsigned __int64)psWork[-1].entry.prev,
        HIDWORD(psWork[-1].entry.next));
    }
    else if ( counter == 1 )
    {
      next = (int)psWork[-1].entry.next;
      prev = psWork[-1].entry.prev;
      if ( ifas_log_enable )
        printk(&unk_EA40, "perfmgr_notify_qudeq_cb");
      mutex_lock(&list_lock);
      v6 = &connected_buffer_list;
      while ( 1 )
      {
        v6 = (__int64 *)*v6;
        if ( v6 == &connected_buffer_list )
          break;
        if ( (list_head *)*(v6 - 11) == prev )
        {
          perfmgr_notify_qudeq_cb_find_buffer = 1;
          perfmgr_do_policy_cpu(v6 - 22);
          break;
        }
      }
      mutex_unlock(&list_lock);
      if ( (perfmgr_notify_qudeq_cb_find_buffer & 1) == 0 )
        perfmgr_notify_connect(next, (unsigned __int64)prev, 1);
    }
    else if ( ifas_log_enable )
    {
      printk(&unk_107A1, "perfmgr_notifer_wq_cb");
    }
    kfree(v2, v1);
  }
}
