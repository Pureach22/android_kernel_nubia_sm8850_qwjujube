__int64 __fastcall debug_wmi_log_size_open(__int64 a1, __int64 a2)
{
  return single_open(a2, debug_wmi_log_size_show, *(_QWORD *)(a1 + 696));
}
