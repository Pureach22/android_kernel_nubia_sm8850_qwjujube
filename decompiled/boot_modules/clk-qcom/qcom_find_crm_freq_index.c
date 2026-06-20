__int64 __fastcall qcom_find_crm_freq_index(unsigned __int64 *a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 *v3; // x9
  __int64 result; // x0
  unsigned __int64 v5; // t1

  if ( !a1 )
    return 4294967274LL;
  v2 = *a1;
  if ( !*a1 )
    return 4294967274LL;
  if ( !a2 )
    return 0;
  v3 = a1 + 3;
  result = 1;
  while ( v2 < a2 )
  {
    v5 = *v3;
    v3 += 3;
    v2 = v5;
    result = (unsigned int)(result + 1);
    if ( !v5 )
      return (unsigned int)(result - 1);
  }
  return result;
}
