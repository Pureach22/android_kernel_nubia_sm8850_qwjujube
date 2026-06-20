__int64 __fastcall show_num_segments(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%lu\n", num_segments);
}
