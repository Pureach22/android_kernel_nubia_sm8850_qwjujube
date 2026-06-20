__int64 __fastcall icnss_reboot_notifier(__int64 a1)
{
  __int64 v3; // x0
  __int64 v4; // x8

  if ( *(_DWORD *)(a1 + 400) )
    return 0;
  printk("%sicnss2: Received Reboot indication", byte_13289B);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Received Reboot indication", (const char *)&unk_12DBF3);
  *(_DWORD *)(a1 + 400) = 1;
  if ( a1 != 2872 )
  {
    mutex_lock(a1 + 2720);
    v3 = *(_QWORD *)(a1 + 392);
    v4 = a1;
    if ( v3 )
    {
      rproc_shutdown(v3);
      rproc_put(*(_QWORD *)(a1 + 392));
      v4 = a1;
      *(_QWORD *)(a1 + 392) = 0;
    }
    mutex_unlock(v4 + 2720);
  }
  return 0;
}
