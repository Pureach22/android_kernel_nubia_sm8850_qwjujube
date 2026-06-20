__int64 __fastcall policy_mgr_allow_4th_new_freq(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w23
  int v24; // w28
  __int64 v25; // x21
  __int64 v26; // x24
  int v27; // w28
  unsigned int v28; // w25
  unsigned int v29; // w26
  int v30; // w19
  unsigned int v31; // w27
  int v32; // w20
  int v33; // w23
  int v34; // w8
  int v35; // w9
  int v36; // w8
  int v37; // w9
  bool v38; // zf
  bool v39; // zf
  int v40; // w11
  int v41; // w12
  int v42; // w13
  int v43; // w14
  unsigned __int64 v44; // x27
  unsigned __int64 v45; // x19
  unsigned __int64 v46; // x25
  unsigned __int64 v47; // x26
  unsigned __int64 v48; // x20
  int v49; // w9
  char *v50; // x8
  int v51; // w8
  __int64 *v52; // x9
  int v53; // w12
  int v54; // w9
  __int64 *v55; // x10
  int v56; // w13
  int v57; // w10
  bool v58; // zf
  bool v59; // zf
  int v60; // w11
  const char *v61; // x5
  __int64 result; // x0
  __int64 v63; // x20
  const char *v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x22
  unsigned int v74; // w22
  __int64 v75; // x23
  __int64 v76; // x20
  const char *v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x20
  const char *v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // [xsp+0h] [xbp-90h]
  __int64 v97; // [xsp+8h] [xbp-88h]
  __int64 v98; // [xsp+10h] [xbp-80h]
  __int64 v99; // [xsp+28h] [xbp-68h]
  int v100; // [xsp+34h] [xbp-5Ch]
  __int64 v101; // [xsp+38h] [xbp-58h]
  __int64 v102; // [xsp+40h] [xbp-50h]
  int v103; // [xsp+48h] [xbp-48h]
  unsigned int v104; // [xsp+4Ch] [xbp-44h]
  __int64 v106; // [xsp+54h] [xbp-3Ch] BYREF
  __int64 v107; // [xsp+5Ch] [xbp-34h] BYREF
  _BYTE v108[4]; // [xsp+64h] [xbp-2Ch] BYREF
  int v109; // [xsp+68h] [xbp-28h] BYREF
  unsigned __int8 v110; // [xsp+6Ch] [xbp-24h]
  __int128 v111; // [xsp+70h] [xbp-20h] BYREF
  int v112; // [xsp+80h] [xbp-10h]
  __int64 v113; // [xsp+88h] [xbp-8h]

  v113 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v112 = 0;
  v111 = 0u;
  v110 = 0;
  v109 = 0;
  v108[0] = 0;
  v107 = 0;
  v106 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_allow_4th_new_freq");
    goto LABEL_207;
  }
  v14 = context;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
LABEL_207:
    result = 0;
    goto LABEL_208;
  }
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = v14 + 1204;
  v104 = a3;
  v101 = 0;
  v102 = 0;
  v100 = 0;
  v99 = v14;
  while ( (_BYTE)v25 )
  {
    if ( (unsigned __int8)v25 == 1 )
    {
      if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
        break;
    }
    else if ( (unsigned int)(v25 - 3) > 1 )
    {
      if ( v25 == 2 && (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 )
        break;
    }
    else if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 && *(_DWORD *)(v99 + 1200) )
    {
      break;
    }
LABEL_5:
    ++v25;
    v26 += 32;
    if ( v25 == 8 )
      goto LABEL_203;
  }
  v103 = v24;
  v27 = v23;
  v29 = pm_conc_connection_list;
  v28 = HIDWORD(pm_conc_connection_list);
  v30 = qword_81C464;
  v31 = HIDWORD(qword_81C464);
  v33 = qword_81C488;
  v32 = HIDWORD(qword_81C488);
  policy_mgr_get_mac_freq_list(
    v26,
    0,
    &v111,
    &v109,
    v108,
    HIDWORD(pm_conc_connection_list),
    (unsigned int)pm_conc_connection_list,
    HIDWORD(qword_81C464),
    qword_81C464,
    HIDWORD(qword_81C488),
    qword_81C488,
    a2,
    v104);
  if ( (unsigned int)v108[0] - 1 < 2
    || v108[0] == 3
    && __PAIR64__(v111, v111) == *(_QWORD *)((char *)&v111 + 4)
    && (((unsigned __int8)v109 | 2) != 2 ? (v35 = 0, v34 = 1) : (v34 = 0, v35 = 1),
        (BYTE1(v109) | 2) != 2 ? ++v34 : ++v35,
        (BYTE2(v109) | 2) != 2 ? ++v34 : ++v35,
        v34 == 2 ? (v39 = v35 == 1) : (v39 = 0),
        v39 || v34 == 3) )
  {
    policy_mgr_get_mac_freq_list(v26, 1, &v111, &v109, v108, v28, v29, v31, v30, v32, v33, a2, v104);
    if ( v108[0] == 3 )
    {
      if ( (_DWORD)v111 == DWORD1(v111) && (_DWORD)v111 == DWORD2(v111) )
      {
        if ( ((unsigned __int8)v109 | 2) == 2 )
        {
          v36 = 0;
          v37 = 1;
        }
        else
        {
          v37 = 0;
          v36 = 1;
        }
        if ( (BYTE1(v109) | 2) == 2 )
          ++v37;
        else
          ++v36;
        if ( (BYTE2(v109) | 2) == 2 )
          ++v37;
        else
          ++v36;
        v38 = v36 == 2 && v37 == 1;
        if ( v38 || v36 == 3 )
        {
LABEL_210:
          v73 = jiffies;
          if ( policy_mgr_allow_4th_new_freq___last_ticks - jiffies + 125 < 0 )
          {
            v86 = device_mode_to_string_0(v104);
            v87 = policy_mgr_hw_mode_to_str(v25);
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: new freq %d mode %s is allowed in hw mode %s",
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              "policy_mgr_allow_4th_new_freq",
              a2,
              v86,
              v87);
            policy_mgr_allow_4th_new_freq___last_ticks = v73;
          }
          result = 1;
          goto LABEL_208;
        }
      }
    }
    else if ( (unsigned int)v108[0] - 1 < 2 )
    {
      goto LABEL_210;
    }
  }
  v23 = v27;
  if ( (wlan_nan_is_sta_p2p_ndp_supported(a1) & 1) != 0 || (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) != 0 )
  {
    policy_mgr_get_mac_freq_list(
      v26,
      0,
      &v111,
      &v109,
      v108,
      HIDWORD(pm_conc_connection_list),
      (unsigned int)pm_conc_connection_list,
      HIDWORD(qword_81C464),
      qword_81C464,
      HIDWORD(qword_81C488),
      qword_81C488,
      a2,
      v104);
    v24 = v103;
    if ( !v108[0] )
    {
      v41 = v102;
      v40 = HIDWORD(v102);
      v43 = v101;
      v42 = HIDWORD(v101);
      LOBYTE(v44) = 0;
      LOBYTE(v45) = 0;
      LODWORD(v46) = 0;
      LOBYTE(v47) = 0;
      LOBYTE(v48) = 0;
      goto LABEL_114;
    }
    v41 = v102;
    v40 = HIDWORD(v102);
    v42 = HIDWORD(v101);
    if ( (unsigned int)v108[0] - 6 < 0xFFFFFFFB )
      __break(0x5512u);
    v43 = v101;
    if ( (unsigned __int8)v109 > 5u )
    {
      LOBYTE(v44) = 0;
      LOBYTE(v45) = 0;
      LODWORD(v46) = 0;
      LOBYTE(v47) = 0;
      LOBYTE(v48) = 0;
      if ( v108[0] == 1 )
        goto LABEL_114;
    }
    else
    {
      v44 = 0x10000000000uLL >> (8 * (unsigned __int8)v109);
      v45 = 0x100uLL >> (8 * (unsigned __int8)v109);
      v46 = 1uLL >> (8 * (unsigned __int8)v109);
      v47 = 0x100000000uLL >> (8 * (unsigned __int8)v109);
      v48 = 0x1010000uLL >> (8 * (unsigned __int8)v109);
      if ( v108[0] == 1 )
        goto LABEL_114;
    }
    if ( BYTE1(v109) <= 1u )
    {
      if ( BYTE1(v109) )
      {
        if ( BYTE1(v109) == 1 )
        {
          LOBYTE(v45) = v45 + 1;
          if ( v108[0] == 2 )
            goto LABEL_114;
          goto LABEL_77;
        }
      }
      else
      {
        LODWORD(v46) = v46 + 1;
      }
    }
    else
    {
      if ( (unsigned int)BYTE1(v109) - 2 < 2 )
      {
        LOBYTE(v48) = v48 + 1;
        if ( v108[0] == 2 )
          goto LABEL_114;
        goto LABEL_77;
      }
      if ( BYTE1(v109) == 4 )
      {
        LOBYTE(v47) = v47 + 1;
        if ( v108[0] == 2 )
          goto LABEL_114;
        goto LABEL_77;
      }
      if ( BYTE1(v109) == 5 )
      {
        LOBYTE(v44) = v44 + 1;
        if ( v108[0] == 2 )
          goto LABEL_114;
        goto LABEL_77;
      }
    }
    if ( v108[0] == 2 )
      goto LABEL_114;
LABEL_77:
    if ( BYTE2(v109) <= 1u )
    {
      if ( BYTE2(v109) )
      {
        if ( BYTE2(v109) == 1 )
          LOBYTE(v45) = v45 + 1;
      }
      else
      {
        LODWORD(v46) = v46 + 1;
      }
    }
    else if ( (unsigned int)BYTE2(v109) - 2 < 2 )
    {
      LOBYTE(v48) = v48 + 1;
    }
    else if ( BYTE2(v109) == 4 )
    {
      LOBYTE(v47) = v47 + 1;
    }
    else if ( BYTE2(v109) == 5 )
    {
      LOBYTE(v44) = v44 + 1;
    }
    if ( v108[0] != 3 )
    {
      if ( HIBYTE(v109) <= 1u )
      {
        if ( HIBYTE(v109) )
        {
          if ( HIBYTE(v109) == 1 )
            LOBYTE(v45) = v45 + 1;
        }
        else
        {
          LODWORD(v46) = v46 + 1;
        }
      }
      else if ( (unsigned int)HIBYTE(v109) - 2 < 2 )
      {
        LOBYTE(v48) = v48 + 1;
      }
      else if ( HIBYTE(v109) == 4 )
      {
        LOBYTE(v47) = v47 + 1;
      }
      else if ( HIBYTE(v109) == 5 )
      {
        LOBYTE(v44) = v44 + 1;
      }
      if ( v108[0] != 4 )
      {
        if ( v110 <= 1u )
        {
          if ( v110 )
          {
            if ( v110 == 1 )
              LOBYTE(v45) = v45 + 1;
          }
          else
          {
            LODWORD(v46) = v46 + 1;
          }
        }
        else if ( (unsigned int)v110 - 2 < 2 )
        {
          LOBYTE(v48) = v48 + 1;
        }
        else if ( v110 == 4 )
        {
          LOBYTE(v47) = v47 + 1;
        }
        else if ( v110 == 5 )
        {
          LOBYTE(v44) = v44 + 1;
        }
      }
    }
LABEL_114:
    if ( (v109 & 0xFE) != 4 )
    {
      v49 = v100;
      if ( (_DWORD)v111 )
      {
        v49 = v111;
        ++v43;
      }
      v100 = v49;
    }
    if ( (BYTE1(v109) & 0xFE) != 4 && DWORD1(v111) )
    {
      ++v43;
      v23 = DWORD1(v111);
      v24 = DWORD1(v111);
      HIDWORD(v107) = DWORD1(v111);
    }
    if ( (BYTE2(v109) & 0xFE) != 4 && DWORD2(v111) )
    {
      ++v43;
      v40 = DWORD2(v111);
      LODWORD(v107) = DWORD2(v111);
    }
    if ( (HIBYTE(v109) & 0xFE) != 4 && HIDWORD(v111) )
    {
      ++v43;
      v41 = HIDWORD(v111);
      HIDWORD(v106) = HIDWORD(v111);
    }
    LODWORD(v102) = v41;
    if ( (v110 & 0xFE) != 4 && v112 )
    {
      ++v43;
      v42 = v112;
      LODWORD(v106) = v112;
    }
    HIDWORD(v101) = v42;
    HIDWORD(v102) = v40;
    if ( (unsigned int)(unsigned __int8)v43 - 1 < 2 )
    {
      LODWORD(v101) = v43;
      goto LABEL_186;
    }
    if ( (unsigned __int8)v43 != 3 )
      goto LABEL_203;
    if ( v100 && v100 == v24 && v24 )
    {
      v50 = (char *)&v107 + 4;
    }
    else if ( v100 && v100 == v40 && v40 )
    {
      v50 = (char *)&v107;
    }
    else if ( v100 && v100 == v41 && v41 )
    {
      v50 = (char *)&v106 + 4;
    }
    else
    {
      v51 = 0;
      if ( !v100 || v100 != v42 || !v42 )
      {
LABEL_150:
        if ( v23 && v23 == v40 && v40 )
        {
          v52 = &v107;
        }
        else
        {
          v53 = HIDWORD(v106);
          if ( v23 && v23 == HIDWORD(v106) && HIDWORD(v106) )
          {
            v52 = (__int64 *)((char *)&v106 + 4);
          }
          else
          {
            v54 = 0;
            if ( !v23 || v23 != (_DWORD)v106 || !(_DWORD)v106 )
            {
LABEL_163:
              if ( v40 && v40 == v53 && v53 )
              {
                v55 = (__int64 *)((char *)&v106 + 4);
              }
              else
              {
                v56 = v106;
                v57 = 0;
                if ( !v40 || v40 != (_DWORD)v106 || !(_DWORD)v106 )
                {
LABEL_172:
                  HIDWORD(v102) = v40;
                  if ( v53 )
                    v58 = v56 == 0;
                  else
                    v58 = 1;
                  v59 = !v58 && v53 == v56;
                  v60 = v59;
                  if ( v59 )
                  {
                    v56 = 0;
                    v53 = 0;
                    v106 = 0;
                  }
                  HIDWORD(v101) = v56;
                  LODWORD(v102) = v53;
                  if ( !((v54 + v51 + v57) | v60) )
                  {
LABEL_203:
                    if ( v104 > 6 )
                      v61 = "Unknown";
                    else
                      v61 = off_9E73C0[v104];
                    qdf_trace_msg(
                      0x4Fu,
                      8u,
                      "%s: the 4th new freq %d mode %s is not allowed in any hw mode",
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      "policy_mgr_allow_4th_new_freq",
                      a2,
                      v61);
                    goto LABEL_207;
                  }
                  v24 = v23;
                  LODWORD(v101) = 3;
                  goto LABEL_186;
                }
                v55 = &v106;
              }
              *(_DWORD *)v55 = 0;
              v40 = 0;
              v57 = 1;
              v56 = v106;
              v53 = HIDWORD(v106);
              LODWORD(v107) = 0;
              goto LABEL_172;
            }
            v52 = &v106;
          }
        }
        *(_DWORD *)v52 = 0;
        v23 = 0;
        v54 = 1;
        v53 = HIDWORD(v106);
        v40 = v107;
        HIDWORD(v107) = 0;
        goto LABEL_163;
      }
      v50 = (char *)&v106;
    }
    *(_DWORD *)v50 = 0;
    v51 = 1;
    v40 = v107;
    v23 = HIDWORD(v107);
    v100 = 0;
    goto LABEL_150;
  }
  v24 = v103;
  LOBYTE(v44) = 0;
  LOBYTE(v45) = 0;
  LODWORD(v46) = 0;
  LOBYTE(v47) = 0;
  LOBYTE(v48) = 0;
LABEL_186:
  if ( (wlan_nan_is_sta_p2p_ndp_supported(a1) & 1) == 0 )
    goto LABEL_4;
  if ( (_DWORD)v46 == 2 && (unsigned __int8)v44 == 1 && (unsigned __int8)v48 == 1 )
  {
    v74 = 2;
    goto LABEL_215;
  }
  if ( (_DWORD)v46 != 1 || (unsigned __int8)v44 != 1 || (unsigned __int8)v47 != 1 || (unsigned __int8)v48 != 1 )
  {
LABEL_4:
    if ( ((_DWORD)v46 == 2 && (unsigned __int8)v44 == 1 && (unsigned __int8)v45 == 1
       || (_DWORD)v46 == 1 && (unsigned __int8)v44 == 1 && (unsigned __int8)v47 == 1 && (unsigned __int8)v45 == 1)
      && (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) != 0 )
    {
      v63 = device_mode_to_string_0(v104);
      v64 = policy_mgr_hw_mode_to_str(v25);
      LODWORD(v98) = (unsigned __int8)v47;
      LODWORD(v97) = (unsigned __int8)v45;
      LODWORD(v96) = (unsigned __int8)v44;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: new freq %d mode %s is allowed in hw mode %s sta %d nan %d sap %d ndi %d",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "policy_mgr_allow_4th_new_freq",
        a2,
        v63,
        v64,
        (unsigned int)v46,
        v96,
        v97,
        v98);
      result = 1;
      goto LABEL_208;
    }
    goto LABEL_5;
  }
  v74 = 1;
  LOBYTE(v47) = 1;
LABEL_215:
  result = 1;
  v75 = jiffies;
  if ( policy_mgr_allow_4th_new_freq___last_ticks_30 - jiffies + 125 < 0 )
  {
    v76 = device_mode_to_string_0(v104);
    v77 = policy_mgr_hw_mode_to_str(v25);
    LODWORD(v98) = (unsigned __int8)v47;
    LODWORD(v97) = 1;
    LODWORD(v96) = 1;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: new freq %d mode %s is allowed in hw mode %s sta %d nan %d p2p %d ndi %d",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "policy_mgr_allow_4th_new_freq",
      a2,
      v76,
      v77,
      v74,
      v96,
      v97,
      v98);
    result = 1;
    policy_mgr_allow_4th_new_freq___last_ticks_30 = v75;
  }
LABEL_208:
  _ReadStatusReg(SP_EL0);
  return result;
}
