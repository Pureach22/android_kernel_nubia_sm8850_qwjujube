__int64 __fastcall extract_pmf_bcn_protect_stats_tlv(__int64 a1, _QWORD *a2, _DWORD *a3)
{
  __int64 v3; // x8

  if ( !a2 )
    return 16;
  if ( (*(_BYTE *)(*a2 + 5LL) & 0x80) == 0 )
    return 0;
  v3 = a2[12];
  if ( !v3 )
    return 0;
  *a3 = *(_DWORD *)(v3 + 4);
  a3[1] = *(_DWORD *)(a2[12] + 8LL);
  a3[2] = *(_DWORD *)(a2[12] + 12LL);
  a3[3] = *(_DWORD *)(a2[12] + 16LL);
  return 0;
}
