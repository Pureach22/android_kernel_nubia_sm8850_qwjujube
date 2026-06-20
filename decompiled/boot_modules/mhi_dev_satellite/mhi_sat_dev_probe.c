__int64 __fastcall mhi_sat_dev_probe(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x22
  int numeric_id; // w0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  int v9; // w21
  __int64 v10; // x23
  __int64 *v11; // x22
  __int64 v12; // x1
  __int64 v13; // x20
  __int64 v14; // x0
  int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x2
  int v18; // w8
  __int64 v19; // x0
  _QWORD *v20; // x21
  _QWORD *v21; // x1
  _QWORD *v22; // x2
  int v23; // w9
  int v24; // w8

  v3 = mhi_sat_driver_1;
  v4 = *(_QWORD *)(a2 + 32);
  numeric_id = mhi_controller_get_numeric_id(*(_QWORD *)(a1 + 16));
  if ( !numeric_id )
  {
    printk(&unk_8237, v6, v7, v8);
    return 4294967274LL;
  }
  v9 = numeric_id;
  v10 = v3 + 96 * v4;
  v11 = (__int64 *)(v10 + 16);
  v12 = raw_spin_lock_irqsave(v10 + 80);
  v13 = v10 + 16;
  do
  {
    v13 = *(_QWORD *)v13;
    if ( (__int64 *)v13 == v11 )
    {
      raw_spin_unlock_irqrestore(v10 + 80, v12);
      goto LABEL_8;
    }
  }
  while ( *(_DWORD *)(v13 + 232) != v9 );
  raw_spin_unlock_irqrestore(v10 + 80, v12);
  if ( !v13 )
  {
LABEL_8:
    v14 = _kmalloc_cache_noprof(kfree, 3520, 360);
    v13 = v14;
    if ( !v14 )
      return 4294967284LL;
    v15 = *(_DWORD *)(a1 + 968);
    *(_DWORD *)(v14 + 252) = -1;
    v16 = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(v14 + 232) = v9;
    *(_DWORD *)(v14 + 236) = v15;
    *(_WORD *)(v14 + 268) = -1;
    *(_QWORD *)(v14 + 16) = v16;
    *(_QWORD *)(v14 + 24) = v10;
    *(_DWORD *)(v14 + 280) = 0;
    _init_swait_queue_head(v14 + 288, "&x->wait", &init_completion___key);
    _mutex_init(v13 + 64, "&sat_cntrl->list_mutex", &mhi_sat_dev_probe___key);
    _mutex_init(v13 + 312, "&sat_cntrl->cmd_wait_mutex", &mhi_sat_dev_probe___key_29);
    *(_DWORD *)(v13 + 128) = 0;
    *(_DWORD *)(v13 + 264) = 0;
    *(_QWORD *)(v13 + 136) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v13 + 144) = v13 + 144;
    *(_QWORD *)(v13 + 152) = v13 + 144;
    *(_QWORD *)(v13 + 160) = mhi_sat_connect_worker;
    *(_QWORD *)(v13 + 168) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v13 + 176) = v13 + 176;
    *(_QWORD *)(v13 + 184) = v13 + 176;
    *(_QWORD *)(v13 + 192) = mhi_sat_process_worker;
    *(_QWORD *)(v13 + 200) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v13 + 208) = v13 + 208;
    *(_QWORD *)(v13 + 216) = v13 + 208;
    *(_QWORD *)(v13 + 224) = mhi_sat_error_worker;
    *(_QWORD *)(v13 + 32) = v13 + 32;
    *(_QWORD *)(v13 + 40) = v13 + 32;
    *(_QWORD *)(v13 + 48) = v13 + 48;
    *(_QWORD *)(v13 + 56) = v13 + 48;
    *(_QWORD *)(v13 + 112) = v13 + 112;
    *(_QWORD *)(v13 + 120) = v13 + 112;
    mutex_lock(v10 + 32);
    raw_spin_lock_irq(v10 + 80);
    v17 = *(_QWORD *)(v10 + 16);
    if ( *(__int64 **)(v17 + 8) != v11 || (__int64 *)v13 == v11 || v17 == v13 )
    {
      _list_add_valid_or_report(v13, v10 + 16);
    }
    else
    {
      *(_QWORD *)(v17 + 8) = v13;
      *(_QWORD *)v13 = v17;
      *(_QWORD *)(v13 + 8) = v11;
      *v11 = v13;
    }
    raw_spin_unlock_irq(v10 + 80);
    mutex_unlock(v10 + 32);
    if ( v10 )
      ipc_log_string(
        *(_QWORD *)(v10 + 88),
        "%s[I][%s][%x] Controller allocated for 0x%x\n",
        (const char *)&unk_8360,
        "mhi_sat_dev_probe",
        *(_DWORD *)(v13 + 232),
        v9);
  }
  *(_DWORD *)(v13 + 252) = 4;
  v18 = *(_DWORD *)(v13 + 236);
  if ( v18 >= *(_DWORD *)(a1 + 968) )
    v18 = *(_DWORD *)(a1 + 968);
  *(_DWORD *)(v13 + 236) = v18;
  if ( v18 <= *(_DWORD *)(a1 + 968) )
    v18 = *(_DWORD *)(a1 + 968);
  *(_DWORD *)(v13 + 240) = v18;
  v19 = devm_kmalloc(a1 + 40, 40, 3520);
  if ( !v19 )
    return 4294967284LL;
  v20 = (_QWORD *)v19;
  *(_QWORD *)(v19 + 16) = a1;
  *(_QWORD *)(v19 + 24) = v13;
  mutex_lock(v13 + 64);
  v21 = (_QWORD *)(v13 + 32);
  v22 = *(_QWORD **)(v13 + 32);
  if ( v22[1] != v13 + 32 || v20 == v21 || v22 == v20 )
  {
    _list_add_valid_or_report(v20, v21);
  }
  else
  {
    v22[1] = v20;
    *v20 = v22;
    v20[1] = v21;
    *v21 = v20;
  }
  mutex_unlock(v13 + 64);
  *(_QWORD *)(a1 + 192) = v20;
  v23 = *(_DWORD *)(v13 + 252);
  v24 = *(_DWORD *)(v13 + 248) + 1;
  *(_DWORD *)(v13 + 248) = v24;
  if ( v24 == v23 )
  {
    *(_DWORD *)(v13 + 244) = *(_DWORD *)(v13 + 240) - *(_DWORD *)(v13 + 236) + 1;
    if ( v10 )
      ipc_log_string(
        *(_QWORD *)(v10 + 88),
        "%s[I][%s][%x] All satellite channels probed!\n",
        (const char *)&unk_8360,
        "mhi_sat_dev_probe",
        *(_DWORD *)(v13 + 232));
    queue_work_on(32, system_wq, v13 + 136);
  }
  return 0;
}
