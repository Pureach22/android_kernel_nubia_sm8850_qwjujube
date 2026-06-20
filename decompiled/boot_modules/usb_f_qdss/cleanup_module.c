__int64 cleanup_module()
{
  __int64 result; // x0
  _QWORD *v1; // x20
  _UNKNOWN **v2; // x24
  __int64 v3; // x21
  _QWORD *v4; // x8
  _UNKNOWN **v5; // x9

  ipc_log_context_destroy(qdss_ipc_log);
  usb_function_unregister(&qdssusb_func);
  result = ipc_log_string(qdss_ipc_log, "%s: cleaning up channel resources.\n", "qdss_cleanup");
  v1 = usb_qdss_ch_list;
  if ( usb_qdss_ch_list != (_UNKNOWN *)&usb_qdss_ch_list )
  {
    do
    {
      v2 = (_UNKNOWN **)*v1;
      destroy_workqueue(v1[20]);
      v3 = raw_spin_lock_irqsave(&channel_lock);
      if ( !v1[3] )
      {
        v4 = (_QWORD *)v1[1];
        if ( (_QWORD *)*v4 == v1 && (v5 = (_UNKNOWN **)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
        {
          v5[1] = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v1);
        }
        *v1 = 0xDEAD000000000100LL;
        v1[1] = 0xDEAD000000000122LL;
        kfree(v1 - 38);
      }
      result = raw_spin_unlock_irqrestore(&channel_lock, v3);
      v1 = v2;
    }
    while ( v2 != &usb_qdss_ch_list );
  }
  return result;
}
