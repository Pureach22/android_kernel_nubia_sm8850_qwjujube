__int64 __fastcall cam_jpeg_enc_test_irq_line(__int64 a1)
{
  int inited; // w0
  unsigned int v3; // w20
  int v4; // w0
  int v5; // w0

  if ( a1 )
  {
    inited = cam_jpeg_enc_init_hw(a1);
    if ( inited )
    {
      v3 = inited;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_enc_test_irq_line",
        345,
        "failed to init hw (rc=%d)",
        inited);
    }
    else
    {
      v4 = cam_jpeg_enc_reset_hw(a1);
      if ( v4 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_test_irq_line",
          351,
          "failed to trigger reset irq (rc=%d)",
          v4);
      else
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          3,
          "cam_jpeg_enc_test_irq_line",
          354,
          "verified JPEG DMA (%s) IRQ line",
          *(const char **)(a1 + 120));
      v5 = cam_jpeg_enc_deinit_hw(a1);
      if ( v5 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_enc_test_irq_line",
          358,
          "failed to de-init hw (rc=%d)",
          v5);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_enc_test_irq_line",
      339,
      "invalid args");
    return (unsigned int)-22;
  }
  return v3;
}
