__int64 __fastcall ipa3_cfg_ep_seq(unsigned int a1, _BYTE *a2)
{
  __int64 v3; // x8
  _DWORD *v4; // x10
  unsigned int v5; // w10
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int *v8; // x12
  unsigned int v9; // w20
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    goto LABEL_35;
  if ( a1 >= 0x24 )
    goto LABEL_64;
  v4 = (_DWORD *)(ipa3_ctx + 168 + 480LL * a1);
  if ( !*v4 )
  {
LABEL_35:
    printk(&unk_3FBFBD, "ipa3_cfg_ep_seq");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d bad param, clnt_hdl = %d", "ipa3_cfg_ep_seq", 8689, a1);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d bad param, clnt_hdl = %d", "ipa3_cfg_ep_seq", 8689, a1);
    }
    goto LABEL_45;
  }
  v5 = v4[1];
  if ( v5 <= 0x85 && (v5 & 1) != 0 )
  {
    printk(&unk_3F8D38, "ipa3_cfg_ep_seq");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d SEQ does not apply to IPA consumer EP %d\n", "ipa3_cfg_ep_seq", 8694, a1);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d SEQ does not apply to IPA consumer EP %d\n", "ipa3_cfg_ep_seq", 8694, a1);
    }
LABEL_45:
    result = 4294967274LL;
    goto LABEL_34;
  }
  if ( v5 - 62 > 9 )
  {
    if ( *a2 == 1 )
    {
      v8 = (unsigned int *)(a2 + 4);
      goto LABEL_17;
    }
    if ( v5 <= 0x85 && *(unsigned __int8 *)(ipa3_ctx + 32244) <= 0x17u )
    {
      v8 = (unsigned int *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 12 + 52 * v5];
LABEL_17:
      v9 = *v8;
      if ( *v8 == -1 )
      {
        if ( !ipa3_ctx )
          goto LABEL_33;
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d should not set sequencer type of ep = %d\n", "ipa3_cfg_ep_seq", 8729, a1);
          v3 = ipa3_ctx;
        }
        result = *(_QWORD *)(v3 + 34160);
        if ( result )
        {
          ipc_log_string(result, "ipa %s:%d should not set sequencer type of ep = %d\n", "ipa3_cfg_ep_seq", 8729, a1);
          goto LABEL_33;
        }
      }
      else
      {
        if ( (v9 & 0xFFFFFFDF) == 0 || *(_DWORD *)(ipa3_ctx + 168 + 480LL * a1 + 232) != 3 )
        {
          ipa3_inc_client_enable_clks();
          v11 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v12 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v12 )
            {
              ipc_log_string(
                v12,
                "ipa %s:%d set sequencers to sequence 0x%x, ep = %d\n",
                "ipa3_cfg_ep_seq",
                8724,
                v9,
                a1);
              v11 = ipa3_ctx;
            }
            v13 = *(_QWORD *)(v11 + 34160);
            if ( v13 )
              ipc_log_string(
                v13,
                "ipa %s:%d set sequencers to sequence 0x%x, ep = %d\n",
                "ipa3_cfg_ep_seq",
                8724,
                v9,
                a1);
          }
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(55, 0, a1, v9);
          if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
          {
            printk(&unk_3E7136, "ipa3_get_client_mapping");
            v23 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v24 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v24 )
              {
                ipc_log_string(v24, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                v23 = ipa3_ctx;
              }
              v25 = *(_QWORD *)(v23 + 34160);
              if ( v25 )
                ipc_log_string(v25, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            }
            __break(0x800u);
            if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
            {
              printk(&unk_3E7136, "ipa3_get_client_mapping");
              v26 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v27 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v27 )
                {
                  ipc_log_string(v27, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                  v26 = ipa3_ctx;
                }
                v28 = *(_QWORD *)(v26 + 34160);
                if ( v28 )
                  ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
              }
              __break(0x800u);
            }
          }
          ipa3_dec_client_disable_clks();
          goto LABEL_33;
        }
        printk(&unk_3B0581, "ipa3_cfg_ep_seq");
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v21 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v21 )
          {
            ipc_log_string(v21, "ipa %s:%d Configuring non-DMA SEQ type to DMA pipe\n", "ipa3_cfg_ep_seq", 8716);
            v20 = ipa3_ctx;
          }
          v22 = *(_QWORD *)(v20 + 34160);
          if ( v22 )
            ipc_log_string(v22, "ipa %s:%d Configuring non-DMA SEQ type to DMA pipe\n", "ipa3_cfg_ep_seq", 8716);
        }
        __break(0x800u);
        result = 4294967274LL;
      }
      goto LABEL_34;
    }
LABEL_64:
    __break(0x5512u);
  }
  if ( !ipa3_ctx )
  {
LABEL_33:
    result = 0;
    goto LABEL_34;
  }
  v6 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v6 )
  {
    ipc_log_string(v6, "ipa %s:%d Skip sequencers configuration for test clients\n", "ipa3_cfg_ep_seq", 8703);
    v3 = ipa3_ctx;
  }
  result = *(_QWORD *)(v3 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Skip sequencers configuration for test clients\n", "ipa3_cfg_ep_seq", 8703);
    goto LABEL_33;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
