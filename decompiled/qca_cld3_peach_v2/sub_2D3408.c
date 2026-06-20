__int64 __fastcall sub_2D3408(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x14

  return wlan_mlme_set_keepalive_period(a1, v7 | __ROR8__(a7, 63));
}
