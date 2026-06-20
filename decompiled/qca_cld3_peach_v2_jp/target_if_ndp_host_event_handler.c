__int64 __fastcall target_if_ndp_host_event_handler(__int64 a1)
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
  unsigned int *v13; // x19
  unsigned int ndp_host_event; // w0
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+8h] [xbp-38h] BYREF
  unsigned int *v43; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v44)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v45)(); // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+28h] [xbp-18h]
  __int64 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = nullptr;
  v45 = nullptr;
  v42 = 0;
  v43 = nullptr;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v24 = "%s: psoc is null";
    goto LABEL_11;
  }
  v10 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v24 = "%s: wmi_handle is null.";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v24, v2, v3, v4, v5, v6, v7, v8, v9, "target_if_ndp_host_event_handler");
    goto LABEL_12;
  }
  v12 = _qdf_mem_malloc(0x10u, "target_if_ndp_host_event_handler", 798);
  if ( !v12 )
  {
    result = 4294967284LL;
    goto LABEL_13;
  }
  v13 = (unsigned int *)v12;
  ndp_host_event = wmi_extract_ndp_host_event(v11);
  if ( ndp_host_event )
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
      "target_if_ndp_host_event_handler",
      ndp_host_event);
  }
  else
  {
    if ( *(_QWORD *)v13 )
    {
      LOWORD(v42) = 17;
      v43 = v13;
      v44 = target_if_ndp_event_dispatcher;
      v45 = target_if_ndp_event_flush_cb;
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: NDP_HOST_UPDATE sent: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "target_if_ndp_host_event_handler",
        17);
      result = scheduler_post_message_debug(
                 0x49u,
                 0x49u,
                 73,
                 (unsigned __int16 *)&v42,
                 0x336u,
                 (__int64)"target_if_ndp_host_event_handler");
      if ( !(_DWORD)result )
        goto LABEL_13;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: failed to post msg, status: %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "target_if_ndp_host_event_handler",
        (unsigned int)result);
      if ( (unsigned __int16)v42 <= 0x11u && ((1 << v42) & 0x29EA0) != 0 && *(_QWORD *)v43 )
        wlan_objmgr_vdev_release_ref(*(_QWORD *)v43, 0x14u, v43, v34, v35, v36, v37, v38, v39, v40, v41);
      v23 = v43;
      goto LABEL_8;
    }
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev is null",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_ndp_host_event_handler");
  }
  v23 = v13;
LABEL_8:
  _qdf_mem_free((__int64)v23);
LABEL_12:
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
