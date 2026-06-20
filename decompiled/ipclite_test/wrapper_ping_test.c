__int64 __fastcall wrapper_ping_test(__int64 a1)
{
  int v1; // w8
  int v2; // w20
  __int64 v3; // x24
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x25
  unsigned int v6; // w21
  unsigned int v7; // w24
  unsigned int v8; // w21
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x21
  char v12; // w8
  unsigned int v13; // w9
  __int64 v14; // x10
  unsigned int v15; // w24
  __int64 v16; // x0
  bool v17; // zf
  unsigned int v18; // w24
  __int64 v19; // x21
  bool v20; // zf
  bool v21; // zf
  unsigned int v22; // w8
  __int64 v23; // x19
  unsigned __int64 v24; // x20
  unsigned int v26; // [xsp+0h] [xbp-40h]
  unsigned int v27; // [xsp+0h] [xbp-40h]
  int v28; // [xsp+4h] [xbp-3Ch]
  unsigned int v29; // [xsp+4h] [xbp-3Ch]
  __int64 v31; // [xsp+10h] [xbp-30h] BYREF
  __int64 v32; // [xsp+18h] [xbp-28h]
  __int64 v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = HIDWORD(test_params);
  if ( (_DWORD)test_params )
    v1 = HIDWORD(qword_B694);
  else
    v1 = HIDWORD(qword_B694) + 1;
  v28 = v1;
  if ( !HIDWORD(qword_B69C) )
    printk(&unk_A8B3, "ipclite_test", "wrapper_ping_test");
  v2 = 0;
  if ( (qword_B680 & 0x100000000LL) != 0 && (_DWORD)qword_B694 )
  {
    v2 = 0;
    do
    {
      v3 = th_arr + 120LL * v2;
      *(_DWORD *)(v3 + 8) = v2;
      *(_BYTE *)(v3 + 112) = 0;
      _init_waitqueue_head(v3 + 88, "&th_data->wq", &thread_init___key);
      v4 = kthread_create_on_node(ping_selected_receivers, v3, 0xFFFFFFFFLL, "test thread");
      v5 = v4;
      if ( v4 >= 0xFFFFFFFFFFFFF001LL )
      {
        *(_QWORD *)v3 = v4;
        printk(&unk_AA01, "ipclite_test", "thread_init");
        goto LABEL_73;
      }
      wake_up_process(v4);
      *(_QWORD *)v3 = v5;
      ++v2;
    }
    while ( v2 < (unsigned int)qword_B694 );
  }
  if ( (_DWORD)qword_B680 )
  {
    v6 = 0;
    v29 = v28 * ((v26 >> 1) + 10000);
    while ( 1 )
    {
      cores_completed = 0;
      ping_sel_senders(0xAA01010000000200LL);
      if ( (qword_B680 & 0x100000000LL) == 0 )
        goto LABEL_38;
      threads_completed = 0;
      if ( !(_DWORD)qword_B694 )
        goto LABEL_24;
      v7 = v6;
      v8 = 0;
      do
      {
        v9 = th_arr + 120LL * (int)v8;
        *(_QWORD *)(v9 + 32) = 0;
        *(_QWORD *)(v9 + 40) = 0;
        *(_DWORD *)(v9 + 48) = 0;
        *(_QWORD *)(v9 + 16) = 0;
        *(_QWORD *)(v9 + 24) = 0;
        *(_QWORD *)(v9 + 52) = 0;
        *(_QWORD *)(v9 + 60) = 0;
        *(_QWORD *)(v9 + 68) = 0;
        *(_QWORD *)(v9 + 76) = 0;
        *(_DWORD *)(v9 + 84) = 0;
        *(_BYTE *)(v9 + 112) = 1;
        _wake_up(v9 + 88, 1, 1, 0);
        ++v8;
      }
      while ( v8 < (unsigned int)qword_B694 );
      v6 = v7;
      if ( threads_completed == (_DWORD)qword_B694 )
        goto LABEL_24;
      v34 = 0;
      v35 = 0;
      v32 = 0;
      v33 = 0;
      v31 = 0;
      init_wait_entry(&v31, 0);
      v10 = prepare_to_wait_event(&thread_wq, &v31, 1);
      if ( threads_completed == (_DWORD)qword_B694 )
        goto LABEL_19;
      if ( !v10 )
        break;
LABEL_23:
      if ( (v10 & 0x80000000) != 0 )
      {
        printk(&unk_AD90, "ipclite_test", "ping_test");
        goto LABEL_38;
      }
LABEL_24:
      v27 = v6;
      if ( !(_DWORD)test_params )
        msleep_interruptible((unsigned int)(2000 * qword_B69C));
      v11 = 0;
      v12 = 0;
      do
      {
        if ( v11 != HIDWORD(qword_B69C) && (((unsigned __int64)(unsigned int)qword_B688 >> v11) & 1) != 0 )
        {
          v13 = qword_B694;
          if ( (_DWORD)qword_B694 )
          {
            v14 = th_arr;
            v15 = 0;
            do
            {
              if ( *(_DWORD *)(v14 + 120LL * (int)v15 + 4 * v11 + 52) != *(_DWORD *)(v14 + 120LL * (int)v15 + 12) )
              {
                printk(&unk_A55B, "ipclite_test", "check_pings");
                v14 = th_arr;
                v13 = qword_B694;
                v12 = 1;
              }
              ++v15;
            }
            while ( v15 < v13 );
          }
        }
        ++v11;
      }
      while ( v11 != 9 );
      if ( (v12 & 1) != 0 )
      {
        printk(&unk_B5EB, "ipclite_test", "ping_test");
        v6 = v27;
      }
      else
      {
        printk(&unk_AD16, "ipclite_test", "ping_test");
        v6 = v27;
        ++cores_completed;
      }
LABEL_38:
      v16 = _msecs_to_jiffies(v29);
      if ( v16 )
        v17 = 0;
      else
        v17 = cores_completed == HIDWORD(qword_B694);
      if ( v17 )
        v16 = 1;
      if ( cores_completed != HIDWORD(qword_B694) && v16 )
      {
        v18 = v6;
        v34 = 0;
        v35 = 0;
        v32 = 0;
        v33 = 0;
        v31 = 0;
        v19 = _msecs_to_jiffies(v29);
        init_wait_entry(&v31, 0);
        v16 = prepare_to_wait_event(a1 + 88, &v31, 1);
        if ( v19 )
          v20 = 0;
        else
          v20 = cores_completed == HIDWORD(qword_B694);
        if ( v20 )
          v19 = 1;
        if ( cores_completed == HIDWORD(qword_B694) || !v19 )
        {
LABEL_63:
          finish_wait(a1 + 88, &v31);
          LODWORD(v16) = v19;
        }
        else
        {
          while ( !v16 )
          {
            v19 = schedule_timeout(v19);
            v16 = prepare_to_wait_event(a1 + 88, &v31, 1);
            if ( v19 )
              v21 = 0;
            else
              v21 = cores_completed == HIDWORD(qword_B694);
            if ( v21 )
              v19 = 1;
            if ( cores_completed == HIDWORD(qword_B694) || !v19 )
              goto LABEL_63;
          }
        }
        v6 = v18;
      }
      ++v6;
      if ( (int)v16 <= 0 )
      {
        printk(&unk_AB50, "ipclite_test", "wrapper_ping_test");
        goto LABEL_73;
      }
      printk(&unk_A99E, "ipclite_test", "wrapper_ping_test");
      v22 = qword_B680;
      if ( (unsigned int)qword_B680 >= 2 )
      {
        msleep_interruptible(500);
        v22 = qword_B680;
      }
      if ( v6 >= v22 )
        goto LABEL_73;
    }
    while ( 1 )
    {
      schedule();
      v10 = prepare_to_wait_event(&thread_wq, &v31, 1);
      if ( threads_completed == (_DWORD)qword_B694 )
        break;
      if ( v10 )
        goto LABEL_23;
    }
LABEL_19:
    finish_wait(&thread_wq, &v31);
    goto LABEL_24;
  }
LABEL_73:
  if ( (qword_B680 & 0x100000000LL) != 0 && v2 >= 1 )
  {
    v23 = 120LL * (unsigned int)v2 - 120;
    v24 = (unsigned int)v2 + 1LL;
    do
    {
      kthread_stop(*(_QWORD *)(th_arr + v23));
      --v24;
      v23 -= 120;
    }
    while ( v24 > 1 );
  }
  complete(&test_done);
  _ReadStatusReg(SP_EL0);
  return 0;
}
