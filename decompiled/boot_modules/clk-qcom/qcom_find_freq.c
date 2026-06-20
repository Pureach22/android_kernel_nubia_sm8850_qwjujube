unsigned __int64 *__fastcall qcom_find_freq(unsigned __int64 *result, unsigned __int64 a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 *v3; // x8

  if ( !result )
    return nullptr;
  v2 = *result;
  if ( *result )
  {
    do
    {
      v3 = result;
      if ( v2 >= a2 )
        break;
      result += 3;
      v2 = v3[3];
    }
    while ( v2 );
    return v3;
  }
  return result;
}
