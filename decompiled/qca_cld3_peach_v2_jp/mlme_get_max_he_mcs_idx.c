__int64 __fastcall mlme_get_max_he_mcs_idx(int a1, _WORD *a2, _WORD *a3)
{
  bool v4; // zf
  __int64 result; // x0
  __int16 v6; // w8
  __int16 v7; // w9
  unsigned int v8; // w8
  unsigned int v9; // w9
  __int16 v10; // w8
  __int16 v11; // w9
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned int v14; // w8

  v4 = a1 == 3;
  result = 255;
  if ( v4 )
    goto LABEL_9;
  if ( a1 != 4 )
    goto LABEL_16;
  v6 = a2[2];
  if ( !v6 )
    goto LABEL_9;
  v7 = a3[2];
  if ( !v7 )
    goto LABEL_9;
  v8 = v6 & 3;
  v9 = v7 & 3;
  if ( v8 >= v9 )
    v8 = v9;
  if ( v8 == 3 )
  {
    result = 3;
LABEL_9:
    v10 = a2[1];
    if ( !v10 )
      goto LABEL_16;
    goto LABEL_10;
  }
  result = 2 * v8 + 7;
  v10 = a2[1];
  if ( !v10 )
    goto LABEL_16;
LABEL_10:
  v11 = a3[1];
  if ( v11 )
  {
    v12 = v10 & 3;
    v13 = v11 & 3;
    if ( v12 >= v13 )
      v12 = v13;
    if ( v12 == 3 )
      result = 3;
    else
      result = 2 * v12 + 7;
  }
LABEL_16:
  if ( *a2 && *a3 )
  {
    v14 = *a2 & 3;
    if ( v14 >= (*a3 & 3u) )
      v14 = *a3 & 3;
    if ( v14 == 3 )
      return 3;
    else
      return 2 * v14 + 7;
  }
  return result;
}
