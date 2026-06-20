__int64 __fastcall ipa3_dma_async_memcpy_notify_cb(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x20
  _QWORD *v3; // x21
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  unsigned int ep_mapping; // w0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x0
  _QWORD *v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x0
  void (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 ipc_logbuf; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int v28; // w9
  unsigned int v31; // w10

  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa_dma %s:%d ENTRY\n", "ipa3_dma_async_memcpy_notify_cb", 1100);
  }
  ep_mapping = ipa_get_ep_mapping(47);
  if ( (ep_mapping & 0x80000000) != 0 )
  {
    v18 = printk(&unk_3F7D17, "ipa3_dma_async_memcpy_notify_cb");
    ipc_logbuf = ipa3_get_ipc_logbuf(v18);
    if ( ipc_logbuf )
    {
      v20 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v20,
                     "ipa_dma %s:%d IPA Client mapping failed\n",
                     "ipa3_dma_async_memcpy_notify_cb",
                     1104);
    }
    result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( result )
    {
      v21 = ipa3_get_ipc_logbuf_low(result);
      return ipc_log_string(v21, "ipa_dma %s:%d IPA Client mapping failed\n", "ipa3_dma_async_memcpy_notify_cb", 1104);
    }
  }
  else
  {
    if ( ep_mapping >= 0x24 )
    {
      __break(0x5512u);
    }
    else
    {
      v3 = &unk_1FD000;
      v8 = *(_QWORD *)(ipa3_ctx + 480LL * ep_mapping + 640);
      v9 = raw_spin_lock_irqsave(ipa3_dma_ctx + 64);
      v1 = *(_QWORD **)(v8 + 1632);
      v10 = (_QWORD *)v1[1];
      v11 = v9;
      if ( (_QWORD *)*v10 == v1 && (v12 = *v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        *(_QWORD *)(v12 + 8) = v10;
        *v10 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(v8 + 1632));
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      --*(_DWORD *)v8;
      v2 = v1 - 3;
      raw_spin_unlock_irqrestore(ipa3_dma_ctx + 64, v11);
      v7 = ipa3_dma_ctx;
    }
    _X8 = (unsigned int *)(v7 + 192);
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 + 1, _X8) );
    _X8 = (unsigned int *)(v3[397] + 180LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 - 1, _X8) );
    v14 = (void (__fastcall *)(_QWORD))v1[6];
    v13 = v1[7];
    if ( *((_DWORD *)v14 - 1) != 251140989 )
      __break(0x8228u);
    v14(v13);
    v15 = kmem_cache_free(*(_QWORD *)(v3[397] + 8LL), v2);
    if ( *(_BYTE *)(v3[397] + 4LL) == 1 )
    {
      v15 = ipa3_dma_work_pending(v15);
      if ( (v15 & 1) == 0 )
        v15 = complete(v3[397] + 128LL);
    }
    result = ipa3_get_ipc_logbuf_low(v15);
    if ( result )
    {
      v17 = ipa3_get_ipc_logbuf_low(result);
      return ipc_log_string(v17, "ipa_dma %s:%d EXIT\n", "ipa3_dma_async_memcpy_notify_cb", 1125);
    }
  }
  return result;
}
