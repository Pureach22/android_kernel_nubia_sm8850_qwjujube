__int64 __fastcall target_if_ndp_end_rsp_handler(__int64 a1)
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
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x0
  unsigned int *v13; // x20
  unsigned int ndp_end_rsp; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x0
  const char *v24; // x2
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  unsigned int *v35; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v36)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v37)(); // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = nullptr;
  v37 = nullptr;
  v34 = 0;
  v35 = nullptr;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v24 = "%s: psoc is null";
    goto LABEL_9;
  }
  v10 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v24 = "%s: wmi_handle is null.";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v24, v2, v3, v4, v5, v6, v7, v8, v9, "target_if_ndp_end_rsp_handler");
    goto LABEL_10;
  }
  v12 = _qdf_mem_malloc(0x18u, "target_if_ndp_end_rsp_handler", 584);
  if ( !v12 )
  {
    result = 4294967284LL;
    goto LABEL_11;
  }
  v13 = (unsigned int *)v12;
  ndp_end_rsp = wmi_extract_ndp_end_rsp(v11);
  if ( ndp_end_rsp )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: parsing of event failed, %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_ndp_end_rsp_handler",
      ndp_end_rsp);
    v23 = v13;
  }
  else
  {
    LOWORD(v34) = 9;
    v35 = v13;
    v36 = target_if_ndp_event_dispatcher;
    v37 = target_if_ndp_event_flush_cb;
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: NDP_END_RSP sent: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_ndp_end_rsp_handler",
      9);
    result = scheduler_post_message_debug(
               0x49u,
               0x49u,
               73,
               (unsigned __int16 *)&v34,
               0x25Au,
               (__int64)"target_if_ndp_end_rsp_handler");
    if ( !(_DWORD)result )
      goto LABEL_11;
    if ( (unsigned __int16)v34 <= 0x11u && ((1 << v34) & 0x29EA0) != 0 && *(_QWORD *)v35 )
      wlan_objmgr_vdev_release_ref(*(_QWORD *)v35, 0x14u, v35, v26, v27, v28, v29, v30, v31, v32, v33);
    v23 = v35;
  }
  _qdf_mem_free((__int64)v23);
LABEL_10:
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
