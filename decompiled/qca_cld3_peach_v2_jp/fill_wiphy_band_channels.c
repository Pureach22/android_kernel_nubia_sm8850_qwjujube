__int64 __fastcall fill_wiphy_band_channels(__int64 result, __int64 a2, unsigned __int8 a3)
{
  __int64 *v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  _DWORD *v7; // x11
  __int64 v8; // x13
  __int64 v9; // x14
  int v10; // w15
  int v11; // w12
  __int64 v12; // x13
  unsigned int v13; // w14

  v3 = *(__int64 **)(result + 8LL * a3 + 328);
  if ( v3 )
  {
    v4 = *((unsigned int *)v3 + 5);
    if ( (_DWORD)v4 )
    {
      v5 = *v3;
      v6 = 0;
      while ( 1 )
      {
        v7 = (_DWORD *)(v5 + (v6 << 6));
        v8 = 0;
        while ( v7[1] != *(_DWORD *)(a2 + v8) )
        {
          v8 += 36;
          if ( v8 == 3672 )
            goto LABEL_5;
        }
        v7[3] = 0;
        v9 = a2 + v8;
        v7[5] = *(_DWORD *)(a2 + v8 + 16);
        v10 = *(_DWORD *)(a2 + v8 + 12);
        if ( (v10 & 1) != 0 )
          break;
        v11 = 0;
        if ( (v10 & 2) != 0 )
          goto LABEL_14;
LABEL_15:
        if ( (v10 & 8) != 0 )
        {
          v11 |= 8u;
          v7[3] = v11;
          v10 = *(_DWORD *)(v9 + 12);
          if ( (v10 & 0x40) == 0 )
          {
LABEL_17:
            if ( (v10 & 0x200) == 0 )
              goto LABEL_19;
LABEL_18:
            v11 |= 0x200u;
            v7[3] = v11;
            goto LABEL_19;
          }
        }
        else if ( (v10 & 0x40) == 0 )
        {
          goto LABEL_17;
        }
        v11 |= 0x40u;
        v7[3] = v11;
        if ( (*(_DWORD *)(v9 + 12) & 0x200) != 0 )
          goto LABEL_18;
LABEL_19:
        v12 = a2 + v8;
        v13 = *(unsigned __int16 *)(v12 + 22);
        if ( v13 <= 9 )
        {
          v11 |= 0x1000u;
          v7[3] = v11;
          v13 = *(unsigned __int16 *)(v12 + 22);
          if ( v13 > 0x13 )
          {
LABEL_21:
            if ( v13 > 0x27 )
              goto LABEL_22;
            goto LABEL_30;
          }
        }
        else if ( v13 > 0x13 )
        {
          goto LABEL_21;
        }
        v11 |= 0x800u;
        v7[3] = v11;
        v13 = *(unsigned __int16 *)(v12 + 22);
        if ( v13 > 0x27 )
        {
LABEL_22:
          if ( v13 <= 0x4F )
            goto LABEL_31;
          goto LABEL_23;
        }
LABEL_30:
        v11 |= 0x30u;
        v7[3] = v11;
        v13 = *(unsigned __int16 *)(v12 + 22);
        if ( v13 <= 0x4F )
        {
LABEL_31:
          v11 |= 0x80u;
          v7[3] = v11;
          if ( *(unsigned __int16 *)(v12 + 22) > 0x9Fu )
            goto LABEL_4;
          goto LABEL_32;
        }
LABEL_23:
        if ( v13 > 0x9F )
          goto LABEL_4;
LABEL_32:
        v11 |= 0x100u;
        v7[3] = v11;
LABEL_4:
        v7[8] = v11;
LABEL_5:
        if ( ++v6 == v4 )
          return result;
      }
      v11 = 1;
      v7[3] = 1;
      v10 = *(_DWORD *)(v9 + 12);
      if ( (v10 & 2) == 0 )
        goto LABEL_15;
LABEL_14:
      v11 |= 2u;
      v7[3] = v11;
      v10 = *(_DWORD *)(v9 + 12);
      goto LABEL_15;
    }
  }
  return result;
}
