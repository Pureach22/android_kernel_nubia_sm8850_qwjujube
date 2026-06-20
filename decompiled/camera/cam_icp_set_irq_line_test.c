__int64 __fastcall cam_icp_set_irq_line_test(__int64 a1)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_test_irq_line",
    2255,
    "[%s] IRQ line verification disabled",
    (const char *)(a1 + 112));
  return 0;
}
