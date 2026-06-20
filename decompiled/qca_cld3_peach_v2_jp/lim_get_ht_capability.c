__int64 __fastcall lim_get_ht_capability(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 8);
  switch ( a2 )
  {
    case 0:
      result = *(unsigned __int8 *)(a1 + 12217);
      break;
    case 1:
      result = (*(unsigned __int16 *)(v3 + 1268) >> 14) & 1;
      break;
    case 2:
      result = *(unsigned __int8 *)(a1 + 12216);
      break;
    case 3:
      result = *(unsigned __int8 *)(a1 + 12215);
      break;
    case 4:
      result = (*(unsigned __int16 *)(v3 + 1268) >> 11) & 1;
      break;
    case 5:
      result = *(unsigned __int8 *)(a3 + 7265);
      break;
    case 6:
      result = *(_BYTE *)(a3 + 7267) & 3;
      break;
    case 7:
      result = *(unsigned __int8 *)(a3 + 7266) >> 7;
      break;
    case 8:
      if ( (*(_WORD *)(a3 + 7266) & 0x40) == 0 )
        goto LABEL_28;
      result = (*(unsigned __int8 *)(v3 + 1268) >> 6) & 1;
      break;
    case 9:
      if ( (*(_WORD *)(a3 + 7266) & 0x20) == 0 )
        goto LABEL_28;
      result = (*(unsigned __int8 *)(v3 + 1268) >> 5) & 1;
      break;
    case 10:
      result = (*(unsigned __int8 *)(v3 + 1268) >> 4) & 1;
      break;
    case 11:
      result = *(unsigned int *)(a1 + 12220);
      break;
    case 12:
      result = *(unsigned __int8 *)(a3 + 160);
      break;
    case 13:
      result = *(_BYTE *)(a3 + 7266) & 1;
      break;
    case 14:
      result = *(unsigned __int8 *)(a1 + 12226);
      break;
    case 15:
      result = *(unsigned __int8 *)(a1 + 12224);
      break;
    case 16:
      result = *(_BYTE *)(v3 + 1271) & 1;
      break;
    case 17:
      result = (*(unsigned __int8 *)(v3 + 1271) >> 1) & 3;
      break;
    case 18:
      result = *(_BYTE *)(v3 + 1272) & 3;
      break;
    case 19:
      result = *(_BYTE *)(v3 + 2677) & 1;
      break;
    case 20:
      result = *(_BYTE *)(v3 + 2678) & 1;
      break;
    case 21:
      result = *(unsigned __int8 *)(a1 + 12227);
      break;
    case 22:
      result = *(unsigned __int8 *)(a1 + 12228);
      break;
    case 23:
      result = *(unsigned __int8 *)(a3 + 7166);
      break;
    case 24:
      result = *(unsigned __int8 *)(a3 + 161);
      break;
    case 25:
      result = *(unsigned int *)(a3 + 164);
      break;
    case 26:
      if ( *(_DWORD *)(a3 + 88) == 1 )
        result = *(unsigned int *)(a3 + 280);
      else
        result = *(unsigned int *)(a1 + 12232);
      break;
    case 27:
      result = *(unsigned __int8 *)(a1 + 12240);
      break;
    case 28:
      result = *(unsigned __int8 *)(a1 + 12239);
      break;
    case 29:
      result = *(unsigned __int8 *)(a3 + 7167);
      break;
    case 30:
      result = *(unsigned __int8 *)(a1 + 12236);
      break;
    case 31:
      result = *(unsigned __int8 *)(a1 + 12237);
      break;
    default:
LABEL_28:
      result = 0;
      break;
  }
  return result;
}
