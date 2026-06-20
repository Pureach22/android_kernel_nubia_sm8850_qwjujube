__int64 __fastcall target_if_send_audio_transport_switch_req_event_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 psoc_from_scn_hdl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x22
  __int64 v16; // x21
  __int64 comp_private_obj; // x0
  __int64 v18; // x23
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  __int64 result; // x0
  void (__fastcall *v30)(__int64, __int64); // x8
  __int64 v31; // x1
  unsigned int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v28 = "%s: psoc is null";
    goto LABEL_10;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v28 = "%s: wmi_handle is null";
LABEL_10:
    qdf_trace_msg(
      0x49u,
      2u,
      v28,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "target_if_send_audio_transport_switch_req_event_handler");
    goto LABEL_11;
  }
  v16 = psoc_from_scn_hdl;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(psoc_from_scn_hdl, 0x34u);
  if ( !comp_private_obj )
  {
    v28 = "%s: psoc_ll_sap_obj is null";
    goto LABEL_10;
  }
  if ( !*(_QWORD *)(comp_private_obj + 24) )
  {
    v28 = "%s: Invalid ll_sap rx ops";
    goto LABEL_10;
  }
  v18 = comp_private_obj;
  v19 = wmi_extract_audio_transport_switch_req_event(v15, a2, a3, &v32);
  if ( v19 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: parsing of event failed, %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "target_if_send_audio_transport_switch_req_event_handler",
      v19);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v30 = *(void (__fastcall **)(__int64, __int64))(v18 + 24);
  v31 = v32;
  if ( *((_DWORD *)v30 - 1) != -2014004587 )
    __break(0x8228u);
  v30(v16, v31);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
