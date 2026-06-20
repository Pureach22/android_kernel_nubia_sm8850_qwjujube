__int64 __fastcall wlan_mlme_get_sap_inactivity_override(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *a2 = *(_BYTE *)(result + 2956);
  return result;
}
