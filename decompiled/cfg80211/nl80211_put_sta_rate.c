__int64 __fastcall nl80211_put_sta_rate(__int64 a1, __int16 *a2, unsigned int a3)
{
  __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w8
  __int64 result; // x0
  _WORD *v9; // x21
  unsigned int v10; // w0
  __int16 v11; // w22
  __int64 v12; // x1
  __int16 v13; // w8
  int v14; // w8
  char v15; // w8
  __int64 v16; // x0
  __int64 v17; // x1
  char v18; // w8
  __int64 v19; // x0
  __int64 v20; // x1
  int v21; // w8
  unsigned int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 216);
  v6 = *(unsigned int *)(a1 + 208);
  v7 = nla_put(a1, a3, 0, 0);
  result = 0;
  if ( (v7 & 0x80000000) == 0 )
  {
    v9 = (_WORD *)(v5 + v6);
    if ( v9 )
    {
      v10 = cfg80211_calculate_bitrate(a2);
      if ( v10 >= 0x10000 )
        v11 = 0;
      else
        v11 = v10;
      if ( !v10 || (v22 = v10, !(unsigned int)nla_put(a1, 5, 4, &v22)) )
      {
        if ( !v11 || (LOWORD(v22) = v11, !(unsigned int)nla_put(a1, 1, 2, &v22)) )
        {
          v12 = 25;
          switch ( *((_BYTE *)a2 + 6) )
          {
            case 0:
              goto LABEL_28;
            case 1:
              v12 = 12;
              goto LABEL_27;
            case 2:
              v12 = 11;
              goto LABEL_27;
            case 3:
              v12 = 3;
              goto LABEL_27;
            case 4:
              v12 = 8;
              goto LABEL_27;
            case 5:
              v12 = 10;
              goto LABEL_27;
            case 6:
              if ( (*a2 & 0x10) != 0 )
                goto LABEL_28;
              __break(0x800u);
              v13 = *a2;
              if ( (*a2 & 1) != 0 )
                goto LABEL_49;
              goto LABEL_29;
            case 7:
              v12 = 18;
              goto LABEL_27;
            case 8:
              if ( (*a2 & 0x80) != 0 )
                goto LABEL_28;
              __break(0x800u);
              v13 = *a2;
              if ( (*a2 & 1) != 0 )
                goto LABEL_49;
              goto LABEL_29;
            case 9:
              goto LABEL_27;
            case 0xA:
              v12 = 26;
              goto LABEL_27;
            case 0xB:
              v12 = 27;
              goto LABEL_27;
            case 0xC:
              v12 = 28;
              goto LABEL_27;
            case 0xD:
              v12 = 29;
LABEL_27:
              v14 = nla_put(a1, v12, 0, 0);
              result = 0;
              if ( v14 )
                goto LABEL_52;
LABEL_28:
              v13 = *a2;
              if ( (*a2 & 1) != 0 )
              {
LABEL_49:
                v18 = *((_BYTE *)a2 + 4);
                v19 = a1;
                v20 = 2;
              }
              else
              {
LABEL_29:
                if ( (v13 & 2) != 0 )
                {
                  LOBYTE(v22) = *((_BYTE *)a2 + 4);
                  if ( (unsigned int)nla_put(a1, 6, 1, &v22) )
                    break;
                  v18 = *((_BYTE *)a2 + 5);
                  v19 = a1;
                  v20 = 7;
                }
                else
                {
                  if ( (v13 & 0x10) != 0 )
                  {
                    LOBYTE(v22) = *((_BYTE *)a2 + 4);
                    if ( !(unsigned int)nla_put(a1, 13, 1, &v22) )
                    {
                      LOBYTE(v22) = *((_BYTE *)a2 + 5);
                      if ( !(unsigned int)nla_put(a1, 14, 1, &v22) )
                      {
                        LOBYTE(v22) = *((_BYTE *)a2 + 7);
                        if ( !(unsigned int)nla_put(a1, 15, 1, &v22) )
                        {
                          LOBYTE(v22) = *((_BYTE *)a2 + 8);
                          if ( !(unsigned int)nla_put(a1, 16, 1, &v22) )
                          {
                            if ( *((_BYTE *)a2 + 6) == 6 )
                            {
                              v15 = *((_BYTE *)a2 + 9);
                              v16 = a1;
                              v17 = 17;
LABEL_46:
                              LOBYTE(v22) = v15;
                              if ( (unsigned int)nla_put(v16, v17, 1, &v22) )
                                break;
                            }
LABEL_55:
                            result = 1;
                            *v9 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v9;
                            goto LABEL_52;
                          }
                        }
                      }
                    }
                    break;
                  }
                  if ( (v13 & 0x100) == 0 )
                  {
                    if ( (v13 & 0x80) == 0 )
                      goto LABEL_55;
                    LOBYTE(v22) = *((_BYTE *)a2 + 4);
                    if ( !(unsigned int)nla_put(a1, 19, 1, &v22) )
                    {
                      LOBYTE(v22) = *((_BYTE *)a2 + 5);
                      if ( !(unsigned int)nla_put(a1, 20, 1, &v22) )
                      {
                        LOBYTE(v22) = *((_BYTE *)a2 + 11);
                        if ( !(unsigned int)nla_put(a1, 21, 1, &v22) )
                        {
                          if ( *((_BYTE *)a2 + 6) == 8 )
                          {
                            v15 = *((_BYTE *)a2 + 12);
                            v16 = a1;
                            v17 = 22;
                            goto LABEL_46;
                          }
                          goto LABEL_55;
                        }
                      }
                    }
                    break;
                  }
                  LOBYTE(v22) = *((_BYTE *)a2 + 4);
                  if ( (unsigned int)nla_put(a1, 23, 1, &v22) )
                    break;
                  v18 = *((_BYTE *)a2 + 5);
                  v19 = a1;
                  v20 = 24;
                }
              }
              LOBYTE(v22) = v18;
              if ( (unsigned int)nla_put(v19, v20, 1, &v22) )
                break;
              if ( (*a2 & 4) == 0 )
                goto LABEL_55;
              v21 = nla_put(a1, 4, 0, 0);
              result = 0;
              if ( !v21 )
                goto LABEL_55;
              goto LABEL_52;
            default:
              __break(0x800u);
              v13 = *a2;
              if ( (*a2 & 1) != 0 )
                goto LABEL_49;
              goto LABEL_29;
          }
        }
      }
      result = 0;
    }
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
