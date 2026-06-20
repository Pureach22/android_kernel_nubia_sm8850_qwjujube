__int64 __fastcall ipa3_send_gsb_msg(unsigned __int64 a1, unsigned __int8 a2)
{
  int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 result; // x0
  unsigned int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v3 = a2;
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d type %d\n", "ipa3_send_gsb_msg", 1522, a2);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d type %d\n", "ipa3_send_gsb_msg", 1522, v3);
  }
  v23 = 0x200000;
  LOBYTE(v23) = v3;
  if ( (unsigned int)(v3 - 35) > 1 )
  {
    printk(&unk_3E8C5C, "ipa3_send_gsb_msg");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d Unexpected event\n", "ipa3_send_gsb_msg", 1545);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d Unexpected event\n", "ipa3_send_gsb_msg", 1545);
    }
    result = 4294967282LL;
  }
  else
  {
    v7 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
    v8 = v7;
    if ( v7 )
    {
      if ( inline_copy_from_user(v7, a1, 0x20u) )
      {
        kfree(v8);
        result = 4294967282LL;
        goto LABEL_17;
      }
      v10 = ipa_send_msg(&v23, v8, ipa3_gsb_msg_free_cb);
      if ( v10 )
      {
        v16 = v10;
        printk(&unk_3A29B0, "ipa3_send_gsb_msg");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(v18, "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n", "ipa3_send_gsb_msg", 1554, v16, v3);
            v17 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v17 + 34160);
          if ( v19 )
            ipc_log_string(v19, "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n", "ipa3_send_gsb_msg", 1554, v16, v3);
        }
        kfree(v8);
        result = v16;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
        {
LABEL_16:
          result = 0;
          goto LABEL_17;
        }
        v12 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d exit\n", "ipa3_send_gsb_msg", 1558);
          v11 = ipa3_ctx;
        }
        result = *(_QWORD *)(v11 + 34160);
        if ( result )
        {
          ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_send_gsb_msg", 1558);
          goto LABEL_16;
        }
      }
    }
    else
    {
      printk(&unk_3C9158, "ipa3_send_gsb_msg");
      v20 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v21 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v21 )
        {
          ipc_log_string(v21, "ipa %s:%d no memory\n", "ipa3_send_gsb_msg", 1532);
          v20 = ipa3_ctx;
        }
        v22 = *(_QWORD *)(v20 + 34160);
        if ( v22 )
          ipc_log_string(v22, "ipa %s:%d no memory\n", "ipa3_send_gsb_msg", 1532);
      }
      result = 4294967284LL;
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
