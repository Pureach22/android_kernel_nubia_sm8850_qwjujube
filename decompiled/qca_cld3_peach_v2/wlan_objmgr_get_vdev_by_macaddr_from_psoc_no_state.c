_QWORD *__fastcall wlan_objmgr_get_vdev_by_macaddr_from_psoc_no_state(
        __int64 a1,
        char a2,
        const void *a3,
        unsigned int a4)
{
  _QWORD *result; // x0
  __int64 pdev_by_id; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  _QWORD *vdev_by_macaddr_from_pdev_no_state; // x20
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  result = nullptr;
  if ( a1 && a3 )
  {
    pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, a2, a4);
    if ( pdev_by_id )
    {
      v17 = pdev_by_id;
      vdev_by_macaddr_from_pdev_no_state = wlan_objmgr_get_vdev_by_macaddr_from_pdev_no_state(pdev_by_id, a3, a4);
      wlan_objmgr_pdev_release_ref(v17, a4, v19, v20, v21, v22, v23, v24, v25, v26, v27);
      return vdev_by_macaddr_from_pdev_no_state;
    }
    else
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: pdev is null",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "wlan_objmgr_get_vdev_by_macaddr_from_psoc_no_state");
      return nullptr;
    }
  }
  return result;
}
