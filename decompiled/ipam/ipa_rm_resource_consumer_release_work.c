__int64 __fastcall ipa_rm_resource_consumer_release_work(__int64 a1, int a2, char a3)
{
  long double v6; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 (__fastcall *v8)(long double); // x8
  unsigned int v9; // w21
  __int64 v10; // x0
  __int64 ipc_logbuf; // x0
  __int64 v13; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v6 = ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d calling driver CB\n", "ipa_rm_resource_consumer_release_work", 83);
  }
  v8 = *(__int64 (__fastcall **)(long double))(a1 + 80);
  if ( *((_DWORD *)v8 - 1) != 1874538549 )
    __break(0x8228u);
  v9 = v8(v6);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v10 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v10, "ipa_rm %s:%d driver CB returned with %d\n", "ipa_rm_resource_consumer_release_work", 85, v9);
  }
  if ( v9 == -115 )
    v9 = 0;
  if ( v9 )
  {
    printk(&unk_3BD106, "ipa_rm_resource_consumer_release_work");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_rm %s:%d driver CB returned error %d\n",
        "ipa_rm_resource_consumer_release_work",
        93,
        v9);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa_rm %s:%d driver CB returned error %d\n", "ipa_rm_resource_consumer_release_work", 93, v9);
    }
    *(_DWORD *)(a1 + 20) = a2;
  }
  else
  {
    if ( (a3 & 1) != 0 )
      ipa_rm_resource_consumer_handle_cb(a1, 1);
    else
      *(_DWORD *)(a1 + 20) = 0;
    complete_all(a1 + 40);
    ipa_rm_perf_profile_change(*(_DWORD *)a1);
  }
  return v9;
}
