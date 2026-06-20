__int64 __fastcall ieee80211_operating_class_to_chandef(unsigned __int8 a1, _DWORD *a2, __int64 a3)
{
  char v6; // w8
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w10
  int v11; // w9
  int v12; // w9
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v6 = ieee80211_operating_class_to_band(a1, &v13);
  result = 0;
  if ( a2 && (v6 & 1) != 0 )
  {
    if ( v13 == *a2 )
    {
      v8 = a2[1];
      *(_QWORD *)a3 = a2;
      if ( v8 < 0x1743 )
      {
        if ( v8 < 0x1671 )
        {
          if ( v8 >> 2 <= 0x50E )
            v9 = 0;
          else
            v9 = v8 - 5180;
        }
        else
        {
          v9 = v8 - 5745;
        }
      }
      else
      {
        v9 = v8 - 5955;
      }
      result = 0;
      v10 = v9 / 0x14;
      v11 = 1;
      switch ( a1 )
      {
        case 0x51u:
        case 0x52u:
        case 0x73u:
        case 0x76u:
        case 0x79u:
        case 0x7Cu:
        case 0x7Du:
        case 0x83u:
        case 0x88u:
          goto LABEL_17;
        case 0x53u:
        case 0x74u:
        case 0x77u:
        case 0x7Au:
        case 0x7Eu:
          goto LABEL_13;
        case 0x54u:
        case 0x75u:
        case 0x78u:
        case 0x7Bu:
        case 0x7Fu:
          v8 -= 10;
          v11 = 2;
          goto LABEL_17;
        case 0x80u:
        case 0x85u:
          v11 = 3;
          v8 = v8 - 20 * (v10 & 3) + 30;
          goto LABEL_17;
        case 0x81u:
        case 0x86u:
          v11 = 5;
          v8 = v8 - 20 * (v10 & 7) + 70;
          goto LABEL_17;
        case 0x84u:
          if ( (v10 & 1) != 0 )
            v12 = -20;
          else
            v12 = 0;
          v8 += v12;
LABEL_13:
          v8 += 10;
          v11 = 2;
LABEL_17:
          result = 1;
          *(_DWORD *)(a3 + 8) = v11;
          *(_DWORD *)(a3 + 12) = v8;
          break;
        default:
          break;
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
