__int64 __fastcall send_bg_pings(__int64 a1)
{
  __int64 v1; // x19
  char v2; // w8
  __int64 should_stop; // x0
  __int64 v5; // x25
  __int64 v6; // x0
  int v7; // w26
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x26
  __int64 v11; // x26
  __int64 v12; // [xsp+8h] [xbp-58h] BYREF
  __int64 v13; // [xsp+10h] [xbp-50h]
  __int64 v14; // [xsp+18h] [xbp-48h]
  __int64 v15; // [xsp+20h] [xbp-40h]
  __int64 v16; // [xsp+28h] [xbp-38h]
  _QWORD v17[4]; // [xsp+30h] [xbp-30h] BYREF
  int v18; // [xsp+50h] [xbp-10h]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v1 = a1;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 112);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  if ( (v2 & 1) == 0 )
  {
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v12 = 0;
    init_wait_entry(&v12, 0);
    a1 = prepare_to_wait_event(v1 + 88, &v12, 1);
    if ( (*(_BYTE *)(v1 + 112) & 1) != 0 )
    {
LABEL_5:
      a1 = finish_wait(v1 + 88, &v12);
    }
    else
    {
      while ( !a1 )
      {
        schedule();
        a1 = prepare_to_wait_event(v1 + 88, &v12, 1);
        if ( *(_BYTE *)(v1 + 112) == 1 )
          goto LABEL_5;
      }
    }
  }
  should_stop = kthread_should_stop(a1);
  if ( (should_stop & 1) != 0 )
    goto LABEL_7;
  while ( 2 )
  {
    v5 = 0;
    *(_BYTE *)(v1 + 112) = 0;
    while ( 1 )
    {
      if ( !v5 || (((unsigned __int64)(unsigned int)qword_B688 >> v5) & 1) == 0 || *((_DWORD *)v17 + v5) )
        goto LABEL_12;
      v6 = ipclite_test_msg_send((unsigned int)v5, 0xAA010500000A0000LL);
      if ( !(_DWORD)v6 )
        break;
      should_stop = printk(&unk_B4F3, "ipclite_test", "send_bg_pings");
      *((_DWORD *)v17 + v5) = 1;
LABEL_12:
      if ( ++v5 == 9 )
        goto LABEL_9;
    }
    if ( (*(_BYTE *)(v1 + 112) & 1) != 0 )
    {
      v7 = 250;
      should_stop = kthread_should_stop(v6);
      if ( (should_stop & 1) != 0 )
        goto LABEL_9;
      goto LABEL_24;
    }
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v12 = 0;
    init_wait_entry(&v12, 0);
    v8 = prepare_to_wait_event(v1 + 88, &v12, 1);
    if ( (*(_BYTE *)(v1 + 112) & 1) != 0 )
    {
      v9 = 250;
LABEL_22:
      v10 = v9;
      finish_wait(v1 + 88, &v12);
      v8 = v10;
    }
    else
    {
      v9 = 250;
      while ( !v8 )
      {
        v11 = schedule_timeout(v9);
        v8 = prepare_to_wait_event(v1 + 88, &v12, 1);
        if ( (*(_BYTE *)(v1 + 112) & (v11 == 0)) != 0 )
          v9 = 1;
        else
          v9 = v11;
        if ( (*(_BYTE *)(v1 + 112) & 1) != 0 || !v9 )
          goto LABEL_22;
      }
    }
    v7 = v8;
    should_stop = kthread_should_stop(v8);
    if ( (should_stop & 1) == 0 )
    {
LABEL_24:
      if ( v7 <= 0 )
        should_stop = printk(&unk_AFD4, "ipclite_test", "send_bg_pings");
      goto LABEL_12;
    }
LABEL_9:
    should_stop = kthread_should_stop(should_stop);
    if ( (should_stop & 1) == 0 )
      continue;
    break;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return 0;
}
