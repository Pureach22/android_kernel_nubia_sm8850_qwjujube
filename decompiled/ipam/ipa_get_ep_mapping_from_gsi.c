__int64 __fastcall ipa_get_ep_mapping_from_gsi(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v6; // x10
  unsigned __int64 i; // x8

  if ( a1 <= 0x23 )
  {
    if ( *(unsigned __int8 *)(ipa3_ctx + 32244) <= 0x17uLL )
    {
      v6 = 134;
      for ( i = 6968LL * *(unsigned __int8 *)(ipa3_ctx + 32244); i <= 0x28D3F; i += 52LL )
      {
        if ( (ipa3_ep_mapping[i] & 1) != 0 )
        {
          if ( i > 0x28D27 )
            break;
          if ( *(_DWORD *)&ipa3_ep_mapping[i + 24] == a1 )
            return *(unsigned int *)&ipa3_ep_mapping[i + 20];
        }
        if ( !--v6 )
          return 0xFFFFFFFFLL;
      }
      __break(1u);
    }
    __break(0x5512u);
    JUMPOUT(0x11D0BC);
  }
  if ( (unsigned int)__ratelimit(&ipa_get_ep_mapping_from_gsi__rs, "ipa_get_ep_mapping_from_gsi") )
    printk(&unk_3B5B5D, "ipa_get_ep_mapping_from_gsi");
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d Bad ch_id number! ch_id =%d\n", "ipa_get_ep_mapping_from_gsi", 8356, a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d Bad ch_id number! ch_id =%d\n", "ipa_get_ep_mapping_from_gsi", 8356, a1);
  }
  return 0xFFFFFFFFLL;
}
