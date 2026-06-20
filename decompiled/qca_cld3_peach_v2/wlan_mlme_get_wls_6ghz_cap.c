__int64 __fastcall wlan_mlme_get_wls_6ghz_cap(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  char v4; // w8

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    v4 = *(_BYTE *)(result + 1088);
  else
    v4 = 0;
  *a2 = v4;
  return result;
}
