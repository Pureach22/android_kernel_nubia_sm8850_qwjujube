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
  __int64 v17; // x23
  __int64 v18; // x0
  __int64 v19; // x19
  char v20; // w21
  void (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x1
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x1
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+0h] [xbp-10h] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v43) = 0;
  LOBYTE(v43) = 0;
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
  if ( !(unsigned int)wmi_extract_update_mac_address_event(v13, a2, (char *)&v43 + 4, &v43) )
  {
    v17 = *(_QWORD *)(v14 + 2136);
    if ( v17 )
    {
      if ( *(_QWORD *)(v17 + 1144) )
      {
        v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                v14,
                BYTE4(v43),
                49);
        if ( !v18 )
        {
          v15 = "%s: VDEV NULL";
          goto LABEL_10;
        }
        v19 = v18;
        if ( (*(_BYTE *)(v18 + 67) & 2) == 0 )
        {
          v20 = 0;
LABEL_17:
          v21 = *(void (__fastcall **)(__int64, __int64))(v17 + 1144);
          v22 = (unsigned __int8)v43;
          if ( *((_DWORD *)v21 - 1) != -1710151299 )
            __break(0x8228u);
          v21(v19, v22);
          goto LABEL_29;
        }
        v23 = *(__int64 (__fastcall **)(__int64, __int64))(v17 + 1136);
        v24 = BYTE4(v43);
        if ( *((_DWORD *)v23 - 1) != -672477040 )
          __break(0x8228u);
        v25 = v23(v14, v24);
        if ( v25 )
        {
          v34 = target_if_vdev_mgr_rsp_timer_stop(v14, v25, 6);
          v20 = qdf_status_to_os_return(v34);
          if ( !v34 )
            goto LABEL_17;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: PSOC_%d VDEV_%d: VDE MGR RSP Timer stop failed",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "target_if_update_macaddr_conf_evt_handler",
            *(unsigned __int8 *)(v14 + 48),
            BYTE4(v43));
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev response timer is null VDEV_%d PSOC_%d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "target_if_update_macaddr_conf_evt_handler",
            BYTE4(v43),
            *(unsigned __int8 *)(v14 + 48));
          v20 = -22;
        }
LABEL_29:
        wlan_objmgr_vdev_release_ref(v19, 49);
        result = (unsigned int)v20;
        goto LABEL_11;
      }
    }
    else
    {
      qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    }
    v15 = "%s: No Rx Ops";
    goto LABEL_10;
  }
  v15 = "%s: Failed to extract update MAC address event";
LABEL_10:
  qdf_trace_msg(0x68u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_update_macaddr_conf_evt_handler", v43, v44);
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
