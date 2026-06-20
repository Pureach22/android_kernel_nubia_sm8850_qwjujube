__int64 __fastcall target_if_vdev_mgr_multi_vdev_restart_resp_handler(
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
  __int64 v12; // x23
  __int64 v13; // x19
  __int64 v14; // x8
  __int64 v15; // x21
  const char *v16; // x2
  __int64 result; // x0
  __int64 v18; // x24
  unsigned __int64 i; // x20
  const char *v20; // x2
  _DWORD *v21; // x8
  __int64 v22; // x0
  int v23; // w0
  __int64 (__fastcall *v24)(__int64, __int64 *); // x8
  unsigned int v25; // w0
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  StatusReg = 0;
  v26 = 0;
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
  v13 = psoc_from_scn_hdl;
  if ( !v12 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_vdev_mgr_get_rx_ops",
      v26,
      v27,
      StatusReg,
      v29);
LABEL_14:
    v16 = "%s: No Rx Ops";
    goto LABEL_15;
  }
  if ( !*(_QWORD *)(v12 + 1120) || !*(_QWORD *)(v12 + 1136) )
    goto LABEL_14;
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v16 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  qdf_mem_set(&v26, 0x18u, 0);
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  if ( (unsigned int)wmi_extract_multi_vdev_restart_resp_event(v15, a2, &v26) )
  {
    v16 = "%s: WMI extract failed";
LABEL_15:
    qdf_trace_msg(
      0x68u,
      2u,
      v16,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_vdev_mgr_multi_vdev_restart_resp_handler",
      v26,
      v27);
    result = 4294967274LL;
    goto LABEL_16;
  }
  v18 = *(unsigned __int8 *)(v13 + 54);
  if ( *(_BYTE *)(v13 + 54) )
  {
    for ( i = 0; v18 != i; ++i )
    {
      if ( ((*(unsigned __int64 *)((char *)&v27 + ((i >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> i) & 1) != 0 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: PSOC_%d VDEV_%d: Restart resp received",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "target_if_vdev_mgr_multi_vdev_restart_resp_handler",
          *(unsigned __int8 *)(v13 + 48),
          (unsigned int)i,
          v26,
          v27);
        v21 = *(_DWORD **)(v12 + 1136);
        if ( *(v21 - 1) != -672477040 )
          __break(0x8228u);
        v22 = ((__int64 (__fastcall *)(__int64, _QWORD))v21)(v13, (unsigned int)i);
        if ( v22 )
        {
          v23 = target_if_vdev_mgr_rsp_timer_stop(v13, v22, 1);
          v20 = "%s: PSOC_%d VDEV_%d: VDE MGR RSP Timer stop failed";
          if ( !v23 )
            continue;
        }
        else
        {
          v20 = "%s: PSOC_%d VDEV_%d: VDEV RSP is NULL";
        }
        qdf_trace_msg(
          0x68u,
          2u,
          v20,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "target_if_vdev_mgr_multi_vdev_restart_resp_handler",
          *(unsigned __int8 *)(v13 + 48),
          (unsigned int)i);
      }
    }
  }
  v24 = *(__int64 (__fastcall **)(__int64, __int64 *))(v12 + 1120);
  if ( *((_DWORD *)v24 - 1) != 1115142641 )
    __break(0x8228u);
  v25 = v24(v13, &v26);
  result = qdf_status_to_os_return(v25);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
