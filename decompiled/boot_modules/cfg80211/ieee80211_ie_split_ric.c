unsigned __int64 __fastcall ieee80211_ie_split_ric(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        int a6,
        unsigned __int64 a7)
{
  unsigned __int64 v7; // x8
  __int64 v8; // x13
  int v9; // w14
  unsigned __int64 v10; // x15
  int v11; // w15
  int v12; // w16
  int v13; // w17
  int v14; // w7
  __int64 v15; // x13
  int v16; // w14
  unsigned __int64 v17; // x15
  int v18; // w15
  int i; // w16
  int v20; // w17
  int v21; // w7
  __int64 v22; // x13
  __int64 v23; // x13

  if ( a7 >= a2 )
    return a7;
  v7 = a7;
LABEL_3:
  v8 = a1 + v7;
  v9 = *(unsigned __int8 *)(a1 + v7);
  v10 = v7 + 2LL * (v9 == 255);
  if ( v10 >= a2 )
    return v7;
  if ( *(unsigned __int8 *)(a3 + a4 - 1) != 255 )
  {
    if ( a4 < 1 )
      return a7;
    v11 = *(unsigned __int8 *)(a1 + v10);
    v12 = 0;
    while ( 1 )
    {
      v14 = *(unsigned __int8 *)(a3 + v12);
      if ( v14 == 255 )
      {
        if ( v9 == 255 && *(unsigned __int8 *)(a3 + 1 + v12) == v11 )
          goto LABEL_41;
        v13 = 2;
      }
      else
      {
        v13 = 1;
        if ( v9 != 255 && v14 == v11 )
        {
          if ( !a6 || v9 != 57 )
          {
LABEL_41:
            v23 = *(unsigned __int8 *)(v8 + 1);
            v7 += v23 + 2;
            if ( v23 == 255 && v7 < a2 )
            {
              do
              {
                if ( *(unsigned __int8 *)(a1 + v7) != 242 )
                  break;
                v7 += *(unsigned __int8 *)(a1 + v7 + 1) + 2LL;
              }
              while ( v7 < a2 );
            }
            goto LABEL_45;
          }
          v15 = *(unsigned __int8 *)(v8 + 1);
          v7 += v15 + 2;
          if ( v15 == 255 && v7 < a2 )
          {
            do
            {
              if ( *(unsigned __int8 *)(a1 + v7) != 242 )
                break;
              v7 += *(unsigned __int8 *)(a1 + v7 + 1) + 2LL;
            }
            while ( v7 < a2 );
          }
          while ( v7 < a2 )
          {
            v16 = *(unsigned __int8 *)(a1 + v7);
            v17 = v7 + 2LL * (v16 == 255);
            if ( v17 >= a2 )
              break;
            if ( *(unsigned __int8 *)(a5 + a6 - 1) == 255 )
            {
              __break(0x800u);
            }
            else if ( a6 >= 1 )
            {
              v18 = *(unsigned __int8 *)(a1 + v17);
              for ( i = 0; i < a6; i += v20 )
              {
                v21 = *(unsigned __int8 *)(a5 + i);
                if ( v21 == 255 )
                {
                  if ( v16 == 255 && *(unsigned __int8 *)(a5 + 1 + i) == v18 )
                    goto LABEL_45;
                  v20 = 2;
                }
                else
                {
                  v20 = 1;
                  if ( v16 != 255 && v21 == v18 )
                    goto LABEL_45;
                }
              }
            }
            v22 = *(unsigned __int8 *)(a1 + v7 + 1);
            v7 += v22 + 2;
            if ( v22 == 255 && v7 < a2 )
            {
              do
              {
                if ( *(unsigned __int8 *)(a1 + v7) != 242 )
                  break;
                v7 += *(unsigned __int8 *)(a1 + v7 + 1) + 2LL;
              }
              while ( v7 < a2 );
            }
          }
LABEL_45:
          if ( v7 >= a2 )
            return v7;
          goto LABEL_3;
        }
      }
      v12 += v13;
      if ( v12 >= a4 )
        return v7;
    }
  }
  __break(0x800u);
  return v7;
}
