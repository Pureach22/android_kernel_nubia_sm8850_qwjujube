__int64 __fastcall cam_isp_test_irq_line_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_isp_get_test_irq_line, cam_isp_set_test_irq_line, "%16llu", a6);
}
