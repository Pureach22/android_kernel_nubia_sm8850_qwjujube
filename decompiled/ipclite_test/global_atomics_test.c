__int64 __fastcall global_atomics_test(int a1)
{
  _DWORD *v1; // x22
  __int64 result; // x0
  int v4; // w25
  __int64 v5; // x8
  __int64 (__fastcall *v6)(); // x20
  __int64 (__fastcall *v7)(); // x21
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x21
  unsigned __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x20
  void *v13; // x0
  void *v14; // x0
  bool v15; // zf
  unsigned __int64 v16; // x20
  _QWORD v17[5]; // [xsp+0h] [xbp-120h] BYREF
  _QWORD v18[11]; // [xsp+28h] [xbp-F8h] BYREF
  _QWORD v19[3]; // [xsp+80h] [xbp-A0h] BYREF
  __int64 v20; // [xsp+98h] [xbp-88h]
  _QWORD v21[11]; // [xsp+A0h] [xbp-80h] BYREF
  _QWORD v22[3]; // [xsp+F8h] [xbp-28h] BYREF
  __int64 v23; // [xsp+110h] [xbp-10h]
  __int64 v24; // [xsp+118h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (_DWORD *)global_memory;
  v23 = 0;
  memset(v22, 0, sizeof(v22));
  memset(v21, 0, sizeof(v21));
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  memset(v18, 0, sizeof(v18));
  if ( global_memory )
  {
    threads_completed = 0;
    if ( (qword_B680 & 0x100000000LL) != 0 )
    {
      LOBYTE(v23) = 0;
      v5 = a1 - 1LL;
      v6 = off_A290[v5];
      v7 = off_A2A8[(int)v5];
      _init_waitqueue_head(v22, "&th_data->wq", &thread_init___key);
      v8 = kthread_create_on_node(v7, v21, 0xFFFFFFFFLL, "test thread");
      if ( v8 > 0xFFFFFFFFFFFFF000LL )
      {
        v21[0] = v8;
        printk(&unk_AA01, "ipclite_test", "thread_init");
        result = 4294967274LL;
        goto LABEL_77;
      }
      v9 = v8;
      wake_up_process(v8);
      v21[0] = v9;
      LOBYTE(v20) = 0;
      _init_waitqueue_head(v19, "&th_data->wq", &thread_init___key);
      v10 = kthread_create_on_node(v6, v18, 0xFFFFFFFFLL, "test thread");
      if ( v10 > 0xFFFFFFFFFFFFF000LL )
      {
        v18[0] = v10;
        printk(&unk_AA01, "ipclite_test", "thread_init");
        kthread_stop(v21[0]);
        result = 4294967274LL;
        goto LABEL_77;
      }
      v16 = v10;
      wake_up_process(v10);
      v18[0] = v16;
    }
    if ( (qword_B680 & 0x200000000LL) != 0 )
    {
      if ( !(unsigned int)ipclite_test_msg_send(1, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
      {
        v4 = 2;
        if ( (qword_B680 & 0x400000000LL) == 0 )
          goto LABEL_16;
        goto LABEL_14;
      }
      printk(&unk_AF01, "ipclite_test", "global_atomics_test");
    }
    v4 = 0;
    if ( (qword_B680 & 0x400000000LL) == 0 )
      goto LABEL_16;
LABEL_14:
    if ( (unsigned int)ipclite_test_msg_send(2, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
    {
      printk(&unk_AF01, "ipclite_test", "global_atomics_test");
      if ( (qword_B680 & 0x800000000LL) == 0 )
      {
LABEL_17:
        if ( (qword_B680 & 0x1000000000LL) == 0 )
          goto LABEL_18;
LABEL_29:
        if ( (unsigned int)ipclite_test_msg_send(4, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
        {
          printk(&unk_AF01, "ipclite_test", "global_atomics_test");
          if ( (qword_B680 & 0x2000000000LL) != 0 )
            goto LABEL_33;
        }
        else
        {
          v4 += 2;
          if ( (qword_B680 & 0x2000000000LL) != 0 )
            goto LABEL_33;
        }
LABEL_19:
        if ( (qword_B680 & 0x4000000000LL) == 0 )
          goto LABEL_20;
LABEL_37:
        if ( (unsigned int)ipclite_test_msg_send(6, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
        {
          printk(&unk_AF01, "ipclite_test", "global_atomics_test");
          if ( (qword_B680 & 0x8000000000LL) == 0 )
            goto LABEL_41;
        }
        else
        {
          v4 += 2;
          if ( (qword_B680 & 0x8000000000LL) == 0 )
            goto LABEL_41;
        }
LABEL_21:
        if ( (unsigned int)ipclite_test_msg_send(7, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
          printk(&unk_AF01, "ipclite_test", "global_atomics_test");
        else
          v4 += 2;
LABEL_41:
        if ( (qword_B680 & 0x10000000000LL) != 0 )
        {
          if ( (unsigned int)ipclite_test_msg_send(8, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
          {
            printk(&unk_AF01, "ipclite_test", "global_atomics_test");
            if ( (qword_B680 & 0x100000000LL) == 0 )
              goto LABEL_46;
            goto LABEL_45;
          }
          v4 += 2;
        }
        if ( (qword_B680 & 0x100000000LL) == 0 )
        {
LABEL_46:
          if ( threads_completed != v4 )
          {
            memset(v17, 0, sizeof(v17));
            init_wait_entry(v17, 0);
            v11 = prepare_to_wait_event(&thread_wq, v17, 1);
            v12 = 1250;
            if ( threads_completed == v4 )
            {
LABEL_48:
              finish_wait(&thread_wq, v17);
              LODWORD(v11) = v12;
            }
            else
            {
              while ( !v11 )
              {
                v12 = schedule_timeout(v12);
                v11 = prepare_to_wait_event(&thread_wq, v17, 1);
                if ( v12 )
                  v15 = 0;
                else
                  v15 = threads_completed == v4;
                if ( v15 )
                  v12 = 1;
                if ( threads_completed == v4 || !v12 )
                  goto LABEL_48;
              }
            }
            if ( (int)v11 <= 0 )
            {
              v13 = &unk_B3D0;
LABEL_76:
              printk(v13, "ipclite_test", "global_atomics_test");
              result = 0xFFFFFFFFLL;
              goto LABEL_77;
            }
          }
          if ( a1 == 3 )
          {
            if ( *v1 )
            {
              v13 = &unk_A3C8;
              goto LABEL_76;
            }
            v14 = &unk_A4D2;
          }
          else if ( a1 == 2 )
          {
            if ( *v1 )
            {
              v13 = &unk_A5B5;
              goto LABEL_76;
            }
            v14 = &unk_AC8D;
          }
          else
          {
            if ( *v1 != 2 * HIDWORD(qword_B694) * (_DWORD)qword_B680 )
            {
              v13 = &unk_A82A;
              goto LABEL_76;
            }
            v14 = &unk_A595;
          }
          printk(v14, "ipclite_test", "global_atomics_test");
          result = 0;
          goto LABEL_77;
        }
LABEL_45:
        LOBYTE(v23) = 1;
        _wake_up(v22, 1, 1, 0);
        LOBYTE(v20) = 1;
        _wake_up(v19, 1, 1, 0);
        v4 += 2;
        goto LABEL_46;
      }
LABEL_24:
      if ( (unsigned int)ipclite_test_msg_send(3, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
      {
        printk(&unk_AF01, "ipclite_test", "global_atomics_test");
        if ( (qword_B680 & 0x1000000000LL) != 0 )
          goto LABEL_29;
      }
      else
      {
        v4 += 2;
        if ( (qword_B680 & 0x1000000000LL) != 0 )
          goto LABEL_29;
      }
LABEL_18:
      if ( (qword_B680 & 0x2000000000LL) == 0 )
        goto LABEL_19;
LABEL_33:
      if ( (unsigned int)ipclite_test_msg_send(5, ((*(_QWORD *)&a1 & 0xFFFFFLL) << 16) | 0xAA01030000000200LL) )
      {
        printk(&unk_AF01, "ipclite_test", "global_atomics_test");
        if ( (qword_B680 & 0x4000000000LL) != 0 )
          goto LABEL_37;
      }
      else
      {
        v4 += 2;
        if ( (qword_B680 & 0x4000000000LL) != 0 )
          goto LABEL_37;
      }
LABEL_20:
      if ( (qword_B680 & 0x8000000000LL) == 0 )
        goto LABEL_41;
      goto LABEL_21;
    }
    v4 += 2;
LABEL_16:
    if ( (qword_B680 & 0x800000000LL) == 0 )
      goto LABEL_17;
    goto LABEL_24;
  }
  printk(&unk_AAF1, "ipclite_test", "global_atomics_test");
  result = 4294967282LL;
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return result;
}
