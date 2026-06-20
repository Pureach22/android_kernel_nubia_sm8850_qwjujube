__int64 __fastcall wlan_twt_setup_req(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v6; // x1
  __int64 v7; // x0
  unsigned int *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w22
  __int64 v18; // x2
  unsigned __int8 *v19; // x1
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  const char *v29; // x3
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  char v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x4
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w21
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x0
  __int64 v67; // x22
  unsigned __int8 *comp_private_obj; // x0
  unsigned int *v69; // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w23
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v96; // [xsp+8h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)a2;
  v95 = 0;
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v6, 94);
  if ( !v7 )
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: vdev:%d is NULL",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_twt_setup_req",
      *(unsigned int *)a2);
    result = 16;
    goto LABEL_16;
  }
  v17 = *(_DWORD *)(v7 + 16);
  wlan_objmgr_vdev_release_ref(v7, 0x5Eu, v8, v9, v10, v11, v12, v13, v14, v15, v16);
  v18 = *((unsigned int *)a2 + 3);
  v19 = a2 + 4;
  if ( (v17 & 0xFFFFFFFD) == 1 )
  {
    if ( (wlan_twt_is_setup_in_progress(a1, v19, v18) & 1) == 0 )
    {
      v28 = "%s: Goto Add session for p2pGo";
      v29 = "wlan_twt_setup_req";
      goto LABEL_5;
    }
LABEL_13:
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: TWT setup is in progress for dialog_id:%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_twt_setup_req",
      *((unsigned int *)a2 + 3));
    result = 6;
    goto LABEL_16;
  }
  v39 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, __int64))wlan_twt_is_max_sessions_reached)(a1, v19, v18);
  v48 = *((unsigned int *)a2 + 3);
  if ( (v39 & 1) != 0 )
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: TWT add failed(dialog_id:%d), another TWT already exists (max reached)",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_twt_setup_req",
      v48);
LABEL_11:
    result = 3;
    goto LABEL_16;
  }
  if ( (wlan_twt_is_setup_in_progress(a1, a2 + 4, v48) & 1) != 0 )
    goto LABEL_13;
  if ( (mlme_get_user_ps(a1, *(unsigned int *)a2) & 1) == 0 )
  {
    qdf_trace_msg(
      0x96u,
      3u,
      "%s: Power save mode disable",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "wlan_twt_setup_req");
    goto LABEL_11;
  }
  v66 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          *(unsigned int *)a2,
          94);
  if ( v66 )
  {
    v67 = v66;
    comp_private_obj = (unsigned __int8 *)wlan_objmgr_vdev_get_comp_private_obj(v66, 0x2Cu);
    if ( comp_private_obj )
    {
      v78 = *comp_private_obj;
      wlan_objmgr_vdev_release_ref(v67, 0x5Eu, v69, v70, v71, v72, v73, v74, v75, v76, v77);
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: is_twt_notify_in_progress: %d",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "wlan_is_twt_notify_in_progress",
        v78);
      if ( v78 == 1 )
      {
        qdf_trace_msg(
          0x96u,
          3u,
          "%s: Waiting for TWT Notify",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "wlan_twt_setup_req");
        result = 8;
        goto LABEL_16;
      }
      goto LABEL_6;
    }
    wlan_objmgr_vdev_release_ref(v67, 0x5Eu, v69, v70, v71, v72, v73, v74, v75, v76, v77);
    v28 = "%s: twt vdev private object is NULL";
  }
  else
  {
    v28 = "%s: vdev object not found";
  }
  v29 = "wlan_is_twt_notify_in_progress";
LABEL_5:
  qdf_trace_msg(0x96u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, v29);
LABEL_6:
  if ( (((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64, unsigned int *))wlan_twt_is_command_in_progress)(
          a1,
          a2 + 4,
          *((unsigned int *)a2 + 3),
          255,
          &v95)
      & 1) != 0 )
  {
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: Already TWT command:%d is in progress",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_twt_setup_req",
      v95);
    result = 24;
  }
  else
  {
    wlan_twt_add_session(a1, a2 + 4, *((unsigned int *)a2 + 3), a3);
    ((void (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64))wlan_twt_set_ack_context)(
      a1,
      a2 + 4,
      *((unsigned int *)a2 + 3),
      a3);
    ((void (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64))wlan_twt_set_command_in_progress)(
      a1,
      a2 + 4,
      *((unsigned int *)a2 + 3),
      1);
    result = tgt_twt_setup_req_send(a1, a2);
    if ( (_DWORD)result )
    {
      v57 = result;
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: tgt_twt_setup_req_send failed (status=%d)",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wlan_twt_setup_req",
        (unsigned int)result);
      wlan_twt_init_context(a1, a2 + 4, *((_DWORD *)a2 + 3));
      result = v57;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
