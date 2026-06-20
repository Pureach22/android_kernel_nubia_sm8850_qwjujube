bool __fastcall cfg80211_chandef_dfs_usable(__int64 a1, __int64 a2)
{
  int v4; // w9
  unsigned int v5; // w22
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w21
  int v9; // w23
  char v10; // w25
  __int64 v11; // x26
  int v12; // w10
  int v13; // w9
  int v14; // w8
  int v15; // w10
  unsigned int v16; // w24
  __int64 channel_khz; // x0
  int v18; // w8
  int v19; // w8
  int v20; // w8
  int v21; // w9
  int v22; // w9
  int v23; // w8
  int v24; // w9

  if ( (cfg80211_chandef_valid((__int64 *)a2) & 1) == 0 )
    goto LABEL_81;
  v4 = *(_DWORD *)(a2 + 8);
  if ( v4 > 4 )
  {
    if ( (unsigned int)(v4 - 6) < 7 )
    {
      v5 = *(unsigned __int16 *)(a2 + 30);
      v6 = *(_DWORD *)(a2 + 12);
LABEL_9:
      v8 = 1000 * v6;
      goto LABEL_18;
    }
    if ( v4 == 5 )
    {
      v5 = *(unsigned __int16 *)(a2 + 30);
      v6 = *(_DWORD *)(a2 + 12);
      v7 = -80000;
      goto LABEL_17;
    }
    if ( v4 == 13 )
    {
      v5 = *(unsigned __int16 *)(a2 + 30);
      v6 = *(_DWORD *)(a2 + 12);
      v7 = -160000;
      goto LABEL_17;
    }
LABEL_81:
    __break(0x800u);
    return 0;
  }
  if ( (unsigned int)v4 >= 2 && (unsigned int)(v4 - 3) >= 2 )
  {
    if ( v4 == 2 )
    {
      v5 = *(unsigned __int16 *)(a2 + 30);
      v6 = *(_DWORD *)(a2 + 12);
      v7 = -20000;
      goto LABEL_17;
    }
    goto LABEL_81;
  }
  v5 = *(unsigned __int16 *)(a2 + 30);
  v6 = *(_DWORD *)(a2 + 12);
  if ( (unsigned int)v4 < 2 )
    goto LABEL_9;
  v7 = -40000;
LABEL_17:
  v8 = v7 + 1000 * v6 + 10000;
LABEL_18:
  v9 = 0;
  v10 = 1;
LABEL_19:
  if ( (v10 & 1) != 0 )
    v11 = 12;
  else
    v11 = 16;
  while ( 1 )
  {
    v13 = *(_DWORD *)(a2 + 8);
    v14 = *(_DWORD *)(a2 + v11);
    if ( v13 <= 4 )
    {
      if ( (unsigned int)v13 < 2 )
      {
LABEL_36:
        v16 = 1000 * v14;
        if ( v8 > 1000 * v14 )
          return v8 > v16 && v9 > 0;
        goto LABEL_42;
      }
      if ( (unsigned int)(v13 - 3) < 2 )
      {
        v15 = 40000;
        goto LABEL_41;
      }
      if ( v13 == 2 )
      {
        v15 = 20000;
        goto LABEL_41;
      }
LABEL_40:
      __break(0x800u);
      v15 = 2147483148;
      goto LABEL_41;
    }
    if ( (unsigned int)(v13 - 6) < 7 )
      goto LABEL_36;
    v15 = 80000;
    if ( v13 != 5 )
    {
      v15 = 160000;
      if ( v13 != 13 )
        goto LABEL_40;
    }
LABEL_41:
    v16 = v15 + 1000 * v14 - 10000;
    if ( v8 > v16 )
      return v8 > v16 && v9 > 0;
LABEL_42:
    if ( (v5 & 1) != 0 )
      goto LABEL_48;
    channel_khz = ieee80211_get_channel_khz(a1, v8);
    if ( !channel_khz )
      break;
    v18 = *(_DWORD *)(channel_khz + 12);
    if ( (v18 & 1) != 0 )
      break;
    if ( (v18 & 8) != 0 )
    {
      v19 = *(_DWORD *)(channel_khz + 44);
      if ( !v19 )
      {
        ++v9;
        v8 += 20000;
        if ( (v10 & 1) == 0 )
          goto LABEL_60;
        goto LABEL_49;
      }
      if ( v19 == 1 )
        return v8 > v16 && v9 > 0;
    }
LABEL_48:
    v8 += 20000;
    if ( (v10 & 1) == 0 )
      goto LABEL_60;
LABEL_49:
    if ( !*(_DWORD *)(a2 + 16) )
      goto LABEL_60;
    v21 = *(_DWORD *)(a2 + 8);
    v20 = *(_DWORD *)(a2 + 12);
    if ( v21 > 4 )
    {
      if ( (unsigned int)(v21 - 6) >= 7 )
      {
        v12 = 80000;
        if ( v21 == 5 || (v12 = 160000, v21 == 13) )
        {
LABEL_59:
          if ( v8 <= v12 + 1000 * v20 - 10000 )
            goto LABEL_60;
LABEL_61:
          v22 = *(_DWORD *)(a2 + 8);
          v23 = *(_DWORD *)(a2 + 16);
          if ( v22 <= 4 )
          {
            if ( (unsigned int)v22 < 2 )
            {
LABEL_69:
              v8 = 1000 * v23;
              v5 = 0;
              v10 = 0;
              goto LABEL_19;
            }
            if ( (unsigned int)(v22 - 3) < 2 )
            {
              v24 = -40000;
              goto LABEL_74;
            }
            if ( v22 == 2 )
            {
              v24 = -20000;
              goto LABEL_74;
            }
          }
          else
          {
            if ( (unsigned int)(v22 - 6) < 7 )
              goto LABEL_69;
            if ( v22 == 5 )
            {
              v24 = -80000;
              goto LABEL_74;
            }
            if ( v22 == 13 )
            {
              v24 = -160000;
LABEL_74:
              v5 = 0;
              v10 = 0;
              v8 = v24 + 1000 * v23 + 10000;
              goto LABEL_19;
            }
          }
          __break(0x800u);
          v24 = -2147483148;
          goto LABEL_74;
        }
LABEL_58:
        __break(0x800u);
        v12 = 2147483148;
        goto LABEL_59;
      }
    }
    else if ( (unsigned int)v21 >= 2 )
    {
      if ( (unsigned int)(v21 - 3) < 2 )
      {
        v12 = 40000;
        goto LABEL_59;
      }
      if ( v21 == 2 )
      {
        v12 = 20000;
        goto LABEL_59;
      }
      goto LABEL_58;
    }
    if ( v8 > 1000 * v20 )
      goto LABEL_61;
LABEL_60:
    v5 >>= 1;
  }
  return v8 > v16 && v9 > 0;
}
