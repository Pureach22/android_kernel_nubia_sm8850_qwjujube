unsigned __int64 __fastcall ipa_debugfs_enable_disable_drop_stats(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x9
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  char v15; // w28
  int ep_bit; // w22
  unsigned int ep_reg_idx; // w21
  unsigned int v18; // w26
  int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  int v23; // w9
  __int64 v24; // x24
  unsigned int v25; // w25
  int v26; // w8
  int v27; // w0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  int v31; // w8
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // [xsp+Ch] [xbp-14h]
  _QWORD v36[2]; // [xsp+10h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36[0] = 0;
  v5 = *(_QWORD *)(ipa3_ctx + 43800);
  if ( v5 && *(_BYTE *)v5 == 1 )
    v36[0] = *(_QWORD *)(v5 + 63896);
  mutex_lock(ipa3_ctx + 29472);
  if ( a3 > 0xFFF
    || (_check_object_size(&dbg_buff_1, a3, 0),
        ((__int64 (__fastcall *)(__int64, unsigned __int64))inline_copy_from_user_1)(a2, a3)) )
  {
    a3 = -14;
    goto LABEL_7;
  }
  v7 = ipa3_ctx;
  *((_BYTE *)&dbg_buff_1 + a3) = 0;
  if ( v7 )
  {
    v8 = *(_QWORD *)(v7 + 34152);
    if ( v8 )
    {
      ipc_log_string(
        v8,
        "ipa %s:%d data is %s",
        "ipa_debugfs_enable_disable_drop_stats",
        2784,
        (const char *)&dbg_buff_1);
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
      ipc_log_string(
        v9,
        "ipa %s:%d data is %s",
        "ipa_debugfs_enable_disable_drop_stats",
        2784,
        (const char *)&dbg_buff_1);
  }
  v10 = 0;
  do
  {
    v11 = v10 + 1;
    if ( v10 >= a3 || *((_BYTE *)&dbg_buff_1 + v10) == 32 )
      goto LABEL_18;
    ++v10;
  }
  while ( v11 != 4096 );
  while ( 1 )
  {
LABEL_17:
    __break(0x5512u);
LABEL_18:
    if ( v11 < a3 )
    {
      if ( v10 == 4095 )
      {
        __break(1u);
        JUMPOUT(0xD3610);
      }
      if ( *((_BYTE *)&dbg_buff_1 + v10 + 1) == 48 )
      {
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v13 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v13 )
          {
            ipc_log_string(
              v13,
              "ipa %s:%d Drop stats will be disabled for pipes:",
              "ipa_debugfs_enable_disable_drop_stats",
              2794);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(
              v14,
              "ipa %s:%d Drop stats will be disabled for pipes:",
              "ipa_debugfs_enable_disable_drop_stats",
              2794);
        }
        v35 = 0;
        if ( !v10 )
          goto LABEL_27;
LABEL_43:
        v24 = 0;
        v25 = 0;
        ep_reg_idx = 0;
        ep_bit = 0;
        v15 = 0;
        while ( 1 )
        {
          v26 = *((unsigned __int8 *)&dbg_buff_1 + v24);
          if ( (unsigned int)(v26 - 48) <= 9 )
          {
            v25 = v26 + 10 * v25 - 48;
            ep_reg_idx = ipahal_get_ep_reg_idx(v25);
            ep_bit = ipahal_get_ep_bit(v25);
            v15 = 1;
          }
          v27 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v25);
          if ( *((_BYTE *)&dbg_buff_1 + v24) == 44 )
          {
            if ( v27 == 83 || v27 == 27 )
            {
              v28 = ipa3_ctx;
              if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x14u )
              {
                v15 = 0;
                v18 = 0;
                goto LABEL_45;
              }
            }
            else
            {
              v28 = ipa3_ctx;
            }
            v15 = 0;
            if ( v25 >= *(_DWORD *)(v28 + 34308) )
            {
              v18 = 0;
            }
            else
            {
              v18 = 0;
              if ( v27 <= 133 )
              {
                if ( v28 )
                {
                  v29 = *(_QWORD *)(v28 + 34152);
                  if ( v29 )
                  {
                    ipc_log_string(
                      v29,
                      "ipa %s:%d pipe number %u\n",
                      "ipa_debugfs_enable_disable_drop_stats",
                      2818,
                      v25);
                    v28 = ipa3_ctx;
                  }
                  v30 = *(_QWORD *)(v28 + 34160);
                  if ( v30 )
                    ipc_log_string(
                      v30,
                      "ipa %s:%d pipe number %u\n",
                      "ipa_debugfs_enable_disable_drop_stats",
                      2818,
                      v25);
                }
                v11 = v35;
                if ( v35 )
                {
                  if ( ep_reg_idx > 1 )
                    goto LABEL_17;
                  v15 = 0;
                  v18 = 0;
                  v31 = *((_DWORD *)v36 + ep_reg_idx) | ep_bit;
                }
                else
                {
                  if ( ep_reg_idx > 1 )
                    goto LABEL_17;
                  v15 = 0;
                  v18 = 0;
                  v31 = *((_DWORD *)v36 + ep_reg_idx) & ~ep_bit;
                }
                *((_DWORD *)v36 + ep_reg_idx) = v31;
              }
            }
          }
          else
          {
            v18 = v25;
          }
LABEL_45:
          ++v24;
          v25 = v18;
          if ( v10 == v24 )
            goto LABEL_28;
        }
      }
    }
    v35 = 1;
    if ( v10 )
      goto LABEL_43;
LABEL_27:
    v15 = 0;
    ep_bit = 0;
    ep_reg_idx = 0;
    v18 = 0;
LABEL_28:
    v19 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v18);
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u && (v19 == 83 || v19 == 27) )
      break;
    if ( (v15 & 1) == 0
      || v18 >= *(_DWORD *)(ipa3_ctx + 34308)
      || (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v18) > 0x85 )
    {
      goto LABEL_71;
    }
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d pipe number %u\n", "ipa_debugfs_enable_disable_drop_stats", 2838, v18);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d pipe number %u\n", "ipa_debugfs_enable_disable_drop_stats", 2838, v18);
    }
    v11 = v35;
    if ( v35 )
    {
      if ( ep_reg_idx <= 1 )
      {
        v23 = *((_DWORD *)v36 + ep_reg_idx) | ep_bit;
LABEL_70:
        *((_DWORD *)v36 + ep_reg_idx) = v23;
        goto LABEL_71;
      }
    }
    else if ( ep_reg_idx <= 1 )
    {
      v23 = *((_DWORD *)v36 + ep_reg_idx) & ~ep_bit;
      goto LABEL_70;
    }
  }
  printk(&unk_3ACE1F, "ipa_debugfs_enable_disable_drop_stats");
  v32 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v33 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v33 )
    {
      ipc_log_string(
        v33,
        "ipa %s:%d Enable/Disable hw stats on DPL is not supported",
        "ipa_debugfs_enable_disable_drop_stats",
        2835);
      v32 = ipa3_ctx;
    }
    v34 = *(_QWORD *)(v32 + 34160);
    if ( v34 )
      ipc_log_string(
        v34,
        "ipa %s:%d Enable/Disable hw stats on DPL is not supported",
        "ipa_debugfs_enable_disable_drop_stats",
        2835);
  }
LABEL_71:
  ipa_init_drop_stats((int *)v36);
LABEL_7:
  mutex_unlock(ipa3_ctx + 29472);
  _ReadStatusReg(SP_EL0);
  return a3;
}
