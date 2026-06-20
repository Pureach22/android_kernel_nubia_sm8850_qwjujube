_BYTE *__fastcall lim_update_sta_run_time_ht_capability(_BYTE *result, __int64 a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w9
  int v4; // w10
  int v5; // w9

  v2 = *(unsigned __int16 *)(a2 + 1);
  if ( (unsigned __int8)result[12217] != v2 >> 15 )
    result[12217] = v2 >> 15;
  v3 = *(unsigned __int8 *)(a2 + 3);
  v4 = (v3 >> 2) & 7;
  if ( (unsigned __int8)result[12224] != v4 )
  {
    result[12224] = v4;
    LOBYTE(v3) = *(_BYTE *)(a2 + 3);
  }
  v5 = v3 & 3;
  if ( (unsigned __int8)result[12226] != v5 )
    result[12226] = v5;
  return result;
}
