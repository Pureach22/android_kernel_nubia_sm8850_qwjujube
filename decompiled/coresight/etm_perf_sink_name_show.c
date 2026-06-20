__int64 __fastcall etm_perf_sink_name_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "0x%lx\n", *(_QWORD *)(a2 + 32));
}
