__int64 __fastcall target_if_mlo_vdev_tid_to_link_map_event_handler(
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
  unsigned int v17; // w0
  __int64 result; // x0
  __int64 (__fastcall *v19)(__int64, __int64 *); // x8
  unsigned int v20; // w0
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  int v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v21 = 0;
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
  if ( !*(_QWORD *)(v12 + 1240) )
  {
LABEL_12:
    v16 = "%s: callback not registered";
    v17 = 73;
LABEL_15:
    qdf_trace_msg(v17, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlo_vdev_tid_to_link_map_event_handler");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v13 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 16)) == 0 )
  {
    v16 = "%s: wmi_handle is null";
    goto LABEL_14;
  }
  v15 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_mlo_vdev_tid_to_link_map_event(v14, a2, &v21) )
  {
    v16 = "%s: Failed to extract TID-to-link mapping event";
LABEL_14:
    v17 = 104;
    goto LABEL_15;
  }
  v19 = *(__int64 (__fastcall **)(__int64, __int64 *))(v12 + 1240);
  if ( *((_DWORD *)v19 - 1) != -1666180180 )
    __break(0x8228u);
  v20 = v19(v15, &v21);
  result = qdf_status_to_os_return(v20);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
