__int64 __fastcall cam_vfe_core_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x1
  int v9; // w0
  unsigned int v10; // w23
  int v11; // w0
  int v12; // w0
  __int64 v13; // x0

  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_core_init",
      688,
      "Enter");
    if ( *(_QWORD *)(a2 + 3296) )
      goto LABEL_4;
LABEL_23:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_init",
      692,
      "Invalid soc_private");
    return (unsigned int)-19;
  }
  if ( !*(_QWORD *)(a2 + 3296) )
    goto LABEL_23;
LABEL_4:
  if ( a2 && *(_DWORD *)(a2 + 480) )
    v8 = *(_QWORD *)(a2 + 288);
  else
    v8 = 0;
  v9 = cam_irq_controller_init("vfe", v8, *(unsigned int **)(*(_QWORD *)a4 + 8LL), (__int64 *)(a1 + 8));
  if ( v9 )
  {
    v10 = v9;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_init",
      702,
      "Error, cam_irq_controller_init failed rc = %d",
      v9);
    return v10;
  }
  v11 = cam_vfe_top_init(*(unsigned int *)(a4 + 40), a2, a3, *(_QWORD *)(a4 + 48), *(_QWORD *)(a1 + 8), a1 + 16);
  if ( v11 )
  {
    v10 = v11;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_init",
      710,
      "Error, cam_vfe_top_init failed rc = %d",
      v11);
LABEL_14:
    cam_irq_controller_deinit((__int64 *)(a1 + 8));
    return v10;
  }
  v12 = cam_vfe_bus_init(*(unsigned int *)(a4 + 8), 0, a2, a3, *(_QWORD *)(a4 + 16), *(_QWORD *)(a1 + 8), a1 + 24);
  if ( v12 )
  {
    v10 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_init",
      718,
      "Error, cam_vfe_bus_init failed rc = %d",
      v12);
    cam_vfe_top_deinit(*(unsigned int *)(a4 + 40), a1 + 16);
    goto LABEL_14;
  }
  v13 = *(unsigned int *)(a4 + 24);
  if ( !(_DWORD)v13 )
    return 0;
  if ( (unsigned int)cam_vfe_bus_init(v13, 1, a2, a3, *(_QWORD *)(a4 + 32), *(_QWORD *)(a1 + 8), a1 + 32) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      2,
      "cam_vfe_core_init",
      728,
      "Error, RD cam_vfe_bus_init failed");
  v10 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_core_init",
      732,
      "vfe_bus_rd %pK hw_idx %d",
      *(const void **)(a1 + 32),
      *(_DWORD *)(a3 + 4));
    return 0;
  }
  return v10;
}
