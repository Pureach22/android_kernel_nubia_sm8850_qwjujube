__int64 icnss_wpss_self_recovery()
{
  __int64 v0; // x21
  __int64 result; // x0
  int v2; // w20

  v0 = penv;
  rproc_shutdown(*(_QWORD *)(penv + 3264));
  result = rproc_boot(*(_QWORD *)(v0 + 3264));
  if ( (_DWORD)result )
  {
    v2 = result;
    printk("%sicnss2: Failed to self recover wpss rproc, ret: %d", byte_130B32, result);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Failed to self recover wpss rproc, ret: %d",
      (const char *)&unk_12DBF3,
      v2);
    return rproc_put(*(_QWORD *)(v0 + 3264));
  }
  return result;
}
