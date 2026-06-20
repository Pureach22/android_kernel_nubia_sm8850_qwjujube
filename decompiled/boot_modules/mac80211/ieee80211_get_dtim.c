unsigned __int8 *__fastcall ieee80211_get_dtim(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  __int64 elem_match; // x21
  unsigned __int8 *result; // x0
  unsigned int v8; // w11
  _BOOL4 v9; // w9
  __int64 v10; // x10
  char v11; // w11
  char v12; // w8
  char v13; // w10
  char v14; // w9

  elem_match = cfg80211_find_elem_match(5, a1 + 29, *(unsigned int *)(a1 + 24), 0, 0, 0);
  result = (unsigned __int8 *)cfg80211_find_elem_match(85, a1 + 29, *(unsigned int *)(a1 + 24), 0, 0, 0);
  if ( elem_match )
  {
    v8 = *(unsigned __int8 *)(elem_match + 1);
    v9 = v8 > 1;
    if ( v8 <= 1 )
      v10 = 0;
    else
      v10 = elem_match + 2;
    if ( !a2 )
    {
      v12 = 1;
      if ( !a3 )
        goto LABEL_19;
LABEL_13:
      if ( v9 )
      {
        v13 = *(_BYTE *)(v10 + 1);
        goto LABEL_17;
      }
LABEL_16:
      v13 = 0;
LABEL_17:
      v14 = 0;
      *a3 = v13;
      if ( !result )
        return result;
      goto LABEL_20;
    }
    if ( v8 >= 2 )
    {
      v11 = *(_BYTE *)(elem_match + 2);
      v9 = 1;
      v10 = elem_match + 2;
      goto LABEL_10;
    }
  }
  else if ( !a2 )
  {
    v12 = 1;
    if ( !a3 )
      goto LABEL_19;
    goto LABEL_16;
  }
  v9 = 0;
  v10 = 0;
  v11 = 0;
LABEL_10:
  v12 = 0;
  *a2 = v11;
  if ( a3 )
    goto LABEL_13;
LABEL_19:
  v14 = 1;
  if ( !result )
    return result;
LABEL_20:
  if ( result[1] >= 3u )
  {
    if ( (v12 & 1) == 0 )
      *a2 = result[4];
    if ( (v14 & 1) == 0 )
      *a3 = result[3];
  }
  return result;
}
