__int64 __fastcall show_curr_cap_cluster(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u %u %u\n", curr_cap_0, curr_cap_1, curr_cap_2);
}
