void ipahal_fltrt_destroy()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x2

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d Entry\n", "ipahal_fltrt_destroy", 4759);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_fltrt_destroy", 4759);
  }
  if ( ipahal_ctx )
  {
    v2 = *(_QWORD *)(ipahal_ctx + 40);
    if ( v2 )
      dma_free_attrs(
        *(_QWORD *)(ipahal_ctx + 32),
        *(unsigned int *)(ipahal_ctx + 56),
        v2,
        *(_QWORD *)(ipahal_ctx + 48),
        0);
  }
}
