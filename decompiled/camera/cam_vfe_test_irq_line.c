__int64 __fastcall cam_vfe_test_irq_line(__int64 a1)
{
  unsigned int inited; // w0
  __int64 v3; // x6
  const char *v4; // x5
  unsigned int v5; // w19
  __int64 v6; // x4
  unsigned int v8; // w0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_test_irq_line",
      622,
      "invalid argument");
    return 4294967274LL;
  }
  inited = cam_vfe_init_hw(a1, 0);
  v3 = *(unsigned int *)(a1 + 116);
  if ( inited )
  {
    v4 = "VFE:%d failed to init hw";
    v5 = inited;
    v6 = 629;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_test_irq_line",
      636,
      "VFE:%d IRQ line test failed",
      v3);
    v8 = cam_vfe_deinit_hw(a1, 0);
    if ( !v8 )
      return 0xFFFFFFFFLL;
    v3 = *(unsigned int *)(a1 + 116);
    v4 = "VFE:%d failed to deinit hw";
    v5 = v8;
    v6 = 642;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_test_irq_line",
    v6,
    v4,
    v3);
  return v5;
}
