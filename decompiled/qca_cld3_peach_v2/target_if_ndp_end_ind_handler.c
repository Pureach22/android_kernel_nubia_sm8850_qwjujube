// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall target_if_ndp_end_ind_handler(__int64 a1)
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
  __int64 v11; // x20
  unsigned int ndp_end_ind; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // [xsp+8h] [xbp-38h] BYREF
  unsigned int *v40; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v41)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v42)(); // [xsp+20h] [xbp-20h]
  __int64 v43; // [xsp+28h] [xbp-18h]
  __int64 v44; // [xsp+30h] [xbp-10h]
  __int64 v45; // [xsp+38h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  v44 = 0;
  v41 = nullptr;
  v42 = nullptr;
  v39 = 0;
  v40 = nullptr;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v21 = "%s: psoc is null";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v21 = "%s: wmi_handle is null.";
LABEL_8:
    qdf_trace_msg(
      0x49u,
      2u,
      v21,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "target_if_ndp_end_ind_handler",
      0,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45);
    goto LABEL_9;
  }
  ndp_end_ind = wmi_extract_ndp_end_ind(*(_QWORD *)(v10 + 16));
  if ( ndp_end_ind )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: parsing of event failed, %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_ndp_end_ind_handler",
      ndp_end_ind);
  }
  else
  {
    off_0 = (_UNKNOWN *)((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(
                          **(_QWORD **)(v11 + 760),
                          11,
                          20);
    LOWORD(v39) = 12;
    v40 = nullptr;
    v41 = target_if_ndp_event_dispatcher;
    v42 = target_if_ndp_event_flush_cb;
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: NDP_END_IND sent: %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_ndp_end_ind_handler",
      12);
    result = scheduler_post_message_debug(
               0x49u,
               0x49u,
               73,
               (unsigned __int16 *)&v39,
               0x2AEu,
               (__int64)"target_if_ndp_end_ind_handler");
    if ( !(_DWORD)result )
      goto LABEL_10;
    if ( (unsigned __int16)v39 <= 0x11u && ((1 << v39) & 0x29EA0) != 0 && *(_QWORD *)v40 )
      wlan_objmgr_vdev_release_ref(*(_QWORD *)v40, 0x14u, v40, v31, v32, v33, v34, v35, v36, v37, v38);
    _qdf_mem_free((__int64)v40);
  }
LABEL_9:
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
