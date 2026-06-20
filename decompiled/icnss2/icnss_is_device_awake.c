__int64 __fastcall icnss_is_device_awake(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    ipc_log_string(icnss_ipc_log_smp2p_context, "icnss2: SOC wake ref_count: %d\n", *(_DWORD *)(v1 + 5488));
    return *(unsigned int *)(v1 + 5488);
  }
  else
  {
    printk("%sicnss2: Platform driver not initialized\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Platform driver not initialized\n", (const char *)&unk_12DBF3);
    return 4294967274LL;
  }
}
