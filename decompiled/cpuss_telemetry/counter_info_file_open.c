__int64 __fastcall counter_info_file_open(__int64 a1, __int64 a2)
{
  return single_open(a2, counter_info_file_show, *(_QWORD *)(a1 + 696));
}
