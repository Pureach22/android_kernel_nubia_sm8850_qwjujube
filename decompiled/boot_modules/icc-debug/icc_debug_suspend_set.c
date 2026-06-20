__int64 __fastcall icc_debug_suspend_set(__int64 a1, __int64 a2)
{
  int v2; // w21
  __int64 result; // x0
  bool v5; // zf
  unsigned int v6; // w19
  const char *v7; // x2

  v2 = a2 != 0;
  if ( (unsigned __int8)debug_suspend == v2 )
    return 0;
  if ( a2 )
  {
    result = tracepoint_probe_register(&_tracepoint_suspend_resume, icc_debug_suspend_trace_probe, 0);
    if ( !(_DWORD)result )
    {
LABEL_5:
      debug_suspend = v2;
      return result;
    }
  }
  else
  {
    result = tracepoint_probe_unregister(&_tracepoint_suspend_resume, icc_debug_suspend_trace_probe, 0);
    if ( !(_DWORD)result )
      goto LABEL_5;
  }
  v5 = a2 == 0;
  v6 = result;
  if ( v5 )
    v7 = "un";
  else
    v7 = (const char *)&unk_65FE;
  printk(&unk_667F, "icc_debug_suspend_set", v7, (unsigned int)result);
  return v6;
}
