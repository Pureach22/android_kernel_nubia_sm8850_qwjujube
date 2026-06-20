__int64 md_trace_oops_exit()
{
  __int64 result; // x0

  result = minidump_add_trace_event("==END==");
  minidump_ftrace_in_oops = 0;
  return result;
}
