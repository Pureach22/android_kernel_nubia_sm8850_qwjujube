__int64 __fastcall ipa3_del_ipv6ct_table(unsigned __int8 *a1)
{
  __int64 v2; // x21
  _BYTE *v3; // x23
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w19
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int inited; // w0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  _QWORD v34[4]; // [xsp+0h] [xbp-20h] BYREF

  v34[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v3 = (_BYTE *)(ipa3_ctx + 30302);
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_del_ipv6ct_table", 2449);
    v5 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d In\n", "ipa3_del_ipv6ct_table", 2449);
  }
  if ( (sram_compatible & 1) == 0 )
    a1[1] = 0;
  if ( (*v3 & 1) != 0 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
    {
      if ( (unsigned int)__ratelimit(&ipa3_del_ipv6ct_table__rs, "ipa3_del_ipv6ct_table") )
      {
        printk(&unk_3E1173, "ipa3_del_ipv6ct_table");
        v6 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_12:
          v7 = *(_QWORD *)(v6 + 34152);
          if ( v7 )
          {
            ipc_log_string(v7, "ipa %s:%d IPv6 connection tracking isn't supported\n", "ipa3_del_ipv6ct_table", 2461);
            v6 = ipa3_ctx;
          }
          v8 = *(_QWORD *)(v6 + 34160);
          if ( v8 )
          {
            ipc_log_string(v8, "ipa %s:%d IPv6 connection tracking isn't supported\n", "ipa3_del_ipv6ct_table", 2461);
LABEL_16:
            v9 = -1;
            goto LABEL_37;
          }
          goto LABEL_47;
        }
      }
      else
      {
        v6 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_12;
      }
LABEL_50:
      v9 = -1;
      goto LABEL_51;
    }
    mutex_lock(v2 + 30096);
    v10 = ipa3_ctx;
    if ( v3[1] != 1 )
      goto LABEL_35;
    v11 = *a1;
    memset(v34, 0, 24);
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d \n", "ipa3_ipv6ct_send_del_table_cmd", 2299);
        v10 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v10 + 34160);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d \n", "ipa3_ipv6ct_send_del_table_cmd", 2299);
        v10 = ipa3_ctx;
      }
    }
    if ( (unsigned int)ipa3_nat_ipv6ct_create_del_table_cmd(v11, 0, v10 + 30080, v34) )
    {
      printk(&unk_3CCC89, "ipa3_ipv6ct_send_del_table_cmd");
      v25 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v26 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v26 )
        {
          ipc_log_string(
            v26,
            "ipa %s:%d Fail to create immediate command to delete IPv6CT table\n",
            "ipa3_ipv6ct_send_del_table_cmd",
            2308);
          v25 = ipa3_ctx;
        }
        v27 = *(_QWORD *)(v25 + 34160);
        if ( v27 )
          ipc_log_string(
            v27,
            "ipa %s:%d Fail to create immediate command to delete IPv6CT table\n",
            "ipa3_ipv6ct_send_del_table_cmd",
            2308);
      }
      v9 = -1;
    }
    else
    {
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d posting IPv6CT delete command\n", "ipa3_ipv6ct_send_del_table_cmd", 2312);
          v14 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v14 + 34160);
        if ( v16 )
          ipc_log_string(v16, "ipa %s:%d posting IPv6CT delete command\n", "ipa3_ipv6ct_send_del_table_cmd", 2312);
      }
      inited = ipa3_ipv6ct_send_init_cmd((__int64)v34);
      if ( !inited )
      {
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(v18, "ipa %s:%d return\n", "ipa3_ipv6ct_send_del_table_cmd", 2319);
            v10 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v10 + 34160);
          if ( v19 )
          {
            ipc_log_string(v19, "ipa %s:%d return\n", "ipa3_ipv6ct_send_del_table_cmd", 2319);
            v10 = ipa3_ctx;
          }
        }
LABEL_35:
        ipa3_nat_ipv6ct_free_mem(v10 + 30080);
        v9 = 0;
LABEL_36:
        mutex_unlock(v2 + 30096);
LABEL_37:
        v6 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_51;
        goto LABEL_38;
      }
      v9 = inited;
      printk(&unk_3A3C85, "ipa3_ipv6ct_send_del_table_cmd");
      v28 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v29 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v29 )
        {
          ipc_log_string(
            v29,
            "ipa %s:%d Fail to send IPv6CT delete immediate command\n",
            "ipa3_ipv6ct_send_del_table_cmd",
            2315);
          v28 = ipa3_ctx;
        }
        v30 = *(_QWORD *)(v28 + 34160);
        if ( v30 )
          ipc_log_string(
            v30,
            "ipa %s:%d Fail to send IPv6CT delete immediate command\n",
            "ipa3_ipv6ct_send_del_table_cmd",
            2315);
      }
    }
    printk(&unk_3C432E, "ipa3_del_ipv6ct_table");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d ipa3_ipv6ct_send_del_table_cmd() fail\n", "ipa3_del_ipv6ct_table", 2472);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
        ipc_log_string(v33, "ipa %s:%d ipa3_ipv6ct_send_del_table_cmd() fail\n", "ipa3_del_ipv6ct_table", 2472);
    }
    goto LABEL_36;
  }
  printk(&unk_3DB94F, "ipa3_del_ipv6ct_table");
  v6 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_50;
  v22 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v22 )
  {
    ipc_log_string(v22, "ipa %s:%d IPv6 connection tracking hasn't been initialized\n", "ipa3_del_ipv6ct_table", 2455);
    v6 = ipa3_ctx;
  }
  v23 = *(_QWORD *)(v6 + 34160);
  if ( v23 )
  {
    ipc_log_string(v23, "ipa %s:%d IPv6 connection tracking hasn't been initialized\n", "ipa3_del_ipv6ct_table", 2455);
    goto LABEL_16;
  }
LABEL_47:
  v9 = -1;
  if ( !v6 )
    goto LABEL_51;
LABEL_38:
  v20 = *(_QWORD *)(v6 + 34152);
  if ( v20 )
  {
    ipc_log_string(v20, "ipa %s:%d Out\n", "ipa3_del_ipv6ct_table", 2483);
    v6 = ipa3_ctx;
  }
  v21 = *(_QWORD *)(v6 + 34160);
  if ( v21 )
    ipc_log_string(v21, "ipa %s:%d Out\n", "ipa3_del_ipv6ct_table", 2483);
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return v9;
}
