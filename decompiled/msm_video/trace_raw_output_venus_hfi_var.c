__int64 __fastcall trace_raw_output_venus_hfi_var(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "TZBSP_MEM_PROTECT_VIDEO_VAR done, cp_start : 0x%x, cp_size : 0x%x, cp_nonpixel_start : 0x%x, cp_nonpixel_size : 0x%x\n\n",
      v1[2],
      v1[3],
      v1[4],
      v1[5]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
