__int64 ipa3_disable_clks()
{
  __int64 v0; // x8
  __int64 v1; // x0
  unsigned __int64 StatusReg; // x8
  int v3; // w0
  __int64 v4; // x0
  void (*v5)(void); // x8
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x8
  unsigned __int64 v10; // x19
  __int64 v11; // x24
  __int64 v12; // x8
  __int64 v13; // x0
  int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v23; // w9

  v0 = ipa3_ctx;
  if ( (*(_DWORD *)(ipa3_ctx + 32248) | 4) == 4 )
  {
    if ( ipa3_ctx )
    {
      v1 = *(_QWORD *)(ipa3_ctx + 34168);
      if ( v1 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v1,
          "ipa %s:%d disabling IPA clocks and bus voting in Process:%s, PID:%d\n",
          "ipa3_disable_clks",
          6786,
          (const char *)(StatusReg + 2320),
          *(_DWORD *)(StatusReg + 1800));
        v0 = ipa3_ctx;
      }
    }
    *(_DWORD *)(v0 + 45120) = 0;
    if ( (*(_BYTE *)(v0 + 32260) & 1) == 0 )
    {
      v3 = gsi_pending_irq_type();
      if ( v3 )
      {
        v14 = v3;
        printk(&unk_3B7451, "ipa3_disable_clks");
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v15 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v15 )
          {
            ipc_log_string(v15, "ipa %s:%d unexpected gsi irq type: %d\n", "ipa3_disable_clks", 6802, v14);
            v9 = ipa3_ctx;
          }
          v16 = *(_QWORD *)(v9 + 34160);
          if ( v16 )
          {
            ipc_log_string(v16, "ipa %s:%d unexpected gsi irq type: %d\n", "ipa3_disable_clks", 6802, v14);
            v9 = ipa3_ctx;
          }
        }
        goto LABEL_46;
      }
      v0 = ipa3_ctx;
    }
    if ( v0 )
    {
      v4 = *(_QWORD *)(v0 + 34168);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d Disabling IPA Clocks Started\n", "ipa3_disable_clks", 6810);
        v0 = ipa3_ctx;
      }
    }
    v5 = *(void (**)(void))(*(_QWORD *)(v0 + 34176) + 144LL);
    if ( *((_DWORD *)v5 - 1) != -440107680 )
      __break(0x8228u);
    v5();
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34168);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d Disabling IPA Clocks Finished\n", "ipa3_disable_clks", 6812);
    }
    result = ipa_pm_set_clock_index(0);
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      result = *(_QWORD *)(ipa3_ctx + 34168);
      if ( result )
      {
        result = ipc_log_string(result, "ipa %s:%d IPA ICC Voting for BW Started\n", "ipa3_disable_clks", 6816);
        v9 = ipa3_ctx;
      }
    }
    if ( *(_DWORD *)(v9 + 48564) )
    {
      v10 = 0;
      v11 = 48572;
      do
      {
        if ( v10 == 4 )
        {
          while ( 1 )
          {
            __break(0x5512u);
LABEL_46:
            _X8 = (unsigned int *)(v9 + 30552);
            __asm { PRFM            #0x11, [X8] }
            do
              v23 = __ldxr(_X8);
            while ( __stxr(v23 + 1, _X8) );
            *(_DWORD *)(ipa3_ctx + 45120) = 1;
            printk(&unk_3AED39, v8);
            __break(0x800u);
          }
        }
        result = *(_QWORD *)(*(_QWORD *)(v9 + 34176) + 8 * v10 + 152);
        if ( result )
        {
          result = icc_set_bw(result, *(unsigned int *)(v9 + v11 - 4), *(unsigned int *)(v9 + v11));
          if ( (_DWORD)result )
          {
            result = _warn_printk("path %d bus off failed", v10);
            __break(0x800u);
          }
        }
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          result = *(_QWORD *)(ipa3_ctx + 34168);
          if ( result )
          {
            result = ipc_log_string(
                       result,
                       "ipa %s:%d IPA ICC Voting for BW %d Path Completed\n",
                       "ipa3_disable_clks",
                       6824,
                       v10);
            v9 = ipa3_ctx;
          }
        }
        ++v10;
        v11 += 8;
      }
      while ( v10 < *(unsigned int *)(v9 + 48564) );
    }
    if ( v9 )
    {
      result = *(_QWORD *)(v9 + 34168);
      if ( result )
      {
        result = ipc_log_string(result, "ipa %s:%d IPA ICC Voting for BW Finished\n", "ipa3_disable_clks", 6826);
        v9 = ipa3_ctx;
      }
    }
    *(_DWORD *)(v9 + 45120) = 0;
  }
  else
  {
    result = printk(&unk_3E5924, "ipa3_disable_clks");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d not supported in this mode\n", "ipa3_disable_clks", 6781);
        v12 = ipa3_ctx;
      }
      result = *(_QWORD *)(v12 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d not supported in this mode\n", "ipa3_disable_clks", 6781);
    }
  }
  return result;
}
