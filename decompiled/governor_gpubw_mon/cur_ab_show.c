__int64 __fastcall cur_ab_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%lu\n", *(_QWORD *)(*(_QWORD *)(a1 + 912) - 16LL));
}
