__int64 __fastcall extract_peer_extd_stats_tlv(int a1, unsigned int **a2, unsigned int a3, _DWORD *a4)
{
  unsigned int *v4; // x9
  unsigned int *v5; // x8
  unsigned int *v7; // x19

  v4 = a2[2];
  if ( !v4 )
    return 16;
  if ( (*a2)[10] > a3 )
  {
    v5 = *a2;
    v7 = &v4[60 * v5[2] + 41 * v5[3] + 40 * v5[7] + 11 * a3 + 6 * v5[5] + 5 * v5[4] + 5 * v5[6] + 3 * v5[9]];
    qdf_mem_set(a4, 0x38u, 0);
    qdf_mem_copy(a4, v7, 8u);
    a4[12] = v7[7];
  }
  return 0;
}
