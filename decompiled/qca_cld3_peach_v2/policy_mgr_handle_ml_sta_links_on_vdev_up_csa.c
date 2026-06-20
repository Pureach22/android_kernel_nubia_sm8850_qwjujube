__int64 __fastcall policy_mgr_handle_ml_sta_links_on_vdev_up_csa(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int8 v3; // w19
  __int64 v6; // x0
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  unsigned int v17; // w21
  __int64 context; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  __int64 v28; // x1
  const char *v29; // x2
  unsigned int v30; // w1
  __int64 result; // x0
  int v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w23
  int v42; // w23
  const char *v43; // x2
  unsigned int v44; // w1
  unsigned int v45; // w22
  unsigned int v46; // w23
  unsigned int v47; // w24
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned __int8 affected_links_for_go_sap_cli; // w0
  unsigned __int8 *v57; // x4
  __int64 v58; // x0
  unsigned int v59; // w1
  unsigned int v60; // w2
  int v61; // w3
  char v62; // w25
  unsigned int v63; // w23
  unsigned int v64; // w24
  unsigned int v65; // w25
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  _BYTE v74[4]; // [xsp+4h] [xbp-8Ch] BYREF
  _BYTE v75[4]; // [xsp+8h] [xbp-88h] BYREF
  _BYTE v76[4]; // [xsp+Ch] [xbp-84h] BYREF
  unsigned int v77; // [xsp+10h] [xbp-80h] BYREF
  unsigned int v78; // [xsp+14h] [xbp-7Ch] BYREF
  int v79; // [xsp+18h] [xbp-78h] BYREF
  char v80; // [xsp+1Ch] [xbp-74h]
  int v81; // [xsp+20h] [xbp-70h] BYREF
  char v82; // [xsp+24h] [xbp-6Ch]
  int v83; // [xsp+28h] [xbp-68h] BYREF
  char v84; // [xsp+2Ch] [xbp-64h]
  int v85; // [xsp+30h] [xbp-60h] BYREF
  char v86; // [xsp+34h] [xbp-5Ch]
  int v87; // [xsp+38h] [xbp-58h] BYREF
  char v88; // [xsp+3Ch] [xbp-54h]
  _QWORD v89[2]; // [xsp+40h] [xbp-50h] BYREF
  int v90; // [xsp+50h] [xbp-40h]
  _QWORD v91[2]; // [xsp+58h] [xbp-38h] BYREF
  int v92; // [xsp+68h] [xbp-28h]
  _QWORD v93[2]; // [xsp+70h] [xbp-20h] BYREF
  int v94; // [xsp+80h] [xbp-10h]
  __int64 v95; // [xsp+88h] [xbp-8h]

  v3 = a3;
  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 24);
  if ( v6 )
  {
    if ( a2 > 3 )
    {
LABEL_11:
      result = wlan_objmgr_vdev_release_ref(v6, 0x18u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
      goto LABEL_12;
    }
    v16 = v6;
    v17 = *(unsigned __int8 *)(v6 + 168);
    v76[0] = 0;
    v75[0] = 0;
    v74[0] = 0;
    v82 = 0;
    v81 = 0;
    v80 = 0;
    v79 = 0;
    v92 = 0;
    v91[0] = 0;
    v91[1] = 0;
    v90 = 0;
    v89[0] = 0;
    v89[1] = 0;
    context = policy_mgr_get_context(a1);
    if ( !context )
    {
      v29 = "%s: Invalid Context";
      v30 = 2;
      goto LABEL_9;
    }
    v27 = context;
    if ( (unsigned int)policy_mgr_handle_ml_sta_link_state_allowed(a1, 1, 0) )
    {
LABEL_10:
      v6 = v16;
      goto LABEL_11;
    }
    if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) != 0 )
    {
      v29 = "%s: STA connected in eMLSR mode, don't enable/disable links";
      v30 = 8;
LABEL_9:
      qdf_trace_msg(
        0x4Fu,
        v30,
        v29,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "policy_mgr_handle_sap_cli_go_ml_sta_up_csa");
      goto LABEL_10;
    }
    v32 = *(_DWORD *)(v16 + 16);
    LOBYTE(v87) = 0;
    BYTE4(v93[0]) = 0;
    LODWORD(v93[0]) = 0;
    if ( !v32 && !(unsigned int)policy_mgr_is_ml_links_in_mcc_allowed(a1, v28, (__int64)v93, &v87) )
    {
      v61 = (unsigned __int8)v87;
      v57 = (unsigned __int8 *)v93;
      v58 = a1;
      v59 = 1;
      v60 = 3;
      goto LABEL_33;
    }
    LOBYTE(v78) = 0;
    LOBYTE(v77) = 0;
    v88 = 0;
    v87 = 0;
    v86 = 0;
    v85 = 0;
    v94 = 0;
    v93[0] = 0;
    v93[1] = 0;
    v84 = 0;
    v83 = 0;
    if ( policy_mgr_get_context(a1) )
    {
      if ( *(_DWORD *)(v16 + 16) )
        goto LABEL_23;
      v41 = policy_mgr_mode_specific_connection_count(a1, 1, nullptr);
      v42 = policy_mgr_mode_specific_connection_count(a1, 6, nullptr) + v41;
      if ( v42 + (unsigned int)policy_mgr_mode_specific_connection_count(a1, 3, nullptr)
        || (unsigned int)policy_mgr_mode_specific_connection_count(a1, 2, nullptr) )
      {
        v43 = "%s: SAP/GO/CLI exist ignore this check";
      }
      else
      {
        policy_mgr_get_ml_and_non_ml_mode_count(
          a1,
          &v78,
          (__int64)&v87,
          &v77,
          (__int64)&v85,
          (unsigned __int64)v93,
          (unsigned __int64)&v83,
          0);
        v62 = v78;
        if ( !(_BYTE)v78 )
          goto LABEL_23;
        v63 = (unsigned __int8)v77;
        if ( !(_BYTE)v77 )
          goto LABEL_23;
        policy_mgr_get_disabled_ml_sta_idx(a1, &v78, (__int64)&v87, (__int64)v93, (__int64)&v83, v77 + v78);
        v64 = (unsigned __int8)v78;
        v65 = (unsigned __int8)(v78 - v62);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: vdev %d: num_ml %d num_non_ml %d disabled_links: %d",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "policy_mgr_handle_ml_sta_link_concurrency",
          *(unsigned __int8 *)(v16 + 168),
          (unsigned __int8)v78,
          v63,
          v65);
        if ( (unsigned __int8)(v64 - 6) >= 0xFCu && (int)(v64 - v65) > 1 )
        {
          policy_mgr_ml_sta_concurrency_on_connect(a1, v16, v64, &v87, v63, &v85, v93, &v83);
          goto LABEL_10;
        }
        v43 = "%s: ML STA is not up or not sufficient links to disable";
      }
      v44 = 8;
    }
    else
    {
      v43 = "%s: Invalid Context";
      v44 = 2;
    }
    qdf_trace_msg(0x4Fu, v44, v43, v33, v34, v35, v36, v37, v38, v39, v40, "policy_mgr_handle_ml_sta_link_concurrency");
LABEL_23:
    policy_mgr_get_ml_sta_and_p2p_cli_go_sap_info(v27, v76, v74, &v81, v91, v75, &v79, v89);
    v45 = v76[0];
    v46 = v74[0];
    v47 = v75[0];
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev %d: num_ml_sta %d disabled %d num_p2p_sap %d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "policy_mgr_handle_sap_cli_go_ml_sta_up_csa",
      v17,
      v76[0],
      v74[0],
      v75[0]);
    v7 = (unsigned int *)(unsigned __int8)(v45 - 6);
    if ( (unsigned int)v7 < 0xFC || v47 > 5 )
      goto LABEL_10;
    affected_links_for_go_sap_cli = policy_mgr_get_affected_links_for_go_sap_cli(a1, v45, &v81, v91, v47, &v79, v89);
    if ( affected_links_for_go_sap_cli )
    {
      if ( v46 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: As a link is already disabled and affected link present (%d), No action required",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "policy_mgr_handle_sap_cli_go_ml_sta_up_csa",
          affected_links_for_go_sap_cli);
        goto LABEL_10;
      }
      v57 = (unsigned __int8 *)&v81;
      v58 = a1;
      v59 = 1;
      v60 = 3;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev %d: no affected link found",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "policy_mgr_handle_sap_cli_go_ml_sta_up_csa",
        v17);
      if ( (policy_mgr_sta_ml_link_enable_allowed(a1, v46, v45, v91, &v81) & 1) == 0 )
        goto LABEL_10;
      v57 = (unsigned __int8 *)&v81;
      v58 = a1;
      v59 = 2;
      v60 = 5;
    }
    v61 = v45;
LABEL_33:
    policy_mgr_mlo_sta_set_link_ext(v58, v59, v60, v61, v57, 0, 0, v8, v9, v10, v11, v12, v13, v14, v15);
    goto LABEL_10;
  }
  result = qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: vdev %d: invalid vdev",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "policy_mgr_handle_ml_sta_links_on_vdev_up_csa",
             v3);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
