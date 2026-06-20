__int64 __fastcall ipa_dmesg_logs_register_each_page(const char *a1)
{
  unsigned int v2; // w22
  __int64 v3; // x20
  __int64 v4; // x2
  bool v5; // cf
  unsigned int v6; // w8
  bool v7; // cc
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w21
  __int64 v12; // x23
  int v13; // w28
  unsigned __int64 v14; // x2
  _QWORD *v15; // x25
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x9
  size_t v19; // x0
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  _QWORD v34[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v36[5]; // [xsp+18h] [xbp-28h] BYREF

  v36[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  memset(v36, 0, 32);
  v34[0] = 0;
  v34[1] = 0;
  kmsg_dump_rewind(v34);
  v2 = 0x20000;
  v3 = 7;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v4 = dmesg_buf[v3];
    if ( !v4 )
    {
      v4 = _kmalloc_large_noprof(0x4000, 3264);
      dmesg_buf[v3] = v4;
      if ( !v4 )
      {
        printk(&unk_3DE206, "ipa_dmesg_logs_register_each_page");
        v8 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v9 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v9 )
          {
            ipc_log_string(
              v9,
              "ipa %s:%d Unable to allocate memory index:%d\n",
              "ipa_dmesg_logs_register_each_page",
              217,
              v3);
            v8 = ipa3_ctx;
          }
          v10 = *(_QWORD *)(v8 + 34160);
          if ( v10 )
            ipc_log_string(
              v10,
              "ipa %s:%d Unable to allocate memory index:%d\n",
              "ipa_dmesg_logs_register_each_page",
              217,
              v3);
        }
LABEL_41:
        mutex_unlock(&region_list_mutex);
        v11 = v3;
        goto LABEL_42;
      }
    }
    if ( (kmsg_dump_get_buffer(v34, 0, v4, 0x4000, &v35) & 1) == 0 )
      break;
    if ( !v35 )
    {
      printk(&unk_3C0A12, "ipa_dmesg_logs_register_each_page");
      v31 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v32 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d dmesg logs have stopped at this point. entry_num:%d\n",
            "ipa_dmesg_logs_register_each_page",
            210,
            v3);
          v31 = ipa3_ctx;
        }
        v33 = *(_QWORD *)(v31 + 34160);
        if ( v33 )
          ipc_log_string(
            v33,
            "ipa %s:%d dmesg logs have stopped at this point. entry_num:%d\n",
            "ipa_dmesg_logs_register_each_page",
            210,
            v3);
      }
      v11 = 0;
      goto LABEL_55;
    }
    *((_DWORD *)v36 + v3) = v35;
    v5 = v3-- != 0;
    v6 = 0;
    if ( !v5 )
    {
      v11 = 0;
LABEL_15:
      v12 = v6;
      LODWORD(v3) = 1;
      while ( 1 )
      {
        mutex_lock(&region_list_mutex);
        v15 = &dump_entry_list;
        v16 = 150;
        while ( v15[13] )
        {
          --v16;
          v15 += 16;
          if ( !v16 )
          {
            printk(&unk_3B4AF5, "ipa_dmesg_logs_register_each_page");
            v24 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v25 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v25 )
              {
                ipc_log_string(
                  v25,
                  "ipa %s:%d too many entries: %zu, cannot insert %s",
                  "ipa_dmesg_logs_register_each_page",
                  232,
                  num_of_regions_registered,
                  a1);
                v24 = ipa3_ctx;
              }
              v26 = *(_QWORD *)(v24 + 34160);
              if ( v26 )
                ipc_log_string(
                  v26,
                  "ipa %s:%d too many entries: %zu, cannot insert %s",
                  "ipa_dmesg_logs_register_each_page",
                  232,
                  num_of_regions_registered,
                  a1);
            }
            goto LABEL_41;
          }
        }
        if ( (v12 & 0x1FFFFFFFFFFFFFF8LL) != 0 )
          break;
        v17 = dmesg_buf[v12];
        if ( !v17 )
          goto LABEL_16;
        if ( (unsigned __int64)(4 * v12) > 0x20 )
          break;
        v18 = *((unsigned int *)v36 + v12);
        if ( (int)v18 > 0 )
        {
          v15[13] = v17;
          v15[14] = v18;
          v19 = strnlen(a1, 0x64u);
          if ( v19 == -1 )
            goto LABEL_59;
          if ( v19 == 100 )
            v14 = 100;
          else
            v14 = v19 + 1;
          if ( v14 >= 0x65 )
            goto LABEL_58;
          sized_strscpy(v15, a1);
          v20 = num_of_regions_registered;
          v13 = v3 + 1;
          v21 = ipa3_ctx;
          *((_BYTE *)v15 + 120) = v3;
          num_of_regions_registered = v20 + 1;
          if ( v21 )
          {
            v22 = *(_QWORD *)(v21 + 34152);
            if ( v22 )
            {
              ipc_log_string(
                v22,
                "ipa %s:%d Registered %s %zu %d\n",
                "ipa_dmesg_logs_register_each_page",
                250,
                a1,
                v15[14],
                (unsigned __int8)v3);
              v21 = ipa3_ctx;
            }
            v23 = *(_QWORD *)(v21 + 34160);
            if ( v23 )
              ipc_log_string(
                v23,
                "ipa %s:%d Registered %s %zu %d\n",
                "ipa_dmesg_logs_register_each_page",
                250,
                a1,
                v15[14],
                *((unsigned __int8 *)v15 + 120));
          }
        }
        else
        {
LABEL_16:
          v13 = v3;
        }
        mutex_unlock(&region_list_mutex);
        ++v12;
        LODWORD(v3) = v13;
        if ( v12 == 7 )
          goto LABEL_42;
      }
      __break(1u);
LABEL_58:
      v19 = _fortify_panic(7, 100, v14);
LABEL_59:
      _fortify_panic(2, -1, v19 + 1);
    }
    v7 = v2 > 0x4000;
    v2 -= 0x4000;
    v11 = 0;
    if ( !v7 )
      goto LABEL_15;
  }
  printk(&unk_3C0A12, "ipa_dmesg_logs_register_each_page");
  v28 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(
        v29,
        "ipa %s:%d dmesg logs have stopped at this point. entry_num:%d\n",
        "ipa_dmesg_logs_register_each_page",
        204,
        v3);
      v28 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v28 + 34160);
    if ( v30 )
      ipc_log_string(
        v30,
        "ipa %s:%d dmesg logs have stopped at this point. entry_num:%d\n",
        "ipa_dmesg_logs_register_each_page",
        204,
        v3);
  }
  v11 = v3;
LABEL_55:
  v6 = v3 + 1;
  if ( (unsigned int)(v3 + 1) <= 6 )
    goto LABEL_15;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v11;
}
