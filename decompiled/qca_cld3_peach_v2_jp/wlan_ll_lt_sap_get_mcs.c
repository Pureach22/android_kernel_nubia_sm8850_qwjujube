bool __fastcall wlan_ll_lt_sap_get_mcs(__int64 a1, unsigned __int8 a2, _DWORD *a3)
{
  _BOOL8 result; // x0

  result = policy_mgr_is_vdev_ll_lt_sap(a1, a2);
  if ( result )
    *a3 = 15;
  return result;
}
