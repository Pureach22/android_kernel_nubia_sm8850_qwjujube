__int64 __fastcall ipa_rm_resource_producer_request(__int64 a1)
{
  int v1; // w19
  __int64 result; // x0
  __int64 v4; // x0
  unsigned int v5; // w21
  unsigned int v6; // w22
  unsigned int *resource; // x0
  int v8; // w1
  unsigned int v9; // w0
  unsigned int v10; // w22
  __int64 ipc_logbuf_low; // x21
  const char *v12; // x0

  v1 = *(_DWORD *)(a1 + 20);
  if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
LABEL_19:
      result = 0;
      goto LABEL_20;
    }
    if ( v1 != 3 )
    {
LABEL_15:
      result = 4294967274LL;
      goto LABEL_20;
    }
  }
  else if ( v1 )
  {
    if ( v1 == 1 )
    {
      result = 4294967181LL;
      goto LABEL_20;
    }
    goto LABEL_15;
  }
  v4 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 20) = 1;
  if ( (int)ipa_rm_peers_list_get_size(v4) >= 1 )
  {
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      resource = (unsigned int *)ipa_rm_peers_list_get_resource(v5, *(_QWORD *)(a1 + 24));
      if ( resource )
      {
        v8 = *(_DWORD *)(a1 + 12);
        ++*(_DWORD *)(a1 + 48);
        result = ipa_rm_resource_consumer_request(resource, v8, 1, 0);
        if ( (_DWORD)result == -115 )
        {
          v6 = -115;
        }
        else
        {
          --*(_DWORD *)(a1 + 48);
          if ( (_DWORD)result )
            return result;
        }
      }
      if ( (int)++v5 >= (int)ipa_rm_peers_list_get_size(*(_QWORD *)(a1 + 24)) )
        goto LABEL_17;
    }
  }
  v6 = 0;
LABEL_17:
  result = v6;
  if ( !*(_DWORD *)(a1 + 48) )
  {
    v9 = *(_DWORD *)a1;
    *(_DWORD *)(a1 + 20) = 2;
    ipa_rm_perf_profile_change(v9);
    ipa_rm_wq_send_cmd(0, *(_DWORD *)a1, 0, 1);
    goto LABEL_19;
  }
LABEL_20:
  if ( v1 != *(_DWORD *)(a1 + 20) )
  {
    v10 = result;
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v12 = ipa_rm_resource_str(*(_DWORD *)a1);
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_rm %s:%d %s state changed %d->%d\n",
        "ipa_rm_resource_producer_request",
        860,
        v12,
        v1,
        *(_DWORD *)(a1 + 20));
    }
    return v10;
  }
  return result;
}
