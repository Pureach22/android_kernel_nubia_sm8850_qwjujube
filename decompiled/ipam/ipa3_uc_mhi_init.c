__int64 __fastcall ipa3_uc_mhi_init(void *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  void *v14[6]; // [xsp+0h] [xbp-30h] BYREF

  v14[5] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_uc_mhi_ctx )
  {
    printk(&unk_3C79C3, "ipa3_uc_mhi_init");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Already initialized\n", "ipa3_uc_mhi_init", 575);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d Already initialized\n", "ipa3_uc_mhi_init", 575);
    }
    result = 4294967282LL;
  }
  else
  {
    v4 = _kmalloc_cache_noprof(ipc_log_string, 3520, 40);
    ipa3_uc_mhi_ctx = v4;
    if ( v4 )
    {
      *(_QWORD *)(v4 + 8) = a1;
      *(_QWORD *)(v4 + 16) = a2;
      v14[0] = a1;
      v14[1] = ipa3_uc_mhi_event_hdlr;
      v14[2] = ipa3_uc_mhi_response_hdlr;
      v14[3] = ipa3_uc_mhi_event_log_info_hdlr;
      v14[4] = nullptr;
      ipa3_uc_register_handlers(1u, v14);
      v5 = ipa3_ctx;
      if ( !ipa3_ctx )
      {
LABEL_8:
        result = 0;
        goto LABEL_9;
      }
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Done\n", "ipa3_uc_mhi_init", 595);
        v5 = ipa3_ctx;
      }
      result = *(_QWORD *)(v5 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d Done\n", "ipa3_uc_mhi_init", 595);
        goto LABEL_8;
      }
    }
    else
    {
      printk(&unk_3CF6DE, "ipa3_uc_mhi_init");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d no mem\n", "ipa3_uc_mhi_init", 581);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(v13, "ipa %s:%d no mem\n", "ipa3_uc_mhi_init", 581);
      }
      result = 4294967284LL;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
