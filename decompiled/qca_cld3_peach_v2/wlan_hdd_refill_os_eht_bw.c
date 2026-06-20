__int64 __fastcall wlan_hdd_refill_os_eht_bw(__int64 result, int a2)
{
  char v2; // w8

  if ( a2 == 4 )
    v2 = 7;
  else
    v2 = 0;
  *(_BYTE *)(result + 6) = v2;
  return result;
}
