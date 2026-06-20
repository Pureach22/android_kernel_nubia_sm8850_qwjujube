__int64 __fastcall target_if_cm_roam_send_vdev_set_pcl_cmd(
        __int64 a1,
        char *a2,
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
  __int64 v12; // x0
  char v13; // t1
  __int64 result; // x0
  const char *v15; // x2
  _QWORD v16[3]; // [xsp+8h] [xbp-18h] BYREF

  v16[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  v16[0] = 0;
  if ( !v10 )
  {
    v15 = "%s: PDEV is NULL";
    goto LABEL_7;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v15 = "%s: wmi_handle is null";
LABEL_7:
    qdf_trace_msg(0x49u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    result = 16;
    goto LABEL_8;
  }
  v13 = *a2;
  v16[1] = a2 + 12;
  LOBYTE(v16[0]) = v13;
  result = wmi_unified_vdev_set_pcl_cmd(v12, v16);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
