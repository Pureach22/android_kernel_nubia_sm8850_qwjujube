__int64 __fastcall icnss_get_mhi_state(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 560) )
      return readl();
    else
      return 4294967284LL;
  }
  else
  {
    printk("%sicnss2: Platform driver not initialized\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Platform driver not initialized\n", (const char *)&unk_12DBF3);
    return 4294967274LL;
  }
}
