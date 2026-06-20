__int64 __fastcall cm_add_fw_roam_cmd_to_list_n_ser(
        unsigned int *a1,
        __int64 a2,
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
  unsigned int v21; // w21
  __int64 v22; // x0
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
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v66; // [xsp+8h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(*(_QWORD *)a1 + 152LL) )
  {
    v12 = cm_add_roam_req_to_list(a1, a2);
    if ( (_DWORD)v12 )
    {
      v21 = v12;
      v22 = *(_QWORD *)a1;
      v65 = -1;
      cm_get_first_roam_command(v22, v13, v14, v15, v16, v17, v18, v19, v20);
      mlme_cm_osif_roam_abort_ind();
      if ( (unsigned int)cm_sm_deliver_event(
                           *(_QWORD *)a1,
                           0x1Fu,
                           4u,
                           (__int64)&v65,
                           v23,
                           v24,
                           v25,
                           v26,
                           v27,
                           v28,
                           v29,
                           v30) )
        cm_remove_cmd((__int64 *)a1, &v65, v31, v32, v33, v34, v35, v36, v37, v38);
      cm_free_roam_req_mem(a2 + 24, v31, v32, v33, v34, v35, v36, v37, v38);
      _qdf_mem_free(a2);
    }
    else
    {
      result = cm_add_fw_roam_dummy_ser_cb(v13, v14, v15, v16, v17, v18, v19, v20, v12, (__int64 *)a1, a2);
      if ( !(_DWORD)result )
        goto LABEL_8;
      v21 = result;
      v48 = *(_QWORD *)a1;
      v65 = *(_DWORD *)(a2 + 24);
      cm_get_first_roam_command(v48, v40, v41, v42, v43, v44, v45, v46, v47);
      mlme_cm_osif_roam_abort_ind();
      if ( (unsigned int)cm_sm_deliver_event(
                           *(_QWORD *)a1,
                           0x1Fu,
                           4u,
                           (__int64)&v65,
                           v49,
                           v50,
                           v51,
                           v52,
                           v53,
                           v54,
                           v55,
                           v56) )
        cm_remove_cmd((__int64 *)a1, &v65, v57, v58, v59, v60, v61, v62, v63, v64);
    }
    result = v21;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to find pdev for vdev id %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_add_fw_roam_cmd_to_list_n_ser",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL));
    result = 16;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
