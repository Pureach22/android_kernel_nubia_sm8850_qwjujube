__int64 __fastcall ssr_timer_callback(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  unsigned int *v8; // x19
  __int64 v9; // x20
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x24
  __int64 v17; // x2
  __int64 v18; // x22
  __int64 v19; // x1
  void *v20; // x0

  if ( a1 == 256 )
    return printk(&unk_23ADD, "ssr_timer_callback", a3, a4, a5, a6);
  v6 = *(_QWORD *)(a1 - 72);
  v8 = *(unsigned int **)(v6 + 128);
  if ( !v8 )
    return printk(
             &unk_25BB9,
             "ssr_timer_callback",
             *(unsigned int *)(a1 - 216),
             *(unsigned int *)(a1 - 220),
             *(unsigned int *)(a1 - 224),
             *(unsigned int *)(a1 - 228));
  fastrpc_channel_ctx_get(*(_QWORD *)(v6 + 128));
  v9 = raw_spin_lock_irqsave(v8 + 12900);
  if ( (v8[16026] & 1) != 0 )
  {
LABEL_4:
    raw_spin_unlock_irqrestore(v8 + 12900, v9);
    return fastrpc_channel_ctx_put((__int64)v8);
  }
  v11 = *((_QWORD *)v8 + 20);
  *((_BYTE *)v8 + 64104) = 1;
  if ( !v11 || v8[16034] )
  {
    printk(
      &unk_248F5,
      "ssr_timer_callback",
      *v8,
      *(unsigned int *)(a1 - 216),
      *(unsigned int *)(a1 - 220),
      *(unsigned int *)(a1 - 224));
    goto LABEL_4;
  }
  v12 = rproc_get_by_child();
  if ( !v12 )
  {
    v17 = *v8;
    v20 = &unk_23E0E;
LABEL_16:
    printk(v20, "ssr_timer_callback", v17, v13, v14, v15);
    goto LABEL_4;
  }
  v16 = *((_QWORD *)v8 + 3);
  v17 = *v8;
  if ( v16 == -184 )
  {
    v20 = &unk_25FB6;
    goto LABEL_16;
  }
  v18 = v12;
  *(_DWORD *)(v16 + 224) = v17;
  raw_spin_unlock_irqrestore(v8 + 12900, v9);
  fastrpc_channel_ctx_put((__int64)v8);
  *(_QWORD *)(v16 + 184) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v16 + 192) = v16 + 192;
  *(_QWORD *)(v16 + 200) = v16 + 192;
  v19 = system_wq;
  *(_QWORD *)(v16 + 208) = fastrpc_handle_ssr_request;
  *(_QWORD *)(v16 + 216) = v18;
  return queue_work_on(32, v19, v16 + 184);
}
