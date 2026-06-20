__int64 __fastcall ipa_rm_resource_producer_release(__int64 a1)
{
  int v1; // w19
  unsigned int v3; // w21
  __int64 v4; // x0
  signed int v5; // w21
  unsigned int *resource; // x0
  int v7; // w1
  unsigned int v8; // w0
  __int64 ipc_logbuf_low; // x22
  const char *v10; // x0

  v1 = *(_DWORD *)(a1 + 20);
  if ( (unsigned int)(v1 - 1) < 2 )
  {
    v4 = *(_QWORD *)(a1 + 24);
    *(_DWORD *)(a1 + 52) = 0;
    *(_DWORD *)(a1 + 20) = 3;
    if ( (int)ipa_rm_peers_list_get_size(v4) >= 1 )
    {
      v5 = 0;
      do
      {
        resource = (unsigned int *)ipa_rm_peers_list_get_resource(v5, *(_QWORD *)(a1 + 24));
        if ( resource )
        {
          v7 = *(_DWORD *)(a1 + 12);
          ++*(_DWORD *)(a1 + 52);
          ipa_rm_resource_consumer_release(resource, v7, 1);
          --*(_DWORD *)(a1 + 52);
        }
        ++v5;
      }
      while ( v5 < (int)ipa_rm_peers_list_get_size(*(_QWORD *)(a1 + 24)) );
    }
    if ( !*(_DWORD *)(a1 + 52) )
    {
      v8 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 20) = 0;
      ipa_rm_perf_profile_change(v8);
      ipa_rm_wq_send_cmd(0, *(_DWORD *)a1, 1, 1);
    }
    v3 = 0;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 20);
    if ( v1 )
    {
      if ( v1 == 3 )
        v3 = -115;
      else
        v3 = -1;
    }
  }
  if ( v1 != *(_DWORD *)(a1 + 20) && ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v10 = ipa_rm_resource_str(*(_DWORD *)a1);
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_rm %s:%d %s state changed %d->%d\n",
      "ipa_rm_resource_producer_release",
      926,
      v10,
      v1,
      *(_DWORD *)(a1 + 20));
  }
  return v3;
}
