__int64 __fastcall cnss_pci_resume_early(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v4; // x7
  unsigned int v5; // w19
  unsigned __int64 StatusReg; // x9
  const char *v7; // x1
  __int16 v8; // w8
  const char *v9; // x9
  char v10; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 0;
  v2 = *(_QWORD *)(v1 + 8);
  if ( (cnss_is_device_powered_on(v2) & 1) != 0 || *(_BYTE *)(v2 + 7880) != 1 )
    return 0;
  result = cnss_power_on_device(v2, 0);
  if ( (_DWORD)result )
  {
    v5 = result;
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
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v7,
      "cnss_pci_resume_early",
      3u,
      3u,
      "Failed to power on device, err = %d\n",
      (unsigned int)result,
      v4,
      v10);
    return v5;
  }
  return result;
}
