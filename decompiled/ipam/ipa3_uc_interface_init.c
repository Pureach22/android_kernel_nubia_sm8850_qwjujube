__int64 ipa3_uc_interface_init()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x10
  int v5; // w21
  int v6; // w22
  int v7; // w10
  __int64 v8; // x2
  __int64 v9; // x0
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0

  v0 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 34656) != 1 )
  {
    _mutex_init(ipa3_ctx + 34664, "&ipa3_ctx->uc_ctx.uc_lock", &ipa3_uc_interface_init___key);
    _mutex_init(ipa3_ctx + 43096, "&ipa3_ctx->uc_ctx.holb_monitor.uc_holb_lock", &ipa3_uc_interface_init___key_21);
    v3 = ipa3_ctx;
    v4 = *(_QWORD *)(ipa3_ctx + 34176);
    *(_DWORD *)(ipa3_ctx + 34712) = 0;
    v5 = *(_DWORD *)(v3 + 28640);
    v6 = *(_DWORD *)(v4 + 36);
    v7 = v6 + v5 + ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(64, 0, 0);
    if ( arm64_use_ng_mappings )
      v8 = 0x68000000000F13LL;
    else
      v8 = 0x68000000000713LL;
    v9 = ioremap_prot(
           (unsigned int)(v7 + *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 328LL)),
           *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 332LL),
           v8);
    v10 = ipa3_ctx;
    *(_QWORD *)(ipa3_ctx + 34752) = v9;
    if ( !v9 )
    {
      printk(&unk_3BE734, "ipa3_uc_interface_init");
      v12 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967284LL;
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d Fail to ioremap IPA uC SRAM\n", "ipa3_uc_interface_init", 1127);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( !v14 )
        return 4294967284LL;
      ipc_log_string(v14, "ipa %s:%d Fail to ioremap IPA uC SRAM\n", "ipa3_uc_interface_init", 1127);
      return 4294967284LL;
    }
    if ( (*(_BYTE *)(v10 + 43308) & 1) != 0 )
      goto LABEL_18;
    if ( (unsigned int)ipa_add_interrupt_handler(1u, (__int64)ipa3_uc_event_handler, 1, v10) )
    {
      printk(&unk_3C78BD, "ipa3_uc_interface_init");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d Fail to register for UC_IRQ0 event interrupt\n",
            "ipa3_uc_interface_init",
            1137);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(
            v17,
            "ipa %s:%d Fail to register for UC_IRQ0 event interrupt\n",
            "ipa3_uc_interface_init",
            1137);
      }
    }
    else
    {
      if ( (unsigned int)ipa_add_interrupt_handler(2u, (__int64)ipa3_uc_response_hdlr, 1, ipa3_ctx) )
      {
        printk(&unk_3DBDDA, "ipa3_uc_interface_init");
        v18 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v19 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v19 )
          {
            ipc_log_string(
              v19,
              "ipa %s:%d fail to register for UC_IRQ1 rsp interrupt\n",
              "ipa3_uc_interface_init",
              1146);
            v18 = ipa3_ctx;
          }
          v20 = *(_QWORD *)(v18 + 34160);
          if ( v20 )
            ipc_log_string(
              v20,
              "ipa %s:%d fail to register for UC_IRQ1 rsp interrupt\n",
              "ipa3_uc_interface_init",
              1146);
        }
      }
      else
      {
        if ( (unsigned int)ipa_add_interrupt_handler(3u, (__int64)ipa3_uc_wigig_misc_int_handler, 1, ipa3_ctx) )
        {
          printk(&unk_3D3644, "ipa3_uc_interface_init");
          v21 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v22 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v22 )
            {
              ipc_log_string(
                v22,
                "ipa %s:%d fail to register for UC_IRQ2 wigig misc interrupt\n",
                "ipa3_uc_interface_init",
                1155);
              v21 = ipa3_ctx;
            }
            v23 = *(_QWORD *)(v21 + 34160);
            if ( v23 )
              ipc_log_string(
                v23,
                "ipa %s:%d fail to register for UC_IRQ2 wigig misc interrupt\n",
                "ipa3_uc_interface_init",
                1155);
          }
        }
        else
        {
          v10 = ipa3_ctx;
          if ( *(_BYTE *)(ipa3_ctx + 34904) != 1 )
          {
LABEL_18:
            *(_BYTE *)(v10 + 34656) = 1;
            if ( !v10 )
              return 0;
            v11 = *(_QWORD *)(v10 + 34152);
            if ( v11 )
            {
              ipc_log_string(v11, "ipa %s:%d IPA uC interface is initialized\n", "ipa3_uc_interface_init", 1174);
              v10 = ipa3_ctx;
            }
            result = *(_QWORD *)(v10 + 34160);
            if ( result )
            {
              ipc_log_string(result, "ipa %s:%d IPA uC interface is initialized\n", "ipa3_uc_interface_init", 1174);
              return 0;
            }
            return result;
          }
          ipa_uc_holb_wq = alloc_workqueue("ipa_uc_holb_wq", 74, 1);
          if ( ipa_uc_holb_wq )
          {
            v10 = ipa3_ctx;
            goto LABEL_18;
          }
          printk(&unk_3B57B0, "ipa3_uc_interface_init");
          v24 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v25 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v25 )
            {
              ipc_log_string(v25, "ipa %s:%d Failed to create ipa_uc_holb_wq\n", "ipa3_uc_interface_init", 1165);
              v24 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v24 + 34160);
            if ( v26 )
              ipc_log_string(v26, "ipa %s:%d Failed to create ipa_uc_holb_wq\n", "ipa3_uc_interface_init", 1165);
          }
          ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(3);
        }
        ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(2);
      }
      ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(1);
    }
    iounmap(*(_QWORD *)(ipa3_ctx + 34752));
    return 4294967282LL;
  }
  if ( !ipa3_ctx )
    return 0;
  v1 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v1 )
  {
    ipc_log_string(v1, "ipa %s:%d uC interface already initialized\n", "ipa3_uc_interface_init", 1112);
    v0 = ipa3_ctx;
  }
  result = *(_QWORD *)(v0 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d uC interface already initialized\n", "ipa3_uc_interface_init", 1112);
    return 0;
  }
  return result;
}
