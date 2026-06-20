__int64 __fastcall max_comp_streams_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", _num_online_cpus);
}
