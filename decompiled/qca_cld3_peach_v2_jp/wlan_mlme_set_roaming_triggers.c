__int64 __fastcall wlan_mlme_set_roaming_triggers(__int64 a1, int a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_DWORD *)(result + 1540) = a2;
  return result;
}
