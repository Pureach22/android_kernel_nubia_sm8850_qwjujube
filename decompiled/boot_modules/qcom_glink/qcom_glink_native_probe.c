__int64 __fastcall qcom_glink_native_probe(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  __int64 v10; // x0
  __int64 v11; // x19
  __int64 v12; // x8
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x21
  __int64 v15; // x1

  v10 = devm_kmalloc(a1, 264, 3520);
  if ( !v10 )
    return -12;
  *(_QWORD *)v10 = a1;
  v11 = v10;
  *(_BYTE *)(v10 + 216) = a5 & 1;
  *(_QWORD *)(v10 + 16) = a3;
  *(_QWORD *)(v10 + 24) = a4;
  *(_QWORD *)(v10 + 208) = a2;
  *(_DWORD *)(v10 + 152) = 0;
  *(_DWORD *)(v10 + 128) = 0;
  *(_QWORD *)(v10 + 136) = v10 + 136;
  *(_QWORD *)(v10 + 144) = v10 + 136;
  *(_QWORD *)(v10 + 96) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 104) = v10 + 104;
  *(_QWORD *)(v10 + 112) = v10 + 104;
  *(_QWORD *)(v10 + 120) = qcom_glink_work;
  _init_waitqueue_head(v10 + 224, "&glink->tx_avail_notify", &qcom_glink_native_probe___key_1);
  *(_QWORD *)(v11 + 156) = 0;
  *(_DWORD *)(v11 + 164) = 268435460;
  *(_QWORD *)(v11 + 168) = 0;
  *(_QWORD *)(v11 + 176) = 0;
  *(_QWORD *)(v11 + 184) = 0x1000000400000000LL;
  *(_QWORD *)(v11 + 192) = 0;
  v12 = *(_QWORD *)v11;
  *(_QWORD *)(v11 + 200) = 0;
  *(_QWORD *)(v12 + 800) = &qcom_glink_groups;
  if ( (unsigned int)device_add_groups(a1) )
    dev_err(a1, "failed to add groups\n");
  if ( (of_property_read_string(*(_QWORD *)(a1 + 744), "label", v11 + 8) & 0x80000000) != 0 )
    *(_QWORD *)(v11 + 8) = **(_QWORD **)(a1 + 744);
  _kthread_init_worker(v11 + 32, "(&glink->kworker)->lock", &qcom_glink_native_probe___key_5);
  v13 = kthread_create_on_node(&kthread_worker_fn, v11 + 32, 0xFFFFFFFFLL, "glink_%s", *(const char **)(v11 + 8));
  v14 = v13;
  if ( v13 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v11 + 88) = v13;
    dev_err(a1, "failed to spawn intent kthread %ld\n", v13);
    return *(_QWORD *)(v11 + 88);
  }
  else
  {
    wake_up_process(v13);
    v15 = *(_QWORD *)(v11 + 8);
    *(_QWORD *)(v11 + 88) = v14;
    *(_QWORD *)(v11 + 256) = ipc_log_context_create(32, v15, 0);
  }
  return v11;
}
