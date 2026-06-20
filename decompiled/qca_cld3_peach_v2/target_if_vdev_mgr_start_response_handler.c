__int64 __fastcall target_if_vdev_mgr_start_response_handler(
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
  unsigned int v18; // w20
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x1
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  __int64 v31; // x0
  unsigned int v32; // w23
  __int64 v33; // x2
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x4
  unsigned int v53; // w19
  unsigned int v54; // w0
  __int64 (__fastcall *v55)(__int64, __int64 *); // x8
  __int64 v56; // [xsp+8h] [xbp-38h] BYREF
  __int64 v57; // [xsp+10h] [xbp-30h]
  __int64 v58; // [xsp+18h] [xbp-28h]
  __int64 v59; // [xsp+20h] [xbp-20h]
  __int64 v60; // [xsp+28h] [xbp-18h]
  int v61; // [xsp+30h] [xbp-10h]
  __int64 v62; // [xsp+38h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 0;
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
  if ( !*(_QWORD *)(v12 + 1072) )
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
  if ( (unsigned int)wmi_extract_vdev_start_resp(v14, a2, &v56) )
  {
    v16 = "%s: WMI extract failed";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_start_response_handler");
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  v18 = (unsigned __int8)v56;
  v19 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1136);
  v20 = (unsigned __int8)v56;
  if ( *((_DWORD *)v19 - 1) != -672477040 )
    __break(0x8228u);
  v21 = v19(v15, v20);
  if ( !v21 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev response timer is null VDEV_%d PSOC_%d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "target_if_vdev_mgr_start_response_handler",
      v18,
      *(unsigned __int8 *)(v15 + 48));
    goto LABEL_16;
  }
  v30 = v21;
  v31 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v15, v18, 49);
  if ( !v31 )
  {
    v16 = "%s: Null Vdev";
    goto LABEL_15;
  }
  v32 = *(_DWORD *)(v31 + 16);
  wlan_objmgr_vdev_release_ref(v31, 49);
  if ( HIDWORD(v57) == 1 )
  {
    v33 = 1;
    v34 = v15;
  }
  else
  {
    v33 = 0;
    v34 = v15;
    if ( v32 <= 6 && ((1 << v32) & 0x4A) != 0 )
    {
      target_if_wake_lock_timeout_release(v15, 0);
      target_if_release_vdev_cmd_rt_lock(v15, v18, v35, v36, v37, v38, v39, v40, v41, v42);
      v34 = v15;
      v33 = 0;
    }
  }
  v43 = target_if_vdev_mgr_rsp_timer_stop(v34, v30, v33);
  if ( v43 )
  {
    v52 = *(unsigned __int8 *)(v15 + 48);
    v53 = v43;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC_%d VDEV_%d: VDE MGR RSP Timer stop failed",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "target_if_vdev_mgr_start_response_handler",
      v52,
      v18);
    v54 = v53;
  }
  else
  {
    v55 = *(__int64 (__fastcall **)(__int64, __int64 *))(v12 + 1072);
    if ( *((_DWORD *)v55 - 1) != 926887046 )
      __break(0x8228u);
    v54 = v55(v15, &v56);
  }
  result = qdf_status_to_os_return(v54);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
