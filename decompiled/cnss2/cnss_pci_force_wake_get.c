__int64 __fastcall cnss_pci_force_wake_get(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x23
  __int64 v9; // x8
  int v10; // w9
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned int sync_atomic; // w19
  unsigned int v15; // w9
  bool v16; // cc
  int v17; // w9
  __int64 v19; // x8
  unsigned __int64 v20; // x8
  const char *v21; // x1
  unsigned __int64 StatusReg; // x8
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  __int16 v27; // w9
  const char *v28; // x8
  char v29; // [xsp+0h] [xbp+0h]

  v8 = *a1;
  v9 = *(_QWORD *)(*a1 + 352);
  if ( !v9 )
    goto LABEL_21;
  v10 = *(_DWORD *)(v9 + 24);
  if ( (unsigned int)(v10 - 4353) > 0x11 || ((1 << (v10 - 1)) & 0x32245) == 0 )
    goto LABEL_13;
  v12 = *(_QWORD *)(v9 + 344);
  if ( !v12 )
  {
    sync_atomic = -22;
    goto LABEL_23;
  }
  v13 = *(_QWORD *)(v9 + 8);
  if ( !v13 )
  {
LABEL_21:
    sync_atomic = -19;
LABEL_23:
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v23 = "irq";
    }
    else
    {
      v24 = *(_DWORD *)(StatusReg + 16);
      v25 = (const char *)(StatusReg + 2320);
      if ( (v24 & 0xFF00) != 0 )
        v23 = "soft_irq";
      else
        v23 = v25;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v23,
      "cnss_pci_force_wake_get",
      3u,
      3u,
      "Failed to request force wake\n",
      a7,
      a8,
      v29);
    return sync_atomic;
  }
  if ( (*(_QWORD *)(v13 + 552) & 0x800) != 0 )
    return (unsigned int)-11;
  sync_atomic = mhi_device_get_sync_atomic(*(_QWORD *)(v12 + 16), 60000, 0);
  if ( sync_atomic != -11 )
  {
    if ( !sync_atomic )
    {
      v9 = *(_QWORD *)(v8 + 352);
      if ( !v9 )
      {
LABEL_19:
        v20 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
        {
          v21 = "irq";
        }
        else
        {
          v27 = *(_DWORD *)(v20 + 16);
          v28 = (const char *)(v20 + 2320);
          if ( (v27 & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = v28;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v21,
          "cnss_pci_force_wake_get",
          4u,
          4u,
          "MHI not in M0, while reg still accessible\n",
          a7,
          a8,
          v29);
        return 0;
      }
      v10 = *(_DWORD *)(v9 + 24);
LABEL_13:
      v15 = v10 - 4353;
      v16 = v15 > 0x11;
      v17 = (1 << v15) & 0x32245;
      if ( !v16 && v17 != 0 )
      {
        v19 = *(_QWORD *)(v9 + 344);
        if ( v19 )
        {
          if ( *(_DWORD *)(v19 + 348) == 2 )
            return 0;
        }
      }
      goto LABEL_19;
    }
    goto LABEL_23;
  }
  return sync_atomic;
}
