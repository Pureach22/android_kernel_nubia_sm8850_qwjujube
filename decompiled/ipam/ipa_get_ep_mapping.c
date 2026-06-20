__int64 __fastcall ipa_get_ep_mapping(__int64 a1)
{
  int v1; // w19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned __int64 v5; // x9
  unsigned int v6; // w9
  unsigned int v7; // w8

  v1 = a1;
  if ( (unsigned int)a1 >= 0x86 )
  {
    if ( (unsigned int)__ratelimit(&ipa_get_ep_mapping__rs, "ipa_get_ep_mapping") )
      printk(&unk_3F3029, "ipa_get_ep_mapping");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d Bad client number! client =%d\n", "ipa_get_ep_mapping", 8324, v1);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d Bad client number! client =%d\n", "ipa_get_ep_mapping", 8324, v1);
    }
    return 0xFFFFFFFFLL;
  }
  if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
    goto LABEL_25;
  v5 = 6968LL * *(unsigned __int8 *)(ipa3_ctx + 32244) + 52LL * (unsigned int)a1;
  if ( v5 > 0x28D3F )
    goto LABEL_24;
  if ( ipa3_ep_mapping[v5] != 1 )
    return 0xFFFFFFFFLL;
  if ( v5 > 0x28D2B )
  {
LABEL_24:
    __break(1u);
LABEL_25:
    __break(0x5512u);
    return ipa3_set_evict_policy(a1);
  }
  v6 = *(_DWORD *)&ipa3_ep_mapping[v5 + 20];
  if ( (v6 & 0x80000000) != 0 )
    return 0xFFFFFFFFLL;
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
    v7 = 31;
  else
    v7 = 36;
  if ( v6 < v7 || (_DWORD)a1 == 73 )
    return v6;
  else
    return 0xFFFFFFFFLL;
}
