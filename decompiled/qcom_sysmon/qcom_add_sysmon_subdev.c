__int64 __fastcall qcom_add_sysmon_subdev(__int64 a1, __int64 a2, int a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x8
  unsigned int byname; // w0
  int v10; // w0
  int v11; // w21
  __int64 v12; // x0
  const char *v13; // x1
  int v14; // w0
  void *v15; // x2
  __int64 v16; // x20

  v6 = _kmalloc_cache_noprof(blocking_notifier_chain_register, 3520, 752);
  v7 = v6;
  if ( !v6 )
    return -12;
  v8 = *(_QWORD *)(a1 + 152);
  *(_QWORD *)(v6 + 128) = a2;
  *(_DWORD *)(v6 + 144) = a3;
  *(_QWORD *)(v6 + 48) = a1;
  *(_QWORD *)(v6 + 224) = v8;
  *(_DWORD *)(v6 + 248) = 0;
  _init_swait_queue_head(v6 + 256, "&x->wait", &init_completion___key);
  *(_DWORD *)(v7 + 280) = 0;
  _init_swait_queue_head(v7 + 288, "&x->wait", &init_completion___key);
  *(_DWORD *)(v7 + 312) = 0;
  _init_swait_queue_head(v7 + 320, "&x->wait", &init_completion___key);
  *(_DWORD *)(v7 + 344) = 0;
  _init_swait_queue_head(v7 + 352, "&x->wait", &init_completion___key);
  init_timer_key(v7 + 160, sysmon_notif_timeout_handler, 0, 0, 0);
  _mutex_init(v7 + 376, "&sysmon->lock", &qcom_add_sysmon_subdev___key);
  _mutex_init(v7 + 64, "&sysmon->state_lock", &qcom_add_sysmon_subdev___key_4);
  if ( *(_DWORD *)(v7 + 144) != -22 )
  {
    byname = of_irq_get_byname(*(_QWORD *)(*(_QWORD *)(v7 + 224) + 744LL), "shutdown-ack");
    *(_DWORD *)(v7 + 136) = byname;
    if ( (byname & 0x80000000) != 0 )
    {
      if ( byname != -61 )
      {
        dev_err(*(_QWORD *)(v7 + 224), "failed to retrieve shutdown-ack IRQ\n");
        v16 = *(int *)(v7 + 136);
        kfree(v7);
        return v16;
      }
    }
    else
    {
      v10 = devm_request_threaded_irq(
              *(_QWORD *)(v7 + 224),
              byname,
              0,
              sysmon_shutdown_interrupt,
              8193,
              "q6v5 shutdown-ack",
              v7);
      if ( v10 )
      {
        v11 = v10;
        v12 = *(_QWORD *)(v7 + 224);
        v13 = "failed to acquire shutdown-ack IRQ\n";
LABEL_14:
        dev_err(v12, v13);
        kfree(v7);
        return v11;
      }
    }
    v14 = qmi_handle_init(v7 + 432, 7, ssctl_ops, &qmi_indication_handler);
    if ( v14 < 0 )
    {
      v11 = v14;
      v12 = *(_QWORD *)(v7 + 224);
      v13 = "failed to initialize qmi handle\n";
      goto LABEL_14;
    }
    qmi_add_lookup(v7 + 432, 43, 0, 0);
  }
  *(_QWORD *)(v7 + 16) = sysmon_prepare;
  *(_QWORD *)(v7 + 24) = sysmon_start;
  *(_QWORD *)(v7 + 32) = sysmon_stop;
  *(_QWORD *)(v7 + 40) = sysmon_unprepare;
  rproc_add_subdev(a1, v7);
  *(_QWORD *)(v7 + 200) = sysmon_notify;
  blocking_notifier_chain_register(&sysmon_notifiers, v7 + 200);
  mutex_lock(&sysmon_lock);
  v15 = sysmon_list;
  if ( sysmon_list == (_UNKNOWN *)(v7 + 112) || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)sysmon_list) != &sysmon_list )
  {
    _list_add_valid_or_report();
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)sysmon_list) = v7 + 112;
    *(_QWORD *)(v7 + 112) = v15;
    *(_QWORD *)(v7 + 120) = &sysmon_list;
    sysmon_list = (_UNKNOWN *)(v7 + 112);
  }
  mutex_unlock(&sysmon_lock);
  return v7;
}
