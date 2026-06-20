__int64 __fastcall hdd_override_all_ps(__int64 *a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = a1[13];
  result = wlan_mlme_override_bmps_imps(*a1);
  *(_BYTE *)(v1 + 123) = 0;
  return result;
}
