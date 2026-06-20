__int64 __fastcall reg_rule_to_chan_bw_flags(__int64 a1, unsigned int *a2, int *a3)
{
  int v3; // w21
  unsigned int v5; // w20
  unsigned int v6; // w8
  unsigned int v7; // w22
  unsigned __int64 v8; // x9
  __int64 v9; // x13
  __int64 v10; // x12
  unsigned __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x14
  bool v14; // zf
  unsigned int v15; // w9
  unsigned int *v16; // x13
  unsigned int *v17; // x15
  unsigned int v18; // w12
  __int64 v19; // x16
  unsigned __int64 v20; // x9
  unsigned int *v21; // x10
  unsigned __int64 v22; // x9
  unsigned int v23; // w11
  bool v24; // cc
  int v25; // w10
  int v26; // w10
  int v27; // w10
  int v28; // w10
  unsigned int v29; // w23
  __int64 result; // x0
  signed int v31; // w8
  int v32; // w9
  int v33; // w8
  int v34; // w8
  int v35; // w8
  int v36; // w8
  int v37; // w8
  unsigned int v38; // w8

  v3 = *a3;
  v5 = *((unsigned __int16 *)a3 + 4) + 1000 * a3[1];
  v6 = a2[21];
  if ( (v6 & 0x800) != 0 )
  {
    v8 = *(unsigned int *)(a1 + 16);
    v9 = 0;
    v10 = a1 + 28;
    v11 = -1;
    v12 = 2;
    do
    {
      ++v11;
      v13 = v9 + 96;
      --v12;
      if ( v11 >= v8 )
        break;
      v14 = v10 + v9 == (_QWORD)a2;
      v9 += 96;
    }
    while ( !v14 );
    if ( (_DWORD)v8 == (_DWORD)v11 )
    {
      v15 = 0;
    }
    else
    {
      v16 = (unsigned int *)(v10 + v13);
      v17 = a2;
      do
      {
        v18 = *v17;
        if ( v13 == 96 )
          break;
        v19 = a1 + v13;
        v13 -= 96;
        v17 = (unsigned int *)(v19 - 164);
      }
      while ( *(_DWORD *)(v19 - 160) >= v18 );
      v20 = (unsigned int)(v8 - 1);
      if ( v11 > v20 )
        v20 = v11;
      v21 = a2;
      v22 = v20 + v12;
      while ( --v22 )
      {
        v23 = v21[1];
        v21 = v16;
        v24 = *v16 > v23;
        v16 += 24;
        if ( v24 )
          goto LABEL_20;
      }
      v23 = v21[1];
LABEL_20:
      v15 = v23 - v18;
    }
    if ( v15 >= 0x27100 )
      v25 = 160000;
    else
      v25 = v15;
    if ( (v6 & 0x40000) != 0 )
      v15 = v25;
    if ( v15 >= 0x13880 )
      v26 = 80000;
    else
      v26 = v15;
    if ( (v6 & 0x10000) != 0 )
      v15 = v26;
    if ( v15 >= 0x9C40 )
      v27 = 40000;
    else
      v27 = v15;
    if ( (v6 & 0x8000) != 0 )
      v15 = v27;
    if ( v15 >= 0x4E20 )
      v28 = 20000;
    else
      v28 = v15;
    if ( (~v6 & 0x6000) != 0 )
      v7 = v15;
    else
      v7 = v28;
  }
  else
  {
    v7 = a2[2];
  }
  if ( (cfg80211_does_bw_fit_range(a2, v5, 10000) & 1) != 0 )
    v29 = 0;
  else
    v29 = 4096;
  if ( (cfg80211_does_bw_fit_range(a2, v5, 20000) & 1) != 0 )
    result = v29;
  else
    result = v29 | 0x800;
  if ( v3 == 4 )
  {
    while ( v7 )
    {
      v31 = v7;
      if ( (v7 & 0x80000000) == 0 )
        v32 = v7;
      else
        v32 = v7 + 1;
      v7 = v32 >> 1;
      if ( !((int)(v5 - *a2 - (v32 >> 1)) % v31) )
      {
        v33 = v31 / 1000;
        if ( v33 <= 3 )
        {
          if ( v33 == 1 )
            return (unsigned int)result | 0x4000;
          if ( v33 == 2 )
            return (unsigned int)result | 0x8000;
        }
        else
        {
          switch ( v33 )
          {
            case 4:
              return (unsigned int)result | 0x10000;
            case 8:
              return (unsigned int)result | 0x20000;
            case 16:
              return (unsigned int)result | 0x40000;
          }
        }
        return (unsigned int)result | 1;
      }
    }
  }
  else
  {
    if ( v7 >> 4 >= 0x271 )
      v34 = result | 0x800;
    else
      v34 = 6144;
    if ( v7 >> 5 >= 0x271 )
      v34 = result;
    v35 = v34 | 0x30;
    if ( v7 >> 6 >= 0x271 )
      v35 = result;
    v36 = v35 | 0x80;
    if ( v7 >> 7 >= 0x271 )
      v36 = result;
    v37 = v36 | 0x100;
    if ( v7 >> 8 >= 0x271 )
      v37 = result;
    v38 = v37 | 0x80000;
    if ( v7 >> 9 >= 0x271 )
      return (unsigned int)result;
    else
      return v38;
  }
  return result;
}
