__int64 ipa3_init_interrupts()
{
  int v0; // w8
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  if ( (unsigned int)ipa3_interrupts_init((unsigned int)dword_1F7DCC, 0, *(_QWORD *)(ipa3_ctx + 34208) + 16LL) )
  {
    printk(&unk_3B450B, "ipa3_init_interrupts");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d ipa interrupts initialization failed\n", "ipa3_init_interrupts", 7523);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d ipa interrupts initialization failed\n", "ipa3_init_interrupts", 7523);
    }
    return 4294967277LL;
  }
  v0 = ipa_add_interrupt_handler(13, &ipa3_suspend_handler, 0, 0);
  result = 0;
  if ( v0 )
  {
    printk(&unk_3D7AEB, "ipa3_init_interrupts");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d register handler for suspend interrupt failed\n", "ipa3_init_interrupts", 7531);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d register handler for suspend interrupt failed\n", "ipa3_init_interrupts", 7531);
        v5 = ipa3_ctx;
      }
    }
    ipa3_interrupts_destroy((unsigned int)dword_1F7DCC, *(_QWORD *)(v5 + 34208) + 16LL);
    return 4294967277LL;
  }
  return result;
}
