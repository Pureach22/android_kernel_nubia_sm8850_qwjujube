__int64 __fastcall target_if_quiet_offload_event_handler(
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
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x20
  const char *v15; // x2
  __int64 result; // x0
  __int64 v17; // x8
  _DWORD *v18; // x8
  _QWORD v19[3]; // [xsp+8h] [xbp-18h] BYREF

  v19[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v19, 0, 14);
  if ( !a2 )
  {
    v15 = "%s: Received NULL event ptr from FW";
    goto LABEL_10;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v15 = "%s: PSOC is NULL";
    goto LABEL_10;
  }
  v12 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 16)) == 0 )
  {
    v15 = "%s: wmi_handle is null";
    goto LABEL_10;
  }
  v14 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_quiet_offload_event(v13, a2, v19) )
  {
    v15 = "%s: Failed to extract quiet IE offload event";
LABEL_10:
    qdf_trace_msg(0x68u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_quiet_offload_event_handler");
    result = 4294967274LL;
    goto LABEL_11;
  }
  v17 = *(_QWORD *)(v14 + 2136);
  if ( !v17 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_18;
  }
  v18 = *(_DWORD **)(v17 + 1160);
  if ( !v18 )
  {
LABEL_18:
    v15 = "%s: No Rx Ops";
    goto LABEL_10;
  }
  if ( *(v18 - 1) != 1859760375 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *))v18)(v14, v19);
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
