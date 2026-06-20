__int64 __fastcall cam_icp_v2_hw_deinit(__int64 a1, unsigned __int8 *a2, int a3)
{
  int v4; // w21
  __int64 v5; // x20
  __int64 v6; // x1
  int v7; // w22
  __int64 result; // x0
  __int64 v9; // x6
  const char *v10; // x5
  __int64 v11; // x1
  __int64 v12; // x4
  const char *v13; // x6
  const char *v14; // x7
  int v15; // w0
  __int64 v16; // x20
  int v17; // w0
  int v18; // w20
  int v19; // w6
  __int64 v20; // x0

  if ( !a1 || !a2 )
  {
    if ( a1 )
      v13 = "Non-NULL";
    else
      v13 = "NULL";
    if ( a2 )
      v14 = "Non-NULL";
    else
      v14 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_hw_deinit",
      329,
      "ICP device info is %s cmd args is %s",
      v13,
      v14);
    return 4294967274LL;
  }
  if ( a3 != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_hw_deinit",
      334,
      "Invalid hw deinit cmd args");
    return 4294967274LL;
  }
  v4 = *a2;
  v5 = *(_QWORD *)(a1 + 3680);
  v6 = raw_spin_lock_irqsave(a1 + 48);
  if ( !*(_DWORD *)(a1 + 92) )
  {
    raw_spin_unlock_irqrestore(a1 + 48, v6);
    return 0;
  }
  v7 = *(_DWORD *)(v5 + 48) - 1;
  *(_DWORD *)(v5 + 48) = v7;
  raw_spin_unlock_irqrestore(a1 + 48, v6);
  if ( v7 )
  {
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      v9 = *(unsigned int *)(v5 + 48);
      v10 = "power on reference still held %u";
      v11 = debug_mdl & 0x100;
      v12 = 351;
LABEL_34:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v11,
        4,
        "cam_icp_v2_hw_deinit",
        v12,
        v10,
        v9);
      return 0;
    }
    return result;
  }
  if ( v4 )
    hfi_send_freq_info(*(unsigned int *)(v5 + 52), 0);
  v15 = cam_icp_soc_resources_disable(a1 + 96);
  if ( v15 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      2,
      "cam_icp_v2_hw_deinit",
      362,
      "failed to disable soc resources rc=%d",
      v15);
  v16 = *(_QWORD *)(a1 + 3680);
  if ( v16 && *(_BYTE *)(v16 + 104) == 1 )
  {
    v17 = cam_cpas_stop(*(_DWORD *)(v16 + 44));
    if ( !v17 )
    {
      *(_BYTE *)(v16 + 104) = 0;
      goto LABEL_29;
    }
    v18 = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_cpas_stop",
      239,
      "failed to stop cpas rc=%d",
      v17);
    v19 = v18;
  }
  else
  {
    v19 = -22;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    2,
    "cam_icp_v2_hw_deinit",
    366,
    "cpas stop failed rc=%d",
    v19);
LABEL_29:
  v20 = raw_spin_lock_irqsave(a1 + 48);
  *(_DWORD *)(a1 + 92) = 0;
  raw_spin_unlock_irqrestore(a1 + 48, v20);
  result = 0;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v9 = *(unsigned int *)(a1 + 116);
    v10 = "ICP%u powered off";
    v11 = debug_mdl & 0x100;
    v12 = 379;
    goto LABEL_34;
  }
  return result;
}
