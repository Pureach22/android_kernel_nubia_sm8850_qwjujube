__int64 __fastcall wlansap_modify_acl(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char v64; // w23
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  char v73; // w0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x4
  __int64 v83; // x5
  __int64 v84; // x6
  __int64 v85; // x7
  __int64 result; // x0
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  char v91; // w24
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x4
  __int64 v117; // x5
  const char *v118; // x2
  const char *v119; // x2
  unsigned int v120; // w1
  int v121; // w8
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // x4
  __int64 v131; // x5
  const char *v132; // x2
  __int64 v133; // x6
  __int64 v134; // x7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  __int64 v151; // x0
  _WORD *v152; // x1
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  __int64 v193; // [xsp+0h] [xbp-20h] BYREF
  __int64 v194; // [xsp+8h] [xbp-18h] BYREF
  __int64 v195; // [xsp+10h] [xbp-10h]
  __int64 v196; // [xsp+18h] [xbp-8h]

  v196 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v193) = 0;
  LOWORD(v193) = 0;
  if ( a1 )
  {
    if ( (unsigned int)qdf_mem_cmp((const void *)(a1 + 816), a2, 6u) )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Modify ACL entered\nBefore modification of ACL\nsize of accept and deny lists %d %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlansap_modify_acl",
        *(unsigned __int16 *)(a1 + 1020),
        *(unsigned __int16 *)(a1 + 1214));
      qdf_trace_msg(0x39u, 8u, "%s: *** ALLOW LIST ***", v24, v25, v26, v27, v28, v29, v30, v31, "wlansap_modify_acl");
      sap_print_acl((unsigned __int8 *)(a1 + 828), *(_WORD *)(a1 + 1020), v32, v33, v34, v35, v36, v37, v38, v39);
      qdf_trace_msg(0x39u, 8u, "%s: *** DENY LIST ***", v40, v41, v42, v43, v44, v45, v46, v47, "wlansap_modify_acl");
      sap_print_acl((unsigned __int8 *)(a1 + 1022), *(_WORD *)(a1 + 1214), v48, v49, v50, v51, v52, v53, v54, v55);
      v64 = sap_search_mac_list(
              a1 + 828,
              *(_WORD *)(a1 + 1020),
              a2,
              (_WORD *)&v193 + 2,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63);
      v73 = sap_search_mac_list(a1 + 1022, *(_WORD *)(a1 + 1214), a2, &v193, v65, v66, v67, v68, v69, v70, v71, v72);
      if ( (v64 & 1) != 0 && (v73 & 1) != 0 )
      {
        if ( a2 )
        {
          v82 = *a2;
          v83 = a2[1];
          v84 = a2[2];
          v85 = a2[5];
        }
        else
        {
          v84 = 0;
          v82 = 0;
          v83 = 0;
          v85 = 0;
        }
        v119 = "%s: Peer mac %02x:%02x:%02x:**:**:%02x found in allow and deny lists.Initial lists passed incorrect. Cann"
               "ot execute this command.";
        goto LABEL_21;
      }
      v91 = v73;
      qdf_trace_msg(0x39u, 8u, "%s: cmd %d", v74, v75, v76, v77, v78, v79, v80, v81, "wlansap_modify_acl", a4, v193);
      if ( a3 )
      {
        if ( a3 != 1 )
        {
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: Invalid list type passed %d",
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlansap_modify_acl",
            a3);
          goto LABEL_36;
        }
        if ( (a4 & 0xFFFFFFFD) != 0 )
        {
          if ( (a4 | 2) == 3 )
          {
            if ( (v64 & 1) != 0 )
            {
              v194 = 0;
              v195 = 0;
              qdf_trace_msg(
                0x39u,
                4u,
                "%s: Delete from allow list",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                "wlansap_modify_acl");
              sap_remove_mac_from_acl(
                a1 + 828,
                (_WORD *)(a1 + 1020),
                WORD2(v193),
                v92,
                v93,
                v94,
                v95,
                v96,
                v97,
                v98,
                v99);
              if ( a4 != 1 )
              {
LABEL_57:
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "%s: After modification of ACL",
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  "wlansap_modify_acl");
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "%s: *** ALLOW LIST ***",
                  v161,
                  v162,
                  v163,
                  v164,
                  v165,
                  v166,
                  v167,
                  v168,
                  "wlansap_modify_acl");
                sap_print_acl(
                  (unsigned __int8 *)(a1 + 828),
                  *(_WORD *)(a1 + 1020),
                  v169,
                  v170,
                  v171,
                  v172,
                  v173,
                  v174,
                  v175,
                  v176);
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "%s: *** DENY LIST ***",
                  v177,
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  v183,
                  v184,
                  "wlansap_modify_acl");
                sap_print_acl(
                  (unsigned __int8 *)(a1 + 1022),
                  *(_WORD *)(a1 + 1214),
                  v185,
                  v186,
                  v187,
                  v188,
                  v189,
                  v190,
                  v191,
                  v192);
                result = 0;
                goto LABEL_37;
              }
              wlansap_populate_del_sta_params((int)a2, 2, 12, (int)&v194);
              wlansap_deauth_sta(a1, &v194);
              v116 = *(unsigned __int16 *)(a1 + 1020);
              v117 = *(unsigned __int16 *)(a1 + 1214);
              v118 = "%s: size of accept and deny lists %d %d";
LABEL_56:
              qdf_trace_msg(
                0x39u,
                8u,
                v118,
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                "wlansap_modify_acl",
                v116,
                v117);
              goto LABEL_57;
            }
            if ( a2 )
            {
              v82 = *a2;
              v83 = a2[1];
              v84 = a2[2];
              v85 = a2[5];
            }
            else
            {
              v84 = 0;
              v82 = 0;
              v83 = 0;
              v85 = 0;
            }
            v119 = "%s: MAC address to be deleted is not present in the allow list %02x:%02x:%02x:**:**:%02x";
            goto LABEL_62;
          }
          goto LABEL_35;
        }
        if ( *(_WORD *)(a1 + 1020) == 32 )
        {
          if ( !a2 )
          {
            v84 = 0;
            v82 = 0;
            v83 = 0;
            v85 = 0;
            v119 = "%s: Allow list is already maxed out. Cannot accept %02x:%02x:%02x:**:**:%02x";
            goto LABEL_21;
          }
          v82 = *a2;
          v83 = a2[1];
          v119 = "%s: Allow list is already maxed out. Cannot accept %02x:%02x:%02x:**:**:%02x";
          goto LABEL_31;
        }
        if ( (v64 & 1) != 0 )
        {
          if ( a2 )
          {
            v130 = *a2;
            v131 = a2[1];
            v133 = a2[2];
            v134 = a2[5];
          }
          else
          {
            v133 = 0;
            v130 = 0;
            v131 = 0;
            v134 = 0;
          }
          v132 = "%s: MAC address already present in allow list %02x:%02x:%02x:**:**:%02x";
          goto LABEL_67;
        }
        if ( (v91 & 1) != 0 )
        {
          qdf_trace_msg(
            0x39u,
            3u,
            "%s: STA present in deny list so first remove from it",
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlansap_modify_acl");
          sap_remove_mac_from_acl(a1 + 1022, (_WORD *)(a1 + 1214), v193, v153, v154, v155, v156, v157, v158, v159, v160);
        }
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: ... Now add to the allow list",
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          "wlansap_modify_acl");
        v151 = a1 + 828;
        v152 = (_WORD *)(a1 + 1020);
      }
      else
      {
        if ( (a4 | 2) != 2 )
        {
          if ( (a4 & 0xFFFFFFFD) == 1 )
          {
            if ( (v91 & 1) != 0 )
            {
              qdf_trace_msg(
                0x39u,
                4u,
                "%s: Delete from deny list",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                "wlansap_modify_acl");
              sap_remove_mac_from_acl(
                a1 + 1022,
                (_WORD *)(a1 + 1214),
                v193,
                v122,
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v129);
              v116 = *(unsigned __int16 *)(a1 + 1020);
              v117 = *(unsigned __int16 *)(a1 + 1214);
              v118 = "%s: no accept and deny mac %d %d";
              goto LABEL_56;
            }
            if ( a2 )
            {
              v82 = *a2;
              v83 = a2[1];
              v119 = "%s: MAC address to be deleted is not present in the deny list %02x:%02x:%02x:**:**:%02x";
              v84 = a2[2];
              v85 = a2[5];
            }
            else
            {
              v84 = 0;
              v82 = 0;
              v83 = 0;
              v85 = 0;
              v119 = "%s: MAC address to be deleted is not present in the deny list %02x:%02x:%02x:**:**:%02x";
            }
LABEL_62:
            v120 = 3;
            goto LABEL_22;
          }
LABEL_35:
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: Invalid cmd type passed",
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlansap_modify_acl");
          goto LABEL_36;
        }
        v121 = *(unsigned __int16 *)(a1 + 1214);
        v194 = 0;
        v195 = 0;
        if ( v121 == 32 )
        {
          if ( !a2 )
          {
            v84 = 0;
            v82 = 0;
            v83 = 0;
            v85 = 0;
            v119 = "%s: Deny list is already maxed out. Cannot accept %02x:%02x:%02x:**:**:%02x";
            goto LABEL_21;
          }
          v82 = *a2;
          v83 = a2[1];
          v119 = "%s: Deny list is already maxed out. Cannot accept %02x:%02x:%02x:**:**:%02x";
LABEL_31:
          v84 = a2[2];
          v85 = a2[5];
LABEL_21:
          v120 = 2;
LABEL_22:
          qdf_trace_msg(
            0x39u,
            v120,
            v119,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlansap_modify_acl",
            v82,
            v83,
            v84,
            v85,
            v193,
            v194,
            v195,
            v196);
LABEL_36:
          result = 16;
          goto LABEL_37;
        }
        if ( (v91 & 1) != 0 )
        {
          if ( a2 )
          {
            v130 = *a2;
            v131 = a2[1];
            v132 = "%s: MAC address already present in deny list %02x:%02x:%02x:**:**:%02x";
            v133 = a2[2];
            v134 = a2[5];
          }
          else
          {
            v133 = 0;
            v130 = 0;
            v131 = 0;
            v134 = 0;
            v132 = "%s: MAC address already present in deny list %02x:%02x:%02x:**:**:%02x";
          }
LABEL_67:
          qdf_trace_msg(
            0x39u,
            3u,
            v132,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlansap_modify_acl",
            v130,
            v131,
            v133,
            v134);
          result = 0;
          goto LABEL_37;
        }
        if ( (v64 & 1) != 0 )
        {
          qdf_trace_msg(
            0x39u,
            3u,
            "%s: Present in allow list so first remove from it",
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlansap_modify_acl");
          sap_remove_mac_from_acl(
            a1 + 828,
            (_WORD *)(a1 + 1020),
            WORD2(v193),
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            v142);
        }
        if ( !a4 )
        {
          wlansap_populate_del_sta_params((int)a2, 2, 12, (int)&v194);
          wlansap_deauth_sta(a1, &v194);
        }
        qdf_trace_msg(
          0x39u,
          4u,
          "%s: ... Now add to deny list",
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          "wlansap_modify_acl");
        v151 = a1 + 1022;
        v152 = (_WORD *)(a1 + 1214);
      }
      sap_add_mac_to_acl(v151, v152, a2, v143, v144, v145, v146, v147, v148, v149, v150);
      v116 = *(unsigned __int16 *)(a1 + 1020);
      v117 = *(unsigned __int16 *)(a1 + 1214);
      v118 = "%s: size of accept and deny lists %d %d";
      goto LABEL_56;
    }
    if ( a2 )
    {
      v87 = *a2;
      v88 = a2[1];
      v89 = a2[2];
      v90 = a2[5];
    }
    else
    {
      v89 = 0;
      v87 = 0;
      v88 = 0;
      v90 = 0;
    }
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: requested peer mac is %02x:%02x:%02x:**:**:%02xour own SAP BSSID. Do not denylist or allowlist this BSSID",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlansap_modify_acl",
      v87,
      v88,
      v89,
      v90,
      v193);
    result = 5;
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP Context", a5, a6, a7, a8, a9, a10, a11, a12, "wlansap_modify_acl", v193);
    result = 5;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
