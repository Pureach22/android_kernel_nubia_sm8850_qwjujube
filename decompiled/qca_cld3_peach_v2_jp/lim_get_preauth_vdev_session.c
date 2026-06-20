__int64 __fastcall lim_get_preauth_vdev_session(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  _QWORD *vdev_by_macaddr_from_psoc; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  vdev_by_macaddr_from_psoc = wlan_objmgr_get_vdev_by_macaddr_from_psoc(
                                *(_QWORD *)(a1 + 21552),
                                *(_BYTE *)(*(_QWORD *)(a1 + 21560) + 40LL),
                                a3 + 4,
                                7u);
  if ( !vdev_by_macaddr_from_psoc )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: not able to find preauth vdev by mac %02x:%02x:%02x:**:**:%02x",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "lim_get_preauth_vdev_session",
             a3[4],
             a3[5],
             a3[6],
             a3[9]);
  v14 = (__int64)vdev_by_macaddr_from_psoc;
  cm_is_vdev_connecting(a2, v6, v7, v8, v9, v10, v11, v12, v13);
  return wlan_objmgr_vdev_release_ref(v14, 7u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
}
