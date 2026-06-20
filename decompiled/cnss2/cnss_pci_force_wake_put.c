__int64 __fastcall cnss_pci_force_wake_put(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  unsigned int v9; // w9
  bool v10; // cc
  int v11; // w9
  __int64 v13; // x9
  __int64 v14; // x8
  unsigned __int64 StatusReg; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(*(_QWORD *)result + 352LL);
  if ( !v8 )
  {
LABEL_10:
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v18;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v16,
             "cnss_pci_force_wake_put",
             3u,
             3u,
             "Failed to release force wake\n",
             a7,
             a8,
             vars0);
  }
  v9 = *(_DWORD *)(v8 + 24) - 4353;
  v10 = v9 > 0x11;
  v11 = (1 << v9) & 0x32245;
  if ( !v10 && v11 != 0 )
  {
    v13 = *(_QWORD *)(v8 + 344);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v8 + 8);
      if ( v14 )
      {
        if ( (*(_QWORD *)(v14 + 552) & 0x800) == 0 )
          return mhi_device_put(*(_QWORD *)(v13 + 16));
        return result;
      }
    }
    goto LABEL_10;
  }
  return result;
}
