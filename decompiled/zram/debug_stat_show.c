__int64 __fastcall debug_stat_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x19

  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v4 + 32);
  v5 = (int)scnprintf(a3, 4096, "version: %d\n%8llu %8llu\n", 1, *(_QWORD *)(v4 + 176), *(_QWORD *)(v4 + 184));
  up_read(v4 + 32);
  return v5;
}
