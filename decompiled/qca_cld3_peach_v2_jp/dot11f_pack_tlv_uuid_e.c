__int64 __fastcall dot11f_pack_tlv_uuid_e(__int64 a1, _BYTE *a2, _WORD *a3, unsigned int a4, int *a5)
{
  int v6; // w19
  int v9; // w9

  if ( a4 < 0x14 )
    return 268435461;
  if ( !*a2 )
    return 0;
  v6 = *a5;
  *a3 = 18192;
  *a5 += 4;
  qdf_mem_copy(a3 + 2, a2 + 1, 0x10u);
  v9 = *a5 + 16;
  *a5 = v9;
  if ( a3 != (_WORD *)-2LL )
    a3[1] = bswap32(v9 - v6 - 4) >> 16;
  return 0;
}
