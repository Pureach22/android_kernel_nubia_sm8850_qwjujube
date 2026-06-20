__int64 __fastcall _ipa_create_flt_entry(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  _QWORD *v10; // x0
  _QWORD *v11; // x24
  int v12; // w0
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0

  v10 = (_QWORD *)kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29376), 3520);
  v11 = v10;
  *a1 = v10;
  if ( !v10 )
    return 0xFFFFFFFFLL;
  *v10 = v10;
  v10[1] = v10;
  memcpy((char *)v10 + 20, (const void *)a2, 0x170u);
  v12 = *(unsigned __int16 *)(a2 + 356);
  v11[49] = a4;
  v11[50] = a3;
  *((_DWORD *)v11 + 4) = 1468208646;
  if ( v12 )
    goto LABEL_5;
  v12 = ipa3_alloc_rule_id(*(_QWORD *)(a4 + 136));
  if ( v12 < 0 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_create_flt_entry__rs, "__ipa_create_flt_entry") )
      printk(&unk_3BB24F, "__ipa_create_flt_entry");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d failed to allocate rule id\n", "__ipa_create_flt_entry", 986);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d failed to allocate rule id\n", "__ipa_create_flt_entry", 986);
        v14 = ipa3_ctx;
      }
    }
    kmem_cache_free(*(_QWORD *)(v14 + 29376), *a1);
    return 0xFFFFFFFFLL;
  }
  v11 = (_QWORD *)*a1;
LABEL_5:
  *((_WORD *)v11 + 209) = v12;
  *(_BYTE *)(*a1 + 421LL) = a5 & 1;
  result = 0;
  if ( *(_BYTE *)(a2 + 360) )
    *(_BYTE *)(*a1 + 420LL) = *(_BYTE *)(a2 + 361);
  else
    *(_BYTE *)(*a1 + 420LL) = 0;
  return result;
}
