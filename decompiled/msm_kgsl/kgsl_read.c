__int64 __fastcall kgsl_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return simple_read_from_buffer(a2, a3, a4, "OH HAI GPU\n", 12);
}
