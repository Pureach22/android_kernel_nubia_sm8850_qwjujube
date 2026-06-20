__int64 __fastcall hw_mutex_test(__int64 a1)
{
  _DWORD *v2; // x22
  void *v3; // x0
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x24
  void *v8; // x20
  unsigned int v9; // w19
  __int64 v10; // x0
  __int64 v11; // x8
  int v12; // w21
  __int64 v14; // x21
  _QWORD v15[6]; // [xsp+0h] [xbp-30h] BYREF

  v15[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (qword_B680 & 0x100000000LL) == 0 )
  {
    *(_BYTE *)(a1 + 112) = 0;
    ping_sel_senders(0xAA01060000000200LL);
    goto LABEL_20;
  }
  v2 = (_DWORD *)global_memory;
  if ( !global_memory )
  {
    v3 = &unk_A8DC;
    goto LABEL_18;
  }
  v4 = printk(&unk_B3FE, "ipclite_test", "hw_unlock_test");
  *v2 = -1;
  if ( (unsigned int)ipclite_hw_mutex_acquire(v4) )
  {
    v3 = &unk_A693;
    goto LABEL_18;
  }
  v5 = 0;
  *v2 = 0;
  do
  {
    if ( v5 )
    {
      if ( (((unsigned __int64)(unsigned int)qword_B688 >> v5) & 1) != 0 )
      {
        *(_BYTE *)(a1 + 112) = 0;
        ipclite_test_msg_send((unsigned int)v5, 0xAA01060000010200LL);
        v6 = -100;
        do
          _const_udelay(4295000);
        while ( !__CFADD__(v6++, 1) );
        if ( *v2 )
        {
          printk(&unk_AE4A, "ipclite_test", "hw_unlock_test");
          goto LABEL_19;
        }
      }
    }
    ++v5;
  }
  while ( v5 != 9 );
  if ( (unsigned int)ipclite_hw_mutex_release() )
  {
    v3 = &unk_B291;
LABEL_18:
    printk(v3, "ipclite_test", "hw_unlock_test");
LABEL_19:
    printk(&unk_ACAC, "ipclite_test", "hw_mutex_test");
  }
LABEL_20:
  v8 = &unk_B23B;
  if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
  {
    v9 = 1250;
  }
  else
  {
    memset(v15, 0, 40);
    init_wait_entry(v15, 0);
    v10 = prepare_to_wait_event(a1 + 88, v15, 1);
    if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
    {
      LODWORD(v11) = 1250;
LABEL_24:
      v12 = v11;
      finish_wait(a1 + 88, v15);
      LODWORD(v10) = v12;
    }
    else
    {
      v11 = 1250;
      while ( !v10 )
      {
        v14 = schedule_timeout(v11);
        v10 = prepare_to_wait_event(a1 + 88, v15, 1);
        if ( (*(_BYTE *)(a1 + 112) & (v14 == 0)) != 0 )
          v11 = 1;
        else
          v11 = v14;
        if ( (*(_BYTE *)(a1 + 112) & 1) != 0 || !v11 )
          goto LABEL_24;
      }
    }
    v9 = v10;
    if ( (int)v10 < 1 )
      v8 = &unk_A713;
  }
  printk(v8, "ipclite_test", "hw_mutex_test");
  complete(&test_done);
  _ReadStatusReg(SP_EL0);
  return v9;
}
