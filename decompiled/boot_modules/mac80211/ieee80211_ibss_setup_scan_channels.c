__int64 __fastcall ieee80211_ibss_setup_scan_channels(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v3; // w8
  unsigned int v6; // w23
  unsigned int v7; // w24
  unsigned int v8; // w25
  char v9; // w26
  unsigned int v10; // w27
  int v11; // w9
  unsigned int v12; // w8
  unsigned int v13; // w21
  unsigned int v14; // w25
  unsigned int v15; // w22
  __int64 channel_khz; // x0
  unsigned int v17; // w24
  unsigned int v18; // w26
  unsigned int v20; // w22
  __int64 v21; // x0

  v3 = a2[2];
  if ( v3 > 3 )
  {
    if ( v3 == 5 )
    {
      v6 = 0;
      v7 = 160;
      goto LABEL_12;
    }
    if ( v3 == 4 )
    {
      v6 = a2[4];
      goto LABEL_8;
    }
  }
  else
  {
    if ( v3 == 2 )
    {
      v6 = 0;
      v7 = 40;
      goto LABEL_12;
    }
    if ( v3 == 3 )
    {
      v6 = 0;
LABEL_8:
      v7 = 80;
LABEL_12:
      v11 = a2[3];
      v12 = v7 >> 1;
      v10 = v11 - (v7 >> 1) + 10;
      v8 = (v7 >> 1) + v11 - 10;
      if ( v10 > v8 )
      {
        v13 = 0;
        if ( v6 )
        {
          v14 = 8;
          goto LABEL_25;
        }
        return v13;
      }
      v9 = 0;
      goto LABEL_16;
    }
  }
  v8 = a2[3];
  v6 = 0;
  v7 = 20;
  v9 = 1;
  v10 = v8;
LABEL_16:
  v13 = 0;
  v15 = 1000 * v10;
  while ( 1 )
  {
    channel_khz = ieee80211_get_channel_khz(a1, v15);
    if ( channel_khz )
      break;
LABEL_17:
    v10 += 20;
    v15 += 20000;
    if ( v10 > v8 )
      goto LABEL_21;
  }
  if ( v13 <= 7 )
  {
    *(_QWORD *)(a3 + 8LL * v13++) = channel_khz;
    goto LABEL_17;
  }
LABEL_21:
  if ( v6 )
  {
    a3 += 8LL * v13;
    v14 = 8 - v13;
    if ( (v9 & 1) != 0 )
    {
      v17 = v6;
LABEL_29:
      v18 = 0;
      v20 = 1000 * v17;
      while ( 1 )
      {
        v21 = ieee80211_get_channel_khz(a1, v20);
        if ( v21 )
        {
          if ( v18 >= v14 )
            goto LABEL_27;
          *(_QWORD *)(a3 + 8LL * v18++) = v21;
        }
        v17 += 20;
        v20 += 20000;
        if ( v17 > v6 )
          goto LABEL_27;
      }
    }
    v12 = v7 >> 1;
LABEL_25:
    v17 = v6 - v12 + 10;
    v6 = v6 + v12 - 10;
    if ( v17 <= v6 )
      goto LABEL_29;
    v18 = 0;
LABEL_27:
    v13 += v18;
  }
  return v13;
}
