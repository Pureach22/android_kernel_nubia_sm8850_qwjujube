__int64 __fastcall wlan_crypto_wapiie_check(_DWORD *a1, __int64 a2)
{
  unsigned int v2; // w8
  int v3; // w11
  int v4; // w12
  char v5; // w9
  unsigned __int8 *v6; // x8
  int v7; // w12
  int v8; // w17
  int v9; // w16
  int v10; // w10
  int v11; // w11
  int v12; // w12
  _DWORD *v13; // x8
  int v14; // w10

  v2 = *(unsigned __int8 *)(a2 + 1);
  *a1 |= 0x100u;
  if ( v2 >= 0x14 && *(_WORD *)(a2 + 2) == 1 )
  {
    v3 = *(unsigned __int8 *)(a2 + 4);
    v4 = (unsigned __int8)v3 | (*(unsigned __int8 *)(a2 + 5) << 8);
    v5 = v2 - 4;
    if ( ((4 * v4) | 2u) <= (unsigned __int8)(v2 - 4) )
    {
      v6 = (unsigned __int8 *)(a2 + 6);
      if ( v4 )
      {
        v5 -= 4 * v3;
        v7 = (*(unsigned __int8 *)(a2 + 5) << 8) + v3 + 1;
        while ( 1 )
        {
          v8 = *(_DWORD *)v6 == 24253440 ? 13 : -1;
          v9 = *(_DWORD *)v6 == 41030656 ? 12 : v8;
          if ( v9 < 0 )
            break;
          --v7;
          v6 += 4;
          a1[5] |= 1 << v9;
          if ( v7 <= 1 )
            goto LABEL_14;
        }
      }
      else
      {
LABEL_14:
        v10 = *v6;
        v11 = v6[1];
        v12 = (unsigned __int8)v10 | (v11 << 8);
        if ( ((4 * v12) | 2u) <= (unsigned __int8)(v5 - 2) )
        {
          v13 = v6 + 2;
          if ( v12 )
          {
            v14 = (v11 << 8) + v10 + 1;
            while ( *v13 == 24253440 )
            {
              --v14;
              ++v13;
              a1[1] |= 0x10u;
              if ( v14 <= 1 )
                goto LABEL_21;
            }
          }
          else if ( a1[1] )
          {
LABEL_21:
            if ( *v13 == 24253440 )
            {
              a1[2] |= 0x10u;
              return 0;
            }
          }
        }
      }
    }
  }
  return 4;
}
