__int64 __fastcall ipa3_send_pdn_config_msg(unsigned __int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 result; // x0
  int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w0
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0x400000;
  v2 = _kmalloc_cache_noprof(ipc_log_string, 3520, 64);
  v3 = v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_38;
  }
  if ( inline_copy_from_user(v2, a1, 0x40u) )
  {
    kfree(v3);
    result = 4294967282LL;
    goto LABEL_38;
  }
  v5 = *(_DWORD *)(v3 + 32);
  *(_BYTE *)(v3 + 31) = 0;
  LOBYTE(v22) = v5;
  if ( (unsigned int)(v5 - 45) <= 0xFFFFFFFC )
  {
    if ( (unsigned int)__ratelimit(&ipa3_send_pdn_config_msg__rs, "ipa3_send_pdn_config_msg") )
      printk(&unk_3C9212, "ipa3_send_pdn_config_msg");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d invalid pdn_cfg_type =%d", "ipa3_send_pdn_config_msg", 1137, *(_DWORD *)(v3 + 32));
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d invalid pdn_cfg_type =%d", "ipa3_send_pdn_config_msg", 1137, *(_DWORD *)(v3 + 32));
    }
    kfree(v3);
    result = 4294967274LL;
    goto LABEL_38;
  }
  v9 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(
        v10,
        "ipa %s:%d type %d, interface name: %s, enable:%d\n",
        "ipa3_send_pdn_config_msg",
        1143,
        v5,
        (const char *)v3,
        *(unsigned __int8 *)(v3 + 36));
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
      ipc_log_string(
        v11,
        "ipa %s:%d type %d, interface name: %s, enable:%d\n",
        "ipa3_send_pdn_config_msg",
        1143,
        v5,
        (const char *)v3,
        *(unsigned __int8 *)(v3 + 36));
  }
  if ( *(_DWORD *)(v3 + 32) == 44 )
  {
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
          "ipa3_send_pdn_config_msg",
          1152,
          *(unsigned __int8 *)(v3 + 50),
          *(unsigned __int8 *)(v3 + 51),
          *(unsigned __int8 *)(v3 + 52),
          *(unsigned __int8 *)(v3 + 53),
          *(unsigned __int8 *)(v3 + 54),
          *(unsigned __int8 *)(v3 + 55));
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(
          v14,
          "ipa %s:%d Client MAC %02x:%02x:%02x:%02x:%02x:%02x\n",
          "ipa3_send_pdn_config_msg",
          1152,
          *(unsigned __int8 *)(v3 + 50),
          *(unsigned __int8 *)(v3 + 51),
          *(unsigned __int8 *)(v3 + 52),
          *(unsigned __int8 *)(v3 + 53),
          *(unsigned __int8 *)(v3 + 54),
          *(unsigned __int8 *)(v3 + 55));
    }
  }
  v15 = ipa_send_msg(&v22, v3, ipa3_pdn_config_msg_free_cb);
  if ( v15 )
  {
    v18 = v15;
    printk(&unk_3A29B0, "ipa3_send_pdn_config_msg");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(
          v20,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_pdn_config_msg",
          1160,
          v18,
          (unsigned __int8)v22);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(
          v21,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_pdn_config_msg",
          1160,
          v18,
          (unsigned __int8)v22);
    }
    kfree(v3);
    result = v18;
  }
  else
  {
    v16 = ipa3_ctx;
    if ( !ipa3_ctx )
    {
LABEL_30:
      result = 0;
      goto LABEL_38;
    }
    v17 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d exit\n", "ipa3_send_pdn_config_msg", 1164);
      v16 = ipa3_ctx;
    }
    result = *(_QWORD *)(v16 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_send_pdn_config_msg", 1164);
      goto LABEL_30;
    }
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
