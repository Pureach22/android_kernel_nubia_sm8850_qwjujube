__int64 __fastcall policy_mgr_update_mlo_links_based_on_linkid(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 *a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _DWORD *v13; // x19
  unsigned int v14; // w21
  unsigned __int8 v15; // w20
  __int64 v16; // x9
  unsigned __int8 v17; // w10
  char v18; // w10
  char v19; // w11
  int *v20; // x12
  __int64 v21; // x13
  int v22; // w14
  int v23; // w15
  _DWORD *v24; // x11
  __int64 v25; // x8
  unsigned int v27; // w25
  __int64 result; // x0
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 context; // x0
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
  unsigned int v65; // w6
  int v66; // w10
  int v67; // w22
  __int64 v68; // x28
  _DWORD *v69; // x23
  unsigned int v70; // w26
  const char *v71; // x2
  int v72; // t1
  int v73; // w27
  __int64 v74; // x9
  unsigned int *v75; // x8
  unsigned __int8 *v76; // x24
  __int64 v77; // x28
  unsigned int v78; // w26
  int v79; // w27
  __int64 v80; // x8
  __int64 v81; // x9
  unsigned __int8 *v82; // x10
  int v83; // t1
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  int v92; // w0
  const char *v93; // x2
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x0
  _WORD *v103; // x6
  unsigned int v104; // w1
  unsigned int v105; // w2
  int v106; // w3
  int v107; // w5
  unsigned __int8 *v108; // [xsp+8h] [xbp-78h]
  _QWORD *v109; // [xsp+10h] [xbp-70h]
  int v110; // [xsp+18h] [xbp-68h]
  __int64 v112; // [xsp+28h] [xbp-58h]
  _BYTE v113[4]; // [xsp+30h] [xbp-50h] BYREF
  _BYTE v114[4]; // [xsp+34h] [xbp-4Ch] BYREF
  _BYTE v115[4]; // [xsp+38h] [xbp-48h] BYREF
  unsigned __int16 v116; // [xsp+3Ch] [xbp-44h] BYREF
  int v117; // [xsp+40h] [xbp-40h] BYREF
  char v118; // [xsp+44h] [xbp-3Ch]
  _WORD v119[2]; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int8 v120[4]; // [xsp+4Ch] [xbp-34h] BYREF
  _QWORD v121[2]; // [xsp+50h] [xbp-30h] BYREF
  int v122; // [xsp+60h] [xbp-20h]
  __int64 v123; // [xsp+68h] [xbp-18h] BYREF
  __int64 v124; // [xsp+70h] [xbp-10h]
  __int64 v125; // [xsp+78h] [xbp-8h]

  v13 = a5;
  v14 = a3;
  v15 = a2;
  v125 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v116 = 0;
  v123 = 0;
  v124 = 0;
  *(_WORD *)v120 = 0;
  v119[0] = 0;
  v115[0] = 0;
  v114[0] = 0;
  v113[0] = 0;
  v118 = 0;
  v117 = 0;
  v122 = 0;
  v121[0] = 0;
  v121[1] = 0;
  if ( !(_BYTE)a3 )
  {
    v17 = 0;
    goto LABEL_16;
  }
  if ( (unsigned __int8)a3 == 1 )
  {
    v16 = 0;
    v17 = 0;
LABEL_12:
    v24 = &a5[v16];
    v25 = (unsigned __int8)a3 - v16;
    do
    {
      if ( !*v24++ )
        ++v17;
      --v25;
    }
    while ( v25 );
    goto LABEL_16;
  }
  v16 = (unsigned __int8)a3 & 0xFE;
  v18 = 0;
  v19 = 0;
  v20 = a5 + 1;
  v21 = v16;
  do
  {
    v22 = *(v20 - 1);
    v23 = *v20;
    v20 += 2;
    if ( !v22 )
      ++v18;
    if ( !v23 )
      ++v19;
    v21 -= 2;
  }
  while ( v21 );
  v17 = v19 + v18;
  if ( v16 != (unsigned __int8)a3 )
    goto LABEL_12;
LABEL_16:
  v27 = (unsigned __int8)a3;
  if ( (unsigned __int8)a3 == v17 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev: %d num_links_to_disable: %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "policy_mgr_update_mlo_links_based_on_linkid",
      (unsigned __int8)a2,
      (unsigned __int8)a3);
    result = 16;
    goto LABEL_39;
  }
  v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v30 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev: %d vdev not found",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "policy_mgr_update_mlo_links_based_on_linkid",
      v15);
    result = 16;
    goto LABEL_39;
  }
  v39 = v30;
  v112 = v30;
  if ( !wlan_cm_is_vdev_connected(v30, v31, v32, v33, v34, v35, v36, v37, v38) )
  {
    v71 = "%s: vdev: %d is not in connected state";
LABEL_36:
    qdf_trace_msg(
      0x4Fu,
      2u,
      v71,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "policy_mgr_update_mlo_links_based_on_linkid",
      v15);
    goto LABEL_37;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v39, v40, v41, v42, v43, v44, v45, v46, v47) & 1) == 0 )
  {
    v71 = "%s: vdev:%d is not mlo vdev";
    goto LABEL_36;
  }
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v109 = (_QWORD *)context;
    mlo_get_ml_vdev_list(v39, &v116, &v123);
    v65 = v116;
    if ( v116 )
    {
      if ( (_BYTE)v14 )
      {
        v66 = 0;
        v67 = 0;
        v68 = (unsigned __int8)v14;
        v69 = v13;
        v70 = *(unsigned __int8 *)(v123 + 93);
        v110 = 0;
        v108 = a4;
        do
        {
          v72 = *a4++;
          if ( v72 == v70 )
          {
            v73 = v66 + 1;
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: link id:%d match",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "policy_mgr_update_mlo_links_based_on_linkid",
              v70);
            if ( *v69 )
            {
              if ( (unsigned __int8)v67 > 1u )
                goto LABEL_71;
              v74 = (unsigned __int8)v67++;
              v120[v74] = *(_BYTE *)(v123 + 168);
            }
            else
            {
              if ( (unsigned __int8)v110 > 1u )
                goto LABEL_71;
              *((_BYTE *)v119 + (unsigned __int8)v110++) = *(_BYTE *)(v123 + 168);
            }
            v66 = v73;
          }
          --v68;
          ++v69;
        }
        while ( v68 );
        v65 = v116;
        if ( v116 > 1u )
        {
          if ( (_BYTE)v14 )
          {
            v76 = v108;
            v77 = (unsigned __int8)v14;
            v78 = *(unsigned __int8 *)(v124 + 93);
            v79 = v110;
            do
            {
              v83 = *v76++;
              if ( v83 == v78 )
              {
                LODWORD(v69) = v66 + 1;
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: link id:%d match",
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  "policy_mgr_update_mlo_links_based_on_linkid",
                  v78);
                if ( *v13 )
                {
                  if ( (unsigned __int8)v67 > 1u )
                    goto LABEL_71;
                  v80 = v124;
                  v81 = (unsigned __int8)v67;
                  v82 = v120;
                  ++v67;
                }
                else
                {
                  if ( (unsigned __int8)v79 > 1u )
                    goto LABEL_71;
                  v80 = v124;
                  v81 = (unsigned __int8)v79;
                  v82 = (unsigned __int8 *)v119;
                  ++v79;
                }
                v82[v81] = *(_BYTE *)(v80 + 168);
                v66 = (int)v69;
              }
              --v77;
              ++v13;
            }
            while ( v77 );
            v65 = v116;
            LODWORD(v69) = v66;
          }
          else
          {
            LODWORD(v69) = v66;
            v79 = v110;
          }
          goto LABEL_59;
        }
        LODWORD(v69) = v66;
      }
      else
      {
        v67 = 0;
        if ( v116 != 1 )
        {
          v79 = 0;
          LODWORD(v69) = 0;
LABEL_59:
          v110 = v79;
          if ( v65 > 2 )
            goto LABEL_71;
          goto LABEL_60;
        }
        LODWORD(v69) = 0;
        v110 = 0;
      }
    }
    else
    {
      v67 = 0;
      v110 = 0;
      LODWORD(v69) = 0;
    }
LABEL_60:
    LODWORD(v13) = v110;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev: %d, active links: %d, ml count: %d, active count: %d, inactive count: %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "policy_mgr_update_mlo_links_based_on_linkid",
      v15,
      v27,
      (unsigned __int8)v110);
    if ( (unsigned __int8)v69 != (unsigned __int8)v14 )
    {
      v93 = "%s: invalid link id(s), num_matched_linkid: %d";
      goto LABEL_65;
    }
    if ( !(_BYTE)v67 || (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) == 0 )
    {
      policy_mgr_get_ml_sta_info(v109, v115, v114, (__int64)&v117, (__int64)v121, v113, 0, 0);
      v14 = v115[0];
      LODWORD(v69) = v114[0];
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev %d: num_ml_sta %d disabled %d num_non_ml: %d",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        "policy_mgr_update_mlo_links_based_on_linkid",
        v15,
        v115[0],
        v114[0],
        v113[0]);
      if ( (unsigned __int8)(v14 - 6) >= 0xFCu )
        goto LABEL_72;
      goto LABEL_67;
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev: %d emlsr sta conn present",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "policy_mgr_update_mlo_links_based_on_linkid",
      v15);
    v92 = 16 * ((unsigned __int8)v67 != 1);
    while ( 1 )
    {
      while ( 1 )
      {
        v75 = (unsigned int *)v116;
        LODWORD(v13) = v92;
        if ( !v116 )
          goto LABEL_38;
        mlo_release_vdev_ref(v123);
        v75 = (unsigned int *)v116;
        if ( v116 < 2u )
          goto LABEL_38;
        mlo_release_vdev_ref(v124);
        v75 = (unsigned int *)v116;
        if ( v116 <= 2u )
          goto LABEL_38;
LABEL_71:
        __break(0x5512u);
LABEL_72:
        if ( !(_DWORD)v69 )
          break;
        if ( (_BYTE)v67 )
        {
          if ( (policy_mgr_sta_ml_link_enable_allowed(a1, (unsigned int)v69, v14, v121, &v117) & 1) != 0 )
          {
            if ( (_BYTE)v13 )
            {
              v102 = a1;
              v103 = v119;
LABEL_84:
              v104 = 1;
              v105 = 6;
              v106 = v67;
              v107 = (int)v13;
              goto LABEL_86;
            }
            v102 = a1;
            v104 = 2;
            v105 = 1;
            v106 = v67;
            v107 = 0;
            v103 = nullptr;
LABEL_86:
            v92 = policy_mgr_mlo_sta_set_link_ext(
                    v102,
                    v104,
                    v105,
                    v106,
                    v120,
                    v107,
                    (__int64)v103,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64);
          }
          else
          {
            v93 = "%s: vdev %d: link enable not allowed";
LABEL_65:
            qdf_trace_msg(
              0x4Fu,
              8u,
              v93,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "policy_mgr_update_mlo_links_based_on_linkid");
            v92 = 16;
          }
        }
        else
        {
LABEL_67:
          v92 = 16;
        }
      }
      if ( !(_BYTE)v67 || (_BYTE)v13 )
      {
        v92 = 16;
        if ( (_BYTE)v67 && (_BYTE)v13 )
        {
          v103 = v119;
          v102 = a1;
          goto LABEL_84;
        }
      }
      else
      {
        v92 = 0;
      }
    }
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid pm context",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "policy_mgr_update_mlo_links_based_on_linkid");
LABEL_37:
  LODWORD(v13) = 16;
LABEL_38:
  wlan_objmgr_vdev_release_ref(v112, 0x18u, v75, v57, v58, v59, v60, v61, v62, v63, v64);
  result = (unsigned int)v13;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
