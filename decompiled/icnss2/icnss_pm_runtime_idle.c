__int64 __fastcall icnss_pm_runtime_idle(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 304) == 43981 )
    {
      printk("%sicnss2: Ignore runtime idle\n", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Ignore runtime idle\n", (const char *)&unk_12DBF3);
    }
    else
    {
      ipc_log_string(icnss_ipc_log_long_context, "icnss2: Runtime idle\n");
      _pm_runtime_suspend(a1, 9);
    }
    return 4294967280LL;
  }
  else
  {
    printk("%sicnss2: icnss priv is NULL\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: icnss priv is NULL\n", (const char *)&unk_12DBF3);
    return 4294967284LL;
  }
}
