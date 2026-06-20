__int64 __fastcall negative_tests(__int64 a1)
{
  unsigned int v2; // w20
  char v3; // w23
  __int64 v4; // x0
  __int64 v5; // x21
  void *v6; // x0
  bool v7; // zf
  _QWORD v9[6]; // [xsp+0h] [xbp-30h] BYREF

  v9[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (qword_B680 & 0x100000000LL) != 0 )
  {
    printk(&unk_B472, "ipclite_test", "negative_tests");
    if ( (qword_B688 & 1) != 0 )
    {
      v3 = 0;
      if ( !(unsigned int)ipclite_test_msg_send(0, 0xAA010200000A0000LL) )
      {
        printk(&unk_B0B9, "ipclite_test", "negative_tests");
        v3 = 1;
      }
    }
    else
    {
      v3 = 0;
    }
    if ( (qword_B688 & 2) != 0 && !(unsigned int)ipclite_test_msg_send(1, 0xAA010200000A0000LL) )
    {
      v3 = 1;
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
    }
    if ( (qword_B688 & 4) != 0 && !(unsigned int)ipclite_test_msg_send(2, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    if ( (qword_B688 & 8) != 0 && !(unsigned int)ipclite_test_msg_send(3, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    if ( (qword_B688 & 0x10) != 0 && !(unsigned int)ipclite_test_msg_send(4, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    if ( (qword_B688 & 0x20) != 0 && !(unsigned int)ipclite_test_msg_send(5, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    if ( (qword_B688 & 0x40) != 0 && !(unsigned int)ipclite_test_msg_send(6, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    if ( (qword_B688 & 0x80) != 0 && !(unsigned int)ipclite_test_msg_send(7, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    if ( (qword_B688 & 0x100) != 0 && !(unsigned int)ipclite_test_msg_send(8, 0xAA010200000A0000LL) )
    {
      printk(&unk_B0B9, "ipclite_test", "negative_tests");
      v3 = 1;
    }
    printk(&unk_AF99, "ipclite_test", "negative_tests");
    if ( (unsigned int)get_global_partition_info(0) )
    {
      if ( (v3 & 1) != 0 )
      {
        v2 = -1;
      }
      else
      {
        printk(&unk_B3B1, "ipclite_test", "negative_tests");
        v2 = 0;
        ++cores_completed;
      }
    }
    else
    {
      printk(&unk_AB85, "ipclite_test", "negative_tests");
      v2 = -1;
    }
  }
  else
  {
    v2 = 0;
  }
  if ( cores_completed == HIDWORD(qword_B694) )
    goto LABEL_51;
  memset(v9, 0, 40);
  init_wait_entry(v9, 0);
  v4 = prepare_to_wait_event(a1 + 88, v9, 1);
  v5 = 1250;
  if ( cores_completed == HIDWORD(qword_B694) )
  {
LABEL_38:
    finish_wait(a1 + 88, v9);
    LODWORD(v4) = v5;
  }
  else
  {
    while ( !v4 )
    {
      v5 = schedule_timeout(v5);
      v4 = prepare_to_wait_event(a1 + 88, v9, 1);
      if ( v5 )
        v7 = 0;
      else
        v7 = cores_completed == HIDWORD(qword_B694);
      if ( v7 )
        v5 = 1;
      if ( cores_completed == HIDWORD(qword_B694) || !v5 )
        goto LABEL_38;
    }
  }
  if ( (int)v4 >= 1 )
LABEL_51:
    v6 = &unk_B23B;
  else
    v6 = &unk_B4A7;
  printk(v6, "ipclite_test", "negative_tests");
  complete(&test_done);
  _ReadStatusReg(SP_EL0);
  return v2;
}
