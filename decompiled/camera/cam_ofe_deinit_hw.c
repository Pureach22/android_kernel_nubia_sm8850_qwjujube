__int64 __fastcall cam_ofe_deinit_hw(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x1
  int v4; // w21
  __int64 result; // x0
  int v6; // w0
  __int64 v7; // x0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ofe_deinit_hw",
      141,
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
      "cam_ofe_deinit_hw",
      149,
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
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_ofe_deinit_hw",
        163,
        "OFE%u power on reference still held %u",
        *(_DWORD *)(a1 + 116),
        *(_DWORD *)(v1 + 12));
      return 0;
    }
  }
  else
  {
    v6 = cam_ofe_disable_soc_resources(a1 + 96, *(unsigned __int8 *)(v1 + 17));
    if ( v6 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_ofe_deinit_hw",
        170,
        "soc disable failed: %d",
        v6);
    else
      *(_BYTE *)(v1 + 17) = 0;
    if ( *(_BYTE *)(v1 + 16) == 1 )
    {
      if ( (unsigned int)cam_cpas_stop(*(_DWORD *)(v1 + 8)) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_ofe_deinit_hw",
          176,
          "cpas stop failed");
      else
        *(_BYTE *)(v1 + 16) = 0;
    }
    v7 = raw_spin_lock_irqsave(a1 + 48);
    *(_DWORD *)(a1 + 92) = 0;
    raw_spin_unlock_irqrestore(a1 + 48, v7);
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_ofe_deinit_hw",
        185,
        "OFE%u powered off",
        *(_DWORD *)(a1 + 116));
      return 0;
    }
  }
  return result;
}
