__int64 __fastcall target_if_vdev_mgr_multi_vdev_restart_rel_ref(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x22
  __int64 v15; // x26
  int v19; // w1
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x25
  __int64 v22; // x24
  __int64 v23; // x0
  const char *v24; // x2
  __int64 v25; // x4

  v13 = *(_QWORD *)(result + 80);
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 2136)) == 0 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_14;
  }
  if ( !*(_QWORD *)(v15 + 1136) )
  {
LABEL_14:
    v24 = "%s: VDEV %d: No Rx Ops";
    v25 = (unsigned int)a4;
    return qdf_trace_msg(
             0x68u,
             2u,
             v24,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "target_if_vdev_mgr_multi_vdev_restart_rel_ref",
             v25);
  }
  if ( a4 < 0 )
    return result;
  v19 = 0;
  while ( 1 )
  {
    v20 = *(__int64 (__fastcall **)(_QWORD))(v15 + 1136);
    v21 = *(_QWORD *)(a2 + 8LL * v19);
    v22 = v19;
    if ( *((_DWORD *)v20 - 1) != -672477040 )
      __break(0x8228u);
    v23 = v20(v13);
    if ( !v23 )
      break;
    if ( a5 )
    {
      if ( *(_BYTE *)(a3 + v22) == 1 )
      {
        target_if_vdev_mgr_rsp_timer_stop(v13, v23, 1u);
        *(_BYTE *)(a3 + v22) = 0;
      }
    }
    result = wlan_objmgr_vdev_release_ref(v21, 49);
    v19 = v22 + 1;
    if ( (int)v22 + 1 > a4 )
      return result;
  }
  v24 = "%s: VDEV %d: No vdev rsp timer";
  v25 = (unsigned int)v22;
  return qdf_trace_msg(
           0x68u,
           2u,
           v24,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           "target_if_vdev_mgr_multi_vdev_restart_rel_ref",
           v25);
}
