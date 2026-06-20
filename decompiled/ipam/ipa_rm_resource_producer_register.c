__int64 __fastcall ipa_rm_resource_producer_register(__int64 a1, __int64 *a2, char a3)
{
  __int64 *v4; // x19
  char v5; // w21
  __int64 *v6; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x9
  __int64 v13; // x2
  unsigned int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x0

  if ( a1 && a2 )
  {
    v4 = (__int64 *)(a1 + 32);
    v5 = a3 & 1;
    v6 = (__int64 *)(a1 + 32);
    do
    {
      v6 = (__int64 *)*v6;
      if ( v6 == v4 )
      {
        v9 = _kmalloc_cache_noprof(ipc_log_string, 2336, 40);
        if ( v9 )
        {
          v10 = *a2;
          v11 = a2[1];
          v12 = v9 + 24;
          *(_BYTE *)(v9 + 16) = v5;
          *(_QWORD *)v9 = v10;
          *(_QWORD *)(v9 + 8) = v11;
          *(_QWORD *)(v9 + 24) = v9 + 24;
          *(_QWORD *)(v9 + 32) = v9 + 24;
          v13 = *v4;
          if ( *(__int64 **)(*v4 + 8) != v4 || (__int64 *)v12 == v4 || v13 == v12 )
          {
            _list_add_valid_or_report(v9 + 24, v4);
            return 0;
          }
          else
          {
            v14 = 0;
            *(_QWORD *)(v13 + 8) = v12;
            *(_QWORD *)(v9 + 24) = v13;
            *(_QWORD *)(v9 + 32) = v4;
            *v4 = v12;
          }
        }
        else
        {
          return (unsigned int)-12;
        }
        return v14;
      }
    }
    while ( *(v6 - 2) != a2[1] );
    printk(&unk_3F138F, "ipa_rm_resource_producer_register");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d already registered\n", "ipa_rm_resource_producer_register", 539);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d already registered\n", "ipa_rm_resource_producer_register", 539);
    }
  }
  else
  {
    printk(&unk_3DA65E, "ipa_rm_resource_producer_register");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_producer_register", 528);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v16, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_producer_register", 528);
    }
  }
  return (unsigned int)-1;
}
