__int64 __fastcall usb_qdss_write(__int64 *a1, _QWORD *a2)
{
  __int64 v4; // x1
  __int64 v5; // x23
  __int64 *v6; // x21
  __int64 **v7; // x8
  __int64 *v8; // x9
  __int64 *v9; // x10
  __int64 *v10; // x1
  __int64 v11; // x23
  __int64 v12; // x5
  __int64 v13; // x0
  __int64 v14; // x9
  unsigned int v15; // w8
  __int64 v16; // x3
  __int64 v18; // x22
  __int64 v19; // x1

  if ( !a1 )
  {
    printk(&unk_81A4, "usb_qdss_write");
    return 4294967274LL;
  }
  mutex_lock(a1 + 22);
  ipc_log_string(qdss_ipc_log, "%s: channel:%s d_req:%pK\n", "usb_qdss_write", (const char *)*a1, a2);
  v5 = raw_spin_lock_irqsave(a1 + 20);
  if ( *((_BYTE *)a1 + 224) != 1 || !*((_DWORD *)a1 - 5) )
  {
    raw_spin_unlock_irqrestore(a1 + 20, v5);
    ipc_log_string(qdss_ipc_log, "%s: return -EIO\n", "usb_qdss_write");
LABEL_15:
    mutex_unlock(a1 + 22);
    return 4294967291LL;
  }
  v6 = (__int64 *)a1[6];
  if ( v6 == a1 + 6 )
  {
    printk(&unk_81B6, v4);
    raw_spin_unlock_irqrestore(a1 + 20, v5);
    mutex_unlock(a1 + 22);
    return 4294967285LL;
  }
  v7 = (__int64 **)v6[1];
  v8 = a1 + 8;
  if ( *v7 == v6 && (v9 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
  {
    v9[1] = (__int64)v7;
    *v7 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(a1[6]);
  }
  v10 = (__int64 *)a1[9];
  if ( v6 == v8 || v10 == v6 || (__int64 *)*v10 != v8 )
  {
    _list_add_valid_or_report(v6, v10, v8);
  }
  else
  {
    a1[9] = (__int64)v6;
    *v6 = (__int64)v8;
    v6[1] = (__int64)v10;
    *v10 = (__int64)v6;
  }
  raw_spin_unlock_irqrestore(a1 + 20, v5);
  *(v6 - 1) = (__int64)a2;
  v11 = *(v6 - 2);
  *(_QWORD *)v11 = *a2;
  v12 = *((unsigned int *)a2 + 2);
  v13 = qdss_ipc_log;
  *(_DWORD *)(v11 + 8) = v12;
  v14 = a2[4];
  *(_QWORD *)(v11 + 24) = v14;
  v15 = *((_DWORD *)a2 + 10);
  *(_DWORD *)(v11 + 32) = v15;
  v16 = *a1;
  if ( v14 )
    ipc_log_string(v13, "%s: %s: req:%pK req->num_sgs:0x%x\n", "usb_qdss_write", v16, v11, v15);
  else
    ipc_log_string(v13, "%s: %s: req:%pK rq->length:0x%x\n", "usb_qdss_write", v16, v11, v12);
  if ( (unsigned int)usb_ep_queue(*(a1 - 7), v11, 2080) )
  {
    v18 = raw_spin_lock_irqsave(a1 + 20);
    list_move_tail(v6, a1 + 6);
    raw_spin_unlock_irqrestore(a1 + 20, v18);
    printk(&unk_8692, v19);
    goto LABEL_15;
  }
  mutex_unlock(a1 + 22);
  return 0;
}
