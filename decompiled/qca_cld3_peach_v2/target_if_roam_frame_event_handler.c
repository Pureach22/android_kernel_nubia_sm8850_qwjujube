__int64 __fastcall target_if_roam_frame_event_handler(__int64 a1, __int64 a2, unsigned int a3)
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
  __int64 v15; // x8
  __int64 v16; // x20
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 result; // x0
  __int64 ext_hdl; // x0
  unsigned int (__fastcall *v29)(__int64, __int64 *); // x8
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h]
  __int64 v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v30 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v26 = "%s: psoc is null";
    goto LABEL_8;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v26 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(
      0x49u,
      2u,
      v26,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "target_if_roam_frame_event_handler",
      v30,
      v31,
      v32,
      v33);
    goto LABEL_9;
  }
  v16 = psoc_from_scn_hdl;
  v17 = wmi_extract_roam_candidate_frame_event(v15, a2, a3, &v30);
  if ( v17 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: parsing of event failed, %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_roam_frame_event_handler",
      v17,
      v30,
      v31,
      v32,
      v33);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v16);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc legacy private object is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "target_if_cm_get_roam_rx_ops",
      v30,
      v31,
      v32,
      v33);
    goto LABEL_19;
  }
  v29 = *(unsigned int (__fastcall **)(__int64, __int64 *))(ext_hdl + 7608);
  if ( !v29 )
  {
LABEL_19:
    v26 = "%s: No valid roam rx ops";
    goto LABEL_8;
  }
  if ( *((_DWORD *)v29 - 1) != 461338757 )
    __break(0x8228u);
  if ( v29(v16, &v30) )
    result = 4294967274LL;
  else
    result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
