__int64 __fastcall _ipa_find_hdr(const char *a1)
{
  size_t v2; // x0
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x7
  int v13; // s2
  int v14; // s16
  __int64 v15; // x1

  v2 = strnlen(a1, 0x20u);
  if ( v2 == 32 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_find_hdr__rs, "__ipa_find_hdr") )
      printk(&unk_3ACCD8, "__ipa_find_hdr");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d Header name too long: %s\n", "__ipa_find_hdr", 1458, a1);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d Header name too long: %s\n", "__ipa_find_hdr", 1458, a1);
    }
  }
  else
  {
    if ( v2 == -1 )
    {
      v11 = _fortify_panic(2, -1, 0);
      *(_DWORD *)(v12 - 176) = v14;
      *(_DWORD *)(v12 - 172) = v13;
      return ipa3_get_hdr_offset(v11, v15);
    }
    v3 = ipa3_ctx;
    v4 = ipa3_ctx + 28656;
    v5 = ipa3_ctx + 28656;
    while ( 1 )
    {
      v5 = *(_QWORD *)v5;
      if ( v5 == v4 )
        break;
      if ( !strcmp(a1, (const char *)(v5 + 280)) )
        return v5;
    }
    v10 = v3 + 28872;
    v5 = v10;
    while ( 1 )
    {
      v5 = *(_QWORD *)v5;
      if ( v5 == v10 )
        break;
      if ( !strcmp(a1, (const char *)(v5 + 280)) )
        return v5;
    }
  }
  return 0;
}
