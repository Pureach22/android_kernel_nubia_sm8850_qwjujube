__int64 __fastcall md_dump_trace_buf(int a1, void *src, _BYTE *a3)
{
  __int64 result; // x0

  if ( minidump_ftrace_in_oops == 1 )
  {
    result = minidump_add_trace_event(src);
    *a3 = 0;
  }
  return result;
}
