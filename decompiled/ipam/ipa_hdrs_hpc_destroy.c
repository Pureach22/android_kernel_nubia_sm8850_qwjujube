__int64 __fastcall ipa_hdrs_hpc_destroy(int a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w20
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  v2 = _kmalloc_cache_noprof(kfree, 3520, 12);
  v3 = v2;
  if ( v2 )
  {
    *(_DWORD *)(v2 + 4) = a1;
    *(_WORD *)v2 = 257;
    v4 = ipa3_del_hdr_hpc((_BYTE *)v2);
    if ( v4 || *(_DWORD *)(v3 + 8) )
    {
      printk(&unk_3FC187, "ipa_hdrs_hpc_destroy");
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d ipa_del_hdr failed\n", "ipa_hdrs_hpc_destroy", 14247);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(v7, "ipa %s:%d ipa_del_hdr failed\n", "ipa_hdrs_hpc_destroy", 14247);
      }
    }
    kfree(v3);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v4;
}
