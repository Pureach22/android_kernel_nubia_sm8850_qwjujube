__int64 __fastcall qmp_fu1_usage_modes_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 160LL);
  return 0;
}
