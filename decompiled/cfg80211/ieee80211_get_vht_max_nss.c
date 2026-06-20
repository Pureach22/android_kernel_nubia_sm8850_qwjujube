__int64 __fastcall ieee80211_get_vht_max_nss(__int64 a1, unsigned int a2, int a3, char a4, unsigned int a5)
{
  unsigned int v5; // w8
  unsigned int v6; // w9
  bool v7; // cc
  _BOOL4 v8; // w10
  _BOOL4 v9; // w12
  unsigned int v10; // w10
  int v11; // w11
  bool v12; // cc
  _BOOL4 v13; // w10
  int v14; // w12
  unsigned int v15; // w10
  int v16; // w11
  bool v17; // cc
  _BOOL4 v18; // w10
  int v19; // w12
  unsigned int v20; // w10
  int v21; // w11
  bool v22; // cc
  _BOOL4 v23; // w10
  int v24; // w12
  unsigned int v25; // w10
  int v26; // w11
  bool v27; // cc
  _BOOL4 v28; // w10
  int v29; // w12
  unsigned int v30; // w10
  int v31; // w11
  bool v32; // cc
  _BOOL4 v33; // w10
  int v34; // w12
  unsigned int v35; // w10
  int v36; // w11
  bool v37; // cc
  _BOOL4 v38; // w10
  int v39; // w12
  unsigned int v40; // w8
  bool v41; // cc
  int v44; // w9
  int v45; // w8
  unsigned int v46; // w9
  char v48; // w8
  char v50; // w8

  v5 = *(unsigned __int16 *)(a1 + 4);
  if ( v5 == 0xFFFF )
    return 0;
  if ( a3 > 9 || a5 >= 9 )
  {
    __break(0x800u);
    return 0;
  }
  else
  {
    if ( a3 == 8 )
      v6 = 1;
    else
      v6 = 2;
    if ( !a5 )
    {
      v7 = a3 > 7 && v6 > v5 >> 14;
      v8 = v7 || v5 >> 14 == 3;
      v9 = v7;
      a5 = v8 ? 0 : 8;
      if ( (v5 >> 14 == 3) != v9 )
      {
        v10 = (v5 >> 12) & 3;
        v11 = v10 == 3;
        v12 = a3 > 7 && v6 > v10;
        v13 = v12 || v10 == 3;
        v14 = v12;
        if ( !v13 )
          a5 = 7;
        if ( v11 != v14 )
        {
          v15 = (v5 >> 10) & 3;
          v16 = v15 == 3;
          v17 = a3 > 7 && v6 > v15;
          v18 = v17 || v15 == 3;
          v19 = v17;
          if ( !v18 )
            a5 = 6;
          if ( v16 != v19 )
          {
            v20 = (v5 >> 8) & 3;
            v21 = v20 == 3;
            v22 = a3 > 7 && v6 > v20;
            v23 = v22 || v20 == 3;
            v24 = v22;
            if ( !v23 )
              a5 = 5;
            if ( v21 != v24 )
            {
              v25 = (unsigned __int8)v5 >> 6;
              v26 = v25 == 3;
              v27 = a3 > 7 && v6 > v25;
              v28 = v27 || v25 == 3;
              v29 = v27;
              if ( !v28 )
                a5 = 4;
              if ( v26 != v29 )
              {
                v30 = (v5 >> 4) & 3;
                v31 = v30 == 3;
                v32 = a3 > 7 && v6 > v30;
                v33 = v32 || v30 == 3;
                v34 = v32;
                if ( !v33 )
                  a5 = 3;
                if ( v31 != v34 )
                {
                  v35 = (v5 >> 2) & 3;
                  v36 = v35 == 3;
                  v37 = a3 > 7 && v6 > v35;
                  v38 = v37 || v35 == 3;
                  v39 = v37;
                  if ( !v38 )
                    a5 = 2;
                  if ( v36 != v39 )
                  {
                    v40 = v5 & 3;
                    v41 = v6 <= v40 || a3 <= 7;
                    if ( v41 && v40 != 3 )
                      a5 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( (*(_WORD *)(a1 + 8) & 0x2000) == 0 )
      return a5;
    v44 = (*(_DWORD *)a1 >> 2) & 3;
    if ( (a4 & 1) != 0 )
      v45 = *(_DWORD *)a1 >> 30;
    else
      v45 = 0;
    if ( v44 == 3 || v44 == 2 && (unsigned int)(v45 - 1) < 2 )
      return 0;
    if ( a2 < 2 )
    {
      v46 = v44 - 1;
      v48 = v45 == 3 && v46 < 2;
      return a5 << v48;
    }
    else
    {
      if ( a2 != 2 )
      {
        if ( a2 != 3 )
          return a5;
        if ( !v44 && v45 == 1 )
          return 0;
        if ( !v44 && v45 == 2 )
          return a5 >> 1;
        if ( v44 || v45 != 3 )
        {
          if ( v44 == 1 && !v45 )
            return 0;
          if ( v44 == 1 && v45 == 1 )
            return a5 >> 1;
          if ( v44 != 1 || v45 != 2 )
            return a5;
        }
        return (3 * a5) >> 2;
      }
      if ( !v44 && (unsigned int)(v45 - 1) <= 1 )
        return a5 >> 1;
      if ( !v44 && v45 == 3 )
        return (3 * a5) >> 2;
      v50 = v44 == 1 && v45 == 3;
      return a5 << v50;
    }
  }
}
