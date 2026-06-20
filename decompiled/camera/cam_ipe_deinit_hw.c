__int64 __fastcall cam_ipe_deinit_hw(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x1
  int v4; // w21
  __int64 result; // x0
  __int64 v6; // x6
  __int64 v7; // x7
  const char *v8; // x5
  __int64 v9; // x1
  __int64 v10; // x4
  int v11; // w0
  int v12; // w8
  __int64 v13; // x0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ipe_deinit_hw",
      140,
      "Invalid cam_dev_info");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 3680);
  if ( !v1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_ipe_deinit_hw",
      148,
      "soc_info = %pK core_info = %pK",
      (const void *)(a1 + 96),
      nullptr);
    return 4294967274LL;
  }
  v3 = raw_spin_lock_irqsave(a1 + 48);
  if ( !*(_DWORD *)(a1 + 92) )
  {
    raw_spin_unlock_irqrestore(a1 + 48, v3);
    return 0;
  }
  v4 = *(_DWORD *)(v1 + 12) - 1;
  *(_DWORD *)(v1 + 12) = v4;
  raw_spin_unlock_irqrestore(a1 + 48, v3);
  if ( v4 )
  {
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      v6 = *(unsigned int *)(a1 + 116);
      v7 = *(unsigned int *)(v1 + 12);
      v8 = "IPE%u power on reference still held %u";
      v9 = debug_mdl & 0x100;
      v10 = 162;
LABEL_22:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        v9,
        4,
        "cam_ipe_deinit_hw",
        v10,
        v8,
        v6,
        v7);
      return 0;
    }
  }
  else
  {
    v11 = cam_ipe_disable_soc_resources(a1 + 96, *(unsigned __int8 *)(v1 + 17));
    if ( v11 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_ipe_deinit_hw",
        169,
        "soc disable is failed : %d",
        v11);
    v12 = *(unsigned __int8 *)(v1 + 16);
    *(_BYTE *)(v1 + 17) = 0;
    if ( v12 == 1 )
    {
      if ( (unsigned int)cam_cpas_stop(*(_DWORD *)(v1 + 8)) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_ipe_deinit_hw",
          174,
          "cpas stop is failed");
      else
        *(_BYTE *)(v1 + 16) = 0;
    }
    v13 = raw_spin_lock_irqsave(a1 + 48);
    *(_DWORD *)(a1 + 92) = 0;
    raw_spin_unlock_irqrestore(a1 + 48, v13);
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      v6 = *(unsigned int *)(a1 + 116);
      v7 = *(unsigned int *)(v1 + 12);
      v8 = "IPE%u powered off (refcnt: %u)";
      v9 = debug_mdl & 0x100;
      v10 = 184;
      goto LABEL_22;
    }
  }
  return result;
}
