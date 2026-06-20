__int64 __fastcall ucfg_spectral_extract_response(unsigned __int8 *a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // w9
  __int64 result; // x0
  void *v6; // x0
  const void *v7; // x1
  size_t v8; // x2
  int v9; // w8

  v3 = a1[4];
  result = 0;
  if ( v3 > 44 )
  {
    if ( v3 <= 46 )
    {
      result = 16;
      if ( a2 && a3 && *a3 >= 0x30u )
      {
        v6 = a2;
        v7 = a1 + 8;
        *a3 = 48;
        v8 = 48;
LABEL_24:
        qdf_mem_copy(v6, v7, v8);
        return 0;
      }
      return result;
    }
    if ( v3 != 47 && v3 != 52 )
      return result;
    result = 16;
    if ( !a2 || !a3 || *a3 < 4u )
      return result;
    result = 0;
    *a3 = 4;
    v9 = *((_DWORD *)a1 + 2);
LABEL_29:
    *a2 = v9;
    return result;
  }
  if ( v3 != 31 )
  {
    if ( v3 == 38 )
    {
      result = 16;
      if ( !a2 || !a3 || *a3 < 4u )
        return result;
      result = 0;
      *a3 = 4;
      v9 = a1[8];
    }
    else
    {
      if ( v3 != 39 )
        return result;
      result = 16;
      if ( !a2 || !a3 || *a3 < 4u )
        return result;
      result = 0;
      *a3 = 4;
      v9 = a1[9];
    }
    goto LABEL_29;
  }
  result = 16;
  if ( a2 && a3 && *a3 >= 0x50u )
  {
    v6 = a2;
    v7 = a1 + 8;
    *a3 = 80;
    v8 = 80;
    goto LABEL_24;
  }
  return result;
}
