__int64 __fastcall qdss_free_reqs(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x9
  __int64 v4; // x20
  int v5; // w21
  _QWORD *v6; // x8
  _QWORD *v7; // x25
  __int64 v8; // x1
  _QWORD *v9; // x22

  v2 = raw_spin_lock_irqsave(a1 + 456);
  v3 = *(_QWORD **)(a1 + 344);
  v4 = v2;
  v5 = 0;
  if ( v3 != (_QWORD *)(a1 + 344) )
  {
    do
    {
      v7 = (_QWORD *)*v3;
      v6 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v6 == v3 && (_QWORD *)v7[1] == v3 )
      {
        v7[1] = v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      v8 = *(v3 - 2);
      v9 = v3 - 2;
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      usb_ep_free_request(*(_QWORD *)(a1 + 240), v8);
      kfree(v9);
      ++v5;
      v3 = v7;
    }
    while ( v7 != (_QWORD *)(a1 + 344) );
  }
  ipc_log_string(
    qdss_ipc_log,
    "%s: channel:%s data_write_req:%d freed\n",
    "qdss_free_reqs",
    *(const char **)(a1 + 296),
    v5);
  return raw_spin_unlock_irqrestore(a1 + 456, v4);
}
