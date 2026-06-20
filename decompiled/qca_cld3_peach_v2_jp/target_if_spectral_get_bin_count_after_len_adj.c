unsigned __int64 __fastcall target_if_spectral_get_bin_count_after_len_adj(
        unsigned __int64 result,
        char a2,
        __int64 a3,
        __int64 *a4)
{
  int v4; // w8
  __int64 v5; // x8
  char v6; // w8

  if ( a2 == 1 && *(_BYTE *)(a3 + 1) )
  {
    *a4 = 0;
    return 0;
  }
  else
  {
    v4 = *(_DWORD *)(a3 + 4);
    if ( v4 == 1 )
    {
      *a4 = 2;
      v6 = 1;
      if ( *(_BYTE *)(a3 + 2) )
        v6 = 2;
      result >>= v6;
    }
    else
    {
      if ( v4 == 2 )
      {
        result >>= 2;
        v5 = 4;
      }
      else
      {
        v5 = 1;
      }
      *a4 = v5;
    }
    if ( a2 == 2 )
      result >>= *(_BYTE *)a3 != 0;
  }
  return result;
}
