__int64 __fastcall ieee80211_get_vht_mask_from_cap(__int64 result, _WORD *a2)
{
  int v2; // w14
  unsigned __int64 v3; // x8

  v2 = (unsigned __int16)result >> 14;
  a2[2] = 0x3FF01FF00FFuLL >> (result & 0x30);
  *a2 = 0x3FF01FF00FFuLL >> (16 * ((unsigned __int8)result & 3u));
  a2[1] = 0x3FF01FF00FFuLL >> ((4 * result) & 0x30);
  v3 = 0x3FF01FF00FFuLL >> (16 * (unsigned __int8)v2);
  a2[3] = 0x3FF01FF00FFuLL >> (((unsigned int)result >> 2) & 0x30);
  if ( v2 == 3 )
    LOWORD(v3) = 0;
  a2[4] = 0x3FF01FF00FFuLL >> (((unsigned int)result >> 4) & 0x30);
  a2[5] = 0x3FF01FF00FFuLL >> (((unsigned int)result >> 6) & 0x30);
  a2[6] = 0x3FF01FF00FFuLL >> (BYTE1(result) & 0x30);
  a2[7] = v3;
  return result;
}
