__int64 __fastcall ipa_rm_resource_producer_deregister(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x8
  _QWORD *v4; // t1
  __int64 v5; // x10
  _QWORD *v6; // x9
  _QWORD *v7; // x10
  _QWORD *v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  _QWORD *v12; // x10

  if ( a1 && a2 )
  {
    v4 = *(_QWORD **)(a1 + 32);
    v2 = (_QWORD *)(a1 + 32);
    v3 = v4;
    while ( v3 != v2 )
    {
      v5 = *(v3 - 2);
      v6 = v3;
      v3 = (_QWORD *)*v3;
      if ( v5 == *(_QWORD *)(a2 + 8) )
      {
        v7 = (_QWORD *)v6[1];
        v8 = v6 - 3;
        if ( (_QWORD *)*v7 == v6 && (_QWORD *)v3[1] == v6 )
        {
          v3[1] = v7;
          *v7 = v3;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
          v8 = v12;
        }
        *v6 = 0xDEAD000000000100LL;
        v6[1] = 0xDEAD000000000122LL;
        kfree(v8);
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_3DA65E, "ipa_rm_resource_producer_deregister");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_producer_deregister", 581);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_producer_deregister", 581);
    }
  }
  return 4294967274LL;
}
