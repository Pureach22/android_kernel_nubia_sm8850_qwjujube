__int64 __fastcall policy_mgr_handle_ml_sta_links_on_vdev_down(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int8 v3; // w20
  __int64 v6; // x0
  unsigned __int64 v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x24
  unsigned int v17; // w20
  __int64 result; // x0
  int v19; // w9
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w21
  unsigned int v30; // w23
  unsigned int v31; // w22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w22
  _QWORD *context; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  const char *v59; // x2
  unsigned __int8 *v60; // x4
  __int64 v61; // [xsp+0h] [xbp-80h] BYREF
  _BYTE v62[4]; // [xsp+8h] [xbp-78h] BYREF
  _BYTE v63[4]; // [xsp+Ch] [xbp-74h] BYREF
  _BYTE v64[4]; // [xsp+10h] [xbp-70h] BYREF
  _BYTE v65[4]; // [xsp+14h] [xbp-6Ch] BYREF
  int v66; // [xsp+18h] [xbp-68h] BYREF
  char v67; // [xsp+1Ch] [xbp-64h]
  int v68; // [xsp+20h] [xbp-60h] BYREF
  char v69; // [xsp+24h] [xbp-5Ch]
  int v70; // [xsp+28h] [xbp-58h] BYREF
  char v71; // [xsp+2Ch] [xbp-54h]
  _QWORD v72[2]; // [xsp+30h] [xbp-50h] BYREF
  int v73; // [xsp+40h] [xbp-40h]
  _QWORD v74[2]; // [xsp+48h] [xbp-38h] BYREF
  int v75; // [xsp+58h] [xbp-28h]
  _QWORD v76[2]; // [xsp+60h] [xbp-20h] BYREF
  int v77; // [xsp+70h] [xbp-10h]
  __int64 v78; // [xsp+78h] [xbp-8h]

  v3 = a3;
  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 24);
  if ( !v6 )
  {
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
               "policy_mgr_handle_ml_sta_links_on_vdev_down",
               v3);
    goto LABEL_7;
  }
  if ( a2 <= 3 )
  {
    v16 = v6;
    v17 = *(unsigned __int8 *)(v6 + 168);
    v62[0] = 0;
    BYTE4(v61) = 0;
    LOBYTE(v61) = 0;
    v69 = 0;
    v68 = 0;
    v67 = 0;
    v66 = 0;
    v75 = 0;
    v74[0] = 0;
    v74[1] = 0;
    v73 = 0;
    v72[0] = 0;
    v72[1] = 0;
    if ( (unsigned int)policy_mgr_handle_ml_sta_link_state_allowed(a1, 2, 0) )
    {
LABEL_4:
      v6 = v16;
      goto LABEL_5;
    }
    v19 = *(_DWORD *)(v16 + 16);
    v65[0] = 0;
    v64[0] = 0;
    v63[0] = 0;
    v71 = 0;
    v70 = 0;
    v77 = 0;
    v76[0] = 0;
    v76[1] = 0;
    if ( !v19 )
    {
      v40 = *(unsigned __int8 *)(v16 + 168);
      context = (_QWORD *)policy_mgr_get_context(a1);
      if ( context )
      {
        policy_mgr_get_ml_sta_info(context, v65, v64, (__int64)&v70, (__int64)v76, v63, 0, 0);
        v29 = v65[0];
        v50 = v64[0];
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: vdev %d: num_ml_sta %d disabled %d num_non_ml: %d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "policy_mgr_handle_ml_sta_link_enable_on_sta_down",
          v40,
          v65[0],
          v64[0],
          v63[0]);
        if ( (unsigned __int8)(v29 - 6) >= 0xFCu )
        {
          v7 = v63[0];
          if ( v63[0] )
          {
            v59 = "%s: non-ML STA is present";
          }
          else
          {
            if ( !v50 )
              goto LABEL_4;
            if ( (policy_mgr_sta_ml_link_enable_allowed(a1, v50, v29, v76, &v70) & 1) != 0 )
            {
              v60 = (unsigned __int8 *)&v70;
              goto LABEL_24;
            }
            v59 = "%s: Not re-enabled due to disallowed concurrency";
          }
          qdf_trace_msg(
            0x4Fu,
            8u,
            v59,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "policy_mgr_handle_ml_sta_link_enable_on_sta_down",
            v61);
          goto LABEL_4;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid Context",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "policy_mgr_handle_ml_sta_link_enable_on_sta_down");
      }
    }
    v20 = policy_mgr_get_context(a1);
    if ( !v20 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "policy_mgr_re_enable_ml_sta_on_p2p_sap_sta_down");
      goto LABEL_4;
    }
    policy_mgr_get_ml_sta_and_p2p_cli_go_sap_info(v20, v62, &v61, &v68, v74, (char *)&v61 + 4, &v66, v72);
    v29 = v62[0];
    v30 = (unsigned __int8)v61;
    v31 = BYTE4(v61);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev %d: num_ml_sta %d disabled %d num_p2p_sap %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "policy_mgr_re_enable_ml_sta_on_p2p_sap_sta_down",
      v17,
      v62[0],
      (unsigned __int8)v61,
      BYTE4(v61));
    v7 = (unsigned __int8)(v29 - 6);
    if ( (unsigned int)v7 < 0xFC || v31 > 5 || (policy_mgr_sta_ml_link_enable_allowed(a1, v30, v29, v74, &v68) & 1) == 0 )
      goto LABEL_4;
    if ( v31 && (unsigned __int8)policy_mgr_get_affected_links_for_go_sap_cli(a1, v29, &v68, v74, v31, &v66, v72) )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev %d: Affected link present, dont reanabe ML link",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "policy_mgr_re_enable_ml_sta_on_p2p_sap_sta_down",
        v17);
      goto LABEL_4;
    }
    v60 = (unsigned __int8 *)&v68;
LABEL_24:
    policy_mgr_mlo_sta_set_link_ext(a1, 2u, 5u, v29, v60, 0, 0, v8, v9, v10, v11, v12, v13, v14, v15);
    goto LABEL_4;
  }
LABEL_5:
  result = wlan_objmgr_vdev_release_ref(v6, 0x18u, (unsigned int *)v7, v8, v9, v10, v11, v12, v13, v14, v15);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
