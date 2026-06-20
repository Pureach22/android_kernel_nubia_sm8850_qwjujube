__int64 __fastcall icnss_idle_shutdown(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = a1[19];
  if ( v1 )
  {
    *(_DWORD *)(v1 + 3276) = 1;
    if ( (*(_BYTE *)(v1 + 3250) & 1) != 0
      || (*(_QWORD *)(v1 + 1832) & 0x40000) != 0
      || (*(_QWORD *)(v1 + 1832) & 0x8000) != 0
      || *(_DWORD *)(v1 + 3272) )
    {
      printk("%sicnss2: SSR/PDR/Shutdown is already in-progress during idle shutdown\n", byte_130B32);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: SSR/PDR/Shutdown is already in-progress during idle shutdown\n",
        (const char *)&unk_12DBF3);
      *(_DWORD *)(v1 + 3276) = 0;
      return 4294967280LL;
    }
    else
    {
      result = icnss_driver_event_post(v1, 7u, 3, 0);
      *(_DWORD *)(v1 + 3276) = 0;
    }
  }
  else
  {
    printk("%sicnss2: Invalid drvdata: dev %pK", byte_130B32, a1);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid drvdata: dev %pK", (const char *)&unk_12DBF3, a1);
    return 4294967274LL;
  }
  return result;
}
