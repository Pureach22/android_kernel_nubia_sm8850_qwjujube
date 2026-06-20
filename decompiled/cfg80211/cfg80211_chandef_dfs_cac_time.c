__int64 __fastcall cfg80211_chandef_dfs_cac_time(__int64 a1, __int64 a2)
{
  int v4; // w9
  unsigned int v5; // w22
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w21
  unsigned int v9; // w23
  unsigned int v10; // w24
  char v11; // w27
  __int64 v12; // x25
  int v13; // w10
  int v14; // w9
  int v15; // w8
  int v16; // w10
  __int64 channel_khz; // x0
  int v18; // w8
  int v19; // w8
  int v20; // w9
  int v21; // w9
  int v22; // w8
  int v23; // w9
  __int64 result; // x0
  unsigned int v26; // w9
  char v27; // [xsp+Ch] [xbp-4h]

  if ( (cfg80211_chandef_valid((__int64 *)a2) & 1) == 0 )
    goto LABEL_97;
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
LABEL_97:
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
    goto LABEL_97;
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
  v10 = 0;
  v11 = 1;
  v27 = 0;
LABEL_19:
  if ( (v11 & 1) != 0 )
    v12 = 12;
  else
    v12 = 16;
  while ( 1 )
  {
    v14 = *(_DWORD *)(a2 + 8);
    v15 = *(_DWORD *)(a2 + v12);
    if ( v14 > 4 )
      break;
    if ( (unsigned int)v14 >= 2 )
    {
      if ( (unsigned int)(v14 - 3) < 2 )
      {
        v16 = 40000;
        goto LABEL_41;
      }
      if ( v14 == 2 )
      {
        v16 = 20000;
        goto LABEL_41;
      }
      goto LABEL_40;
    }
LABEL_36:
    if ( v8 > 1000 * v15 )
      goto LABEL_83;
LABEL_42:
    if ( (v5 & 1) != 0 )
      goto LABEL_53;
    channel_khz = ieee80211_get_channel_khz(a1, v8);
    if ( !channel_khz || (v18 = *(_DWORD *)(channel_khz + 12), (v18 & 1) != 0) )
    {
      if ( (v11 & 1) != 0 )
        v10 = 0x7FFFFFFF;
      else
        v9 = 0x7FFFFFFF;
LABEL_53:
      v8 += 20000;
      if ( (v11 & 1) == 0 )
        goto LABEL_67;
      goto LABEL_54;
    }
    if ( (v18 & 8) == 0 )
      goto LABEL_53;
    if ( (v11 & 1) == 0 )
    {
      if ( (v27 & 1) != 0 && *(_DWORD *)(channel_khz + 56) > v9 )
        v9 = *(_DWORD *)(channel_khz + 56);
      v8 += 20000;
      goto LABEL_67;
    }
    v8 += 20000;
    if ( *(_DWORD *)(channel_khz + 56) > v10 )
      v10 = *(_DWORD *)(channel_khz + 56);
LABEL_54:
    if ( !*(_DWORD *)(a2 + 16) )
      goto LABEL_67;
    v20 = *(_DWORD *)(a2 + 8);
    v19 = *(_DWORD *)(a2 + 12);
    if ( v20 <= 4 )
    {
      if ( (unsigned int)v20 < 2 )
      {
LABEL_23:
        if ( v8 > 1000 * v19 )
          goto LABEL_68;
        goto LABEL_67;
      }
      if ( (unsigned int)(v20 - 3) < 2 )
      {
        v13 = 40000;
        goto LABEL_66;
      }
      if ( v20 == 2 )
      {
        v13 = 20000;
        goto LABEL_66;
      }
LABEL_65:
      __break(0x800u);
      v13 = 2147483148;
      goto LABEL_66;
    }
    if ( (unsigned int)(v20 - 6) < 7 )
      goto LABEL_23;
    v13 = 80000;
    if ( v20 != 5 )
    {
      v13 = 160000;
      if ( v20 != 13 )
        goto LABEL_65;
    }
LABEL_66:
    if ( v8 > v13 + 1000 * v19 - 10000 )
    {
LABEL_68:
      v21 = *(_DWORD *)(a2 + 8);
      v22 = *(_DWORD *)(a2 + 16);
      if ( v21 <= 4 )
      {
        if ( (unsigned int)v21 < 2 )
          goto LABEL_76;
        if ( (unsigned int)(v21 - 3) >= 2 )
        {
          if ( v21 != 2 )
            goto LABEL_79;
          v23 = -20000;
        }
        else
        {
          v23 = -40000;
        }
LABEL_81:
        v5 = 0;
        v11 = 0;
        v8 = v23 + 1000 * v22 + 10000;
      }
      else
      {
        if ( (unsigned int)(v21 - 6) >= 7 )
        {
          if ( v21 == 5 )
          {
            v23 = -80000;
          }
          else
          {
            if ( v21 == 13 )
            {
              v23 = -160000;
              goto LABEL_81;
            }
LABEL_79:
            __break(0x800u);
            v23 = -2147483148;
          }
          goto LABEL_81;
        }
LABEL_76:
        v8 = 1000 * v22;
        v5 = 0;
        v11 = 0;
      }
      v27 = 1;
      goto LABEL_19;
    }
LABEL_67:
    v5 >>= 1;
  }
  if ( (unsigned int)(v14 - 6) < 7 )
    goto LABEL_36;
  v16 = 80000;
  if ( v14 != 5 )
  {
    v16 = 160000;
    if ( v14 != 13 )
    {
LABEL_40:
      __break(0x800u);
      v16 = 2147483148;
    }
  }
LABEL_41:
  if ( v8 <= v16 + 1000 * v15 - 10000 )
    goto LABEL_42;
LABEL_83:
  if ( v9 == 0x7FFFFFFF && v10 == 0x7FFFFFFF )
    result = 0;
  else
    result = v9;
  if ( v10 != 0x7FFFFFFF )
  {
    if ( v10 <= v9 )
      v26 = v9;
    else
      v26 = v10;
    if ( v9 == 0x7FFFFFFF )
      return v10;
    else
      return v26;
  }
  return result;
}
