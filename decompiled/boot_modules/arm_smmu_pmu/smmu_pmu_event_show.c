__int64 __fastcall smmu_pmu_event_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 15, "event=0x%02llx\n", *(_QWORD *)(a2 + 32));
}
