__int64 __fastcall _ipa_add_ep_flt_rule(
        unsigned int a1,
        unsigned int a2,
        const void *a3,
        unsigned int a4,
        const void *a5,
        char a6)
{
  unsigned int v12; // w22
  __int64 v13; // x22
  __int64 v14; // x3
  char v15; // w8
  __int64 v16; // x0
  __int64 result; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 0x85 || !a3 || !a5 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_ep_flt_rule__rs, "__ipa_add_ep_flt_rule") )
      printk(&unk_3B4F94, "__ipa_add_ep_flt_rule");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d bad parms rule=%pK rule_hdl=%pK ep=%d\n",
          "__ipa_add_ep_flt_rule",
          1226,
          a3,
          a5,
          a2);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(
          v20,
          "ipa %s:%d bad parms rule=%pK rule_hdl=%pK ep=%d\n",
          "__ipa_add_ep_flt_rule",
          1226,
          a3,
          a5,
          a2);
    }
    goto LABEL_19;
  }
  v24 = 0;
  if ( (unsigned int)_ipa_add_flt_get_ep_idx(a2, &v24) )
  {
LABEL_19:
    result = 4294967274LL;
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = v24;
  if ( v12 >= (unsigned int)ipa3_get_max_num_pipes() )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_ep_flt_rule__rs_162, "__ipa_add_ep_flt_rule") )
      printk(&unk_3C3F7B, "__ipa_add_ep_flt_rule");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d invalid ipa_ep_idx=%d\n", "__ipa_add_ep_flt_rule", 1234, v12);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d invalid ipa_ep_idx=%d\n", "__ipa_add_ep_flt_rule", 1234, v12);
    }
    goto LABEL_19;
  }
  if ( a1 <= 2 && v12 < 0x24 )
  {
    v13 = ipa3_ctx + 304LL * v12 + 152LL * a1;
    v14 = a4;
    v15 = a6;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d add ep flt rule ip=%d ep=%d\n", "__ipa_add_ep_flt_rule", 1239, a1, a2);
        v15 = a6;
        v14 = a4;
      }
    }
    result = _ipa_add_flt_rule(v13 + 17640, a1, a3, v14, a5, v15 & 1);
    goto LABEL_20;
  }
  __break(0x5512u);
  return ipa3_add_flt_rule_after();
}
