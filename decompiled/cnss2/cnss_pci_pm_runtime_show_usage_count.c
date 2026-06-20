__int64 __fastcall cnss_pci_pm_runtime_show_usage_count(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  unsigned __int64 StatusReg; // x9
  const char *v10; // x1
  __int16 v11; // w10
  const char *v12; // x9

  if ( result )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v12;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v10,
             "cnss_pci_pm_runtime_show_usage_count",
             7u,
             7u,
             "Runtime PM usage count: %d\n",
             *(unsigned int *)(*(_QWORD *)result + 680LL),
             a8,
             v8);
  }
  return result;
}
