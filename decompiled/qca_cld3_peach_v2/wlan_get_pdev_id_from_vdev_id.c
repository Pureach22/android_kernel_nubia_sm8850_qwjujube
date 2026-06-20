__int64 __fastcall wlan_get_pdev_id_from_vdev_id(__int64 a1, __int64 a2, unsigned int a3)
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
  unsigned int v14; // w20

  v4 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 216);
    if ( v13 )
      v14 = *(unsigned __int8 *)(v13 + 40);
    else
      v14 = -1;
    wlan_objmgr_vdev_release_ref(v4, a3, (unsigned int *)v13, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    return (unsigned int)-1;
  }
  return v14;
}
