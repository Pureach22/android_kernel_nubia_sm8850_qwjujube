__int64 __fastcall cnss_pci_get_wake_msi(_QWORD *a1)
{
  __int64 v1; // x0
  __int64 v2; // x6
  __int64 v3; // x7
  unsigned __int64 StatusReg; // x8
  const char *v5; // x1
  __int64 result; // x0
  __int16 v7; // w9
  const char *v8; // x8
  char v9; // [xsp+0h] [xbp-20h]
  _BYTE v10[4]; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v11; // [xsp+10h] [xbp-10h] BYREF
  int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *a1 + 200LL;
    v12 = 0;
    v11 = 0;
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, const char *, int *, unsigned int *, _BYTE *))cnss_get_user_msi_assignment)(
                         v1,
                         "WAKE",
                         &v12,
                         &v11,
                         v10) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v5 = "irq";
      }
      else
      {
        v7 = *(_DWORD *)(StatusReg + 16);
        v8 = (const char *)(StatusReg + 2320);
        if ( (v7 & 0xFF00) != 0 )
          v5 = "soft_irq";
        else
          v5 = v8;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v5,
        "cnss_pci_get_wake_msi",
        3u,
        3u,
        "WAKE MSI is not valid\n",
        v2,
        v3,
        v9);
      result = 0;
    }
    else
    {
      result = v11;
    }
  }
  else
  {
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
