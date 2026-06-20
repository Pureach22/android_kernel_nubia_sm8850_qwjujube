__int64 __fastcall cnss_pci_call_driver_remove(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x19
  unsigned int v9; // w8
  __int64 *v10; // x20
  __int64 v11; // x8
  __int64 v12; // x0
  unsigned int (__fastcall *v13)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v17; // w9
  const char *v18; // x8
  unsigned __int64 v19; // x8
  const char *v20; // x1
  __int64 v21; // x8
  __int64 v22; // x0
  void (__fastcall *v23)(_QWORD); // x8
  __int64 *v24; // x20
  __int64 v25; // x0
  void (__fastcall *v26)(_QWORD); // x8
  __int16 v27; // w9
  const char *v28; // x8
  unsigned __int64 v31; // x10
  unsigned __int64 v38; // x10
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v8 = (_QWORD *)a1[1];
  if ( (v8[69] & 8) != 0 || (v8[69] & 0x400) != 0 || (v8[69] & 0x1000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_pci_call_driver_remove",
      7u,
      7u,
      "Skip driver remove\n",
      a7,
      a8,
      vars0);
    return 0;
  }
  else
  {
    if ( a1[5] )
    {
      v9 = *((_DWORD *)a1 + 6) - 4353;
      if ( v9 <= 0x11 && ((1 << v9) & 0x32245) != 0 )
      {
        v10 = a1;
        cancel_delayed_work_sync(a1 + 61);
        a1 = v10;
      }
      if ( (v8[69] & 0x200) != 0 && (v8[69] & 0x100) != 0 )
      {
        v24 = a1;
        complete(v8 + 827);
        v25 = *v24;
        v26 = *(void (__fastcall **)(_QWORD))(v24[5] + 48);
        if ( *((_DWORD *)v26 - 1) != -1303601879 )
          __break(0x8228u);
        v26(v25);
      }
      else if ( (v8[69] & 0x20) != 0 )
      {
        v21 = a1[5];
        v22 = *a1;
        v23 = *(void (__fastcall **)(_QWORD))(v21 + 16);
        if ( *((_DWORD *)v23 - 1) != -1303601879 )
          __break(0x8228u);
        v23(v22);
        _X8 = v8 + 69;
        __asm { PRFM            #0x11, [X8] }
        do
          v31 = __ldxr(_X8);
        while ( __stxr(v31 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
      }
      else if ( (v8[69] & 0x80) != 0 )
      {
        v11 = a1[5];
        v12 = *a1;
        v13 = *(unsigned int (__fastcall **)(_QWORD))(v11 + 32);
        if ( *((_DWORD *)v13 - 1) != -55329153 )
          __break(0x8228u);
        if ( v13(v12) == -11 )
        {
          _X8 = v8 + 69;
          __asm { PRFM            #0x11, [X8] }
          do
            v38 = __ldxr(_X8);
          while ( __stxr(v38 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
          return 4294967285LL;
        }
      }
      v8[935] = 0;
      v8[934] = 0;
      v8[933] = 0;
      v8[932] = 0;
      return 0;
    }
    v19 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(v19 + 16);
      v28 = (const char *)(v19 + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v20 = "soft_irq";
      else
        v20 = v28;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v20,
      "cnss_pci_call_driver_remove",
      3u,
      3u,
      "driver_ops is NULL\n",
      a7,
      a8,
      vars0);
    return 4294967274LL;
  }
}
