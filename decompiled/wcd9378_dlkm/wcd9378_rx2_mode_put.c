__int64 __fastcall wcd9378_rx2_mode_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 372LL) = *(_DWORD *)(a2 + 72) != 0;
  return 1;
}
