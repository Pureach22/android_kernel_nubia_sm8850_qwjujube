__int64 __fastcall ipa3_dma_shutdown(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa_dma %s:%d ENTRY\n", "ipa3_dma_shutdown", 172);
  }
  result = ipa_dma_init_refcnt_ctrl;
  if ( ipa_dma_init_refcnt_ctrl )
  {
    v4 = kfree(ipa_dma_init_refcnt_ctrl);
    ipa_dma_init_refcnt_ctrl = 0;
    result = ipa3_get_ipc_logbuf_low(v4);
    if ( result )
    {
      v5 = ipa3_get_ipc_logbuf_low(result);
      return ipc_log_string(v5, "ipa_dma %s:%d EXIT\n", "ipa3_dma_shutdown", 180);
    }
  }
  return result;
}
