void __noreturn deferred_free_thread()
{
  __int64 v0; // x0
  __int64 v1; // x21
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x23
  __int64 v5; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  while ( 1 )
  {
    v0 = raw_spin_lock_irqsave(&free_list_lock);
    v1 = list_nr_pages;
    raw_spin_unlock_irqrestore(&free_list_lock, v0);
    if ( !v1 )
    {
      memset(v6, 0, sizeof(v6));
      init_wait_entry(v6, 0);
      while ( 1 )
      {
        v2 = prepare_to_wait_event(&freelist_waitqueue, v6, 8193);
        v3 = raw_spin_lock_irqsave(&free_list_lock);
        v4 = list_nr_pages;
        v5 = raw_spin_unlock_irqrestore(&free_list_lock, v3);
        if ( v4 )
          break;
        if ( v2 )
          goto LABEL_3;
        schedule(v5);
      }
      finish_wait(&freelist_waitqueue, v6);
    }
LABEL_3:
    free_one_item(0);
  }
}
