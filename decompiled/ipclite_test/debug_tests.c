__int64 __fastcall debug_tests(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  void *v4; // x0
  bool v5; // zf
  _QWORD v7[6]; // [xsp+0h] [xbp-30h] BYREF

  v7[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (qword_B680 & 0x100000000LL) != 0 )
  {
    if ( (unsigned int)ipclite_test_msg_send(9, 0xAA010400000A0000LL) )
    {
      printk(&unk_AE2E, "ipclite_test", "debug_tests");
      ++cores_completed;
    }
    else
    {
      printk(&unk_A321, "ipclite_test", "debug_tests");
    }
  }
  if ( cores_completed == HIDWORD(qword_B694) )
    goto LABEL_20;
  memset(v7, 0, 40);
  init_wait_entry(v7, 0);
  v2 = prepare_to_wait_event(a1 + 88, v7, 1);
  v3 = 1250;
  if ( cores_completed == HIDWORD(qword_B694) )
  {
LABEL_7:
    finish_wait(a1 + 88, v7);
    LODWORD(v2) = v3;
  }
  else
  {
    while ( !v2 )
    {
      v3 = schedule_timeout(v3);
      v2 = prepare_to_wait_event(a1 + 88, v7, 1);
      if ( v3 )
        v5 = 0;
      else
        v5 = cores_completed == HIDWORD(qword_B694);
      if ( v5 )
        v3 = 1;
      if ( cores_completed == HIDWORD(qword_B694) || !v3 )
        goto LABEL_7;
    }
  }
  if ( (int)v2 >= 1 )
LABEL_20:
    v4 = &unk_B23B;
  else
    v4 = &unk_B4A7;
  printk(v4, "ipclite_test", "debug_tests");
  complete(&test_done);
  _ReadStatusReg(SP_EL0);
  return 0;
}
