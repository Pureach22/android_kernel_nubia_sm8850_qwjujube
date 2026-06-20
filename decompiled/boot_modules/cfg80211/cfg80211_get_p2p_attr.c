__int64 __fastcall cfg80211_get_p2p_attr(unsigned __int8 *a1, unsigned int a2, int a3, char *dest, unsigned int a5)
{
  int v5; // w21
  _BOOL4 v6; // w10
  unsigned __int16 v7; // w23
  __int64 v8; // x8
  unsigned int v9; // w8
  unsigned int v10; // w8
  unsigned int v11; // w24
  char *v12; // x19
  unsigned int v13; // w25
  size_t v14; // x20
  unsigned int v15; // w27
  char *v16; // x22
  _BOOL4 v17; // w28
  unsigned int v18; // w9
  unsigned __int8 *v19; // x8
  unsigned int v20; // w25
  unsigned int v21; // w23
  int v22; // w9
  unsigned __int8 *v23; // x19
  unsigned int v24; // w24
  size_t v25; // x20
  int v26; // w28
  unsigned int v27; // w22
  int v28; // w26
  char *v29; // x21
  _BOOL4 v30; // w27
  char *v31; // x3
  int v33; // [xsp+0h] [xbp-10h]
  unsigned int v34; // [xsp+4h] [xbp-Ch]
  unsigned int v35; // [xsp+4h] [xbp-Ch]
  unsigned __int8 *v36; // [xsp+8h] [xbp-8h]
  unsigned __int8 *v37; // [xsp+8h] [xbp-8h]

  v5 = 0;
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    v9 = -84;
    if ( !a2 )
      break;
    if ( a2 == 1 )
      return v9;
    v10 = a1[1];
    if ( v10 + 2 > a2 )
      return (unsigned int)-84;
    v11 = v10 - 4;
    if ( v10 >= 4 && *a1 == 221 && a1[2] == 80 && a1[3] == 111 && a1[4] == 154 && a1[5] == 9 )
    {
      v12 = (char *)(a1 + 6);
      if ( v11 >= v7 )
        v13 = v7;
      else
        v13 = v10 - 4;
      if ( v13 != 0 && v6 )
      {
        if ( dest )
        {
          v36 = a1;
          if ( a5 >= v13 )
            v14 = v13;
          else
            v14 = a5;
          v33 = a3;
          v34 = a2;
          v15 = a5;
          v16 = dest;
          v17 = v6;
          memcpy(dest, v12, v14);
          a3 = v33;
          a2 = v34;
          a1 = v36;
          v6 = v17;
          dest = &v16[v14];
          a5 = v15 - v14;
        }
        v5 += v13;
        if ( v11 >= v7 )
          return (unsigned __int16)v5;
      }
      v7 -= v13;
      if ( !v7 )
      {
        v18 = v11 - v13;
        if ( v11 != v13 )
        {
          v19 = (unsigned __int8 *)&v12[v13];
          v37 = a1;
          v35 = a2;
          while ( 1 )
          {
            v20 = v18 - 3;
            if ( v18 < 3 )
              return (unsigned int)-84;
            v21 = *(unsigned __int16 *)(v19 + 1);
            v22 = *v19;
            v23 = v19 + 3;
            if ( v20 >= v21 )
              v24 = *(unsigned __int16 *)(v19 + 1);
            else
              v24 = v20;
            v6 = v22 == a3;
            if ( v22 == a3 )
            {
              if ( dest )
              {
                if ( a5 >= v24 )
                  v25 = v24;
                else
                  v25 = a5;
                v26 = a3;
                v27 = a5;
                v28 = v5;
                v29 = dest;
                v30 = v22 == a3;
                memcpy(dest, v19 + 3, v25);
                v31 = v29;
                a1 = v37;
                a2 = v35;
                v6 = v30;
                v5 = v28;
                a3 = v26;
                dest = &v31[v25];
                a5 = v27 - v25;
              }
              v5 += v24;
              if ( v20 >= v21 )
                return (unsigned __int16)v5;
            }
            v19 = &v23[v24];
            v18 = v20 - v24;
            if ( v20 == v24 )
            {
              v7 = v21 - v24;
              goto LABEL_4;
            }
          }
        }
        v7 = 0;
      }
    }
LABEL_4:
    v8 = a1[1] + 2LL;
    a2 -= v8;
    a1 += v8;
  }
  if ( v7 != 0 && v6 )
    return (unsigned int)-84;
  else
    return (unsigned int)-2;
}
