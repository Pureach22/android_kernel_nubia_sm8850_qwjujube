__int64 __fastcall target_if_nan_rsp_handler(__int64 a1)
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
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  const char *v22; // x3
  __int64 result; // x0
  unsigned int nan_event_rsp; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 *v33; // x0
  __int64 *v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const void *v67; // [xsp+0h] [xbp-60h]
  __int64 v68; // [xsp+8h] [xbp-58h] BYREF
  __int64 *v69; // [xsp+10h] [xbp-50h]
  __int64 (__fastcall *v70)(); // [xsp+18h] [xbp-48h]
  __int64 (__fastcall *v71)(); // [xsp+20h] [xbp-40h]
  __int64 v72; // [xsp+28h] [xbp-38h]
  __int64 v73; // [xsp+30h] [xbp-30h]
  __int64 v74; // [xsp+38h] [xbp-28h] BYREF
  __int64 v75; // [xsp+40h] [xbp-20h]
  __int64 v76; // [xsp+48h] [xbp-18h]
  __int64 v77; // [xsp+50h] [xbp-10h]
  __int64 v78; // [xsp+58h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = nullptr;
  v71 = nullptr;
  v68 = 0;
  v69 = nullptr;
  v67 = nullptr;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v21 = "%s: psoc is null";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v21 = "%s: wmi_handle is null";
LABEL_8:
    v22 = "target_if_nan_rsp_handler";
    goto LABEL_9;
  }
  v12 = psoc_from_scn_hdl;
  if ( !wlan_objmgr_psoc_get_comp_private_obj(psoc_from_scn_hdl, 0xFu) )
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_get_nan_config",
      0,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78);
  nan_event_rsp = wmi_extract_nan_event_rsp(v11);
  if ( nan_event_rsp )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: parsing of event failed, %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "target_if_nan_rsp_handler",
      nan_event_rsp);
    goto LABEL_10;
  }
  v33 = (__int64 *)_qdf_mem_malloc((unsigned int)v76 + 32LL, "target_if_nan_rsp_handler", 983);
  if ( !v33 )
  {
    result = 4294967284LL;
    goto LABEL_11;
  }
  v34 = v33;
  qdf_mem_copy(v33, &v74, 0x20u);
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(v12, 0x14u, v35, v36, v37, v38, v39, v40, v41, v42) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to obtain psoc ref",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "target_if_nan_rsp_handler");
    result = 4294967283LL;
    goto LABEL_11;
  }
  *v34 = v12;
  qdf_mem_copy((char *)v34 + 26, v67, *((unsigned int *)v34 + 4));
  v69 = v34;
  LOWORD(v68) = *((_DWORD *)v34 + 2);
  v70 = target_if_nan_event_dispatcher;
  v71 = target_if_nan_event_flush_cb;
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: NAN Event sent: %d",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    "target_if_nan_rsp_handler",
    (unsigned __int16)v68);
  result = scheduler_post_message_debug(
             0x49u,
             0x49u,
             73,
             (unsigned __int16 *)&v68,
             0x3EDu,
             (__int64)"target_if_nan_rsp_handler");
  if ( !(_DWORD)result )
    goto LABEL_11;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: failed to post msg, status: %d",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    "target_if_nan_rsp_handler",
    (unsigned int)result);
  if ( v69 )
  {
    wlan_objmgr_psoc_release_ref(*v69, 0x14u, v2, v3, v4, v5, v6, v7, v8, v9);
    _qdf_mem_free((__int64)v69);
    goto LABEL_10;
  }
  v21 = "%s: Empty message for NAN Discovery event";
  v22 = "target_if_nan_event_flush_cb";
LABEL_9:
  qdf_trace_msg(0x49u, 2u, v21, v2, v3, v4, v5, v6, v7, v8, v9, v22, v67);
LABEL_10:
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
