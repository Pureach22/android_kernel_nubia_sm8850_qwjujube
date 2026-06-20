__int64 __fastcall target_if_mlo_link_state_info_event_handler(
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
  __int64 v15; // x20
  const char *v16; // x2
  __int64 result; // x0
  _DWORD *v18; // x8
  unsigned int v19; // w0
  _QWORD v20[5]; // [xsp+8h] [xbp-38h] BYREF
  int v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  memset(v20, 0, sizeof(v20));
  if ( !a2 )
  {
    v16 = "%s: Received NULL event ptr from FW";
    goto LABEL_14;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v16 = "%s: PSOC is NULL";
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v12 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlo_get_rx_ops");
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(v12 + 1256) )
  {
LABEL_12:
    v16 = "%s: callback not registered";
    goto LABEL_14;
  }
  v13 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 16)) == 0 )
  {
    v16 = "%s: wmi_handle is null";
    goto LABEL_14;
  }
  v15 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_mlo_link_state_info_event(v14, a2, v20) )
  {
    v16 = "%s: Failed to extract link status event";
LABEL_14:
    qdf_trace_msg(0x49u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlo_link_state_info_event_handler");
    result = 4294967274LL;
    goto LABEL_15;
  }
  v18 = *(_DWORD **)(v12 + 1256);
  if ( *(v18 - 1) != 1497491624 )
    __break(0x8228u);
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD *))v18)(v15, v20);
  result = qdf_status_to_os_return(v19);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
