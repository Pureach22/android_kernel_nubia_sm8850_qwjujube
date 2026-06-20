__int64 __fastcall wlan_util_stats_get_rssi(__int64 result, unsigned int a2, unsigned int a3, char *a4)
{
  char v4; // w1
  char v5; // w8

  if ( (result & 1) == 0 )
  {
    if ( a3 >= 0x60 )
      v5 = 0;
    else
      v5 = a3;
    if ( a2 < 0x60 )
      v5 = a2;
    LOBYTE(a2) = v5 - 96;
    goto LABEL_13;
  }
  if ( a2 != 255 )
  {
LABEL_13:
    *a4 = a2;
    return result;
  }
  if ( a3 == 255 )
    v4 = -96;
  else
    v4 = a3;
  *a4 = v4;
  return result;
}
