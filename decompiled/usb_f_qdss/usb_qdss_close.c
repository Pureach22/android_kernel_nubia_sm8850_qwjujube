__int64 __fastcall usb_qdss_close(__int64 a1)
{
  __int64 v2; // x9
  __int64 v3; // x8
  _QWORD *v4; // x21
  _QWORD *v5; // x23
  _QWORD *v6; // x8
  __int64 v7; // x10
  _QWORD *v8; // x1
  int v9; // w0
  __int64 v10; // x22
  int v11; // w8
  const char *v12; // x21
  __int64 v13; // x1

  if ( !a1 )
    return printk(&unk_81A4, "usb_qdss_close");
  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "usb_qdss_close", *(const char **)a1);
  mutex_lock(a1 + 176);
  if ( (*(_BYTE *)(a1 + 224) & 1) != 0 )
  {
    v2 = raw_spin_lock_irqsave(a1 + 160);
    v3 = *(_QWORD *)(a1 + 64);
    *(_BYTE *)(a1 + 224) = 0;
    if ( v3 != a1 + 64 )
    {
      v4 = (_QWORD *)(a1 + 80);
      do
      {
        v5 = *(_QWORD **)(a1 + 72);
        v6 = (_QWORD *)v5[1];
        if ( (_QWORD *)*v6 == v5 && (v7 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
        {
          *(_QWORD *)(v7 + 8) = v6;
          *v6 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 72));
        }
        v8 = *(_QWORD **)(a1 + 88);
        if ( v5 == v4 || v8 == v5 || (_QWORD *)*v8 != v4 )
        {
          _list_add_valid_or_report(v5, v8, a1 + 80);
        }
        else
        {
          *(_QWORD *)(a1 + 88) = v5;
          *v5 = v4;
          v5[1] = v8;
          *v8 = v5;
        }
        raw_spin_unlock_irqrestore(a1 + 160, v2);
        v9 = usb_ep_dequeue(*(_QWORD *)(a1 - 56), *(v5 - 2));
        ipc_log_string(qdss_ipc_log, "%s: dequeue req:%pK status=%d\n", "usb_qdss_close", (const void *)*(v5 - 2), v9);
        v2 = raw_spin_lock_irqsave(a1 + 160);
      }
      while ( *(_QWORD *)(a1 + 64) != a1 + 64 );
    }
    v10 = *(_QWORD *)(a1 + 80);
    raw_spin_unlock_irqrestore(a1 + 160, v2);
    if ( v10 != a1 + 80 )
    {
      ipc_log_string(qdss_ipc_log, "%s: waiting for completion on dequeued requests\n", "usb_qdss_close");
      wait_for_completion(a1 + 232);
    }
    if ( *(_QWORD *)(a1 + 80) != a1 + 80 )
      __break(0x800u);
    qdss_free_reqs(a1 - 296);
    v11 = *(_DWORD *)(a1 - 20);
    *(_QWORD *)(a1 + 24) = 0;
    if ( v11 )
    {
      v12 = *(const char **)a1;
      if ( strcmp(*(const char **)a1, "qdss_mdm") )
      {
        if ( strcmp(v12, "qdss_sw") )
        {
          v13 = *(_QWORD *)(a1 - 8);
          if ( v13 )
            usb_ep_dequeue(*(_QWORD *)(a1 - 56), v13);
          if ( (unsigned int)set_qdss_data_connection(a1 - 296, 0) )
            printk(&unk_8624, "usb_qdss_close");
        }
      }
    }
  }
  else
  {
    printk(&unk_8283, "usb_qdss_close");
  }
  return mutex_unlock(a1 + 176);
}
