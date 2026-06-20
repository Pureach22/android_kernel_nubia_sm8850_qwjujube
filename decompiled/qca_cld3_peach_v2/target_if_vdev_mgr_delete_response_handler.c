__int64 __fastcall target_if_vdev_mgr_delete_response_handler(
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
  __int64 psoc_from_scn_hdl; // x0
  __int64 v12; // x22
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x19
  const char *v16; // x2
  __int64 result; // x0
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x1
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w20
  __int64 (__fastcall *v40)(__int64, unsigned __int8 *); // x8
  unsigned __int8 v41[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41[0] = 0;
  if ( !a1 || !a2 )
  {
    v16 = "%s: Invalid input";
    goto LABEL_15;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v16 = "%s: PSOC is NULL";
    goto LABEL_15;
  }
  v12 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v12 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(v12 + 1088) )
  {
LABEL_13:
    v16 = "%s: No Rx Ops";
    goto LABEL_15;
  }
  v13 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 16)) == 0 )
  {
    v16 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  v15 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_vdev_delete_resp(v14, a2, v41) )
  {
    v16 = "%s: WMI extract failed";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_delete_response_handler");
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  v18 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1136);
  v19 = v41[0];
  if ( *((_DWORD *)v18 - 1) != -672477040 )
    __break(0x8228u);
  v20 = v18(v15, v19);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev response timer is null VDEV_%d PSOC_%d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "target_if_vdev_mgr_delete_response_handler",
      v41[0],
      *(unsigned __int8 *)(v15 + 48));
    goto LABEL_16;
  }
  v29 = v20;
  target_if_release_vdev_cmd_rt_lock(v15, v41[0], v21, v22, v23, v24, v25, v26, v27, v28);
  v30 = target_if_vdev_mgr_rsp_timer_stop(v15, v29, 3);
  if ( v30 )
  {
    v39 = v30;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC_%d VDEV_%d: VDE MGR RSP Timer stop failed",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "target_if_vdev_mgr_delete_response_handler",
      *(unsigned __int8 *)(v15 + 48),
      v41[0]);
  }
  else
  {
    v40 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *))(v12 + 1088);
    if ( *((_DWORD *)v40 - 1) != -2103606579 )
      __break(0x8228u);
    v39 = v40(v15, v41);
    target_if_wake_lock_timeout_release(v15, 2);
  }
  result = qdf_status_to_os_return(v39);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
