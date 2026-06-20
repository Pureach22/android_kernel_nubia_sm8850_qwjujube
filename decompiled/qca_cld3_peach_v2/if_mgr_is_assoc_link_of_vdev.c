_QWORD *__fastcall if_mgr_is_assoc_link_of_vdev(__int64 a1, __int64 a2, char a3)
{
  _QWORD *result; // x0
  __int64 v5; // x20
  __int64 assoc_link_vdev; // x21
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  result = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a3, 0x4Eu);
  if ( result )
  {
    v5 = (__int64)result;
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(result);
    wlan_objmgr_vdev_release_ref(v5, 0x4Eu, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    return (_QWORD *)(assoc_link_vdev == a2);
  }
  return result;
}
