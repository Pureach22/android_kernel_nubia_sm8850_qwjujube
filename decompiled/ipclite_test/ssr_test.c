__int64 __fastcall ssr_test(__int64 a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x20
  unsigned __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w20
  __int64 result; // x0
  __int64 v10; // x20
  _QWORD v11[6]; // [xsp+0h] [xbp-30h] BYREF

  v11[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 112) = 0;
  byte_B7B8 = 0;
  _init_waitqueue_head(&unk_B7A0, "&th_data->wq", &thread_init___key);
  v2 = kthread_create_on_node(ssr_wakeup_check, &wakeup_check, 0xFFFFFFFFLL, "test thread");
  v3 = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    wakeup_check = v2;
    printk(&unk_AA01, "ipclite_test", "thread_init");
    result = 4294967274LL;
  }
  else
  {
    wake_up_process(v2);
    wakeup_check = v3;
    byte_B830 = 0;
    _init_waitqueue_head(&unk_B818, "&th_data->wq", &thread_init___key);
    v4 = kthread_create_on_node(send_bg_pings, &bg_pings, 0xFFFFFFFFLL, "test thread");
    v5 = v4;
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      bg_pings = v4;
      printk(&unk_AA01, "ipclite_test", "thread_init");
      kthread_stop(wakeup_check);
      result = 4294967274LL;
    }
    else
    {
      wake_up_process(v4);
      bg_pings = v5;
      qword_B6E4 = 0;
      qword_B6EC = 0;
      qword_B6F4 = 0;
      qword_B6FC = 0;
      dword_B704 = 0;
      ipclite_test_msg_send((unsigned int)ssr_client, 0xAA01050000010200LL);
      if ( (*(_BYTE *)(a1 + 112) & 1) == 0 )
      {
        memset(v11, 0, 40);
        init_wait_entry(v11, 0);
        v6 = prepare_to_wait_event(a1 + 88, v11, 1);
        if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
        {
          LODWORD(v7) = 11250;
LABEL_6:
          v8 = v7;
          finish_wait(a1 + 88, v11);
          LODWORD(v6) = v8;
        }
        else
        {
          v7 = 11250;
          while ( !v6 )
          {
            v10 = schedule_timeout(v7);
            v6 = prepare_to_wait_event(a1 + 88, v11, 1);
            if ( (*(_BYTE *)(a1 + 112) & (v10 == 0)) != 0 )
              v7 = 1;
            else
              v7 = v10;
            if ( (*(_BYTE *)(a1 + 112) & 1) != 0 || !v7 )
              goto LABEL_6;
          }
        }
        if ( (int)v6 <= 0 )
          printk(&unk_B1DD, "ipclite_test", "ssr_test");
      }
      complete(&test_done);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
