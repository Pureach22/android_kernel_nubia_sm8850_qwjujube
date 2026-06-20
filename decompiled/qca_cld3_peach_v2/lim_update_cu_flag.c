_WORD *__fastcall lim_update_cu_flag(_WORD *result, __int64 a2)
{
  __int16 v2; // w8

  if ( *(_BYTE *)(a2 + 10177) )
    v2 = 64;
  else
    v2 = 0;
  *result = *result & 0xFFBF | v2;
  return result;
}
