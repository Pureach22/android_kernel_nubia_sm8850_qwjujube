__int64 __fastcall target_if_cm_roam_send_roam_init(
        __int64 a1,
        unsigned __int8 *a2,
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
  __int64 *v11; // x8
  __int64 result; // x0
  const char *v13; // x2

  _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v13 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || !*v11 )
  {
    v13 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    result = 16;
    goto LABEL_9;
  }
  if ( *a2 >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev_id: %d is invalid, reject the req: param id %d val %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_vdev_set_param");
    result = 4;
  }
  else
  {
    result = wmi_unified_vdev_set_param_send(*v11);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
