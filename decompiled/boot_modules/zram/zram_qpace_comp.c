__int64 zram_qpace_comp()
{
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  char v4; // w21
  int v5; // w21
  __int64 *v6; // x21
  __int64 **v7; // x24
  __int64 *v8; // x8

  if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
  {
    do
    {
      v3 = wait_for_completion(&unk_470);
      get_qpace(v3);
      mutex_lock(&unk_3F0);
      v4 = qpace_trigger_tr(0);
      v1 = mutex_unlock(&unk_3F0);
      if ( (v4 & 1) != 0 )
      {
        qpace_wait_for_tr_consumption(0, 0);
        v5 = qpace_consume_er(0, zram_compress_success_handler, zram_compress_success_handler, 1);
        mutex_lock(&unk_3F0);
        comp_control -= v5;
        mutex_lock(&unk_430);
        if ( off_420 != (_UNKNOWN *)&off_420 )
        {
          v6 = (__int64 *)off_428;
          if ( off_428 != &off_420 && comp_control != 127 )
          {
            do
            {
              v7 = (__int64 **)v6[1];
              if ( *v7 == v6 && (v8 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
              {
                v8[1] = (__int64)v7;
                *v7 = v8;
              }
              else
              {
                _list_del_entry_valid_or_report(v6);
              }
              *v6 = 0xDEAD000000000100LL;
              v6[1] = 0xDEAD000000000122LL;
              --dword_460;
              zram_req_queue(v6 + 2);
              kfree(v6);
              if ( v7 == (__int64 **)&off_420 )
                break;
              v6 = (__int64 *)v7;
            }
            while ( comp_control != 127 );
          }
        }
        mutex_unlock(&unk_430);
        v1 = mutex_unlock(&unk_3F0);
      }
      v2 = put_qpace(v1);
    }
    while ( (kthread_should_stop(v2) & 1) == 0 );
  }
  return 0;
}
