__int64 __fastcall qmp_fu2_usage_modes_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned __int64 v5; // x9

  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 152LL);
  v5 = *(_QWORD *)(v4 + 192);
  *(_DWORD *)(v4 + 164) = *(_DWORD *)(a2 + 72);
  *(_QWORD *)(v4 + 184) = v5 >> 4;
  return 0;
}
