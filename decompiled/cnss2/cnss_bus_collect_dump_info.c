__int64 __fastcall cnss_bus_collect_dump_info(__int64 result, char a2)
{
  int v2; // w6
  unsigned __int64 StatusReg; // x8
  const char *v4; // x1
  __int16 v5; // w9
  const char *v6; // x8

  if ( result )
  {
    v2 = *(_DWORD *)(result + 16);
    if ( v2 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v4 = "irq";
      }
      else
      {
        v5 = *(_DWORD *)(StatusReg + 16);
        v6 = (const char *)(StatusReg + 2320);
        if ( (v5 & 0xFF00) != 0 )
          v4 = "soft_irq";
        else
          v4 = v6;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v4,
        "cnss_bus_collect_dump_info",
        3,
        3,
        "Unsupported bus type: %d\n",
        v2);
      return 0;
    }
    else
    {
      return cnss_pci_collect_dump_info(*(_QWORD *)(result + 8), a2 & 1);
    }
  }
  return result;
}
