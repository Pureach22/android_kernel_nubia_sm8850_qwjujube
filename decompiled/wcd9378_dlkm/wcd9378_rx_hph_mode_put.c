__int64 __fastcall wcd9378_rx_hph_mode_put(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x8

  v2 = *(_DWORD *)(a2 + 72);
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 152LL);
  if ( *(_DWORD *)(v3 + 360) == v2 )
    return 0;
  *(_DWORD *)(v3 + 360) = v2;
  return 1;
}
