__int64 __fastcall hal_srng_dst_get_num_avail_words_peach(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  unsigned int v4; // w0

  v2 = *(_QWORD *)(a1 + 160);
  v3 = *(_QWORD *)(a1 + 96) + *(int *)(v2 + 74332);
  if ( (*(_BYTE *)(v2 + 74224) & 1) != 0 )
    hal_read32_mb_1(v2, (const char *)(unsigned int)(v3 - *(_DWORD *)(v2 + 16)));
  else
    v4 = readl_8(v3);
  return HIWORD(v4);
}
