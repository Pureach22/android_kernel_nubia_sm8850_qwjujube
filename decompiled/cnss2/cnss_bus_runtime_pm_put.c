__int64 __fastcall cnss_bus_runtime_pm_put(__int64 result)
{
  int v1; // w6
  unsigned __int64 StatusReg; // x8
  const char *v3; // x1
  __int64 v4; // x19
  __int16 v5; // w9
  const char *v6; // x8

  if ( result )
  {
    v1 = *(_DWORD *)(result + 16);
    if ( v1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v3 = "irq";
      }
      else
      {
        v5 = *(_DWORD *)(StatusReg + 16);
        v6 = (const char *)(StatusReg + 2320);
        if ( (v5 & 0xFF00) != 0 )
          v3 = "soft_irq";
        else
          v3 = v6;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v3,
               "cnss_bus_runtime_pm_put",
               3,
               3,
               "Unsupported bus type: %d\n",
               v1);
    }
    else
    {
      v4 = result;
      cnss_pci_pm_runtime_mark_last_busy(*(_QWORD *)(result + 8));
      return cnss_pci_pm_runtime_put_autosuspend(*(_QWORD *)(v4 + 8), 0);
    }
  }
  return result;
}
