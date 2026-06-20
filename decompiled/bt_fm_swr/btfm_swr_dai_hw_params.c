__int64 __fastcall btfm_swr_dai_hw_params(__int64 a1, int a2, __int16 a3, char a4)
{
  __int64 v6; // x8

  v6 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  *(_DWORD *)(v6 + 24) = a2;
  *(_WORD *)(v6 + 28) = a3;
  *(_BYTE *)(v6 + 30) = a4;
  return 0;
}
