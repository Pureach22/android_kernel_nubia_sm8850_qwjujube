__int64 __fastcall dp_try_send_rps_ind(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_get_vdev_priv_obj");
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: dp link is NULL",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "dp_try_send_rps_ind");
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: dp link is NULL",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "dp_try_send_rps_ind");
  result = *(_QWORD *)(comp_private_obj + 32);
  if ( *(_BYTE *)(*(_QWORD *)result + 368LL) == 1 )
    return ((__int64 (*)(void))dp_send_rps_ind)();
  return result;
}
