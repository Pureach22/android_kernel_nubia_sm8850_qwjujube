__int64 __fastcall cnss_pci_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v5; // x6
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  __int64 v11; // x9
  __int64 (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  __int64 v14; // x7
  unsigned int v15; // w21
  unsigned __int64 v16; // x9
  const char *v17; // x1
  unsigned int v18; // w21
  __int16 v19; // w8
  const char *v20; // x9
  unsigned __int64 v27; // x10
  char v28; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 0;
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 || *(_BYTE *)(v1 + 49) )
    return 0;
  if ( *(_BYTE *)(v2 + 7880) == 1 )
  {
    *(_BYTE *)(v1 + 48) = 1;
    return 0;
  }
  if ( (cnss_is_device_powered_on(*(_QWORD *)(v1 + 8)) & 1) == 0 )
    return 0;
  if ( (*(_QWORD *)(v2 + 528) == 4369 || of_find_property(*(_QWORD *)(*(_QWORD *)v2 + 760LL), "fig-direct-cx", 0))
    && (cnss_set_cxpc(a1, 0) & 0x80000000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v10;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_pci_resume",
      3u,
      3u,
      "failed to set cx to CX_RET\n",
      v5,
      v6,
      v28);
  }
  if ( *(_BYTE *)(v1 + 592)
    || (mutex_lock(v1 + 600), v18 = cnss_pci_resume_bus(v1), mutex_unlock(v1 + 600), (result = v18) == 0) )
  {
    result = 0;
    v11 = *(_QWORD *)(v1 + 40);
    if ( (*(_QWORD *)(*(_QWORD *)(v1 + 8) + 552LL) & 0x4000000) != 0 && v11 )
    {
      v12 = *(__int64 (__fastcall **)(_QWORD))(v11 + 72);
      if ( v12 )
      {
        v13 = *(_QWORD *)v1;
        if ( *((_DWORD *)v12 - 1) != -55329153 )
          __break(0x8229u);
        result = v12(v13);
        if ( (_DWORD)result )
        {
          v15 = result;
          v16 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
          {
            v17 = "irq";
          }
          else
          {
            v19 = *(_DWORD *)(v16 + 16);
            v20 = (const char *)(v16 + 2320);
            if ( (v19 & 0xFF00) != 0 )
              v17 = "soft_irq";
            else
              v17 = v20;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v17,
            "cnss_pci_resume_driver",
            3u,
            3u,
            "Failed to resume host driver, err = %d\n",
            (unsigned int)result,
            v14,
            v28);
          result = v15;
        }
      }
      else
      {
        result = 0;
      }
    }
    *(_BYTE *)(v1 + 232) = 0;
    _X8 = (unsigned __int64 *)(v2 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
  }
  return result;
}
