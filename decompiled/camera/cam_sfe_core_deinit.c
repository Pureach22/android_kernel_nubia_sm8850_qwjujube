__int64 __fastcall cam_sfe_core_deinit(__int64 a1, unsigned int *a2)
{
  int v4; // w0
  int v5; // w0
  int v6; // w0
  unsigned int v7; // w19

  v4 = cam_sfe_bus_deinit(a2[6], 1, a1 + 24);
  if ( v4 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_deinit",
      566,
      "SFE bus rd deinit failed rc: %d",
      v4);
  v5 = cam_sfe_bus_deinit(a2[2], 0, a1 + 16);
  if ( v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_deinit",
      572,
      "SFE bus wr deinit failed rc: %d",
      v5);
  v6 = cam_sfe_top_deinit(a2[10], a1 + 8);
  if ( v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_deinit",
      578,
      "SFE top deinit failed rc: %d",
      v6);
  v7 = cam_irq_controller_deinit((__int64 *)(a1 + 32));
  if ( v7 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_core_deinit",
      583,
      "Error cam_irq_controller_deinit failed rc=%d",
      v7);
  return v7;
}
