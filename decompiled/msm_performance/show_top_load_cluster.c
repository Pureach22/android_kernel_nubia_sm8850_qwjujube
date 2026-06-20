__int64 __fastcall show_top_load_cluster(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u %u %u\n", top_load_0, top_load_1, top_load_2);
}
