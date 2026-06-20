__int64 __fastcall dot11f_pack_tlv_manufacturer(__int64 a1, _BYTE *a2, _WORD *a3, unsigned int a4, int *a5)
{
  int v6; // w19
  int v10; // w9

  if ( (unsigned int)(unsigned __int8)a2[1] + 4 > a4 )
    return 268435461;
  if ( !*a2 )
    return 0;
  v6 = *a5;
  *a3 = 8464;
  *a5 += 4;
  qdf_mem_copy(a3 + 2, a2 + 2, (unsigned __int8)a2[1]);
  v10 = *a5 + (unsigned __int8)a2[1];
  *a5 = v10;
  if ( a3 != (_WORD *)-2LL )
    a3[1] = bswap32(v10 - v6 - 4) >> 16;
  return 0;
}
