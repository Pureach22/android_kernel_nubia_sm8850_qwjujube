__int64 __fastcall target_if_pmkid_request_event_handler(__int64 a1, __int64 a2, unsigned int a3)
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
  __int64 v16; // x21
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  const char *v27; // x2
  __int64 result; // x0
  __int64 ext_hdl; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x0
  __int64 v40; // [xsp+0h] [xbp-10h] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v27 = "%s: psoc is null";
    goto LABEL_8;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v27 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v27, v6, v7, v8, v9, v10, v11, v12, v13, "target_if_pmkid_request_event_handler", v40, v41);
    result = 4294967274LL;
    goto LABEL_19;
  }
  v16 = psoc_from_scn_hdl;
  v17 = wmi_extract_roam_pmkid_request(v15, a2, a3, &v40);
  if ( v17 )
  {
    v26 = v17;
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
      "target_if_pmkid_request_event_handler",
      v17);
  }
  else
  {
    *(_QWORD *)(v40 + 8) = v16;
    ext_hdl = wlan_psoc_mlme_get_ext_hdl(v16);
    if ( ext_hdl )
    {
      v38 = *(__int64 (__fastcall **)(_QWORD))(ext_hdl + 7376);
      if ( v38 )
      {
        v39 = v40;
        if ( *((_DWORD *)v38 - 1) != 541138348 )
          __break(0x8228u);
        v26 = v38(v39);
        goto LABEL_16;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc legacy private object is NULL",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "target_if_cm_get_roam_rx_ops");
    }
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: No valid roam rx ops",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "target_if_pmkid_request_event_handler",
      v40,
      v41);
    v26 = 4;
  }
LABEL_16:
  if ( v40 )
    _qdf_mem_free(v40);
  result = qdf_status_to_os_return(v26);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
