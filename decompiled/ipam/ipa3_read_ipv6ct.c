__int64 __fastcall ipa3_read_ipv6ct(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  _BYTE *v3; // x21
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v12[0] = 0;
  v3 = (_BYTE *)(ipa3_ctx + 30302);
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    v5 = ipa3_ctx;
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_read_ipv6ct", 2675);
      v5 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v5 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d In\n", "ipa3_read_ipv6ct", 2675);
  }
  printk(&unk_3C36C1, a2);
  if ( (*v3 & 1) != 0 )
  {
    if ( (v3[1] & 1) != 0 )
    {
      mutex_lock(v2 + 30096);
      ipa3_start_read_memory_device(v2 + 30080, 3, (char *)v12 + 4, v12);
      ipa3_finish_read_memory_device(v2 + 30080, HIDWORD(v12[0]), LODWORD(v12[0]));
      mutex_unlock(v2 + 30096);
    }
    else
    {
      printk(&unk_3B4A85, v7);
    }
  }
  else
  {
    printk(&unk_3D82E7, v7);
  }
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d Out\n", "ipa3_read_ipv6ct", 2705);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d Out\n", "ipa3_read_ipv6ct", 2705);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
