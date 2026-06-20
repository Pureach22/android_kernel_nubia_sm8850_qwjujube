__int64 __fastcall target_if_vdev_mgr_wmi_handle_get(
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
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8
  __int64 *v12; // x8
  __int64 result; // x0
  const char *v14; // x2

  v11 = *(_QWORD *)(a1 + 216);
  if ( !v11 )
  {
    v14 = "%s: PDEV is NULL";
    goto LABEL_6;
  }
  v12 = *(__int64 **)(v11 + 1240);
  if ( !v12 || (result = *v12) == 0 )
  {
    v14 = "%s: wmi_handle is null";
LABEL_6:
    qdf_trace_msg(0x68u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_wmi_handle_get", v9, v10);
    return 0;
  }
  return result;
}
