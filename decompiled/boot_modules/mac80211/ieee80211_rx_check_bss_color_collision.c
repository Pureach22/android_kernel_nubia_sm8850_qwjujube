__int64 __fastcall ieee80211_rx_check_bss_color_collision(__int64 result)
{
  __int64 v1; // x10
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x19
  unsigned int v5; // w9
  __int64 v6; // x20
  unsigned int v7; // w10
  unsigned __int64 v8; // x9
  unsigned int v9; // t1
  int v10; // w11
  unsigned int v11; // w11
  __int64 v12; // x9
  char v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 16);
  if ( (*(_BYTE *)(*(_QWORD *)(v1 + 72) + 119LL) & 4) != 0 )
  {
    v2 = *(_QWORD *)(result + 8);
    v3 = *(_QWORD *)(v2 + 224);
    if ( (*(_QWORD *)(v1 + 96) & 0x8000000000000LL) == 0 )
    {
      v4 = *(_QWORD *)(*(_QWORD *)(result + 32) + 944LL);
      if ( (*(_BYTE *)(v4 + 830) & 1) == 0 && (*(_BYTE *)(v4 + 840) & 1) == 0 && *(_BYTE *)(v4 + 346) == 1 )
      {
        v5 = *(_DWORD *)(v2 + 112);
        if ( v5 >= 0x24 )
        {
          v6 = result;
          v13[0] = 36;
          result = cfg80211_find_elem_match(255, v3 + 36, v5 - 36, v13, 1, 0);
          if ( result )
          {
            v7 = *(unsigned __int8 *)(result + 1);
            if ( v7 >= 6 )
            {
              v9 = *(_DWORD *)(result + 3);
              result += 3;
              v8 = v9;
              if ( !result )
                goto LABEL_22;
              if ( (v8 & 0x4000) != 0 )
                v10 = 9;
              else
                v10 = 6;
              v11 = v10 + (((unsigned int)v8 >> 15) & 1);
              if ( (v8 & 0x20000) != 0 )
                v11 += 5;
              if ( v7 > v11 )
              {
LABEL_22:
                if ( (v8 & 0x80000000) == 0 )
                {
                  v12 = (v8 >> 24) & 0x3F;
                  if ( *(unsigned __int8 *)(v4 + 345) == (_DWORD)v12 )
                    result = ieee80211_obss_color_collision_notify(
                               *(_QWORD *)(v6 + 24) + 4720LL,
                               1LL << v12,
                               *(_DWORD *)(v4 + 24));
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
