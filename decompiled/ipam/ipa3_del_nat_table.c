__int64 __fastcall ipa3_del_nat_table(unsigned __int8 *a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w24
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  const char *v15; // x8
  const char *v16; // x4
  __int64 v17; // x0
  const char *v18; // x8
  const char *v19; // x4
  __int64 v20; // x8
  unsigned int v21; // w19
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int inited; // w19
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  _QWORD v47[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v48; // [xsp+18h] [xbp-28h]
  __int64 v49; // [xsp+20h] [xbp-20h]
  __int64 v50; // [xsp+28h] [xbp-18h]
  __int64 v51; // [xsp+30h] [xbp-10h]
  __int64 v52; // [xsp+38h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v3 = ipa3_ctx + 29750;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    v5 = ipa3_ctx;
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_del_nat_table", 2358);
      v5 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v5 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d In\n", "ipa3_del_nat_table", 2358);
  }
  if ( sram_compatible == 1 )
  {
    v7 = a1[1];
    if ( (*(_BYTE *)v3 & 1) == 0 )
      goto LABEL_8;
LABEL_14:
    if ( *a1 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_del_nat_table__rs, "ipa3_del_nat_table") )
      {
        printk(&unk_3F2550, "ipa3_del_nat_table");
        v8 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
      }
      else
      {
        v8 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
      }
      v11 = *(_QWORD *)(v8 + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Unsupported table index %d\n", "ipa3_del_nat_table", 2373, *a1);
        v8 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v8 + 34160);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d Unsupported table index %d\n", "ipa3_del_nat_table", 2373, *a1);
        goto LABEL_75;
      }
LABEL_78:
      inited = -1;
      if ( !v8 )
        goto LABEL_87;
      goto LABEL_79;
    }
    if ( v7 >= 2 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_del_nat_table__rs_112, "ipa3_del_nat_table") )
      {
        printk(&unk_3A3A99, "ipa3_del_nat_table");
        v8 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
      }
      else
      {
        v8 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_86;
      }
      v35 = *(_QWORD *)(v8 + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d Bad ipa3_nat_mem_in type\n", "ipa3_del_nat_table", 2379);
        v8 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v8 + 34160);
      if ( v36 )
      {
        ipc_log_string(v36, "ipa %s:%d Bad ipa3_nat_mem_in type\n", "ipa3_del_nat_table", 2379);
        goto LABEL_75;
      }
      goto LABEL_78;
    }
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        if ( v7 == 1 )
          v15 = "IPA_NAT_MEM_IN_SRAM";
        else
          v15 = "INVALID_MEM_TYPE";
        if ( v7 )
          v16 = v15;
        else
          v16 = "IPA_NAT_MEM_IN_DDR";
        ipc_log_string(v14, "ipa %s:%d nmi(%s)\n", "ipa3_del_nat_table", 2384, v16);
        v13 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v13 + 34160);
      if ( v17 )
      {
        if ( v7 == 1 )
          v18 = "IPA_NAT_MEM_IN_SRAM";
        else
          v18 = "INVALID_MEM_TYPE";
        if ( v7 )
          v19 = v18;
        else
          v19 = "IPA_NAT_MEM_IN_DDR";
        ipc_log_string(v17, "ipa %s:%d nmi(%s)\n", "ipa3_del_nat_table", 2384, v19);
      }
    }
    mutex_lock(v2 + 29544);
    if ( *(_BYTE *)(v3 + 1) != 1 )
      goto LABEL_59;
    v20 = ipa3_ctx;
    v21 = *a1;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v47[0] = 0;
    v47[1] = 0;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d In\n", "ipa3_nat_send_del_table_cmd", 2254);
        v20 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v20 + 34160);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d In\n", "ipa3_nat_send_del_table_cmd", 2254);
        v20 = ipa3_ctx;
      }
    }
    if ( (unsigned int)ipa3_nat_ipv6ct_create_del_table_cmd(
                         v21,
                         *(unsigned int *)(**(_QWORD **)(v20 + 34176) + 180LL),
                         v20 + 29528,
                         v47) )
    {
      printk(&unk_3B533D, "ipa3_nat_send_del_table_cmd");
      v28 = ipa3_ctx;
      if ( !ipa3_ctx )
      {
        inited = -1;
        goto LABEL_100;
      }
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(
          v40,
          "ipa %s:%d Fail to create immediate command to delete NAT table\n",
          "ipa3_nat_send_del_table_cmd",
          2265);
        v28 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v28 + 34160);
      if ( !v41 )
      {
        inited = -1;
LABEL_53:
        if ( v28 )
        {
          v29 = *(_QWORD *)(v28 + 34152);
          if ( v29 )
          {
            ipc_log_string(v29, "ipa %s:%d Out\n", "ipa3_nat_send_del_table_cmd", 2289);
            v28 = ipa3_ctx;
          }
          v30 = *(_QWORD *)(v28 + 34160);
          if ( v30 )
            ipc_log_string(v30, "ipa %s:%d Out\n", "ipa3_nat_send_del_table_cmd", 2289);
        }
        if ( !inited )
        {
LABEL_59:
          v31 = v2 + 29888 + 96LL * v7;
          *(_DWORD *)(v3 + 82) = 0;
          *(_QWORD *)(v31 + 80) = 0;
          *(_QWORD *)(v31 + 88) = 0;
          v32 = ipa3_ctx;
          if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu && *(_QWORD *)(v2 + 29840) )
          {
            if ( ipa3_ctx )
            {
              v33 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v33 )
              {
                ipc_log_string(v33, "ipa %s:%d Freeing the PDN memory\n", "ipa3_del_nat_table", 2412);
                v32 = ipa3_ctx;
              }
              v34 = *(_QWORD *)(v32 + 34160);
              if ( v34 )
              {
                ipc_log_string(v34, "ipa %s:%d Freeing the PDN memory\n", "ipa3_del_nat_table", 2412);
                v32 = ipa3_ctx;
              }
            }
            dma_free_attrs(
              *(_QWORD *)(v32 + 34216),
              *(unsigned int *)(v3 + 106),
              *(_QWORD *)(v2 + 29840),
              *(_QWORD *)(v2 + 29848),
              0);
            *(_QWORD *)(v2 + 29840) = 0;
          }
          ipa3_nat_ipv6ct_free_mem(v2 + 29528);
          inited = 0;
LABEL_68:
          mutex_unlock(v2 + 29544);
          goto LABEL_76;
        }
LABEL_100:
        printk(&unk_3F854F, "ipa3_del_nat_table");
        v44 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v45 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v45 )
          {
            ipc_log_string(
              v45,
              "ipa %s:%d Fail to send immediate command to delete NAT table\n",
              "ipa3_del_nat_table",
              2396);
            v44 = ipa3_ctx;
          }
          v46 = *(_QWORD *)(v44 + 34160);
          if ( v46 )
            ipc_log_string(
              v46,
              "ipa %s:%d Fail to send immediate command to delete NAT table\n",
              "ipa3_del_nat_table",
              2396);
        }
        goto LABEL_68;
      }
      ipc_log_string(
        v41,
        "ipa %s:%d Fail to create immediate command to delete NAT table\n",
        "ipa3_nat_send_del_table_cmd",
        2265);
      inited = -1;
    }
    else
    {
      v24 = ipa3_ctx;
      HIDWORD(v51) = 0;
      LOBYTE(v51) = v48;
      v49 = v47[0];
      v50 = v47[0];
      BYTE1(v51) = v48;
      if ( ipa3_ctx )
      {
        v25 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v25 )
        {
          ipc_log_string(v25, "ipa %s:%d Posting NAT delete command\n", "ipa3_nat_send_del_table_cmd", 2279);
          v24 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v24 + 34160);
        if ( v26 )
          ipc_log_string(v26, "ipa %s:%d Posting NAT delete command\n", "ipa3_nat_send_del_table_cmd", 2279);
      }
      inited = ipa3_nat_send_init_cmd((__int64)v47, 1);
      if ( inited )
      {
        printk(&unk_3C43EF, "ipa3_nat_send_del_table_cmd");
        v28 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_100;
        v42 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v42 )
        {
          ipc_log_string(
            v42,
            "ipa %s:%d Fail to send NAT delete immediate command\n",
            "ipa3_nat_send_del_table_cmd",
            2284);
          v28 = ipa3_ctx;
        }
        v43 = *(_QWORD *)(v28 + 34160);
        if ( !v43 )
          goto LABEL_53;
        ipc_log_string(
          v43,
          "ipa %s:%d Fail to send NAT delete immediate command\n",
          "ipa3_nat_send_del_table_cmd",
          2284);
      }
    }
    v28 = ipa3_ctx;
    goto LABEL_53;
  }
  v7 = 0;
  a1[1] = 0;
  if ( (*(_BYTE *)v3 & 1) != 0 )
    goto LABEL_14;
LABEL_8:
  printk(&unk_3B8435, "ipa3_del_nat_table");
  v8 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_86:
    inited = -1;
    goto LABEL_87;
  }
  v9 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v9 )
  {
    ipc_log_string(v9, "ipa %s:%d NAT hasn't been initialized\n", "ipa3_del_nat_table", 2366);
    v8 = ipa3_ctx;
  }
  v10 = *(_QWORD *)(v8 + 34160);
  if ( !v10 )
    goto LABEL_78;
  ipc_log_string(v10, "ipa %s:%d NAT hasn't been initialized\n", "ipa3_del_nat_table", 2366);
LABEL_75:
  inited = -1;
LABEL_76:
  v8 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_87;
LABEL_79:
  v37 = *(_QWORD *)(v8 + 34152);
  if ( v37 )
  {
    ipc_log_string(v37, "ipa %s:%d Out\n", "ipa3_del_nat_table", 2429);
    v8 = ipa3_ctx;
  }
  v38 = *(_QWORD *)(v8 + 34160);
  if ( v38 )
    ipc_log_string(v38, "ipa %s:%d Out\n", "ipa3_del_nat_table", 2429);
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return inited;
}
