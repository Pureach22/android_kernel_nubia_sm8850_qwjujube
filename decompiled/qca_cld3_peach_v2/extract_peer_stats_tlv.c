__int64 __fastcall extract_peer_stats_tlv(int a1, _QWORD *a2, unsigned int a3, __int64 a4)
{
  _DWORD *v5; // x20

  if ( *(_DWORD *)(*a2 + 16LL) > a3 )
  {
    v5 = (_DWORD *)(a2[2] + 240LL * *(unsigned int *)(*a2 + 8LL) + 164LL * *(unsigned int *)(*a2 + 12LL) + 20LL * a3);
    qdf_mem_set((void *)a4, 0x54u, 0);
    qdf_mem_copy((void *)a4, v5, 8u);
    *(_BYTE *)(a4 + 8) = v5[2];
    *(_DWORD *)(a4 + 16) = v5[3];
    *(_DWORD *)(a4 + 20) = v5[4];
  }
  return 0;
}
