__int64 __fastcall cnss_bus_fw_boot_timeout_hdlr(__int64 result)
{
  int v1; // w6
  unsigned __int64 StatusReg; // x8
  const char *v3; // x1
  __int16 v4; // w9
  const char *v5; // x8

  if ( result != 6272 )
  {
    v1 = *(_DWORD *)(result - 6256);
    if ( v1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v3 = "irq";
      }
      else
      {
        v4 = *(_DWORD *)(StatusReg + 16);
        v5 = (const char *)(StatusReg + 2320);
        if ( (v4 & 0xFF00) != 0 )
          v3 = "soft_irq";
        else
          v3 = v5;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v3,
               "cnss_bus_fw_boot_timeout_hdlr",
               3,
               3,
               "Unsupported bus type: %d\n",
               v1);
    }
    else
    {
      return cnss_pci_fw_boot_timeout_hdlr(*(_QWORD *)(result - 6264));
    }
  }
  return result;
}
