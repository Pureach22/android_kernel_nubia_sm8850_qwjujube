size_t __fastcall cfg80211_defragment_element(
        unsigned __int8 *a1,
        __int64 a2,
        __int64 a3,
        char *dest,
        size_t a5,
        unsigned __int8 a6)
{
  size_t v6; // x22
  char *v9; // x23
  size_t v10; // x21
  __int64 v11; // x21
  __int64 v12; // x24
  unsigned __int8 v13; // w25
  size_t v14; // x22
  __int64 v16; // x24
  __int64 v17; // x25
  unsigned __int8 v18; // w26
  int v19; // w24
  char *v20; // x8
  unsigned __int64 v21; // x25
  char *v22; // x1
  size_t v23; // x23
  char *v24; // x26

  if ( !a1 )
    return -22;
  v6 = a1[1];
  v9 = (char *)(a1 + 2);
  if ( *a1 == 255 )
  {
    v10 = v6 - 1;
    if ( !dest )
    {
LABEL_10:
      if ( (_DWORD)v6 != 255 )
        return v10;
LABEL_14:
      v19 = a6;
      v20 = &v9[v6];
      v21 = a2 + a3;
      while ( 1 )
      {
        v22 = v20 + 2;
        if ( (unsigned __int64)(v20 + 2) >= v21 )
          break;
        v23 = (unsigned __int8)v20[1];
        v24 = &v22[v23];
        if ( (unsigned __int64)&v22[v23] > v21 || (unsigned __int8)*v20 != v19 )
          break;
        v14 = v10 + v23;
        if ( dest )
        {
          if ( v14 > a5 )
            return -28;
          memmove(&dest[v10], v22, v23);
        }
        v10 += v23;
        v20 = v24;
        if ( (_DWORD)v23 != 255 )
          return v14;
      }
      return v10;
    }
    if ( v10 <= a5 )
    {
      v16 = a2;
      v17 = a3;
      v18 = a6;
      memmove(dest, a1 + 3, v6 - 1);
      a2 = v16;
      a3 = v17;
      a6 = v18;
      if ( (_DWORD)v6 != 255 )
        return v10;
      goto LABEL_14;
    }
  }
  else
  {
    v10 = a1[1];
    if ( !dest )
      goto LABEL_10;
    if ( v6 <= a5 )
    {
      v11 = a2;
      v12 = a3;
      v13 = a6;
      memmove(dest, v9, v6);
      a2 = v11;
      a3 = v12;
      a6 = v13;
      v10 = v6;
      goto LABEL_10;
    }
  }
  return -28;
}
