__int64 ipclite_test_set_test()
{
  void *v0; // x0
  __int64 result; // x0
  unsigned __int64 v2; // x8
  __int64 (__fastcall *v3)(); // x1
  __int64 (__fastcall *v4)(); // x0
  char v5; // w11
  char v6; // w10
  unsigned __int64 v7; // x0
  __int64 v8; // x19
  unsigned int v9; // w9
  unsigned int v10; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v12; // x21
  __int64 v13; // x0

  if ( HIDWORD(qword_B688) > 8 )
  {
    v0 = &unk_B434;
    return printk(v0, "ipclite_test", "ipclite_test_set_test");
  }
  if ( (unsigned int)(HIDWORD(qword_B688) - 1) < 7 )
  {
    printk(&unk_AD4E, "ipclite_test", "ipclite_test_set_test");
    if ( HIDWORD(qword_B688) == 1 )
    {
      result = _kmalloc_noprof(120LL * (unsigned int)qword_B694, 3520);
      goto LABEL_7;
    }
    v0 = &unk_B093;
    v2 = ((unsigned __int64)BYTE4(qword_B688) << 40) | 0xAA01000000000200LL;
    if ( SHIDWORD(qword_B688) <= 3 )
    {
      if ( HIDWORD(qword_B688) != 2 )
      {
        if ( HIDWORD(qword_B688) != 3 )
          return printk(v0, "ipclite_test", "ipclite_test_set_test");
        byte_B720 = 0;
        _init_waitqueue_head(&unk_B708, "&th_data->wq", &thread_init___key);
        v4 = global_atomics_test_wrapper;
        goto LABEL_32;
      }
      v5 = __clz(__rbit32(qword_B688));
      if ( (_DWORD)qword_B688 )
        v6 = v5;
      else
        v6 = -1;
      cores_completed = 0;
      if ( (((unsigned __int64)(unsigned int)dword_B690 >> v6) & 1) != 0 )
      {
        v0 = &unk_AC52;
        return printk(v0, "ipclite_test", "ipclite_test_set_test");
      }
      ping_sel_senders(v2);
      v3 = negative_tests;
LABEL_29:
      if ( (unsigned int)thread_init(&m_thread, v3) )
        goto LABEL_36;
      goto LABEL_35;
    }
    if ( HIDWORD(qword_B688) == 4 )
    {
      cores_completed = 0;
      ping_sel_senders(v2);
      byte_B720 = 0;
      _init_waitqueue_head(&unk_B708, "&th_data->wq", &thread_init___key);
      v4 = debug_tests;
LABEL_32:
      v7 = kthread_create_on_node(v4, &m_thread, 0xFFFFFFFFLL, "test thread");
      if ( v7 >= 0xFFFFFFFFFFFFF001LL )
      {
        m_thread = v7;
        printk(&unk_AA01, "ipclite_test", "thread_init");
LABEL_36:
        if ( HIDWORD(qword_B688) == 1 )
        {
          kfree(th_arr);
          th_arr = 0;
        }
        v0 = &unk_A437;
        return printk(v0, "ipclite_test", "ipclite_test_set_test");
      }
      v8 = v7;
      wake_up_process();
      m_thread = v8;
LABEL_35:
      wait_for_completion(&test_done);
      goto LABEL_36;
    }
    if ( HIDWORD(qword_B688) != 5 )
    {
      if ( HIDWORD(qword_B688) != 6 )
        return printk(v0, "ipclite_test", "ipclite_test_set_test");
      if ( HIDWORD(qword_B694) != 1 )
      {
        v0 = &unk_A7E4;
        return printk(v0, "ipclite_test", "ipclite_test_set_test");
      }
      if ( ((unsigned int)qword_B688 & HIDWORD(qword_B680)) != 0 )
      {
        v0 = &unk_B5A6;
        return printk(v0, "ipclite_test", "ipclite_test_set_test");
      }
      v3 = hw_mutex_test;
      goto LABEL_29;
    }
    if ( HIDWORD(qword_B694) != 1 )
    {
      v0 = &unk_B330;
      return printk(v0, "ipclite_test", "ipclite_test_set_test");
    }
    if ( ((unsigned int)qword_B688 & HIDWORD(qword_B680)) != 0 )
    {
      v0 = &unk_B371;
      return printk(v0, "ipclite_test", "ipclite_test_set_test");
    }
    if ( (qword_B688 & 1) == 0 )
    {
      v0 = &unk_A46C;
      return printk(v0, "ipclite_test", "ipclite_test_set_test");
    }
    v9 = __clz(__rbit32(HIDWORD(qword_B680)));
    if ( HIDWORD(qword_B680) )
      v10 = v9;
    else
      v10 = -1;
    ssr_client = v10;
    if ( !v10 || (((unsigned __int64)(unsigned int)dword_B690 >> v10) & 1) == 0 )
    {
      v0 = &unk_ACDF;
      return printk(v0, "ipclite_test", "ipclite_test_set_test");
    }
    if ( v10 <= 9 )
    {
      printk(&unk_A40F, "ipclite_test", "ipclite_test_set_test");
      v3 = ssr_test;
      goto LABEL_29;
    }
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(StatusReg + 80);
  v13 = 120LL * (unsigned int)qword_B694;
  *(_QWORD *)(StatusReg + 80) = &ipclite_test_set_test__alloc_tag;
  result = _kmalloc_noprof(v13, 3520);
  *(_QWORD *)(StatusReg + 80) = v12;
LABEL_7:
  th_arr = result;
  if ( result )
  {
    byte_B720 = 0;
    _init_waitqueue_head(&unk_B708, "&th_data->wq", &thread_init___key);
    v4 = wrapper_ping_test;
    goto LABEL_32;
  }
  return result;
}
