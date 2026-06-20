__int64 __fastcall btfm_slim_dai_hw_params(__int64 a1, int a2, __int16 a3)
{
  __int64 v5; // x8

  v5 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  *(_DWORD *)(v5 + 1088) = a2;
  *(_WORD *)(v5 + 1092) = a3;
  return 0;
}
