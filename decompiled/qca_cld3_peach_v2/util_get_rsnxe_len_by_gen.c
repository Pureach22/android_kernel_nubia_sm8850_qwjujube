__int64 __fastcall util_get_rsnxe_len_by_gen(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x8

  if ( result )
  {
    if ( a2 == 1 )
    {
      v2 = *(_QWORD *)(result + 1792);
      if ( v2 )
        return *(unsigned __int8 *)(v2 + 1);
      return 0;
    }
    v3 = *(_QWORD *)(result + 1872);
    if ( !v3 )
      return 0;
    return (unsigned int)*(unsigned __int8 *)(v3 + 1) - 4;
  }
  return result;
}
