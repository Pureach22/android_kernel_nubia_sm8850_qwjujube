__int64 __fastcall usb_qdss_set_inst_name(__int64 a1, char *s)
{
  __int64 v5; // x0
  const char *v6; // x3
  __int64 v7; // x0
  const char *v8; // x21
  __int64 v9; // x20
  _UNKNOWN **v10; // x22
  unsigned __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x22
  bool v14; // zf
  _QWORD *v15; // x0
  _QWORD *v16; // x1
  int v17; // w8
  void *v18; // x0
  __int64 v19; // x1

  if ( strlen(s) + 1 > 0xF )
    return 4294967260LL;
  v5 = kstrndup(s);
  if ( v5 )
  {
    v6 = (const char *)v5;
    v7 = qdss_ipc_log;
    *(_QWORD *)(a1 + 184) = v6;
    ipc_log_string(v7, "%s: qdss: channel_name:%s\n", "usb_qdss_set_inst_name", v6);
    v8 = *(const char **)(a1 + 184);
    v9 = raw_spin_lock_irqsave(&channel_lock);
    v10 = &usb_qdss_ch_list;
    while ( 1 )
    {
      v10 = (_UNKNOWN **)*v10;
      if ( v10 == &usb_qdss_ch_list )
        break;
      if ( !strcmp(v8, (const char *)*(v10 - 1)) )
      {
        raw_spin_unlock_irqrestore(&channel_lock, v9);
        printk(&unk_8513, "alloc_usb_qdss");
        goto LABEL_20;
      }
    }
    raw_spin_unlock_irqrestore(&channel_lock, v9);
    v11 = _kmalloc_cache_noprof(wait_for_completion, 3520, 560);
    if ( v11 )
    {
      v12 = alloc_workqueue(&unk_8352, 393226, 1, v8);
      *(_QWORD *)(v11 + 464) = v12;
      if ( v12 )
      {
        v13 = raw_spin_lock_irqsave(&channel_lock);
        *(_QWORD *)(v11 + 296) = v8;
        v14 = strcmp(v8, "qdss_ebc") == 0;
        v15 = (_QWORD *)(v11 + 304);
        v16 = off_A8;
        if ( v14 )
          v17 = 3;
        else
          v17 = 0;
        *(_DWORD *)(v11 + 336) = v17;
        if ( v16 == v15 || (_UNKNOWN **)*v16 != &usb_qdss_ch_list )
        {
          _list_add_valid_or_report(v15, v16, &usb_qdss_ch_list);
        }
        else
        {
          off_A8 = (_UNKNOWN *)(v11 + 304);
          *(_QWORD *)(v11 + 304) = &usb_qdss_ch_list;
          *(_QWORD *)(v11 + 312) = v16;
          *v16 = v15;
        }
        raw_spin_unlock_irqrestore(&channel_lock, v13);
        *(_DWORD *)(v11 + 456) = 0;
        *(_QWORD *)(v11 + 344) = v11 + 344;
        *(_QWORD *)(v11 + 352) = v11 + 344;
        *(_QWORD *)(v11 + 360) = v11 + 360;
        *(_QWORD *)(v11 + 368) = v11 + 360;
        *(_QWORD *)(v11 + 376) = v11 + 376;
        *(_QWORD *)(v11 + 384) = v11 + 376;
        *(_QWORD *)(v11 + 392) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v11 + 400) = v11 + 400;
        *(_QWORD *)(v11 + 408) = v11 + 400;
        *(_QWORD *)(v11 + 416) = usb_qdss_connect_work;
        *(_QWORD *)(v11 + 424) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v11 + 432) = v11 + 432;
        *(_QWORD *)(v11 + 440) = v11 + 432;
        *(_QWORD *)(v11 + 448) = usb_qdss_disconnect_work;
        _mutex_init(v11 + 472, "&qdss->mutex", &alloc_usb_qdss___key_38);
        *(_DWORD *)(v11 + 528) = 0;
        _init_swait_queue_head(v11 + 536, "&x->wait", &init_completion___key);
        if ( v11 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(a1 + 176) = v11;
          return 0;
        }
      }
      else
      {
        kfree(v11);
      }
    }
LABEL_20:
    v19 = *(_QWORD *)(a1 + 184);
    v18 = &unk_839F;
  }
  else
  {
    v18 = &unk_825E;
    v19 = 0;
  }
  printk(v18, v19);
  return 4294967284LL;
}
