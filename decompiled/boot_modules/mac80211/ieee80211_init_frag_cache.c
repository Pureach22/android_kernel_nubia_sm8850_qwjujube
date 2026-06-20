_QWORD *__fastcall ieee80211_init_frag_cache(_QWORD *result)
{
  *result = result;
  result[1] = result;
  result[7] = result + 7;
  result[8] = result + 7;
  result[14] = result + 14;
  result[15] = result + 14;
  result[2] = 0;
  result[9] = 0;
  result[16] = 0;
  result[21] = result + 21;
  result[22] = result + 21;
  result[23] = 0;
  return result;
}
