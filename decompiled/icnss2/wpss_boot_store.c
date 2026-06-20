__int64 __fastcall wpss_boot_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  const char *v6; // x2
  __int64 v7; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  if ( (*(_BYTE *)(v5 + 5968) & 1) != 0 || *(_BYTE *)(v5 + 6112) == 1 )
  {
    if ( sscanf(s, "%du", &v9) == 1 )
    {
      if ( v9 )
        v6 = "GET";
      else
        v6 = "PUT";
      ipc_log_string(icnss_ipc_log_context, "icnss2: WPSS Remote Processor: %s", v6);
      if ( v9 )
      {
        if ( v9 == 1 )
          queue_work_on(32, system_wq, &wpss_loader);
      }
      else if ( v5 )
      {
        mutex_lock(v5 + 5592);
        v7 = *(_QWORD *)(v5 + 3264);
        if ( v7 )
        {
          rproc_shutdown(v7);
          rproc_put(*(_QWORD *)(v5 + 3264));
          *(_QWORD *)(v5 + 3264) = 0;
        }
        mutex_unlock(v5 + 5592);
      }
    }
    else
    {
      printk("%sicnss2: Failed to read wpss rproc info", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to read wpss rproc info", (const char *)&unk_12DBF3);
      a4 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
