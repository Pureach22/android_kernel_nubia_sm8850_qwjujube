__int64 __fastcall debug_wmi_enable_open(__int64 a1, __int64 a2)
{
  return single_open(a2, debug_wmi_enable_show, *(_QWORD *)(a1 + 696));
}
