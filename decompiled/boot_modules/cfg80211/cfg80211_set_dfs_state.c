__int64 __fastcall cfg80211_set_dfs_state(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  int v7; // w9
  unsigned int v8; // w23
  int v9; // w8
  int v10; // w9
  unsigned int v11; // w22
  char v12; // w26
  __int64 v13; // x28
  int v14; // w10
  int v15; // w9
  int v16; // w8
  int v17; // w10
  int v18; // w8
  int v19; // w9
  int v20; // w9
  int v21; // w8
  int v22; // w9

  result = cfg80211_chandef_valid((__int64 *)a2);
  if ( (result & 1) != 0 )
  {
    v7 = *(_DWORD *)(a2 + 8);
    if ( v7 <= 4 )
    {
      if ( (unsigned int)v7 < 2 || (unsigned int)(v7 - 3) < 2 )
      {
        v8 = *(unsigned __int16 *)(a2 + 30);
        v9 = *(_DWORD *)(a2 + 12);
        if ( (unsigned int)v7 < 2 )
          goto LABEL_9;
        v10 = -40000;
LABEL_18:
        v11 = v10 + 1000 * v9 + 10000;
        goto LABEL_19;
      }
      if ( v7 == 2 )
      {
        v8 = *(unsigned __int16 *)(a2 + 30);
        v9 = *(_DWORD *)(a2 + 12);
        v10 = -20000;
        goto LABEL_18;
      }
    }
    else
    {
      if ( (unsigned int)(v7 - 6) < 7 )
      {
        v8 = *(unsigned __int16 *)(a2 + 30);
        v9 = *(_DWORD *)(a2 + 12);
LABEL_9:
        v11 = 1000 * v9;
LABEL_19:
        v12 = 1;
        while ( 1 )
        {
          if ( (v12 & 1) != 0 )
            v13 = 12;
          else
            v13 = 16;
          while ( 1 )
          {
            v15 = *(_DWORD *)(a2 + 8);
            v16 = *(_DWORD *)(a2 + v13);
            if ( v15 <= 4 )
            {
              if ( (unsigned int)v15 < 2 )
              {
LABEL_37:
                if ( v11 > 1000 * v16 )
                  return result;
                goto LABEL_43;
              }
              if ( (unsigned int)(v15 - 3) < 2 )
              {
                v17 = 40000;
                goto LABEL_42;
              }
              if ( v15 == 2 )
              {
                v17 = 20000;
                goto LABEL_42;
              }
LABEL_41:
              __break(0x800u);
              v17 = 2147483148;
              goto LABEL_42;
            }
            if ( (unsigned int)(v15 - 6) < 7 )
              goto LABEL_37;
            v17 = 80000;
            if ( v15 != 5 )
            {
              v17 = 160000;
              if ( v15 != 13 )
                goto LABEL_41;
            }
LABEL_42:
            if ( v11 > v17 + 1000 * v16 - 10000 )
              return result;
LABEL_43:
            if ( (v8 & 1) == 0 )
            {
              result = ieee80211_get_channel_khz(a1, v11);
              if ( result )
              {
                if ( (*(_BYTE *)(result + 12) & 8) != 0 )
                {
                  *(_DWORD *)(result + 44) = a3;
                  *(_QWORD *)(result + 48) = jiffies;
                }
              }
            }
            v11 += 20000;
            if ( (v12 & 1) == 0 || !*(_DWORD *)(a2 + 16) )
              goto LABEL_57;
            v19 = *(_DWORD *)(a2 + 8);
            v18 = *(_DWORD *)(a2 + 12);
            if ( v19 > 4 )
            {
              if ( (unsigned int)(v19 - 6) >= 7 )
              {
                v14 = 80000;
                if ( v19 != 5 )
                {
                  v14 = 160000;
                  if ( v19 != 13 )
                    goto LABEL_55;
                }
                goto LABEL_56;
              }
              goto LABEL_24;
            }
            if ( (unsigned int)v19 >= 2 )
              break;
LABEL_24:
            if ( v11 > 1000 * v18 )
              goto LABEL_58;
LABEL_57:
            v8 >>= 1;
          }
          if ( (unsigned int)(v19 - 3) < 2 )
          {
            v14 = 40000;
            goto LABEL_56;
          }
          if ( v19 == 2 )
          {
            v14 = 20000;
            goto LABEL_56;
          }
LABEL_55:
          __break(0x800u);
          v14 = 2147483148;
LABEL_56:
          if ( v11 <= v14 + 1000 * v18 - 10000 )
            goto LABEL_57;
LABEL_58:
          v20 = *(_DWORD *)(a2 + 8);
          v21 = *(_DWORD *)(a2 + 16);
          if ( v20 <= 4 )
          {
            if ( (unsigned int)v20 < 2 )
              goto LABEL_66;
            if ( (unsigned int)(v20 - 3) >= 2 )
            {
              if ( v20 != 2 )
                goto LABEL_69;
              v22 = -20000;
            }
            else
            {
              v22 = -40000;
            }
LABEL_71:
            v8 = 0;
            v12 = 0;
            v11 = v22 + 1000 * v21 + 10000;
          }
          else
          {
            if ( (unsigned int)(v20 - 6) >= 7 )
            {
              if ( v20 == 5 )
              {
                v22 = -80000;
              }
              else
              {
                if ( v20 == 13 )
                {
                  v22 = -160000;
                  goto LABEL_71;
                }
LABEL_69:
                __break(0x800u);
                v22 = -2147483148;
              }
              goto LABEL_71;
            }
LABEL_66:
            v11 = 1000 * v21;
            v8 = 0;
            v12 = 0;
          }
        }
      }
      if ( v7 == 5 )
      {
        v8 = *(unsigned __int16 *)(a2 + 30);
        v9 = *(_DWORD *)(a2 + 12);
        v10 = -80000;
        goto LABEL_18;
      }
      if ( v7 == 13 )
      {
        v8 = *(unsigned __int16 *)(a2 + 30);
        v9 = *(_DWORD *)(a2 + 12);
        v10 = -160000;
        goto LABEL_18;
      }
    }
  }
  __break(0x800u);
  return result;
}
