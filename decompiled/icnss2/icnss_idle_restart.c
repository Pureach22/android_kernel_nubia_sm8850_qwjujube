__int64 __fastcall icnss_idle_restart(_QWORD *a1)
{
  __int64 v2; // x0

  v2 = a1[19];
  if ( v2 )
  {
    if ( (*(_BYTE *)(v2 + 3250) & 1) != 0
      || (*(_QWORD *)(v2 + 1832) & 0x40000) != 0
      || (*(_QWORD *)(v2 + 1832) & 0x8000) != 0 )
    {
      printk("%sicnss2: SSR/PDR is already in-progress during idle restart\n", byte_130B32);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: SSR/PDR is already in-progress during idle restart\n",
        (const char *)&unk_12DBF3);
      return 4294967280LL;
    }
    else
    {
      return icnss_driver_event_post(v2, 8u, 3, 0);
    }
  }
  else
  {
    printk("%sicnss2: Invalid drvdata: dev %pK", byte_130B32, a1);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid drvdata: dev %pK", (const char *)&unk_12DBF3, a1);
    return 4294967274LL;
  }
}
