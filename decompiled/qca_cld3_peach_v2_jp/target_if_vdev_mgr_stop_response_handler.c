__int64 __fastcall target_if_vdev_mgr_stop_response_handler(
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
  __int64 v12; // x21
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
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  unsigned int v39; // w19
  unsigned int v40; // w0
  __int64 (__fastcall *v41)(__int64, char *); // x9
  __int64 v42; // [xsp+0h] [xbp-10h] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v42) = 0;
  LODWORD(v42) = 0;
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
  if ( !*(_QWORD *)(v12 + 1080) )
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
  if ( (unsigned int)wmi_extract_vdev_stopped_param(v14, a2, &v42) )
  {
    v16 = "%s: WMI extract failed";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_stop_response_handler", v42, v43);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  v18 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1136);
  v19 = (unsigned int)v42;
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
      "target_if_vdev_mgr_stop_response_handler",
      (unsigned int)v42,
      *(unsigned __int8 *)(v15 + 48));
    goto LABEL_16;
  }
  v29 = target_if_vdev_mgr_rsp_timer_stop(v15, v20, 2);
  if ( v29 )
  {
    v38 = *(unsigned __int8 *)(v15 + 48);
    v39 = v29;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC_%d VDEV_%d: VDE MGR RSP Timer stop failed",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "target_if_vdev_mgr_stop_response_handler",
      v38,
      (unsigned int)v42);
    v40 = v39;
  }
  else
  {
    v41 = *(__int64 (__fastcall **)(__int64, char *))(v12 + 1080);
    BYTE4(v42) = v42;
    if ( *((_DWORD *)v41 - 1) != -552073721 )
      __break(0x8229u);
    v40 = v41(v15, (char *)&v42 + 4);
  }
  result = qdf_status_to_os_return(v40);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
