__int64 __fastcall reg_debug_suspend_enable_set(__int64 a1, __int64 a2)
{
  int v2; // w21
  __int64 result; // x0
  unsigned int v4; // w19

  v2 = a2 != 0;
  if ( (unsigned __int8)debug_suspend == v2 )
    return 0;
  if ( !a2 )
  {
    result = tracepoint_probe_unregister(&_tracepoint_suspend_resume, regulator_debug_suspend_trace_probe, 0);
    if ( !(_DWORD)result )
      goto LABEL_5;
LABEL_8:
    v4 = result;
    printk(&unk_7F58, "reg_debug_suspend_enable_set");
    return v4;
  }
  result = tracepoint_probe_register(&_tracepoint_suspend_resume, regulator_debug_suspend_trace_probe, 0);
  if ( (_DWORD)result )
    goto LABEL_8;
LABEL_5:
  debug_suspend = v2;
  return result;
}
