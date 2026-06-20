__int64 __fastcall ipa3_dma_work_pending(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v2; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x0

  if ( *(_DWORD *)(ipa3_dma_ctx + 176) )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf(a1);
    if ( ipc_logbuf )
    {
      v2 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v2, "ipa_dma %s:%d pending sync\n", "ipa3_dma_work_pending", 438);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v4 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v4, "ipa_dma %s:%d pending sync\n", "ipa3_dma_work_pending", 438);
    }
    return 1;
  }
  if ( *(_DWORD *)(ipa3_dma_ctx + 180) )
  {
    v5 = ipa3_get_ipc_logbuf(a1);
    if ( v5 )
    {
      v6 = ipa3_get_ipc_logbuf(v5);
      v5 = ipc_log_string(v6, "ipa_dma %s:%d pending async\n", "ipa3_dma_work_pending", 442);
    }
    v7 = ipa3_get_ipc_logbuf_low(v5);
    if ( v7 )
    {
      v8 = ipa3_get_ipc_logbuf_low(v7);
      ipc_log_string(v8, "ipa_dma %s:%d pending async\n", "ipa3_dma_work_pending", 442);
    }
    return 1;
  }
  if ( *(_DWORD *)(ipa3_dma_ctx + 184) )
  {
    v9 = ipa3_get_ipc_logbuf(a1);
    if ( v9 )
    {
      v10 = ipa3_get_ipc_logbuf(v9);
      v9 = ipc_log_string(v10, "ipa_dma %s:%d pending uc\n", "ipa3_dma_work_pending", 446);
    }
    v11 = ipa3_get_ipc_logbuf_low(v9);
    if ( v11 )
    {
      v12 = ipa3_get_ipc_logbuf_low(v11);
      ipc_log_string(v12, "ipa_dma %s:%d pending uc\n", "ipa3_dma_work_pending", 446);
    }
    return 1;
  }
  result = ipa3_get_ipc_logbuf_low(a1);
  if ( result )
  {
    v14 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(v14, "ipa_dma %s:%d no pending work\n", "ipa3_dma_work_pending", 449);
    return 0;
  }
  return result;
}
