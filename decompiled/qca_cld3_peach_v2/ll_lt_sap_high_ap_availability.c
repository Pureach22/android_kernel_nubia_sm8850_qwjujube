__int64 __fastcall ll_lt_sap_high_ap_availability(
        __int64 a1,
        int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w20
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  __int64 v35; // x8
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w19
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  _QWORD v71[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v72; // [xsp+18h] [xbp-28h]
  __int64 v73; // [xsp+20h] [xbp-20h]
  __int64 v74; // [xsp+28h] [xbp-18h]
  __int64 v75; // [xsp+30h] [xbp-10h]
  __int64 v76; // [xsp+38h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a1 + 168);
  v72 = 0;
  v73 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a4, a5, a6, a7, a8, a9, a10, a11, "ll_sap_get_vdev_priv_obj");
    goto LABEL_9;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_9:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d ll_sap obj null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ll_lt_sap_high_ap_availability",
      v11);
    goto LABEL_10;
  }
  if ( a2 == 5 )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: Invalid operation value received",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ll_lt_sap_high_ap_availability");
  }
  else if ( a2 || *(__int16 *)(comp_private_obj + 8) == -1 || *(__int16 *)(comp_private_obj + 10) == -1 )
  {
    v25 = _qdf_mem_malloc(0x10u, "ll_lt_sap_high_ap_availability", 839);
    if ( !v25 )
    {
      result = 2;
      goto LABEL_11;
    }
    *(_DWORD *)(v25 + 4) = a2;
    *(_DWORD *)(v25 + 8) = a3;
    *(_BYTE *)v25 = v11;
    v34 = v25;
    *(_DWORD *)(v25 + 12) = a2;
    v71[0] = 32;
    v71[1] = ll_lt_sap_high_ap_availability_ser_cb;
    LODWORD(v73) = 1700;
    LODWORD(v72) = 52;
    v35 = *(_QWORD *)(a1 + 216);
    BYTE4(v72) = 0;
    v74 = a1;
    v75 = v25;
    if ( v35 )
      v36 = *(_QWORD *)(v35 + 80);
    else
      v36 = 0;
    if ( (wlan_serialization_is_cmd_present_in_active_queue(
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v36,
            (unsigned int *)v71)
        & 1) != 0 )
    {
      qdf_trace_msg(
        0xA1u,
        8u,
        "%s: cmd already in active queue, update timeout",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "ll_lt_sap_high_ap_availability");
      wlan_serialization_update_timer((__int64)v71, v45, v46, v47, v48, v49, v50, v51, v52);
      v53 = ll_lt_sap_high_ap_availability_process(a1, v34);
      _qdf_mem_free(v34);
      result = v53;
      goto LABEL_11;
    }
    wlan_objmgr_vdev_get_ref(a1, 0x69u, v37, v38, v39, v40, v41, v42, v43, v44);
    if ( (unsigned int)wlan_serialization_request((unsigned int *)v71, v54, v55, v56, v57, v58, v59, v60, v61) < 2 )
    {
      result = 0;
      goto LABEL_11;
    }
    wlan_objmgr_vdev_release_ref(a1, 0x69u, v62, v63, v64, v65, v66, v67, v68, v69, v70);
    _qdf_mem_free(v34);
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: Invalid high AP availability request",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ll_lt_sap_high_ap_availability");
  }
LABEL_10:
  result = 4;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
