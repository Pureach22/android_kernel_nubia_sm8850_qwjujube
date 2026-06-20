__int64 __fastcall cam_jpeg_irq_line_test_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_jpeg_get_irq_line_test, cam_jpeg_set_irq_line_test, "%08llu", a6);
}
