__int64 __fastcall disksize_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%llu\n", *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL) + 216LL));
}
