__int64 __fastcall dot11f_pack_tlv_request_device_type(__int64 a1, __int64 a2, _WORD *a3, unsigned int a4, int *a5)
{
  int v6; // w19
  int v10; // w9

  if ( a4 < 0xC )
    return 268435461;
  if ( !*(_BYTE *)a2 )
    return 0;
  v6 = *a5;
  *a3 = 27152;
  *a5 += 4;
  a3[2] = bswap32(*(unsigned __int16 *)(a2 + 2)) >> 16;
  *a5 += 2;
  qdf_mem_copy(a3 + 3, (const void *)(a2 + 4), 4u);
  *a5 += 4;
  a3[5] = bswap32(*(unsigned __int16 *)(a2 + 8)) >> 16;
  v10 = *a5 + 2;
  *a5 = v10;
  if ( a3 != (_WORD *)-2LL )
    a3[1] = bswap32(v10 - v6 - 4) >> 16;
  return 0;
}
