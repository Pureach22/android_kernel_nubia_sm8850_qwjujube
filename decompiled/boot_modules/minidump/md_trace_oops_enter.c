void __fastcall md_trace_oops_enter(__int64 a1, char *a2)
{
  char v2; // w8

  v2 = 1;
  if ( (minidump_ftrace_in_oops & 1) == 0 )
  {
    minidump_ftrace_in_oops = 1;
    v2 = 0;
  }
  *a2 = v2;
}
