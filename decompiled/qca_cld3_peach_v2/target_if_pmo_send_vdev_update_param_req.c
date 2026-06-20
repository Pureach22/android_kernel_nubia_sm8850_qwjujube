__int64 __fastcall target_if_pmo_send_vdev_update_param_req(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x19
  __int64 result; // x0
  const char *v15; // x2

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    v15 = "%s: vdev ptr passed is NULL";
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v15 = "%s: psoc handle is NULL";
LABEL_10:
    qdf_trace_msg(0x49u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_pmo_send_vdev_update_param_req");
LABEL_11:
    result = 4;
    goto LABEL_12;
  }
  if ( a2 >= 4 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: invalid vdev param id %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_vdev_update_param_req",
      a2);
    goto LABEL_11;
  }
  v12 = *(_QWORD *)(v11 + 2800);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 16)) == 0 )
  {
    v15 = "%s: Invalid wmi handle";
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: set vdev param vdev_id: %d value: %d for param_id: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_pmo_send_vdev_update_param_req");
  result = wmi_unified_vdev_set_param_send(v13);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
