bool __fastcall mlo_check_is_given_vdevs_on_same_mld(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x10
  _BOOL4 v15; // w19

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 1360);
    v15 = false;
    if ( v13 )
    {
      if ( (v14 = *(_QWORD *)(v13 + 24)) != 0 && *(unsigned __int8 *)(v14 + 168) == a3
        || (v13 = *(_QWORD *)(v13 + 32)) != 0 && (v13 = *(unsigned __int8 *)(v13 + 168), (_DWORD)v13 == a3) )
      {
        v15 = true;
      }
    }
    wlan_objmgr_vdev_release_ref(v4, 0x4Du, (unsigned int *)v13, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    return 0;
  }
  return v15;
}
