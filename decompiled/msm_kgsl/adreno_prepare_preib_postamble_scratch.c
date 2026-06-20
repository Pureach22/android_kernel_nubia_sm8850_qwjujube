__int64 __fastcall adreno_prepare_preib_postamble_scratch(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  int v3; // w8

  if ( !*(_DWORD *)(a1 + 20588) )
    return 0;
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 800LL;
  *(_DWORD *)a2 = 1893040131;
  *(_QWORD *)(a2 + 4) = v2;
  v3 = *(_DWORD *)(a1 + 20588);
  *(_DWORD *)(a2 + 12) = v3 & 0xFFFFF | 0x300000;
  return 4;
}
