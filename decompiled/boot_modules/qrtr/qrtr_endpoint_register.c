__int64 __fastcall qrtr_endpoint_register(_QWORD *a1, int a2, char a3, _QWORD *a4)
{
  __int64 v8; // x0
  __int64 v9; // x20
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x23
  __int64 result; // x0
  unsigned __int64 v13; // x25
  unsigned __int64 v14; // x8
  int v15; // w26
  __int64 v16; // x23
  unsigned int v17; // w23
  void *v18; // x0
  void *v19; // x2
  struct sched_param param; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  param.__sched_priority = 1;
  if ( !a1 || !*a1 )
  {
    result = 4294967274LL;
    goto LABEL_8;
  }
  v8 = _kmalloc_cache_noprof(raw_spin_lock, 3520, 360);
  v9 = v8;
  if ( !v8 )
    goto LABEL_6;
  *(_DWORD *)(v8 + 56) = 1;
  _mutex_init(v8, "&node->ep_lock", &qrtr_endpoint_register___key);
  *(_QWORD *)(v9 + 160) = 0;
  *(_QWORD *)(v9 + 144) = v9 + 144;
  *(_QWORD *)(v9 + 152) = v9 + 144;
  *(_DWORD *)(v9 + 60) = -1;
  *(_QWORD *)(v9 + 48) = a1;
  *(_DWORD *)(v9 + 68) = 0;
  *(_DWORD *)(v9 + 72) = 0;
  *(_QWORD *)(v9 + 272) = 0;
  *(_QWORD *)(v9 + 280) = 0;
  *(_QWORD *)(v9 + 248) = v9 + 248;
  *(_QWORD *)(v9 + 256) = v9 + 248;
  *(_QWORD *)(v9 + 264) = qrtr_node_rx_work;
  *(_QWORD *)(v9 + 312) = 0;
  *(_QWORD *)(v9 + 320) = 0;
  *(_QWORD *)(v9 + 288) = v9 + 288;
  *(_QWORD *)(v9 + 296) = v9 + 288;
  *(_QWORD *)(v9 + 304) = qrtr_hello_work;
  _kthread_init_worker(v9 + 184, "(&node->kworker)->lock", &qrtr_endpoint_register___key_8);
  v10 = kthread_create_on_node(&kthread_worker_fn, v9 + 184, 0xFFFFFFFFLL, "qrtr_rx");
  v11 = v10;
  if ( v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v9 + 240) = v10;
    kfree(v9);
LABEL_6:
    result = 4294967284LL;
    goto LABEL_8;
  }
  wake_up_process(v10);
  *(_QWORD *)(v9 + 240) = v11;
  if ( (a3 & 1) != 0 )
    sched_setscheduler(v11, 1, &param);
  *(_QWORD *)(v9 + 336) = 0;
  *(_QWORD *)(v9 + 344) = 0;
  if ( a4 && (v13 = a4[1]) != 0 )
  {
    v14 = 0;
    v15 = 1;
    while ( 1 )
    {
      v16 = *(unsigned int *)(*a4 + 4 * v14);
      raw_spin_lock(v9 + 336);
      v17 = _xa_insert(v9 + 336, v16, v9, 3264);
      raw_spin_unlock(v9 + 336);
      if ( v17 )
        break;
      v14 = v15++;
      if ( v13 <= v14 )
        goto LABEL_16;
    }
    kfree(v9);
    result = v17;
  }
  else
  {
LABEL_16:
    *(_QWORD *)(v9 + 80) = 0xCC000000000LL;
    *(_QWORD *)(v9 + 88) = 0;
    _mutex_init(v9 + 96, "&node->qrtr_tx_lock", &qrtr_endpoint_register___key_11);
    *(_DWORD *)(v9 + 64) = a2;
    down_write(&qrtr_epts_lock);
    v18 = (void *)(v9 + 168);
    v19 = qrtr_all_epts;
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)qrtr_all_epts) != &qrtr_all_epts || qrtr_all_epts == v18 )
    {
      _list_add_valid_or_report(v18, &qrtr_all_epts);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)qrtr_all_epts) = v18;
      *(_QWORD *)(v9 + 168) = v19;
      *(_QWORD *)(v9 + 176) = &qrtr_all_epts;
      qrtr_all_epts = (_UNKNOWN *)(v9 + 168);
    }
    up_write(&qrtr_epts_lock);
    a1[1] = v9;
    *(_QWORD *)(v9 + 328) = wakeup_source_register(0, "qrtr_ws");
    kthread_queue_work(v9 + 184, v9 + 288);
    result = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
