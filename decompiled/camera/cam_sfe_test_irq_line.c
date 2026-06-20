__int64 __fastcall cam_sfe_test_irq_line(__int64 a1)
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
      0x40000000,
      1,
      "cam_sfe_test_irq_line",
      184,
      "Invalid arguments");
    return 4294967274LL;
  }
  inited = cam_sfe_init_hw(a1);
  v3 = *(unsigned int *)(a1 + 116);
  if ( inited )
  {
    v4 = "SFE:%d failed to init hw";
    v5 = inited;
    v6 = 192;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_test_irq_line",
      199,
      "failed to test SFE:%d",
      v3);
    v8 = cam_sfe_deinit_hw(a1);
    if ( !v8 )
      return 0xFFFFFFFFLL;
    v3 = *(unsigned int *)(a1 + 116);
    v4 = "SFE:%d failed to deinit hw";
    v5 = v8;
    v6 = 205;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_test_irq_line",
    v6,
    v4,
    v3);
  return v5;
}
