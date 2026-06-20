__int64 __fastcall cam_sfe_core_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x23
  unsigned int v8; // w0
  unsigned int v9; // w21
  int v10; // w0
  int v11; // w0

  v6 = a2;
  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 480) )
      a2 = *(_QWORD *)(a2 + 288);
    else
      a2 = 0;
  }
  v8 = cam_irq_controller_init("sfe", a2, *(unsigned int **)a4, (__int64 *)(a1 + 32));
  if ( v8 )
  {
    v9 = v8;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_init",
      508,
      "SFE irq controller init failed");
    return v9;
  }
  v10 = cam_sfe_top_init(*(unsigned int *)(a4 + 40), v6, a3, *(_QWORD *)(a4 + 48), *(_QWORD *)(a1 + 32), a1 + 8);
  if ( v10 )
  {
    v9 = v10;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_init",
      516,
      "SFE top init failed rc: %d",
      v10);
    goto LABEL_14;
  }
  v11 = cam_sfe_bus_init(*(unsigned int *)(a4 + 8), 0, v6, a3, *(_QWORD *)(a4 + 16), *(_QWORD *)(a1 + 32), a1 + 16);
  if ( v11 )
  {
    v9 = v11;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_init",
      525,
      "SFE bus wr init failed rc: %d",
      v11);
LABEL_13:
    cam_sfe_top_deinit(*(unsigned int *)(a4 + 40), a1 + 8);
LABEL_14:
    if ( (unsigned int)cam_irq_controller_deinit((__int64 *)(a1 + 32)) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_core_init",
        551,
        "Error cam_irq_controller_deinit failed rc=%d",
        v9);
    return v9;
  }
  v9 = cam_sfe_bus_init(*(unsigned int *)(a4 + 24), 1, v6, a3, *(_QWORD *)(a4 + 32), *(_QWORD *)(a1 + 32), a1 + 24);
  if ( v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_init",
      534,
      "SFE bus rd init failed rc: %d",
      v9);
    cam_sfe_bus_deinit(*(unsigned int *)(a4 + 8), 0, a1 + 16);
    goto LABEL_13;
  }
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_core_init",
      539,
      "SFE device [%u] INIT success",
      *(_DWORD *)(a3 + 4));
    return 0;
  }
  return v9;
}
