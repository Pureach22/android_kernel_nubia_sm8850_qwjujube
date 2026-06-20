__int64 __fastcall cfg80211_wdev_channel_allowed(unsigned int *a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  unsigned __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w25
  int v7; // w24
  __int64 v8; // x23
  unsigned int v9; // w0
  unsigned __int64 v10; // x8
  int v11; // w13
  unsigned int v12; // w10
  unsigned __int64 v13; // x11
  bool v14; // w14
  unsigned int *v15; // x9
  unsigned int v16; // w12
  unsigned int v17; // w13
  unsigned int *v18; // x15
  int v19; // w13
  unsigned __int64 v20; // x11
  unsigned int v21; // w12
  unsigned int v22; // w10
  bool v23; // w13
  __int64 result; // x0
  __int64 v25; // [xsp+8h] [xbp-28h] BYREF
  __int64 v26; // [xsp+10h] [xbp-20h]
  __int64 v27; // [xsp+18h] [xbp-18h]
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v3 = *(_DWORD *)(*(_QWORD *)a1 + 1496LL);
  if ( v3 )
  {
    v4 = a1[369];
    if ( ((-1LL << v3) ^ v4) != 0xFFFFFFFFFFFFFFFFLL )
    {
      v27 = 0;
      v28 = 0;
      v25 = 0;
      v26 = 0;
      cfg80211_chandef_create((__int64)&v25, a2, 1);
      if ( *(int *)(v2 + 1496) < 1 )
      {
LABEL_21:
        result = 0;
        goto LABEL_22;
      }
      v5 = 0;
      while ( 1 )
      {
        if ( ((v4 >> v5) & 1) != 0 )
        {
          v6 = HIDWORD(v26);
          v7 = WORD2(v28);
          v8 = *(_QWORD *)(v2 + 1504) + 32 * v5;
          v9 = nl80211_chan_width_to_mhz(v26);
          v10 = *(unsigned int *)(v8 + 8);
          if ( (int)v10 >= 1 )
          {
            v11 = v7 + 1000 * v6;
            v12 = v9 >> 1;
            v13 = 0;
            v14 = 1;
            v15 = (unsigned int *)(*(_QWORD *)v8 + 4LL);
            v16 = (v9 >> 1) + v11;
            v17 = v11 - (v9 >> 1);
            v18 = v15;
            do
            {
              if ( v17 >= *(v18 - 1) && v16 <= *v18 )
                break;
              ++v13;
              v18 += 2;
              v14 = v13 < v10;
            }
            while ( v10 != v13 );
            if ( v14 )
            {
              v19 = 1000 * v27;
              if ( !(1000 * (_DWORD)v27) )
                break;
              v20 = 0;
              v21 = v19 + v12;
              v22 = v19 - v12;
              v23 = 1;
              do
              {
                if ( v22 >= *(v15 - 1) && v21 <= *v15 )
                  break;
                ++v20;
                v15 += 2;
                v23 = v20 < v10;
              }
              while ( v10 != v20 );
              if ( v23 )
                break;
            }
          }
        }
        if ( ++v5 >= *(int *)(v2 + 1496) )
          goto LABEL_21;
      }
    }
  }
  result = 1;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
