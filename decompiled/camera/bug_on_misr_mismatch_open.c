__int64 __fastcall bug_on_misr_mismatch_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_jpeg_get_bug_on_misr, cam_jpeg_set_bug_on_misr, "%08llu", a6);
}
