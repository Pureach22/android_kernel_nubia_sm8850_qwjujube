bool __fastcall mlo_roam_is_auth_status_connected(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned __int8 *v11; // x8
  _BOOL4 v12; // w19

  if ( a1
    && (v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1)) != 0 )
  {
    v11 = *(unsigned __int8 **)(v2 + 1360);
    if ( v11
      && (v11 = *((unsigned __int8 **)v11 + 278)) != nullptr
      && (v11 = *((unsigned __int8 **)v11 + 36)) != nullptr
      && (v11 = *((unsigned __int8 **)v11 + 18)) != nullptr )
    {
      v11 = (unsigned __int8 *)*v11;
      v12 = (_DWORD)v11 == 1;
    }
    else
    {
      v12 = 0;
    }
    wlan_objmgr_vdev_release_ref(v2, 1u, (unsigned int *)v11, v3, v4, v5, v6, v7, v8, v9, v10);
  }
  else
  {
    return 0;
  }
  return v12;
}
