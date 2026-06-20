__int64 __fastcall trace_raw_output_msm_vidc_buffer_dma_ops(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s: dmabuf %pK, size %d, kvaddr %pK, buffer_type %s, secure %d, region %d\n\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(const void **)(v1 + 16),
      *(unsigned __int8 *)(v1 + 24),
      *(const void **)(v1 + 32),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 40)),
      *(unsigned __int8 *)(v1 + 44),
      *(_DWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
