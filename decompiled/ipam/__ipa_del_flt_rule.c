__int64 __fastcall _ipa_del_flt_rule(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x19
  _QWORD *v3; // x8
  unsigned int v4; // w20
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  unsigned int v10; // w22
  unsigned int v11; // w22
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0

  v1 = ipa3_id_find(a1);
  if ( !v1 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_del_flt_rule__rs, "__ipa_del_flt_rule") )
      printk(&unk_3DE445, "__ipa_del_flt_rule");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d lookup failed\n", "__ipa_del_flt_rule", 1129);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d lookup failed\n", "__ipa_del_flt_rule", 1129);
    }
    return 4294967274LL;
  }
  v2 = v1;
  if ( *(_DWORD *)(v1 + 16) != 1468208646 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_del_flt_rule__rs_211, "__ipa_del_flt_rule") )
      printk(&unk_3EC4EF, "__ipa_del_flt_rule");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d bad params\n", "__ipa_del_flt_rule", 1134);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d bad params\n", "__ipa_del_flt_rule", 1134);
    }
    return 4294967274LL;
  }
  v3 = *(_QWORD **)(v1 + 8);
  v4 = *(_DWORD *)(v1 + 412);
  if ( *v3 == v1 && (v5 = *(_QWORD *)v1, *(_QWORD *)(*(_QWORD *)v1 + 8LL) == v1) )
  {
    *(_QWORD *)(v5 + 8) = v3;
    *v3 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(v1);
  }
  v6 = *(_QWORD *)(v2 + 392);
  *(_QWORD *)v2 = 0xDEAD000000000100LL;
  *(_QWORD *)(v2 + 8) = 0xDEAD000000000122LL;
  --*(_DWORD *)(v6 + 16);
  v7 = *(_QWORD *)(v2 + 400);
  if ( v7 )
  {
    v7 = ipa3_check_idr_if_freed();
    if ( (v7 & 1) == 0 )
      --*(_DWORD *)(*(_QWORD *)(v2 + 400) + 80LL);
  }
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d del flt rule rule_cnt=%d rule_id=%d\n",
        "__ipa_del_flt_rule",
        1144,
        *(_DWORD *)(*(_QWORD *)(v2 + 392) + 16LL),
        *(unsigned __int16 *)(v2 + 418));
      v8 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v8 + 34160);
    if ( v7 )
      v7 = ipc_log_string(
             v7,
             "ipa %s:%d del flt rule rule_cnt=%d rule_id=%d\n",
             "__ipa_del_flt_rule",
             1144,
             *(_DWORD *)(*(_QWORD *)(v2 + 392) + 16LL),
             *(unsigned __int16 *)(v2 + 418));
  }
  v10 = *(unsigned __int16 *)(v2 + 418);
  *(_DWORD *)(v2 + 16) = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64))ipahal_get_rule_id_hi_bit)(v7) > v10 )
  {
    v11 = *(unsigned __int16 *)(v2 + 418);
    if ( (unsigned int)((__int64 (*)(void))ipahal_get_low_rule_id)() <= v11 )
      idr_remove(*(_QWORD *)(*(_QWORD *)(v2 + 392) + 136LL), *(unsigned __int16 *)(v2 + 418));
  }
  kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29376), v2);
  ipa3_id_remove(v4);
  return 0;
}
