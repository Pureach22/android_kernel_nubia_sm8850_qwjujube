__int64 __fastcall target_if_vdev_mgr_multiple_vdev_set_param_cmd(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x8
  const char *v11; // x2
  unsigned int v13; // w8

  if ( !a1 || !a2 )
  {
    v11 = "%s: Invalid input";
LABEL_11:
    qdf_trace_msg(0x68u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_multiple_vdev_set_param_cmd");
    return 4;
  }
  if ( !*(_QWORD *)(a1 + 80) )
  {
    v11 = "%s: PSOC is NULL";
    goto LABEL_11;
  }
  v10 = *(_QWORD **)(a1 + 1232);
  if ( !v10 || !*v10 )
  {
    v11 = "%s: PDEV WMI Handle is NULL!";
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a2 + 12) >= 7u )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: param->num_vdevs: %u exceed the limit",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_vdev_mgr_multiple_vdev_set_param_cmd");
    return 4;
  }
  v13 = *(_DWORD *)(a2 + 4);
  if ( v13 <= 0xE && ((0x777Fu >> v13) & 1) != 0 )
    v13 = dword_9DEB6C[v13];
  *(_DWORD *)(a2 + 4) = v13;
  return wmi_unified_send_multiple_vdev_set_param_cmd();
}
