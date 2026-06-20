_DWORD *__fastcall policy_mger_remove_duplicate_freq_with_weight(_DWORD *result, _DWORD *a2, int a3, int a4)
{
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  _DWORD *v6; // x9
  __int64 v7; // t1
  int v8; // w11

  v4 = (unsigned int)*a2;
  if ( (_DWORD)v4 )
  {
    v5 = 0;
    while ( *result != a3 || result[1] != a4 )
    {
      ++v5;
      result += 3;
      if ( v4 == v5 )
        return result;
    }
    if ( (int)v4 - 1 > (unsigned int)v5 )
    {
      v6 = result;
      do
      {
        v7 = *(_QWORD *)(v6 + 3);
        v6 += 3;
        v8 = result[5];
        ++v5;
        *(_QWORD *)result = v7;
        result[2] = v8;
        result = v6;
      }
      while ( v5 < (unsigned int)(*a2 - 1) );
    }
    *a2 = v5;
  }
  return result;
}
