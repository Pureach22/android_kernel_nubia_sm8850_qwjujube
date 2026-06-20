__int64 __fastcall ipa_rm_resource_delete(_DWORD *a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  int v5; // w8
  __int64 v6; // x0
  int v7; // w0
  int v8; // w20
  unsigned int j; // w21
  __int64 v10; // x0
  __int64 v11; // x22
  char v12; // w0
  _QWORD *v13; // x9
  _QWORD *v14; // x8
  _QWORD *v15; // x22
  __int64 v16; // x0
  int size; // w0
  int v18; // w20
  unsigned int i; // w21
  __int64 resource; // x0
  __int64 v21; // x22
  char userspace_dep; // w0
  __int64 v24; // x0
  __int64 v25; // x0

  if ( a1 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d ENTER with resource %d\n", "ipa_rm_resource_delete", 454, *a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v3 = ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d ENTER with resource %d\n", "ipa_rm_resource_delete", 454, *a1);
    }
    v5 = a1[1];
    if ( v5 == 1 )
    {
      v16 = *((_QWORD *)a1 + 3);
      if ( v16 )
      {
        size = ipa_rm_peers_list_get_size(v16);
        if ( size >= 1 )
        {
          v18 = size;
          for ( i = 0; i != v18; ++i )
          {
            resource = ipa_rm_peers_list_get_resource(i, *((_QWORD *)a1 + 3));
            if ( resource )
            {
              v21 = resource;
              userspace_dep = ipa_rm_peers_list_get_userspace_dep(i, *((_QWORD *)a1 + 3));
              ipa_rm_resource_delete_dependency(v21, a1, userspace_dep & 1);
            }
          }
        }
      }
    }
    else if ( !v5 )
    {
      v6 = *((_QWORD *)a1 + 3);
      if ( v6 )
      {
        v7 = ipa_rm_peers_list_get_size(v6);
        if ( v7 >= 1 )
        {
          v8 = v7;
          for ( j = 0; j != v8; ++j )
          {
            v10 = ipa_rm_peers_list_get_resource(j, *((_QWORD *)a1 + 3));
            if ( v10 )
            {
              v11 = v10;
              v12 = ipa_rm_peers_list_get_userspace_dep(j, *((_QWORD *)a1 + 3));
              ipa_rm_resource_delete_dependency(a1, v11, v12 & 1);
            }
          }
        }
      }
      ipa_rm_resource_producer_release(a1, v3);
      v13 = *((_QWORD **)a1 + 4);
      if ( v13 != (_QWORD *)(a1 + 8) )
      {
        do
        {
          v15 = (_QWORD *)*v13;
          v14 = (_QWORD *)v13[1];
          if ( (_QWORD *)*v14 == v13 && (_QWORD *)v15[1] == v13 )
          {
            v15[1] = v14;
            *v14 = v15;
          }
          else
          {
            _list_del_entry_valid_or_report(v13);
          }
          *v13 = 0xDEAD000000000100LL;
          v13[1] = 0xDEAD000000000122LL;
          kfree(v13 - 3);
          v13 = v15;
        }
        while ( v15 != (_QWORD *)(a1 + 8) );
      }
    }
    ipa_rm_peers_list_delete(*((_QWORD **)a1 + 3));
    kfree(a1);
    return 0;
  }
  else
  {
    printk(&unk_3DA65E, "ipa_rm_resource_delete");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_delete", 450);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v25, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_delete", 450);
    }
    return 4294967274LL;
  }
}
