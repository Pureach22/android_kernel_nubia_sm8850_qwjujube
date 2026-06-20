__int64 __fastcall ieee80211_sta_set_expected_throughput(__int64 result, unsigned int a2)
{
  char v2; // w8
  int v3; // w10
  int v4; // w9

  if ( a2 && 6000LL * *(_QWORD *)(*(_QWORD *)(result - 2616) + 1608LL) > (unsigned __int64)a2 )
  {
    v2 = 0;
    v3 = 48828;
    v4 = 292968;
  }
  else
  {
    v2 = 1;
    v3 = 19531;
    v4 = 97656;
  }
  *(_DWORD *)(result - 1376) = v3;
  *(_DWORD *)(result - 1368) = v4;
  *(_BYTE *)(result - 1360) = v2;
  return result;
}
