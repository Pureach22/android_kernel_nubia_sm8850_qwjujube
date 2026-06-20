__int64 __fastcall he_build_mcs_mask(__int64 result, _WORD *a2)
{
  a2[2] = 0xFFF03FF00FFuLL >> (result & 0x30);
  *a2 = 0xFFF03FF00FFuLL >> (16 * ((unsigned __int8)result & 3u));
  a2[1] = 0xFFF03FF00FFuLL >> ((4 * result) & 0x30);
  a2[3] = 0xFFF03FF00FFuLL >> (((unsigned int)result >> 2) & 0x30);
  a2[4] = 0xFFF03FF00FFuLL >> (((unsigned int)result >> 4) & 0x30);
  a2[5] = 0xFFF03FF00FFuLL >> (((unsigned int)result >> 6) & 0x30);
  a2[6] = 0xFFF03FF00FFuLL >> (BYTE1(result) & 0x30);
  a2[7] = 0xFFF03FF00FFuLL >> (((unsigned int)result >> 10) & 0x30);
  return result;
}
