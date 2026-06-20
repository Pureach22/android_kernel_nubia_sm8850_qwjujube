__int64 __fastcall target_if_vdev_mgr_ext_tbttoffset_update_handler(
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
  __int64 v12; // x20
  __int64 v13; // x8
  __int64 v14; // x0
  const char *v15; // x2
  __int64 result; // x0
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  __int64 v18; // x0
  unsigned int v19; // w0
  unsigned int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  if ( !a1 || !a2 )
  {
    v15 = "%s: Invalid input";
    goto LABEL_15;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v15 = "%s: PSOC is NULL";
    goto LABEL_15;
  }
  v12 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v12 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(v12 + 1104) )
  {
LABEL_13:
    v15 = "%s: No Rx Ops";
    goto LABEL_15;
  }
  v13 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 16)) == 0 )
  {
    v15 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  if ( (unsigned int)wmi_extract_ext_tbttoffset_num_vdevs(v14, a2, &v20) )
  {
    v15 = "%s: WMI extract failed";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_ext_tbttoffset_update_handler");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v17 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1104);
  v18 = v20;
  if ( *((_DWORD *)v17 - 1) != -2129657465 )
    __break(0x8228u);
  v19 = v17(v18, 1);
  result = qdf_status_to_os_return(v19);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
