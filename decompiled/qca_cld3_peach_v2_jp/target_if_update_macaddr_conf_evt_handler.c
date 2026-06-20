__int64 __fastcall target_if_update_macaddr_conf_evt_handler(
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
  __int64 v17; // x19
  __int64 v18; // x0
  void (*v19)(void); // x8
  __int64 v20; // x19
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v21) = 0;
  LOBYTE(v21) = 0;
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
  if ( (unsigned int)wmi_extract_update_mac_address_event(v13, a2, (char *)&v21 + 4, &v21) )
  {
    v15 = "%s: Failed to extract update MAC address event";
LABEL_10:
    qdf_trace_msg(
      0x68u,
      2u,
      v15,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_update_macaddr_conf_evt_handler",
      v21,
      v22);
    result = 4294967274LL;
    goto LABEL_11;
  }
  v17 = *(_QWORD *)(v14 + 2136);
  if ( !v17 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_19;
  }
  if ( !*(_QWORD *)(v17 + 1144) )
  {
LABEL_19:
    v15 = "%s: No Rx Ops";
    goto LABEL_10;
  }
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v14, BYTE4(v21), 49);
  if ( !v18 )
  {
    v15 = "%s: VDEV NULL";
    goto LABEL_10;
  }
  v19 = *(void (**)(void))(v17 + 1144);
  v20 = v18;
  if ( *((_DWORD *)v19 - 1) != -1710151299 )
    __break(0x8228u);
  v19();
  wlan_objmgr_vdev_release_ref(v20, 49);
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
