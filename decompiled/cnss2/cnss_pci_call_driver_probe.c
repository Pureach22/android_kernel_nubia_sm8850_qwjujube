__int64 __fastcall cnss_pci_call_driver_probe(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  _QWORD *v9; // x8
  _QWORD *v10; // x19
  __int64 v11; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x0
  const char *v15; // x1
  unsigned __int64 v16; // x8
  __int64 v17; // x0
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  const char *v21; // x5
  unsigned __int64 v22; // x8
  __int16 v23; // w9
  const char *v24; // x8
  const char *v25; // x2
  const char *v26; // x5
  __int64 (__fastcall *v27)(__int64, __int64); // x9
  __int64 v28; // x1
  __int64 v29; // x0
  unsigned int v30; // w0
  __int64 v31; // x7
  unsigned __int64 v32; // x9
  unsigned int v33; // w19
  const char *v34; // x1
  __int64 (__fastcall *v35)(__int64, __int64); // x9
  __int64 v36; // x1
  __int64 v37; // x0
  unsigned int v38; // w0
  __int64 v39; // x7
  unsigned __int64 v40; // x9
  unsigned int v41; // w19
  const char *v42; // x1
  __int16 v43; // w9
  const char *v44; // x8
  __int64 (__fastcall *v45)(__int64, __int64); // x9
  __int64 v46; // x1
  __int64 v47; // x0
  unsigned int v48; // w0
  __int64 v49; // x7
  unsigned __int64 v50; // x9
  const char *v51; // x1
  __int16 v52; // w8
  const char *v53; // x9
  unsigned int v54; // w8
  unsigned __int64 v55; // x8
  __int16 v56; // w9
  const char *v57; // x8
  __int16 v58; // w8
  const char *v59; // x9
  __int16 v60; // w8
  const char *v61; // x9
  unsigned __int64 v68; // x10
  unsigned __int64 v71; // x10
  unsigned __int64 v74; // x10
  unsigned __int64 v77; // x9
  unsigned __int64 v80; // x10
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v8 = a1[1];
  if ( (*(_QWORD *)(v8 + 552) & 0x10000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(StatusReg + 16);
      v20 = (const char *)(StatusReg + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v20;
    }
    v21 = "Reboot is in progress, skip driver probe\n";
    goto LABEL_20;
  }
  if ( (*(_QWORD *)(v8 + 552) & 0x1000) != 0 )
  {
    _X8 = (unsigned __int64 *)(v8 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v68 = __ldxr(_X8);
    while ( __stxr(v68 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
    v16 = _ReadStatusReg(SP_EL0);
    v17 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v23 = *(_DWORD *)(v16 + 16);
      v24 = (const char *)(v16 + 2320);
      if ( (v23 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v24;
    }
    v25 = "cnss_pci_call_driver_probe";
    v26 = "Skip driver probe\n";
    goto LABEL_27;
  }
  v9 = (_QWORD *)a1[5];
  if ( !v9 )
  {
    v22 = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v43 = *(_DWORD *)(v22 + 16);
      v44 = (const char *)(v22 + 2320);
      if ( (v43 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v44;
    }
    v21 = "driver_ops is NULL\n";
LABEL_20:
    cnss_debug_ipc_log_print(v14, v15, "cnss_pci_call_driver_probe", 3u, 3u, v21, a7, a8, vars0);
    return 4294967274LL;
  }
  if ( (*(_QWORD *)(v8 + 552) & 0x200) != 0 && (*(_QWORD *)(v8 + 552) & 0x100) != 0 )
  {
    v35 = (__int64 (__fastcall *)(__int64, __int64))v9[5];
    v10 = a1;
    v36 = a1[2];
    v37 = *a1;
    if ( *((_DWORD *)v35 - 1) != -2038225168 )
      __break(0x8229u);
    v38 = v35(v37, v36);
    if ( v38 )
    {
      v40 = _ReadStatusReg(SP_EL0);
      v41 = v38;
      if ( (*(_DWORD *)(v40 + 16) & 0xF0000) != 0 )
      {
        v42 = "irq";
      }
      else
      {
        v58 = *(_DWORD *)(v40 + 16);
        v59 = (const char *)(v40 + 2320);
        if ( (v58 & 0xFF00) != 0 )
          v42 = "soft_irq";
        else
          v42 = v59;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v42,
        "cnss_pci_call_driver_probe",
        3u,
        3u,
        "Failed to reinit host driver, err = %d\n",
        v38,
        v39,
        vars0);
      return v41;
    }
    v11 = 6648;
    goto LABEL_51;
  }
  if ( (*(_QWORD *)(v8 + 552) & 0x10) != 0 )
  {
    v27 = (__int64 (__fastcall *)(__int64, __int64))v9[1];
    v10 = a1;
    v28 = a1[2];
    v29 = *a1;
    if ( *((_DWORD *)v27 - 1) != -2038225168 )
      __break(0x8229u);
    v30 = v27(v29, v28);
    if ( v30 )
    {
      v32 = _ReadStatusReg(SP_EL0);
      v33 = v30;
      if ( (*(_DWORD *)(v32 + 16) & 0xF0000) != 0 )
      {
        v34 = "irq";
      }
      else
      {
        v52 = *(_DWORD *)(v32 + 16);
        v53 = (const char *)(v32 + 2320);
        if ( (v52 & 0xFF00) != 0 )
          v34 = "soft_irq";
        else
          v34 = v53;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v34,
        "cnss_pci_call_driver_probe",
        3u,
        3u,
        "Failed to probe host driver, err = %d\n",
        v30,
        v31,
        vars0);
      goto LABEL_78;
    }
    _X8 = (unsigned __int64 *)(v8 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v74 = __ldxr(_X8);
    while ( __stxr(v74 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
    _X8 = (unsigned __int64 *)(v8 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v77 = __ldxr(_X8);
    while ( __stxr(v77 | 0x100, _X8) );
  }
  else
  {
    if ( (*(_QWORD *)(v8 + 552) & 0x40) == 0 )
    {
      v10 = a1;
      v11 = 6312;
LABEL_51:
      complete(v8 + v11);
      goto LABEL_58;
    }
    v45 = (__int64 (__fastcall *)(__int64, __int64))v9[3];
    v10 = a1;
    v46 = a1[2];
    v47 = *a1;
    if ( *((_DWORD *)v45 - 1) != -2038225168 )
      __break(0x8229u);
    v48 = v45(v47, v46);
    if ( v48 )
    {
      v50 = _ReadStatusReg(SP_EL0);
      v33 = v48;
      if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
      {
        v51 = "irq";
      }
      else
      {
        v60 = *(_DWORD *)(v50 + 16);
        v61 = (const char *)(v50 + 2320);
        if ( (v60 & 0xFF00) != 0 )
          v51 = "soft_irq";
        else
          v51 = v61;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v51,
        "cnss_pci_call_driver_probe",
        3u,
        3u,
        "Failed to idle restart host driver, err = %d\n",
        v48,
        v49,
        vars0);
      *(_DWORD *)(v8 + 7568) = v33;
LABEL_78:
      complete_all(v8 + 6312);
      return v33;
    }
    _X8 = (unsigned __int64 *)(v8 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v80 = __ldxr(_X8);
    while ( __stxr(v80 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
  }
  complete_all(v8 + 6312);
LABEL_58:
  if ( (*(_QWORD *)(v8 + 552) & 0x200) != 0 )
  {
    _X8 = (unsigned __int64 *)(v8 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v71 = __ldxr(_X8);
    while ( __stxr(v71 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
    _pm_relax(*(_QWORD *)(v8 + 7440));
  }
  result = 0;
  v54 = *((_DWORD *)v10 + 6) - 4353;
  if ( v54 <= 0x11 && ((1 << v54) & 0x32245) != 0 )
  {
    if ( *(_DWORD *)(v10[1] + 6484LL) )
    {
      cnss_pci_time_sync_work_hdlr(v10 + 61);
      return 0;
    }
    v55 = _ReadStatusReg(SP_EL0);
    v17 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v55 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v56 = *(_DWORD *)(v55 + 16);
      v57 = (const char *)(v55 + 2320);
      if ( (v56 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v57;
    }
    v25 = "cnss_pci_start_time_sync_update";
    v26 = "Device time clock frequency is not valid, skip time sync\n";
LABEL_27:
    cnss_debug_ipc_log_print(v17, v18, v25, 7u, 7u, v26, a7, a8, vars0);
    return 0;
  }
  return result;
}
