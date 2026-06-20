__int64 __fastcall ipa_rm_resource_consumer_request_work(__int64 a1, int a2, int a3, char a4, char a5)
{
  long double v10; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 (__fastcall *v12)(long double); // x8
  unsigned int v13; // w20
  __int64 v14; // x0
  unsigned int v15; // w0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v10 = ipc_log_string(
            ipc_logbuf_low,
            "ipa_rm %s:%d calling driver CB\n",
            "ipa_rm_resource_consumer_request_work",
            119);
  }
  v12 = *(__int64 (__fastcall **)(long double))(a1 + 72);
  if ( *((_DWORD *)v12 - 1) != 1874538549 )
    __break(0x8228u);
  v13 = v12(v10);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v14, "ipa_rm %s:%d driver CB returned with %d\n", "ipa_rm_resource_consumer_request_work", 121, v13);
  }
  if ( v13 != -115 )
  {
    if ( v13 )
    {
      *(_DWORD *)(a1 + 16) -= a3;
      *(_DWORD *)(a1 + 20) = a2;
      if ( (a5 & 1) != 0 )
        --*(_DWORD *)(a1 + 32);
    }
    else if ( (a4 & 1) != 0 )
    {
      ipa_rm_resource_consumer_handle_cb(a1, 0);
    }
    else
    {
      v15 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 20) = 2;
      ipa_rm_perf_profile_change(v15);
      ipa3_resume_resource(*(_DWORD *)a1);
    }
  }
  return v13;
}
