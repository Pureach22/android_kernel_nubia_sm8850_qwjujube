__int64 __fastcall extract_bcn_stats_tlv(__int64 a1, unsigned int **a2, unsigned int a3, unsigned int *a4)
{
  unsigned int *v4; // x8
  unsigned int *v5; // x8

  if ( (*a2)[9] > a3 )
  {
    v4 = *a2;
    v5 = &a2[2][60 * v4[2] + 41 * v4[3] + 40 * v4[7] + 5 * v4[4] + 5 * v4[6] + 3 * a3];
    *a4 = *v5;
    a4[1] = v5[1];
    a4[2] = v5[2];
  }
  return 0;
}
