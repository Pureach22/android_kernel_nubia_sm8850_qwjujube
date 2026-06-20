__int64 __fastcall sub_529F80(__int64 a1)
{
  __int64 v1; // x18
  __int64 v2; // x25

  *(_QWORD *)(v2 + 440) = v1;
  *(_QWORD *)(v2 + 448) = a1;
  return wmi_unified_infra_cp_stats_request_send();
}
