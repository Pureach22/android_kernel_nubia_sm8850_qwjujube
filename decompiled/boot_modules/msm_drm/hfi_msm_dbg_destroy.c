__int64 hfi_msm_dbg_destroy()
{
  __int64 result; // x0

  if ( hfi_dbg )
  {
    hfi_adapter_buffer_dealloc(hfi_dbg + 40);
    hfi_adapter_buffer_dealloc(hfi_dbg + 96);
    hfi_adapter_buffer_dealloc(hfi_dbg + 152);
    hfi_adapter_buffer_dealloc(hfi_dbg + 208);
    kfree(*(_QWORD *)(hfi_dbg + 24));
    return kfree(hfi_dbg);
  }
  return result;
}
