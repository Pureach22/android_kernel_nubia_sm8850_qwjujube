__int64 __fastcall rmnet_shs_boost_gold_cpu(__int64 result)
{
  _DWORD *v1; // x8

  if ( (unsigned int)result <= 7 && ((HIBYTE(word_1949D) >> result) & 1) == 0 )
  {
    v1 = (_DWORD *)(_per_cpu_offset[(unsigned int)result] + shs_cpu_boosts_0);
    *v1 = dword_194A0;
    v1[1] = 0x7FFFFFFF;
  }
  return result;
}
