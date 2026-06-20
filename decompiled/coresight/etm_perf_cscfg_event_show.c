__int64 __fastcall etm_perf_cscfg_event_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "configid=0x%lx\n", *(_QWORD *)(a2 + 32));
}
