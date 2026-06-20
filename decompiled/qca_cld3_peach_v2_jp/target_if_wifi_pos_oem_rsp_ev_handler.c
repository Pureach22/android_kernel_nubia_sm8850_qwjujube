__int64 __fastcall target_if_wifi_pos_oem_rsp_ev_handler(__int64 a1)
{
  __int64 psoc_from_scn_hdl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  __int64 ref; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x21
  __int64 psoc; // x0
  __int64 v23; // x22
  double (__fastcall *v24)(__int64, __int64 *); // x8
  double v25; // d0
  unsigned int v26; // w0
  unsigned int v27; // w20
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  const char *v36; // x2
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  __int64 v46; // [xsp+28h] [xbp-38h] BYREF
  __int64 v47; // [xsp+30h] [xbp-30h]
  __int64 v48; // [xsp+38h] [xbp-28h]
  __int64 v49; // [xsp+40h] [xbp-20h]
  __int64 v50; // [xsp+48h] [xbp-18h]
  __int64 v51; // [xsp+50h] [xbp-10h]
  __int64 v52; // [xsp+58h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v45 = "%s: psoc is null";
LABEL_13:
    qdf_trace_msg(0x49u, 2u, v45, v2, v3, v4, v5, v6, v7, v8, v9, "target_if_wifi_pos_oem_rsp_ev_handler", 0, 0);
    goto LABEL_14;
  }
  v10 = psoc_from_scn_hdl;
  ref = wlan_objmgr_psoc_get_ref(psoc_from_scn_hdl, 0x29u, v2, v3, v4, v5, v6, v7, v8, v9);
  v20 = *(_QWORD *)(v10 + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    v36 = "%s: wmi_handle is null";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v36, v12, v13, v14, v15, v16, v17, v18, v19, "target_if_wifi_pos_oem_rsp_ev_handler", 0, 0);
    wlan_objmgr_psoc_release_ref(v10, 0x29u, v37, v38, v39, v40, v41, v42, v43, v44);
LABEL_14:
    result = 28;
    goto LABEL_15;
  }
  psoc = wifi_pos_get_psoc(ref);
  if ( !wifi_pos_get_psoc_priv_obj(psoc) )
  {
    v36 = "%s: priv_obj is null";
    goto LABEL_11;
  }
  v23 = *(_QWORD *)(v10 + 2136);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_ops is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_wifi_pos_get_rxops");
    goto LABEL_18;
  }
  if ( !*(_QWORD *)(v23 + 376) )
  {
LABEL_18:
    wlan_objmgr_psoc_release_ref(v10, 0x29u, v12, v13, v14, v15, v16, v17, v18, v19);
    v45 = "%s: lmac callbacks not registered";
    goto LABEL_13;
  }
  wmi_extract_oem_response_param(v21);
  LODWORD(v46) = 0;
  v47 = 0;
  v24 = *(double (__fastcall **)(__int64, __int64 *))(v23 + 376);
  if ( *((_DWORD *)v24 - 1) != 907115100 )
    __break(0x8228u);
  v25 = v24(v10, &v46);
  v27 = v26;
  wlan_objmgr_psoc_release_ref(v10, 0x29u, v25, v28, v29, v30, v31, v32, v33, v34);
  result = v27;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
