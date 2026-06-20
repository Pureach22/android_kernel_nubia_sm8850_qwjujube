__int64 __fastcall wlan_hdd_cfg80211_vendor_fpm(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  const char *v37; // x3
  unsigned int v38; // w0
  int v39; // w24
  _WORD *v40; // x20
  __int64 v41; // x9
  _WORD *v42; // x22
  __int64 v43; // x23
  __int64 ctx_by_vdev; // x0
  char *v45; // x21
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w0
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x19
  __int64 v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x20
  unsigned __int8 v75; // w0
  unsigned __int8 v76; // w22
  __int64 v77; // x23
  __int64 v78; // x24
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  const char *v87; // x21
  _WORD *v88; // x25
  __int64 v89; // x26
  __int64 v90; // x27
  int v91; // w24
  unsigned int v92; // w19
  int v93; // w19
  __int64 v94; // x22
  __int64 v95; // x23
  _WORD *v96; // x22
  __int64 v97; // x23
  __int64 v98; // x28
  _WORD *v99; // x23
  __int64 v100; // x28
  int v101; // w8
  int v102; // w8
  __int64 v103; // x0
  __int64 v104; // x1
  __int64 *v105; // x3
  __int64 v106; // x2
  int v107; // w8
  int v108; // w8
  int v109; // w8
  char v110; // w8
  __int64 v111; // x23
  __int64 v112; // x28
  _WORD *v113; // x23
  __int64 v114; // x28
  int v115; // w8
  char v116; // w8
  int v117; // w8
  int v118; // w23
  int v119; // w22
  unsigned int v120; // w0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  int v129; // w8
  char v130; // w8
  int v131; // w8
  unsigned int v132; // w0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x1
  __int64 *v142; // [xsp+38h] [xbp-128h] BYREF
  __int64 v143; // [xsp+40h] [xbp-120h] BYREF
  __int64 v144; // [xsp+48h] [xbp-118h]
  __int64 v145; // [xsp+50h] [xbp-110h]
  _WORD *v146; // [xsp+58h] [xbp-108h]
  _WORD *v147; // [xsp+60h] [xbp-100h]
  __int64 v148; // [xsp+68h] [xbp-F8h]
  __int64 v149; // [xsp+70h] [xbp-F0h] BYREF
  __int64 v150; // [xsp+78h] [xbp-E8h]
  __int64 v151; // [xsp+80h] [xbp-E0h]
  __int64 v152; // [xsp+88h] [xbp-D8h] BYREF
  __int64 v153; // [xsp+90h] [xbp-D0h]
  __int64 v154; // [xsp+98h] [xbp-C8h]
  __int64 v155; // [xsp+A0h] [xbp-C0h]
  __int64 v156; // [xsp+A8h] [xbp-B8h]
  __int64 v157; // [xsp+B0h] [xbp-B0h]
  __int64 v158; // [xsp+B8h] [xbp-A8h]
  __int64 v159; // [xsp+C0h] [xbp-A0h]
  __int64 v160; // [xsp+C8h] [xbp-98h]
  __int64 v161; // [xsp+D0h] [xbp-90h]
  __int64 v162; // [xsp+D8h] [xbp-88h] BYREF
  __int64 v163; // [xsp+E0h] [xbp-80h]
  __int64 v164; // [xsp+E8h] [xbp-78h] BYREF
  __int64 v165; // [xsp+F0h] [xbp-70h]
  __int64 v166; // [xsp+F8h] [xbp-68h]
  __int64 v167; // [xsp+100h] [xbp-60h]
  __int64 v168; // [xsp+108h] [xbp-58h]
  __int64 v169; // [xsp+110h] [xbp-50h]
  __int64 v170; // [xsp+118h] [xbp-48h]
  __int64 v171; // [xsp+120h] [xbp-40h]
  __int64 v172; // [xsp+128h] [xbp-38h]
  __int64 v173; // [xsp+130h] [xbp-30h]
  __int64 v174; // [xsp+138h] [xbp-28h]
  __int64 v175; // [xsp+140h] [xbp-20h]
  __int64 v176; // [xsp+148h] [xbp-18h]
  __int64 v177; // [xsp+150h] [xbp-10h]

  v177 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v142 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v142, (__int64)"wlan_hdd_cfg80211_vendor_fpm");
  if ( (_DWORD)result )
    goto LABEL_32;
  if ( a1 )
  {
    v10 = *(_QWORD *)(a2 + 32);
    v147 = nullptr;
    v148 = 0;
    v145 = 0;
    v146 = nullptr;
    v143 = 0;
    v144 = 0;
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__wlan_hdd_cfg80211_vendor_fpm");
      v19 = -1;
LABEL_31:
      v92 = v19;
      _osif_vdev_sync_op_stop((__int64)v142, (__int64)"wlan_hdd_cfg80211_vendor_fpm");
      result = v92;
LABEL_32:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v19 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_vendor_fpm",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18);
    if ( v19 )
      goto LABEL_31;
    v19 = _hdd_validate_adapter(
            v10 + 2688,
            (__int64)"__wlan_hdd_cfg80211_vendor_fpm",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27);
    if ( v19 )
      goto LABEL_31;
    if ( (unsigned int)_nla_parse(&v143, 5, a3, a4, &fpm_policy, 31, 0) )
    {
      v36 = "%s: invalid fpm attr";
      v37 = "__wlan_hdd_cfg80211_vendor_fpm";
      v38 = 51;
LABEL_29:
      qdf_trace_msg(v38, 2u, v36, v28, v29, v30, v31, v32, v33, v34, v35, v37);
LABEL_30:
      v19 = -22;
      goto LABEL_31;
    }
    if ( !v144 )
    {
      v36 = "%s: TWT operation NOT specified";
LABEL_16:
      v37 = "hdd_fpm_configure";
      v38 = 51;
      goto LABEL_29;
    }
    v39 = *(unsigned __int8 *)(v144 + 4);
    v40 = v147;
    v41 = *(_QWORD *)(v10 + 55512);
    v43 = v145;
    v42 = v146;
    ctx_by_vdev = ucfg_fpm_policy_get_ctx_by_vdev(*(_QWORD *)(v41 + 32), v28, v29, v30, v31, v32, v33, v34, v35);
    if ( !ctx_by_vdev )
    {
      v36 = "%s: fpm: fpm_ctx NULL";
      goto LABEL_27;
    }
    v45 = (char *)ctx_by_vdev;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: fpm Operation 0x%x",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_fpm_configure",
      (unsigned int)v39);
    if ( v39 <= 1 )
    {
      if ( v39 )
      {
        if ( v145 )
        {
          v164 = 0;
          nla_memcpy(&v164, v145, 8);
          v54 = ucfg_fpm_policy_rem((__int64)v45, v164, v46, v47, v48, v49, v50, v51, v52, v53);
          v19 = qdf_status_to_os_return(v54);
          goto LABEL_31;
        }
        v36 = "%s: fpm: policy_id not present";
        v37 = "osif_fpm_del";
        goto LABEL_28;
      }
      if ( v42 && v40 )
      {
        v160 = 0;
        v161 = 0;
        v158 = 0;
        v159 = 0;
        v156 = 0;
        v157 = 0;
        v154 = 0;
        v155 = 0;
        v152 = 0;
        v153 = 0;
        v150 = 0;
        v151 = 0;
        v149 = 0;
        v175 = 0;
        v176 = 0;
        v173 = 0;
        v174 = 0;
        v171 = 0;
        v172 = 0;
        v169 = 0;
        v170 = 0;
        v167 = 0;
        v168 = 0;
        v165 = 0;
        v166 = 0;
        v164 = 0;
        if ( ((__int16)v42[1] & 0x80000000) == 0 )
          goto LABEL_36;
        if ( (unsigned int)_nla_parse(&v152, 9, v42 + 2, (unsigned __int16)(*v42 - 4), &fpm_policy_param, 31, 0) )
          goto LABEL_91;
        if ( v161 )
          v116 = *(_BYTE *)(v161 + 4);
        else
          v116 = 3;
        LOBYTE(v168) = v116;
        if ( v153 )
        {
          if ( !*(_BYTE *)(v153 + 4) )
          {
            v129 = v175;
            v119 = v175 | 1;
            LODWORD(v175) = v175 | 1;
            if ( v154 )
            {
              v119 = v129 | 5;
              LODWORD(v175) = v129 | 5;
              LODWORD(v170) = *(_DWORD *)(v154 + 4);
            }
            if ( v157 )
            {
              v119 |= 8u;
              LODWORD(v175) = v119;
              LODWORD(v172) = *(_DWORD *)(v157 + 4);
            }
            goto LABEL_120;
          }
          if ( *(_BYTE *)(v153 + 4) == 1 )
          {
            v118 = v175;
            v119 = v175 | 2;
            LODWORD(v175) = v175 | 2;
            if ( v155 )
            {
              v162 = 0;
              v163 = 0;
              nla_memcpy(&v162, v155, 16);
              v119 = v118 | 6;
              LODWORD(v175) = v118 | 6;
              v170 = v162;
              v171 = v163;
            }
            if ( v158 )
            {
              v162 = 0;
              v163 = 0;
              nla_memcpy(&v162, v158, 16);
              v119 |= 8u;
              LODWORD(v175) = v119;
              v172 = v162;
              v173 = v163;
            }
LABEL_120:
            if ( v156 )
            {
              v119 |= 0x10u;
              LODWORD(v175) = v119;
              LOWORD(v174) = *(_WORD *)(v156 + 4);
            }
            if ( v159 )
            {
              v119 |= 0x20u;
              LODWORD(v175) = v119;
              WORD1(v174) = *(_WORD *)(v159 + 4);
            }
            if ( !v160 )
            {
LABEL_134:
              if ( (__int16)v40[1] < 0 )
              {
                if ( !(unsigned int)_nla_parse(
                                      &v149,
                                      2,
                                      v40 + 2,
                                      (unsigned __int16)(*v40 - 4),
                                      &fpm_policy_config,
                                      31,
                                      0) )
                {
                  v131 = v176;
                  if ( !v150
                    || (v131 = v176 | 1, LODWORD(v176) = v176 | 1, BYTE4(v176) = *(_BYTE *)(v150 + 4), BYTE4(v176) < 8u) )
                  {
                    if ( v151 )
                    {
                      LODWORD(v176) = v131 | 2;
                      BYTE5(v176) = *(_BYTE *)(v151 + 4);
                    }
                    else if ( !v131 )
                    {
                      v36 = "%s: fpm: no configs associated for given flow";
                      goto LABEL_92;
                    }
                    v132 = ucfg_fpm_policy_add();
                    if ( v132 )
                    {
                      if ( (unsigned int)qdf_status_to_os_return(v132) )
                        goto LABEL_30;
                      v141 = 0;
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x48u,
                        4u,
                        "%s: fpm: policy-add: [flags:0x%x][prio:%d][policy_id:0x%llx][src_ip:%d][dst_ip:%d][src_port:%d]["
                        "dst_port:%d][proto:%d][tid:%d][svc:%d]",
                        v133,
                        v134,
                        v135,
                        v136,
                        v137,
                        v138,
                        v139,
                        v140,
                        "osif_fpm_add",
                        (unsigned int)v176,
                        (unsigned __int8)v168,
                        v169,
                        (unsigned int)v170,
                        v172,
                        (unsigned __int16)v174,
                        WORD1(v174),
                        BYTE4(v174),
                        BYTE4(v176),
                        BYTE5(v176));
                      v141 = v169;
                    }
                    v19 = osif_send_policy_id(a1, v141);
                    goto LABEL_31;
                  }
                  v36 = "%s: fpm: invalid tid value";
LABEL_92:
                  v37 = "osif_fpm_add";
                  goto LABEL_28;
                }
LABEL_91:
                v36 = "%s: fpm: nla_parse_nested failed";
                goto LABEL_92;
              }
LABEL_36:
              do_trace_netlink_extack("NLA_F_NESTED is missing");
              goto LABEL_91;
            }
            if ( !*(_BYTE *)(v160 + 4) )
            {
              v130 = 17;
              goto LABEL_133;
            }
            if ( *(_BYTE *)(v160 + 4) == 1 )
            {
              v130 = 6;
LABEL_133:
              BYTE4(v174) = v130;
              LODWORD(v175) = v119 | 0x40;
              goto LABEL_134;
            }
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: invalid user proto",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "osif_fpm_convert_proto_uton");
            v36 = "%s: fpm: invalid proto";
LABEL_111:
            v37 = "osif_fpm_parse_policy_params";
            goto LABEL_28;
          }
        }
        v36 = "%s: fpm: invalid policy type";
        goto LABEL_111;
      }
      goto LABEL_41;
    }
    if ( v39 != 2 )
    {
      if ( v39 == 3 )
      {
        v55 = _cfg80211_alloc_reply_skb(a1, 103, 197, 3696);
        if ( !v55 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: nl reply skb alloc failed",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "osif_fpm_query");
          v19 = -12;
          goto LABEL_31;
        }
        v64 = v55;
        v65 = _qdf_mem_malloc(0xD00u, "osif_fpm_query", 377);
        if ( !v65 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: policy memory alloc failed",
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            "osif_fpm_query");
          sk_skb_reason_drop(0, v64, 2);
          v19 = -12;
          goto LABEL_31;
        }
        v74 = v65;
        v75 = ucfg_fpm_policy_get(v45, v65, 0x20u, v66, v67, v68, v69, v70, v71, v72, v73);
        if ( !v75 )
        {
LABEL_129:
          _qdf_mem_free(v74);
          v19 = cfg80211_vendor_cmd_reply(v64);
          goto LABEL_31;
        }
        v76 = v75;
        v77 = *(_QWORD *)(v64 + 216);
        v78 = *(unsigned int *)(v64 + 208);
        v87 = "%s: fpm: nla_nest_start error";
        if ( (nla_put(v64, 32773, 0, 0) & 0x80000000) != 0 || (v88 = (_WORD *)(v77 + v78)) == nullptr )
        {
LABEL_87:
          qdf_trace_msg(0x48u, 2u, v87, v79, v80, v81, v82, v83, v84, v85, v86, "osif_fpm_query");
LABEL_88:
          _qdf_mem_free(v74);
          sk_skb_reason_drop(0, v64, 2);
          v19 = -90;
          goto LABEL_31;
        }
        v89 = 0;
        v90 = 104LL * v76;
        v91 = 1;
        while ( 1 )
        {
          v94 = *(_QWORD *)(v64 + 216);
          v95 = *(unsigned int *)(v64 + 208);
          if ( (nla_put(v64, v91 | 0x8000u, 0, 0) & 0x80000000) != 0 )
            goto LABEL_88;
          v96 = (_WORD *)(v94 + v95);
          if ( !v96 )
            goto LABEL_88;
          v164 = *(_QWORD *)(v74 + v89 + 40);
          if ( (unsigned int)nla_put_64bit(v64, 2, 8, &v164, 229) )
            goto LABEL_86;
          v97 = *(_QWORD *)(v64 + 216);
          v98 = *(unsigned int *)(v64 + 208);
          if ( (nla_put(v64, 32771, 0, 0) & 0x80000000) != 0 )
            goto LABEL_87;
          v99 = (_WORD *)(v97 + v98);
          if ( !v99 )
            goto LABEL_87;
          v100 = v74 + v89;
          v101 = *(_DWORD *)(v74 + v89 + 88);
          if ( (v101 & 1) != 0 )
          {
            LOBYTE(v164) = 0;
            if ( (unsigned int)nla_put(v64, 1, 1, &v164) )
              goto LABEL_86;
            v107 = *(_DWORD *)(v100 + 88);
            if ( (v107 & 4) != 0 )
            {
              LODWORD(v164) = *(_DWORD *)(v100 + 48);
              if ( (unsigned int)nla_put(v64, 2, 4, &v164) )
                goto LABEL_86;
              v107 = *(_DWORD *)(v100 + 88);
            }
            if ( (v107 & 8) == 0 )
              goto LABEL_65;
            v105 = &v164;
            v103 = v64;
            v104 = 5;
            v106 = 4;
            LODWORD(v164) = *(_DWORD *)(v74 + v89 + 64);
          }
          else
          {
            if ( (v101 & 2) == 0 )
              goto LABEL_65;
            LOBYTE(v164) = 1;
            if ( (unsigned int)nla_put(v64, 1, 1, &v164) )
              goto LABEL_86;
            v102 = *(_DWORD *)(v100 + 88);
            if ( (v102 & 4) != 0 )
            {
              if ( (unsigned int)nla_put(v64, 3, 16, v100 + 48) )
                goto LABEL_86;
              v102 = *(_DWORD *)(v100 + 88);
            }
            if ( (v102 & 8) == 0 )
              goto LABEL_65;
            v103 = v64;
            v104 = 6;
            v105 = (__int64 *)(v74 + v89 + 64);
            v106 = 16;
          }
          if ( (unsigned int)nla_put(v103, v104, v106, v105) )
            goto LABEL_86;
LABEL_65:
          v108 = *(_DWORD *)(v100 + 88);
          if ( (v108 & 0x10) != 0 )
          {
            LOWORD(v164) = *(_WORD *)(v74 + v89 + 80);
            if ( (unsigned int)nla_put(v64, 4, 2, &v164) )
              goto LABEL_86;
            v108 = *(_DWORD *)(v100 + 88);
          }
          if ( (v108 & 0x20) != 0 )
          {
            LOWORD(v164) = *(_WORD *)(v74 + v89 + 82);
            if ( (unsigned int)nla_put(v64, 7, 2, &v164) )
              goto LABEL_86;
          }
          LOBYTE(v164) = *(_BYTE *)(v74 + v89 + 32);
          if ( (unsigned int)nla_put(v64, 9, 1, &v164) )
            goto LABEL_86;
          if ( (*(_BYTE *)(v100 + 88) & 0x40) != 0 )
          {
            v109 = *(unsigned __int8 *)(v74 + v89 + 84);
            if ( v109 == 17 )
            {
              v110 = 0;
LABEL_76:
              LOBYTE(v164) = v110;
              if ( (unsigned int)nla_put(v64, 8, 1, &v164) )
                goto LABEL_86;
              goto LABEL_79;
            }
            if ( v109 == 6 )
            {
              v110 = 1;
              goto LABEL_76;
            }
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: invalid user proto",
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              "osif_fpm_convert_proto_ntou");
          }
LABEL_79:
          *v99 = *(_WORD *)(v64 + 216) + *(_DWORD *)(v64 + 208) - (_WORD)v99;
          v111 = *(_QWORD *)(v64 + 216);
          v112 = *(unsigned int *)(v64 + 208);
          if ( (nla_put(v64, 32772, 0, 0) & 0x80000000) != 0 )
            goto LABEL_87;
          v113 = (_WORD *)(v111 + v112);
          if ( !v113 )
            goto LABEL_87;
          v114 = v74 + v89;
          v115 = *(_DWORD *)(v74 + v89 + 96);
          if ( (v115 & 1) != 0 )
          {
            LOBYTE(v164) = *(_BYTE *)(v114 + 100);
            if ( (unsigned int)nla_put(v64, 1, 1, &v164) )
              goto LABEL_86;
            v115 = *(_DWORD *)(v114 + 96);
          }
          if ( (v115 & 2) != 0 )
          {
            LOBYTE(v164) = *(_BYTE *)(v74 + v89 + 101);
            if ( (unsigned int)nla_put(v64, 2, 1, &v164) )
            {
LABEL_86:
              v87 = "%s: fpm: nla_put_u8 failed";
              goto LABEL_87;
            }
          }
          v89 += 104;
          ++v91;
          *v113 = *(_DWORD *)(v64 + 216) + *(_DWORD *)(v64 + 208) - (_WORD)v113;
          *v96 = *(_WORD *)(v64 + 216) + *(_DWORD *)(v64 + 208) - (_WORD)v96;
          if ( v90 == v89 )
          {
            *v88 = *(_WORD *)(v64 + 216) + *(_DWORD *)(v64 + 208) - (_WORD)v88;
            goto LABEL_129;
          }
        }
      }
      v36 = "%s: Invalid FPM Operation";
LABEL_27:
      v37 = "hdd_fpm_configure";
LABEL_28:
      v38 = 72;
      goto LABEL_29;
    }
    if ( !v43 || !v40 )
    {
LABEL_41:
      v36 = "%s: fpm parameters NOT specified";
      goto LABEL_16;
    }
    v153 = 0;
    v154 = 0;
    v152 = 0;
    v175 = 0;
    v176 = 0;
    v173 = 0;
    v174 = 0;
    v171 = 0;
    v172 = 0;
    v169 = 0;
    v170 = 0;
    v167 = 0;
    v168 = 0;
    v165 = 0;
    v166 = 0;
    v164 = 0;
    v149 = 0;
    nla_memcpy(&v149, v43, 8);
    v169 = v149;
    if ( ((__int16)v40[1] & 0x80000000) == 0 )
    {
      do_trace_netlink_extack("NLA_F_NESTED is missing");
      v93 = -22;
LABEL_94:
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: fpm: nla_parse_nested failed",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "osif_fpm_update");
      v19 = v93;
      goto LABEL_31;
    }
    v93 = _nla_parse(&v152, 2, v40 + 2, (unsigned __int16)(*v40 - 4), &fpm_policy_config, 31, 0);
    if ( v93 )
      goto LABEL_94;
    v117 = v176;
    if ( v153 )
    {
      v117 = v176 | 1;
      LODWORD(v176) = v176 | 1;
      BYTE4(v176) = *(_BYTE *)(v153 + 4);
      if ( BYTE4(v176) >= 8u )
      {
        v36 = "%s: fpm: invalid tid value";
LABEL_131:
        v37 = "osif_fpm_update";
        goto LABEL_28;
      }
    }
    if ( v154 )
    {
      LODWORD(v176) = v117 | 2;
      BYTE5(v176) = *(_BYTE *)(v154 + 4);
    }
    else if ( !v117 )
    {
      v36 = "%s: fpm: nothing to update";
      goto LABEL_131;
    }
    v120 = ucfg_fpm_policy_update((__int64 *)v45, (__int64)&v164, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( v120 )
    {
      v19 = qdf_status_to_os_return(v120);
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        4u,
        "%s: fpm: policy-update: [flags:0x%x][prio:%d][policy_id:0x%llx][src_ip:%d][dst_ip:%d][src_port:%d][dst_port:%d]["
        "proto:%d][tid:%d][svc:%d]",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "osif_fpm_update",
        (unsigned int)v176,
        (unsigned __int8)v168,
        v169,
        (unsigned int)v170,
        v172,
        (unsigned __int16)v174,
        WORD1(v174),
        BYTE4(v174),
        BYTE4(v176),
        BYTE5(v176));
      v19 = 0;
    }
    goto LABEL_31;
  }
  __break(0x800u);
  return ((__int64 (*)(void))osif_send_policy_id)();
}
