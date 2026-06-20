__int64 __fastcall cam_vfe_core_deinit(__int64 a1, __int64 a2)
{
  int v4; // w0
  int v5; // w0
  unsigned int v6; // w19

  v4 = cam_vfe_bus_deinit(*(unsigned int *)(a2 + 8), a1 + 24);
  if ( v4 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_deinit",
      755,
      "Error cam_vfe_bus_deinit failed rc=%d",
      v4);
  v5 = cam_vfe_top_deinit(*(unsigned int *)(a2 + 40), a1 + 16);
  if ( v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_deinit",
      760,
      "Error cam_vfe_top_deinit failed rc=%d",
      v5);
  v6 = cam_irq_controller_deinit((__int64 *)(a1 + 8));
  if ( v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_deinit",
      765,
      "Error cam_irq_controller_deinit failed rc=%d",
      v6);
  return v6;
}
