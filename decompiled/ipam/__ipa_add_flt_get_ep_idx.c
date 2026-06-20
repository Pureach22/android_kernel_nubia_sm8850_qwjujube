__int64 __fastcall _ipa_add_flt_get_ep_idx(__int64 a1, unsigned int *a2)
{
  unsigned int v3; // w19
  unsigned int ep_mapping; // w0
  unsigned int v5; // w21
  __int64 max_num_pipes; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0

  v3 = a1;
  ep_mapping = ipa_get_ep_mapping(a1);
  *a2 = ep_mapping;
  if ( (ep_mapping & 0x80000000) != 0
    || (v5 = ep_mapping, max_num_pipes = ipa3_get_max_num_pipes(), v5 >= (unsigned int)max_num_pipes) )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_flt_get_ep_idx__rs, "__ipa_add_flt_get_ep_idx") )
      printk(&unk_3E9819, "__ipa_add_flt_get_ep_idx");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d ep not valid ep=%d\n", "__ipa_add_flt_get_ep_idx", 1203, v3);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d ep not valid ep=%d\n", "__ipa_add_flt_get_ep_idx", 1203, v3);
    }
    return 4294967274LL;
  }
  if ( *a2 < 0x24 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 480LL * *a2 + 168) )
      goto LABEL_5;
    if ( (unsigned int)__ratelimit(&_ipa_add_flt_get_ep_idx__rs_169, "__ipa_add_flt_get_ep_idx") )
    {
      printk(&unk_3CFC16, "__ipa_add_flt_get_ep_idx");
      v18 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_5;
    }
    else
    {
      v18 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_5;
    }
    v19 = *(_QWORD *)(v18 + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d ep not connected ep_idx=%d\n", "__ipa_add_flt_get_ep_idx", 1207, *a2);
      v18 = ipa3_ctx;
    }
    v20 = *(_QWORD *)(v18 + 34160);
    if ( v20 )
      ipc_log_string(v20, "ipa %s:%d ep not connected ep_idx=%d\n", "__ipa_add_flt_get_ep_idx", 1207, *a2);
LABEL_5:
    if ( (ipa_is_ep_support_flt(*a2) & 1) != 0 )
      return 0;
    if ( (unsigned int)__ratelimit(&_ipa_add_flt_get_ep_idx__rs_172, "__ipa_add_flt_get_ep_idx") )
    {
      printk(&unk_3AF962, "__ipa_add_flt_get_ep_idx");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_17;
    }
    else
    {
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_17:
        v16 = *(_QWORD *)(v15 + 34152);
        if ( v16 )
        {
          ipc_log_string(v16, "ipa %s:%d ep do not support filtering ep=%d\n", "__ipa_add_flt_get_ep_idx", 1210, v3);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(v17, "ipa %s:%d ep do not support filtering ep=%d\n", "__ipa_add_flt_get_ep_idx", 1210, v3);
      }
    }
    return 4294967274LL;
  }
  __break(0x5512u);
  return _ipa_add_flt_rule_after(max_num_pipes, v7, v8, v9, v10);
}
