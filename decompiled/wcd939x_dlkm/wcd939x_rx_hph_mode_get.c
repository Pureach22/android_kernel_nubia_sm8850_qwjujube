__int64 __fastcall wcd939x_rx_hph_mode_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a2 + 72) = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 284LL);
  return 0;
}
