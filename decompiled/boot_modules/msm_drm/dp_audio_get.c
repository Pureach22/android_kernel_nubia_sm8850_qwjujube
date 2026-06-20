__int64 __fastcall dp_audio_get(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  unsigned __int64 v8; // x0
  __int64 v9; // x20
  void (__fastcall *v10)(_QWORD); // x10
  __int64 v12; // x0
  __int64 ipc_log_context; // x0

  if ( a1 && a2 && a3 )
  {
    v6 = devm_kmalloc(a1 + 16, 392, 3520);
    if ( v6 )
    {
      v7 = v6;
      v8 = alloc_workqueue("%s", byte_40008);
      *(_QWORD *)(v7 + 192) = v8;
      if ( v8 && v8 <= 0xFFFFFFFFFFFFF000LL )
      {
        *(_QWORD *)(v7 + 200) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v7 + 208) = v7 + 208;
        *(_QWORD *)(v7 + 216) = v7 + 208;
        *(_QWORD *)(v7 + 224) = dp_audio_notify_work_fn;
        init_timer_key(v7 + 232, &delayed_work_timer_fn, 0x200000, 0, 0);
        *(_DWORD *)(v7 + 160) = 0;
        _init_swait_queue_head(v7 + 168, "&x->wait", &init_completion___key_3);
        *(_QWORD *)(v7 + 136) = a2;
        *(_QWORD *)(v7 + 8) = a1;
        *(_QWORD *)(v7 + 16) = a3;
        v9 = v7 + 352;
        *(_DWORD *)(v7 + 384) = 0;
        _mutex_init(v7 + 304, "&audio->ops_lock", &dp_audio_get___key);
        v10 = *(void (__fastcall **)(_QWORD))(a3 + 16);
        *(_QWORD *)(v7 + 368) = dp_audio_on;
        *(_QWORD *)(v7 + 376) = dp_audio_off;
        if ( *((_DWORD *)v10 - 1) != 1586062320 )
          __break(0x822Au);
        v10(a3);
      }
      else
      {
        ipc_log_context = get_ipc_log_context(v8);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]Error creating notify_workqueue\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_21C441, "dp_audio_create_notify_workqueue");
        devm_kfree(a1 + 16);
        return -1;
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(v12, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_audio_get");
    return -22;
  }
  return v9;
}
