__int64 __fastcall ssr_wakeup_check(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w23
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w21
  __int64 v7; // x21
  void *v8; // x0
  __int64 v9; // x0
  unsigned __int8 v10; // w9
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // [xsp+0h] [xbp-30h] BYREF
  __int64 v17; // [xsp+8h] [xbp-28h]
  __int64 v18; // [xsp+10h] [xbp-20h]
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 112) & 1) == 0 )
  {
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v16 = 0;
    init_wait_entry(&v16, 0);
    v2 = prepare_to_wait_event(a1 + 88, &v16, 1);
    if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
    {
LABEL_5:
      finish_wait(a1 + 88, &v16);
    }
    else
    {
      while ( !v2 )
      {
        schedule();
        v2 = prepare_to_wait_event(a1 + 88, &v16, 1);
        if ( *(_BYTE *)(a1 + 112) == 1 )
          goto LABEL_5;
      }
    }
  }
  *(_BYTE *)(a1 + 112) = 0;
  msleep_interruptible(30000);
  v3 = 0;
  while ( 1 )
  {
    ipclite_test_msg_send((unsigned int)ssr_client, 0xAA01050000020200LL);
    if ( *(_BYTE *)(a1 + 112) == 1 )
      break;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v16 = 0;
    init_wait_entry(&v16, 0);
    v4 = prepare_to_wait_event(a1 + 88, &v16, 1);
    if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
    {
      LODWORD(v5) = 250;
LABEL_10:
      v6 = v5;
      finish_wait(a1 + 88, &v16);
      LODWORD(v4) = v6;
    }
    else
    {
      v5 = 250;
      while ( !v4 )
      {
        v7 = schedule_timeout(v5);
        v4 = prepare_to_wait_event(a1 + 88, &v16, 1);
        if ( (*(_BYTE *)(a1 + 112) & (v7 == 0)) != 0 )
          v5 = 1;
        else
          v5 = v7;
        if ( (*(_BYTE *)(a1 + 112) & 1) != 0 || !v5 )
          goto LABEL_10;
      }
    }
    if ( (int)v4 > 0 )
      break;
    if ( ++v3 == 10 )
    {
      kthread_stop(bg_pings);
      v8 = &unk_B1F5;
LABEL_24:
      printk(v8, "ipclite_test", "ssr_wakeup_check");
      goto LABEL_27;
    }
  }
  kthread_stop(bg_pings);
  *(_BYTE *)(a1 + 112) = 0;
  printk(&unk_A864, "ipclite_test", "ssr_wakeup_check");
  ipclite_test_msg_send(
    (unsigned int)ssr_client,
    ((unsigned __int64)(unsigned int)test_params << 56)
  | ((unsigned __int64)(HIDWORD(test_params) & 0xFFFFF) << 28)
  | ((unsigned __int64)(qword_B680 & 0xFFF) << 16)
  | (16 * (qword_B688 & 0xFFF))
  | qword_B694 & 0xF
  | 0x2000000000000LL);
  ipclite_test_msg_send((unsigned int)ssr_client, 0xAA01010000000200LL);
  if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
    goto LABEL_27;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v16 = 0;
  init_wait_entry(&v16, 0);
  v9 = prepare_to_wait_event(a1 + 88, &v16, 1);
  v10 = *(_BYTE *)(a1 + 112);
  if ( (v10 & 1) == 0 )
  {
    if ( v9 )
    {
LABEL_36:
      if ( (v10 & 1) != 0 )
        goto LABEL_27;
LABEL_37:
      v8 = &unk_B11E;
      goto LABEL_24;
    }
    v12 = 1250;
    while ( 1 )
    {
      v13 = schedule_timeout(v12);
      v14 = prepare_to_wait_event(a1 + 88, &v16, 1);
      v10 = *(_BYTE *)(a1 + 112);
      v15 = v14;
      v12 = (v10 & (v13 == 0)) != 0 ? 1LL : v13;
      if ( (*(_BYTE *)(a1 + 112) & 1) != 0 || !v12 )
        break;
      if ( v15 )
        goto LABEL_36;
    }
  }
  finish_wait(a1 + 88, &v16);
  if ( (*(_BYTE *)(a1 + 112) & 1) == 0 )
    goto LABEL_37;
LABEL_27:
  byte_B720 = 1;
  _wake_up(&unk_B708, 1, 1, 0);
  _ReadStatusReg(SP_EL0);
  return 0;
}
