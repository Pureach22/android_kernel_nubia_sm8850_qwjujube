__int64 __fastcall comp_algorithm_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x19

  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v4 + 32);
  v5 = zcomp_available_show(*(const char **)(v4 + 224), a3);
  up_read(v4 + 32);
  return v5;
}
