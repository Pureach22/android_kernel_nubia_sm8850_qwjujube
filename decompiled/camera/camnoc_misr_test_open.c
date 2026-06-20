__int64 __fastcall camnoc_misr_test_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_jpeg_get_camnoc_misr_test, cam_jpeg_set_camnoc_misr_test, "%08llu", a6);
}
