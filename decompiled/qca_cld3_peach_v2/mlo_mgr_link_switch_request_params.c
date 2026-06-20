__int64 __fastcall mlo_mgr_link_switch_request_params(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x19
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
  const char *v39; // x2
  const char *v40; // x3
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  _DWORD *v50; // x8
  __int64 result; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w20
  _DWORD v61[3]; // [xsp+1Ch] [xbp-14h] BYREF
  __int64 v62; // [xsp+28h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61[2] = 0;
  if ( !a2 )
  {
    v39 = "%s: Invalid params";
    v40 = "mlo_mgr_link_switch_request_params";
LABEL_16:
    qdf_trace_msg(0x8Fu, 2u, v39, a3, a4, a5, a6, a7, a8, a9, a10, v40);
    goto LABEL_17;
  }
  v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 90);
  v21 = *a2;
  if ( !v12 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid link switch VDEV %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_link_switch_request_params",
      v21);
    v61[0] = *a2;
    v61[1] = 1;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: VDEV %d link switch completed, %s",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "mlo_mgr_link_switch_send_cnf_cmd");
    v49 = *(_QWORD *)(a1 + 2128);
    if ( v49 == -1984 || (v50 = *(_DWORD **)(v49 + 2048)) == nullptr )
    {
      v39 = "%s: handler is not registered";
    }
    else
    {
      if ( *(v50 - 1) != 1127800684 )
        __break(0x8228u);
      if ( !((unsigned int (__fastcall *)(__int64, _DWORD *))v50)(a1, v61) )
        goto LABEL_17;
      v39 = "%s: Link switch status update to FW failed";
    }
    v40 = "mlo_mgr_link_switch_send_cnf_cmd";
    goto LABEL_16;
  }
  v22 = v12;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: VDEV %d, curr_link_id %d, new_link_id %d, new_freq %d, new_phymode: %d, reason %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "mlo_mgr_link_switch_request_params",
    v21,
    a2[1],
    a2[2],
    *((unsigned int *)a2 + 3),
    *((_DWORD *)a2 + 4),
    *((_DWORD *)a2 + 6));
  if ( (unsigned int)mlo_mgr_link_switch_validate_request(v22, a2, v23, v24, v25, v26, v27, v28, v29, v30) )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Link switch params/request invalid",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "mlo_mgr_link_switch_request_params");
    mlo_mgr_link_switch_complete(v22);
LABEL_17:
    result = 4;
    goto LABEL_18;
  }
  result = mlo_mgr_ser_link_switch_cmd(v22, (__int64 *)a2, v31, v32, v33, v34, v35, v36, v37, v38);
  if ( (_DWORD)result )
  {
    v60 = result;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to serialize link switch command",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "mlo_mgr_link_switch_request_params");
    mlo_mgr_link_switch_complete(v22);
    result = v60;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
