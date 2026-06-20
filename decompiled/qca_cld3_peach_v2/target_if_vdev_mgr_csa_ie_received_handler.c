__int64 __fastcall target_if_vdev_mgr_csa_ie_received_handler(
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
  __int64 v18; // x0
  __int64 v19; // x20
  int v20; // w0
  _DWORD *v21; // x8
  __int64 v22; // x1
  _BYTE v23[4]; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  int v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v27 = 0;
  v25 = 0;
  v26 = 0;
  v24[0] = 0;
  v24[1] = 0;
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
  if ( !*(_QWORD *)(v12 + 1168) )
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
  if ( (unsigned int)wmi_extract_csa_ie_received_event(v14, a2, v23, v24) )
  {
    v16 = "%s: Extracting CSA IE Received event failed";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_csa_ie_received_handler");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v15, v23[0], 49);
  if ( !v18 )
  {
    v16 = "%s: Null Vdev";
    goto LABEL_15;
  }
  v19 = *(_QWORD *)(v18 + 216);
  wlan_objmgr_vdev_release_ref(v18, 49);
  if ( BYTE2(v25) && (wlan_reg_is_6ghz_op_class(v19) & 1) != 0 )
    v20 = wlan_reg_chan_band_to_freq(v19, LOBYTE(v24[0]), 4);
  else
    v20 = wlan_reg_legacy_chan_to_freq(v19, LOBYTE(v24[0]));
  v21 = *(_DWORD **)(v12 + 1168);
  v22 = v23[0];
  HIDWORD(v24[0]) = v20;
  if ( *(v21 - 1) != -536299403 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v21)(v15, v22, v24);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
