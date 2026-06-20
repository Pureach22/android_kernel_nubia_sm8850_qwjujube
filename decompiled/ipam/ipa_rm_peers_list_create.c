__int64 __fastcall ipa_rm_peers_list_create(int a1, __int64 *a2)
{
  __int64 v4; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v4 = _kmalloc_cache_noprof(kfree, 2336, 16);
  *a2 = v4;
  if ( !v4 )
  {
    printk(&unk_3E0188, "ipa_rm_peers_list_create");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d no mem\n", "ipa_rm_peers_list_create", 54);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d no mem\n", "ipa_rm_peers_list_create", 54);
    }
    return 4294967284LL;
  }
  *(_DWORD *)(v4 + 8) = a1;
  *(_QWORD *)*a2 = _kmalloc_noprof(16LL * *(int *)(*a2 + 8), 2336);
  if ( !*(_QWORD *)*a2 )
  {
    printk(&unk_3E0188, "ipa_rm_peers_list_create");
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(v6, "ipa_rm %s:%d no mem\n", "ipa_rm_peers_list_create", 63);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v7 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v7, "ipa_rm %s:%d no mem\n", "ipa_rm_peers_list_create", 63);
    }
    kfree(*a2);
    *a2 = 0;
    return 4294967284LL;
  }
  return 0;
}
