__int64 __fastcall ipa3_panic_notifier(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v7; // x9
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x0
  int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x0
  unsigned int v16; // w9
  unsigned int v22; // w11
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned int v40; // w9
  unsigned int v43; // w10

  if ( ipa3_ctx )
  {
    if ( (*(_BYTE *)(ipa3_ctx + 51241) & 1) != 0 )
      return 0;
    *(_BYTE *)(ipa3_ctx + 51241) = 1;
  }
  ipa3_freeze_clock_vote_and_notify_modem();
  v7 = ipa3_ctx;
  v8 = a1;
  v9 = a2;
  v10 = a3;
  if ( ipa3_ctx )
  {
    if ( *(_QWORD *)(ipa3_ctx + 34152) )
    {
      ipc_log_string(*(_QWORD *)(ipa3_ctx + 34152), "ipa %s:%d Calling uC panic handler\n", "ipa3_panic_notifier", 7637);
      v7 = ipa3_ctx;
      v8 = a1;
      v9 = a2;
      v10 = a3;
    }
    if ( *(_QWORD *)(v7 + 34160) )
    {
      ipc_log_string(*(_QWORD *)(v7 + 34160), "ipa %s:%d Calling uC panic handler\n", "ipa3_panic_notifier", 7637);
      v8 = a1;
      v9 = a2;
      v10 = a3;
    }
  }
  v11 = ipa3_uc_panic_notifier(v8, v9, v10);
  if ( (_DWORD)v11 )
  {
    v12 = v11;
    v11 = printk(&unk_3EE69B, "ipa3_panic_notifier");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d uC panic handler failed %d\n", "ipa3_panic_notifier", 7640, v12);
        v13 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v13 + 34160);
      if ( v11 )
        v11 = ipc_log_string(v11, "ipa %s:%d uC panic handler failed %d\n", "ipa3_panic_notifier", 7640, v12);
    }
  }
  _X8 = (unsigned int *)(ipa3_ctx + 30552);
  v16 = *(_DWORD *)(ipa3_ctx + 30552);
  while ( v16 )
  {
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v22 = __ldxr(_X8);
      if ( v22 != v16 )
        break;
      if ( !__stlxr(v16 + 1, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v22 == v16;
    v16 = v22;
    if ( _ZF )
    {
      v23 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v11 )
        {
          v11 = ipc_log_string(
                  v11,
                  "ipa %s:%d active clients = %d\n",
                  "ipa3_inc_client_enable_clks_no_block",
                  7045,
                  *(_DWORD *)(ipa3_ctx + 30552));
          v23 = ipa3_ctx;
        }
      }
      if ( *(_DWORD *)(v23 + 45120) )
      {
        ipa_save_registers(v11);
        v27 = ipahal_print_all_regs(0);
        ipa_wigig_save_regs(v27);
        goto LABEL_35;
      }
      goto LABEL_29;
    }
  }
  v31 = ipa3_ctx;
  if ( !*(_DWORD *)(ipa3_ctx + 45120) )
  {
LABEL_29:
    printk(&unk_3FA926, "ipa3_panic_notifier");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d IPA clk off not saving the IPA registers\n", "ipa3_panic_notifier", 7646);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(v26, "ipa %s:%d IPA clk off not saving the IPA registers\n", "ipa3_panic_notifier", 7646);
    }
    goto LABEL_35;
  }
  if ( ipa3_ctx )
  {
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      ipc_log_string(v32, "ipa %s:%d IPA resume in progress increment clinet cnt\n", "ipa3_panic_notifier", 7650);
      v31 = ipa3_ctx;
    }
    v33 = *(_QWORD *)(v31 + 34160);
    if ( v33 )
    {
      ipc_log_string(v33, "ipa %s:%d IPA resume in progress increment clinet cnt\n", "ipa3_panic_notifier", 7650);
      v31 = ipa3_ctx;
    }
  }
  _X8 = (unsigned int *)(v31 + 30552);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stxr(v40 + 1, _X8) );
  ((void (*)(void))ipa_save_registers)();
  v34 = ipahal_print_all_regs(0);
  ipa_wigig_save_regs(v34);
  v35 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v36 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v36 )
    {
      ipc_log_string(v36, "ipa %s:%d IPA resume in progress decrement clinet cnt\n", "ipa3_panic_notifier", 7657);
      v35 = ipa3_ctx;
    }
    v37 = *(_QWORD *)(v35 + 34160);
    if ( v37 )
    {
      ipc_log_string(v37, "ipa %s:%d IPA resume in progress decrement clinet cnt\n", "ipa3_panic_notifier", 7657);
      v35 = ipa3_ctx;
    }
  }
  _X8 = (unsigned int *)(v35 + 30552);
  __asm { PRFM            #0x11, [X8] }
  do
    v43 = __ldxr(_X8);
  while ( __stxr(v43 - 1, _X8) );
LABEL_35:
  ipa3_active_clients_log_print_table(active_clients_table_buf, 4096);
  printk(&unk_3E5C70, "ipa3_panic_notifier");
  v28 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d %s\n", "ipa3_panic_notifier", 7664, (const char *)active_clients_table_buf);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( v30 )
      ipc_log_string(v30, "ipa %s:%d %s\n", "ipa3_panic_notifier", 7664, (const char *)active_clients_table_buf);
  }
  return 0;
}
