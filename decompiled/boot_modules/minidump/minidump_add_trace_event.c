char *__fastcall minidump_add_trace_event(char *src, unsigned __int64 a2)
{
  __int64 v2; // x8
  char *v3; // x19
  __int64 v4; // x9
  unsigned __int64 v5; // x23
  __int64 v6; // x20
  unsigned __int64 v7; // x21

  v2 = md_ftrace_buf_addr;
  if ( a2 <= 0x200000 && md_ftrace_buf_addr )
  {
    v3 = src;
    v4 = md_ftrace_buf_current;
    if ( md_ftrace_buf_current + a2 <= 0x200000 )
    {
      v6 = 0;
    }
    else
    {
      v5 = a2;
      v6 = 0x200000 - md_ftrace_buf_current;
      memcpy((void *)(md_ftrace_buf_addr + md_ftrace_buf_current), src, 0x200000 - md_ftrace_buf_current);
      v2 = md_ftrace_buf_addr;
      a2 = v5;
      v4 = 0;
      md_ftrace_buf_current = 0;
    }
    v7 = a2 - v6;
    src = (char *)memcpy((void *)(v2 + v4), &v3[v6], a2 - v6);
    md_ftrace_buf_current += v7;
  }
  return src;
}
