__int64 __fastcall ieee80211_chandef_eht_oper(_BYTE *a1, unsigned int **a2)
{
  __int64 result; // x0
  unsigned int v5; // w8
  int v6; // w8
  int v7; // w8
  unsigned int *v8; // x9

  result = ieee80211_channel_to_freq_khz((unsigned __int8)a1[1], **a2);
  *((_DWORD *)a2 + 3) = (unsigned int)result / 0x3E8;
  v5 = *a1 & 7;
  if ( v5 <= 1 )
  {
    if ( (*a1 & 7) != 0 )
    {
      if ( v5 != 1 )
        return result;
      v7 = 2;
    }
    else
    {
      v7 = 1;
    }
    goto LABEL_13;
  }
  switch ( v5 )
  {
    case 2u:
      v7 = 3;
LABEL_13:
      *((_DWORD *)a2 + 2) = v7;
      return result;
    case 3u:
      v6 = 5;
      break;
    case 4u:
      v6 = 13;
      break;
    default:
      return result;
  }
  v8 = *a2;
  *((_DWORD *)a2 + 2) = v6;
  result = ieee80211_channel_to_freq_khz((unsigned __int8)a1[2], *v8);
  *((_DWORD *)a2 + 3) = (unsigned int)result / 0x3E8;
  return result;
}
