__int64 __fastcall ipa_rm_resource_set_perf_profile(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0
  int v6; // w8
  signed int v7; // w21
  unsigned int *resource; // x0
  unsigned int v9; // w10
  int v10; // w8
  int v11; // w8
  __int64 ipc_logbuf; // x0
  __int64 v13; // x0

  if ( a1 && a2 )
  {
    if ( *a2 == *(_DWORD *)(a1 + 12) )
    {
      result = ipa3_get_ipc_logbuf_low();
      if ( !result )
        return result;
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d same profile\n", "ipa_rm_resource_set_perf_profile", 1074);
    }
    else
    {
      v6 = *(_DWORD *)(a1 + 4);
      if ( (v6 == 1 || !v6 && (unsigned int)(*(_DWORD *)(a1 + 20) - 1) <= 1)
        && (int)ipa_rm_peers_list_get_size(*(_QWORD *)(a1 + 24)) >= 1 )
      {
        v7 = 0;
        do
        {
          resource = (unsigned int *)ipa_rm_peers_list_get_resource(v7, *(_QWORD *)(a1 + 24));
          if ( resource )
          {
            v9 = resource[5];
            v10 = resource[4] - *(_DWORD *)(a1 + 12);
            resource[4] = v10;
            resource[4] = *a2 + v10;
            if ( v9 == 2 )
              ipa_rm_perf_profile_change(*resource);
          }
          ++v7;
        }
        while ( v7 < (int)ipa_rm_peers_list_get_size(*(_QWORD *)(a1 + 24)) );
      }
      v11 = *(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 12) = *a2;
      if ( v11 == 2 )
        ipa_rm_perf_profile_change(*(_DWORD *)a1);
    }
    return 0;
  }
  else
  {
    printk(&unk_3DA65E, "ipa_rm_resource_set_perf_profile");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_set_perf_profile", 1069);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_set_perf_profile", 1069);
    }
    return 4294967274LL;
  }
}
