void __fastcall _ipa_stop_gsi_channel(unsigned int a1)
{
  __int64 v2; // x25
  unsigned int v3; // w19
  bool v4; // zf
  unsigned int v5; // w8
  int v6; // w26
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  int v12; // w23
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0

  if ( *(_DWORD *)(ipa3_ctx + 34308) > a1 )
  {
    if ( a1 >= 0x24 )
      JUMPOUT(0x12CA44);
    v2 = ipa3_ctx + 168 + 480LL * a1;
    if ( *(_DWORD *)v2 )
    {
      v3 = *(_DWORD *)(ipa3_ctx + 168 + 480LL * a1 + 4);
      v4 = v3 - 87 > 6 || ((1 << (v3 - 87)) & 0x55) == 0;
      if ( !v4 || v3 <= 0x13 && ((1 << v3) & 0x82800) != 0 )
      {
        if ( (unsigned int)ipa3_uc_client_del_holb_monitor(*(_WORD *)(v2 + 8), 0) )
          JUMPOUT(0x12C884);
        if ( *(_WORD *)(v2 + 348) )
          ipa3_cfg_ep_holb(a1, (_DWORD *)(v2 + 336));
      }
      v5 = *(_DWORD *)(ipa3_ctx + 32240);
      if ( v5 < 0x11 || v5 <= 0x17 && ((1 << v5) & 0x940000) != 0 )
      {
        v6 = 10;
        while ( 1 )
        {
          v7 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v8 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v8 )
            {
              ipc_log_string(
                v8,
                "ipa %s:%d Calling gsi_stop_channel ch:%lu\n",
                "__ipa_stop_gsi_channel",
                12632,
                *(_QWORD *)(v2 + 8));
              v7 = ipa3_ctx;
            }
            v9 = *(_QWORD *)(v7 + 34160);
            if ( v9 )
              ipc_log_string(
                v9,
                "ipa %s:%d Calling gsi_stop_channel ch:%lu\n",
                "__ipa_stop_gsi_channel",
                12632,
                *(_QWORD *)(v2 + 8));
          }
          v10 = gsi_stop_channel(*(_QWORD *)(v2 + 8));
          v11 = ipa3_ctx;
          v12 = v10;
          if ( ipa3_ctx )
          {
            v13 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v13 )
            {
              ipc_log_string(
                v13,
                "ipa %s:%d gsi_stop_channel ch: %lu returned %d\n",
                "__ipa_stop_gsi_channel",
                12635,
                *(_QWORD *)(v2 + 8),
                v12);
              v11 = ipa3_ctx;
            }
            v10 = *(_QWORD *)(v11 + 34160);
            if ( v10 )
              v10 = ipc_log_string(
                      v10,
                      "ipa %s:%d gsi_stop_channel ch: %lu returned %d\n",
                      "__ipa_stop_gsi_channel",
                      12635,
                      *(_QWORD *)(v2 + 8),
                      v12);
          }
          if ( (unsigned int)(v12 + 10) < 0xFFFFFFFE )
            JUMPOUT(0x12C860);
          v14 = ipa3_ctx;
          if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
          {
            if ( ipa3_ctx )
            {
              v15 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v15 )
              {
                ipc_log_string(
                  v15,
                  "ipa %s:%d Inject a DMA_TASK with 1B packet to IPA\n",
                  "__ipa_stop_gsi_channel",
                  12643);
                v14 = ipa3_ctx;
              }
              v10 = *(_QWORD *)(v14 + 34160);
              if ( v10 )
                v10 = ipc_log_string(
                        v10,
                        "ipa %s:%d Inject a DMA_TASK with 1B packet to IPA\n",
                        "__ipa_stop_gsi_channel",
                        12643);
            }
            if ( (unsigned int)ipa3_inject_dma_task_for_gsi(v10) )
              JUMPOUT(0x12C900);
          }
          usleep_range_state(1000, 2000, 2);
          if ( !--v6 )
            JUMPOUT(0x12C7F4);
        }
      }
      JUMPOUT(0x12C78C);
    }
  }
  printk(&unk_3F1C1D, "__ipa_stop_gsi_channel");
  v16 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v17 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d bad parm.\n", "__ipa_stop_gsi_channel", 12556);
      v16 = ipa3_ctx;
    }
    if ( *(_QWORD *)(v16 + 34160) )
      JUMPOUT(0x12C774);
  }
  JUMPOUT(0x12C7C8);
}
