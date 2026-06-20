__int64 __fastcall cnss_pci_add_fw_prefix_name(__int64 result, __int64 a2, const char *a3)
{
  unsigned int v4; // w8
  __int64 v5; // x7
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  char v10; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    if ( *(_BYTE *)(*(_QWORD *)(result + 8) + 6514LL) )
    {
      v4 = *(_DWORD *)(result + 24) - 4353;
      if ( v4 > 0x11 )
        scnprintf(a2, 40, "%s", a3);
      else
        scnprintf(a2, 40, off_5BAD0[v4], a3);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v7 = "irq";
      }
      else
      {
        v8 = *(_DWORD *)(StatusReg + 16);
        v9 = (const char *)(StatusReg + 2320);
        if ( (v8 & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = v9;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v7,
               "cnss_pci_add_fw_prefix_name",
               7u,
               7u,
               "FW name added with prefix: %s\n",
               a2,
               v5,
               v10);
    }
    else
    {
      return scnprintf(a2, 40, "%s", a3);
    }
  }
  return result;
}
