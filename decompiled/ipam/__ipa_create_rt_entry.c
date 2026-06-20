__int64 __fastcall _ipa_create_rt_entry(
        __int64 *a1,
        _BYTE *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int16 a6,
        char a7)
{
  __int64 v14; // x0
  __int64 v15; // x26
  int v16; // w0
  int v17; // w8
  __int64 v18; // x0
  int v19; // w21
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0

  v14 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29384), 3520);
  v15 = v14;
  *a1 = v14;
  if ( !v14 )
    return 0xFFFFFFFFLL;
  *(_QWORD *)v14 = v14;
  *(_QWORD *)(v14 + 8) = v14;
  *(_DWORD *)(v14 + 16) = 1468208644;
  memcpy((void *)(v14 + 20), a2, 0xB0u);
  *(_QWORD *)(v15 + 200) = a3;
  *(_QWORD *)(v15 + 208) = a4;
  *(_QWORD *)(v15 + 216) = a5;
  if ( a6 )
  {
    *(_WORD *)(v15 + 236) = 1;
    goto LABEL_6;
  }
  v16 = ipa3_alloc_rule_id(*(_QWORD *)(a3 + 216));
  if ( v16 < 0 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_create_rt_entry__rs, "__ipa_create_rt_entry") )
      printk(&unk_3BB24F, "__ipa_create_rt_entry");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d failed to allocate rule id\n", "__ipa_create_rt_entry", 1071);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d failed to allocate rule id\n", "__ipa_create_rt_entry", 1071);
        v21 = ipa3_ctx;
      }
    }
    kmem_cache_free(*(_QWORD *)(v21 + 29384), *a1);
    return 0xFFFFFFFFLL;
  }
  v15 = *a1;
  a6 = v16;
LABEL_6:
  *(_WORD *)(v15 + 234) = a6;
  *(_BYTE *)(*a1 + 239) = a7 & 1;
  if ( *(_BYTE *)(*a1 + 187) )
  {
    v17 = *(_DWORD *)(*a1 + 20);
    if ( v17 == 35 )
    {
      v18 = 95;
      v19 = 95;
LABEL_11:
      if ( (unsigned int)ipa_get_ep_mapping(v18) != -1 )
        *(_DWORD *)(*a1 + 20) = v19;
      goto LABEL_13;
    }
    if ( v17 == 33 )
    {
      v18 = 127;
      v19 = 127;
      goto LABEL_11;
    }
  }
LABEL_13:
  result = 0;
  if ( a2[168] )
    *(_BYTE *)(*a1 + 238) = a2[169];
  else
    *(_BYTE *)(*a1 + 238) = 0;
  return result;
}
