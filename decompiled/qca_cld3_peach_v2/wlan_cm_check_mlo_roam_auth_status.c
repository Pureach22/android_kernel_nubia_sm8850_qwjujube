__int64 __fastcall wlan_cm_check_mlo_roam_auth_status(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 216);
  if ( v1 )
    v1 = *(_QWORD *)(v1 + 80);
  return mlo_roam_is_auth_status_connected(v1, *(unsigned __int8 *)(a1 + 168)) & 1;
}
