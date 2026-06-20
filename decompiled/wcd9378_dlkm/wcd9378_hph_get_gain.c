__int64 __fastcall wcd9378_hph_get_gain(__int64 a1, __int64 a2)
{
  __int64 v2; // x9

  v2 = *(_QWORD *)(a1 + 128);
  *(_DWORD *)(a2 + 72) = (unsigned __int16)-*(_WORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 364LL) / 0x180u;
  return 0;
}
