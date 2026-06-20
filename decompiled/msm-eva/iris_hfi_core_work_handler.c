__int64 iris_hfi_core_work_handler()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x8
  __int64 v2; // x20
  unsigned int v3; // w21
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x2
  void *v7; // x0
  int v8; // w0
  char v9; // w10
  __int64 v10; // x3
  int v11; // w25
  unsigned __int64 v12; // x26
  __int64 v13; // x27
  unsigned __int64 v14; // x22
  void (__fastcall *v15)(__int64, unsigned __int64); // x8
  __int64 v16; // x0
  bool v17; // cf
  unsigned __int64 v19; // [xsp+8h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( !v1 )
  {
    if ( (iris_hfi_core_work_handler___already_done & 1) == 0 )
    {
      iris_hfi_core_work_handler___already_done = 1;
      _warn_printk("EVA Core is not created\n");
      __break(0x800u);
    }
    return 1;
  }
  v2 = **(_QWORD **)(v1 + 256);
  mutex_lock(v2 + 80);
  if ( *(_DWORD *)(v2 + 2408) == 1 )
  {
    if ( (iris_hfi_core_work_handler_warning_on & 1) != 0 )
    {
      v3 = 0;
    }
    else
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        printk(&unk_9123D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      v3 = 0;
      iris_hfi_core_work_handler_warning_on = 1;
    }
    goto LABEL_33;
  }
  v4 = *(_QWORD *)(v2 + 128);
  iris_hfi_core_work_handler_warning_on = 0;
  if ( !v4 )
  {
    v3 = 0;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_33;
    v5 = *(unsigned int *)(StatusReg + 1800);
    v6 = *(unsigned int *)(StatusReg + 1804);
    v7 = &unk_837F7;
LABEL_19:
    printk(v7, v5, v6, &unk_8E7CE);
    v3 = 0;
    goto LABEL_33;
  }
  if ( (unsigned int)_resume(v2) )
  {
    v3 = 0;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_33;
    v5 = *(unsigned int *)(StatusReg + 1800);
    v6 = *(unsigned int *)(StatusReg + 1804);
    v7 = &unk_8930E;
    goto LABEL_19;
  }
  if ( v2 )
  {
    v8 = _read_register(v2, 0xB000Cu);
    if ( (v8 & 0x64) != 0 )
    {
      v9 = BYTE1(msm_cvp_debug);
      v10 = (unsigned int)(*(_DWORD *)(v2 + 2196) + 1);
      *(_DWORD *)(v2 + 20) |= v8;
      *(_DWORD *)(v2 + 2196) = v10;
      if ( (v9 & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_842F3, "core", v2, v10);
    }
    else
    {
      ++*(_DWORD *)(v2 + 2192);
    }
    _write_register(v2, 0xA001Cu, 1u);
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_89BB3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  v3 = _response_handler(v2);
  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
    printk(&unk_89C1E, "hfi", "iris_hfi_core_work_handler", v3);
LABEL_33:
  v11 = *(_DWORD *)(v2 + 20);
  v19 = StatusReg;
  mutex_unlock(v2 + 80);
  v12 = *(_QWORD *)(v2 + 2432);
  if ( v12 && v12 <= 0xFFFFFFFFFFFFF000LL && (int)v3 >= 1 )
  {
    v13 = 0;
    v14 = 1;
    while ( *(_DWORD *)(v2 + 2408) != 1 )
    {
      if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        printk(&unk_96C94, "hfi", (unsigned int)v14, v3);
      v15 = *(void (__fastcall **)(__int64, unsigned __int64))(v2 + 128);
      v16 = *(unsigned int *)(v12 + v13);
      if ( *((_DWORD *)v15 - 1) != -312014295 )
        __break(0x8228u);
      v15(v16, v12 + v13 + 8);
      v12 = *(_QWORD *)(v2 + 2432);
      if ( v12 )
      {
        if ( v12 <= 0xFFFFFFFFFFFFF000LL )
        {
          v17 = v14++ >= v3;
          v13 += 768;
          if ( !v17 )
            continue;
        }
      }
      goto LABEL_50;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_83834, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
      if ( (v11 & 8) != 0 )
        return 1;
      goto LABEL_51;
    }
  }
LABEL_50:
  if ( (v11 & 8) == 0 )
LABEL_51:
    enable_irq(**(unsigned int **)(v2 + 2168));
  return 1;
}
