void ipa3_freeze_clock_vote_and_notify_modem()
{
  __int64 v0; // x9
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w9
  unsigned int v10; // w11
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  _BYTE *v17; // x9
  __int64 v18; // x0
  const char *v19; // x4
  __int64 v20; // x0
  const char *v21; // x4
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0

  v0 = ipa3_ctx;
  _X8 = (unsigned int *)(ipa3_ctx + 30552);
  if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
  {
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d Ignore smp2p on APQ platform\n", "ipa3_freeze_clock_vote_and_notify_modem", 7573);
        v0 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v0 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d Ignore smp2p on APQ platform\n", "ipa3_freeze_clock_vote_and_notify_modem", 7573);
    }
  }
  else if ( (*(_BYTE *)(ipa3_ctx + 43729) & 1) == 0 )
  {
    if ( *(_QWORD *)(ipa3_ctx + 43736) >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_3B1A6F, "ipa3_freeze_clock_vote_and_notify_modem");
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v23 )
        {
          ipc_log_string(
            v23,
            "ipa %s:%d fail to get smp2p clk resp bit %ld\n",
            "ipa3_freeze_clock_vote_and_notify_modem",
            7582,
            *(_QWORD *)(ipa3_ctx + 43736));
          v22 = ipa3_ctx;
        }
        v24 = *(_QWORD *)(v22 + 34160);
        if ( v24 )
          ipc_log_string(
            v24,
            "ipa %s:%d fail to get smp2p clk resp bit %ld\n",
            "ipa3_freeze_clock_vote_and_notify_modem",
            7582,
            *(_QWORD *)(v22 + 43736));
      }
    }
    else
    {
      v4 = *_X8;
      do
      {
        if ( !v4 )
        {
          v11 = ipa3_ctx;
          v13 = 1;
          goto LABEL_22;
        }
        __asm { PRFM            #0x11, [X8] }
        while ( 1 )
        {
          v10 = __ldxr(_X8);
          if ( v10 != v4 )
            break;
          if ( !__stlxr(v4 + 1, _X8) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v10 == v4;
        v4 = v10;
      }
      while ( !_ZF );
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v12 )
        {
          ipc_log_string(
            v12,
            "ipa %s:%d active clients = %d\n",
            "ipa3_inc_client_enable_clks_no_block",
            7045,
            *(_DWORD *)(ipa3_ctx + 30552));
          v11 = ipa3_ctx;
        }
      }
      v13 = 3;
      LOBYTE(v4) = 1;
LABEL_22:
      v14 = v11 + 40960;
      v15 = *(_QWORD *)(v14 + 2776);
      *(_BYTE *)(v14 + 2768) = v4;
      qcom_smem_state_update_bits(v15, 3, v13);
      v16 = ipa3_ctx;
      v17 = (_BYTE *)(ipa3_ctx + 43728);
      *(_BYTE *)(ipa3_ctx + 43729) = 1;
      if ( v16 )
      {
        v18 = *(_QWORD *)(v16 + 34152);
        if ( v18 )
        {
          if ( *v17 )
            v19 = "ON";
          else
            v19 = "OFF";
          ipc_log_string(v18, "ipa %s:%d IPA clocks are %s\n", "ipa3_freeze_clock_vote_and_notify_modem", 7601, v19);
          v16 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v16 + 34160);
        if ( v20 )
        {
          if ( *(_BYTE *)(v16 + 43728) )
            v21 = "ON";
          else
            v21 = "OFF";
          ipc_log_string(v20, "ipa %s:%d IPA clocks are %s\n", "ipa3_freeze_clock_vote_and_notify_modem", 7601, v21);
        }
      }
    }
  }
}
