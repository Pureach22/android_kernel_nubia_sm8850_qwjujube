__int64 __fastcall extract_recv_bcn_stats_tlv(__int64 a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x8

  if ( !a2 )
    return 16;
  v4 = *(_QWORD *)(a2 + 160);
  if ( !v4 )
    return 16;
  v5 = v4 + 88LL * a3;
  *a4 = *(_DWORD *)(v5 + 4);
  qdf_mem_copy(a4 + 1, (const void *)(v5 + 8), 0x50u);
  return 0;
}
