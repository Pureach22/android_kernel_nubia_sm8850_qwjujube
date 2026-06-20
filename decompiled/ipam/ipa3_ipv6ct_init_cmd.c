__int64 __fastcall ipa3_ipv6ct_init_cmd(unsigned int *a1)
{
  __int64 v2; // x23
  _BYTE *v3; // x22
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  unsigned int v15; // w0
  unsigned int v16; // w19
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned int inited; // w0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  _QWORD v42[4]; // [xsp+10h] [xbp-20h] BYREF

  v42[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v3 = (_BYTE *)(ipa3_ctx + 30303);
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    v5 = ipa3_ctx;
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_ipv6ct_init_cmd", 1607);
      v5 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v5 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d In\n", "ipa3_ipv6ct_init_cmd", 1607);
      v5 = ipa3_ctx;
    }
  }
  else
  {
    v5 = 0;
  }
  v7 = *(_DWORD *)(v5 + 32240);
  memset(v42, 0, 24);
  if ( v7 <= 0xD )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_init_cmd__rs, "ipa3_ipv6ct_init_cmd") )
    {
      printk(&unk_3E1173, "ipa3_ipv6ct_init_cmd");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_10;
    }
    else
    {
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_10:
        v9 = *(_QWORD *)(v8 + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d IPv6 connection tracking isn't supported\n", "ipa3_ipv6ct_init_cmd", 1612);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(v10, "ipa %s:%d IPv6 connection tracking isn't supported\n", "ipa3_ipv6ct_init_cmd", 1612);
      }
    }
LABEL_21:
    result = 0xFFFFFFFFLL;
    goto LABEL_22;
  }
  if ( *((_BYTE *)a1 + 12) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_init_cmd__rs_56, "ipa3_ipv6ct_init_cmd") )
    {
      printk(&unk_3F2550, "ipa3_ipv6ct_init_cmd");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
    }
    v12 = *(_QWORD *)(v11 + 34152);
    if ( v12 )
    {
      ipc_log_string(
        v12,
        "ipa %s:%d Unsupported table index %d\n",
        "ipa3_ipv6ct_init_cmd",
        1617,
        *((unsigned __int8 *)a1 + 12));
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(
        v13,
        "ipa %s:%d Unsupported table index %d\n",
        "ipa3_ipv6ct_init_cmd",
        1617,
        *((unsigned __int8 *)a1 + 12));
    goto LABEL_21;
  }
  if ( !*((_WORD *)a1 + 4) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_init_cmd__rs_57, "ipa3_ipv6ct_init_cmd") )
    {
      printk(&unk_3C10FD, "ipa3_ipv6ct_init_cmd");
      v20 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
    }
    else
    {
      v20 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
    }
    v21 = *(_QWORD *)(v20 + 34152);
    if ( v21 )
    {
      ipc_log_string(v21, "ipa %s:%d Table entries is zero\n", "ipa3_ipv6ct_init_cmd", 1622);
      v20 = ipa3_ctx;
    }
    v22 = *(_QWORD *)(v20 + 34160);
    if ( v22 )
      ipc_log_string(v22, "ipa %s:%d Table entries is zero\n", "ipa3_ipv6ct_init_cmd", 1622);
    goto LABEL_21;
  }
  if ( (v3[1] & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_init_cmd__rs_60, "ipa3_ipv6ct_init_cmd") )
    {
      printk(&unk_3E9AC5, "ipa3_ipv6ct_init_cmd");
      v23 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
    }
    else
    {
      v23 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
    }
    v24 = *(_QWORD *)(v23 + 34152);
    if ( v24 )
    {
      ipc_log_string(
        v24,
        "ipa %s:%d attempt to init %s before mmap\n",
        "ipa3_ipv6ct_init_cmd",
        1628,
        (const char *)(v2 + 30080));
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( v25 )
      ipc_log_string(
        v25,
        "ipa %s:%d attempt to init %s before mmap\n",
        "ipa3_ipv6ct_init_cmd",
        1628,
        (const char *)(v2 + 30080));
    goto LABEL_21;
  }
  v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))ipa3_nat_ipv6ct_check_table_params)(
          v2 + 30080,
          0,
          *a1,
          (unsigned int)*((unsigned __int16 *)a1 + 4) + 1,
          3);
  if ( v15 )
  {
    v16 = v15;
    if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_init_cmd__rs_63, "ipa3_ipv6ct_init_cmd") )
    {
      printk(&unk_3C9D5E, "ipa3_ipv6ct_init_cmd");
      v17 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_86;
    }
    else
    {
      v17 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_86;
    }
    v18 = *(_QWORD *)(v17 + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d Bad params for IPv6CT base table\n", "ipa3_ipv6ct_init_cmd", 1639);
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d Bad params for IPv6CT base table\n", "ipa3_ipv6ct_init_cmd", 1639);
LABEL_53:
      result = v16;
      goto LABEL_22;
    }
LABEL_86:
    result = v16;
    goto LABEL_22;
  }
  v26 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))ipa3_nat_ipv6ct_check_table_params)(
          v2 + 30080,
          0,
          a1[1],
          *((unsigned __int16 *)a1 + 5),
          3);
  if ( v26 )
  {
    v16 = v26;
    if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_init_cmd__rs_66, "ipa3_ipv6ct_init_cmd") )
    {
      printk(&unk_3A9E99, "ipa3_ipv6ct_init_cmd");
      v27 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_86;
    }
    else
    {
      v27 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_86;
    }
    v28 = *(_QWORD *)(v27 + 34152);
    if ( v28 )
    {
      ipc_log_string(v28, "ipa %s:%d Bad params for IPv6CT expansion table\n", "ipa3_ipv6ct_init_cmd", 1650);
      v27 = ipa3_ctx;
    }
    v29 = *(_QWORD *)(v27 + 34160);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d Bad params for IPv6CT expansion table\n", "ipa3_ipv6ct_init_cmd", 1650);
      goto LABEL_53;
    }
    goto LABEL_86;
  }
  v30 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v31 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v31 )
    {
      ipc_log_string(v31, "ipa %s:%d Will install v6 NAT in: %s\n", "ipa3_ipv6ct_init_cmd", 1655, "IPA_NAT_MEM_IN_DDR");
      v30 = ipa3_ctx;
    }
    v32 = *(_QWORD *)(v30 + 34160);
    if ( v32 )
      ipc_log_string(v32, "ipa %s:%d Will install v6 NAT in: %s\n", "ipa3_ipv6ct_init_cmd", 1655, "IPA_NAT_MEM_IN_DDR");
  }
  ipa3_nat_ipv6ct_create_init_cmd(
    v42,
    0,
    *(_QWORD *)(v2 + 30336),
    *((unsigned __int8 *)a1 + 12),
    *a1,
    a1[1],
    *((unsigned __int16 *)a1 + 4),
    *((unsigned __int16 *)a1 + 5),
    v2 + 30080);
  v33 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v34 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v34 )
    {
      ipc_log_string(v34, "ipa %s:%d posting ip_v6_ct_init imm command\n", "ipa3_ipv6ct_init_cmd", 1668);
      v33 = ipa3_ctx;
    }
    v35 = *(_QWORD *)(v33 + 34160);
    if ( v35 )
      ipc_log_string(v35, "ipa %s:%d posting ip_v6_ct_init imm command\n", "ipa3_ipv6ct_init_cmd", 1668);
  }
  inited = ipa3_ipv6ct_send_init_cmd(v42);
  if ( inited )
  {
    v16 = inited;
    printk(&unk_3C42F6, "ipa3_ipv6ct_init_cmd");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d fail to send IPv6CT init immediate command\n", "ipa3_ipv6ct_init_cmd", 1673);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
      {
        ipc_log_string(v41, "ipa %s:%d fail to send IPv6CT init immediate command\n", "ipa3_ipv6ct_init_cmd", 1673);
        goto LABEL_53;
      }
    }
    goto LABEL_86;
  }
  ipa3_nat_ipv6ct_init_device_structure(v2 + 30080, 0, *a1, a1[1], *((_WORD *)a1 + 4), *((_WORD *)a1 + 5), 0, 0, 0);
  *v3 = 1;
  v37 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_72:
    result = 0;
    goto LABEL_22;
  }
  v38 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v38 )
  {
    ipc_log_string(v38, "ipa %s:%d Out\n", "ipa3_ipv6ct_init_cmd", 1688);
    v37 = ipa3_ctx;
  }
  result = *(_QWORD *)(v37 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Out\n", "ipa3_ipv6ct_init_cmd", 1688);
    goto LABEL_72;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
