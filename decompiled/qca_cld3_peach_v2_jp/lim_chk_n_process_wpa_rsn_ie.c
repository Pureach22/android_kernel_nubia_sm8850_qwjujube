__int64 __fastcall lim_chk_n_process_wpa_rsn_ie(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        _BYTE *a6,
        _DWORD *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  char v63; // w26
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x4
  __int64 v73; // x5
  __int64 v74; // x6
  __int64 v75; // x7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x4
  __int64 v85; // x5
  __int64 v86; // x6
  __int64 v87; // x7
  __int64 v88; // x26
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned __int8 *v97; // x0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned __int8 *v106; // x27
  __int64 v107; // x28
  unsigned __int8 v108; // w8
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w25
  int param; // w8
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 result; // x0
  __int64 v128; // x8
  __int64 v129; // x0
  __int64 v130; // x1
  __int64 v131; // x0
  const void *v132; // x25
  unsigned int v133; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  unsigned __int8 *v142; // x0
  unsigned __int8 v143; // w8
  unsigned __int8 *v144; // x26
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  int v153; // w25
  __int64 v154; // x6
  __int64 v155; // x4
  __int64 v156; // x5
  __int64 v157; // x7
  int v158; // w0
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  bool v167; // zf
  __int64 v168; // x4
  __int64 v169; // x5
  __int64 v170; // x6
  __int64 v171; // x7
  int v172; // w8
  unsigned int v173; // [xsp+10h] [xbp-200h] BYREF
  unsigned int v174; // [xsp+14h] [xbp-1FCh] BYREF
  _QWORD v175[8]; // [xsp+18h] [xbp-1F8h] BYREF
  __int64 v176; // [xsp+58h] [xbp-1B8h]
  __int64 v177; // [xsp+60h] [xbp-1B0h]
  __int64 v178; // [xsp+68h] [xbp-1A8h]
  __int64 v179; // [xsp+70h] [xbp-1A0h]
  __int64 v180; // [xsp+78h] [xbp-198h]
  __int64 v181; // [xsp+80h] [xbp-190h]
  __int64 v182; // [xsp+88h] [xbp-188h]
  __int64 v183; // [xsp+90h] [xbp-180h]
  __int64 v184; // [xsp+98h] [xbp-178h]
  __int64 v185; // [xsp+A0h] [xbp-170h]
  __int16 v186; // [xsp+A8h] [xbp-168h]
  _QWORD v187[6]; // [xsp+B0h] [xbp-160h] BYREF
  _DWORD s[72]; // [xsp+E0h] [xbp-130h] BYREF
  __int64 v189; // [xsp+200h] [xbp-10h]

  v189 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a4 + 3268) && *(_WORD *)(a4 + 1004) )
  {
    if ( wlan_get_vendor_ie_ptr_from_oui(&unk_A0967C, 4u, (unsigned __int8 *)(a4 + 1006), *(_WORD *)(a4 + 1004)) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Assoc req WSE IE is present",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_chk_n_process_wpa_rsn_ie");
LABEL_59:
      result = 1;
      goto LABEL_60;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Assoc req addIEPresent: %d addIE length: %d",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "lim_chk_n_process_wpa_rsn_ie");
  }
  if ( *(_DWORD *)(a3 + 88) != 1 )
    goto LABEL_59;
  v30 = *(_QWORD *)(a3 + 104);
  if ( !*(_BYTE *)(v30 + 49) || !*(_WORD *)(v30 + 56) )
    goto LABEL_59;
  memset(v187, 0, sizeof(v187));
  v186 = 0;
  v184 = 0;
  v185 = 0;
  v182 = 0;
  v183 = 0;
  v180 = 0;
  v181 = 0;
  v178 = 0;
  v179 = 0;
  v176 = 0;
  v177 = 0;
  memset(v175, 0, sizeof(v175));
  qdf_mem_set(v175, 0x92u, 0);
  qdf_mem_set(v187, 0x30u, 0);
  if ( a2 )
  {
    v39 = *a2;
    v40 = a2[1];
    v41 = a2[2];
    v42 = a2[5];
  }
  else
  {
    v41 = 0;
    v39 = 0;
    v40 = 0;
    v42 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: RSN enabled auth, Re/Assoc req from STA: %02x:%02x:%02x:**:**:%02x",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "lim_check_wpa_rsn_ie",
    v39,
    v40,
    v41,
    v42);
  if ( *(_BYTE *)(a4 + 3267) )
  {
    if ( *(_BYTE *)(a4 + 748) )
    {
      v54 = dot11f_unpack_ie_rsn(a1, a4 + 749, *(unsigned __int8 *)(a4 + 748), v175, 0);
      if ( v54 )
      {
        v63 = v54;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid RSN IE 0x%x",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "lim_check_wpa_rsn_ie",
          v54);
        if ( (v63 & 0x40) != 0 )
        {
          if ( a2 )
          {
            v72 = *a2;
            v73 = a2[1];
            v74 = a2[2];
            v75 = a2[5];
          }
          else
          {
            v74 = 0;
            v72 = 0;
            v73 = 0;
            v75 = 0;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Re/Assoc rejected from: %02x:%02x:%02x:**:**:%02x",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "lim_check_wpa_rsn_ie",
            v72,
            v73,
            v74,
            v75);
          v128 = a4 + 3608;
          v129 = a1;
          v130 = 44;
          goto LABEL_50;
        }
        goto LABEL_35;
      }
      v88 = *(_QWORD *)(a3 + 16);
      memset(s, 0, sizeof(s));
      v174 = 0;
      if ( !v88 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: pe session vdev is null!",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "lim_check_rsn_ie");
        v117 = 1;
        if ( a2 )
        {
LABEL_48:
          v155 = *a2;
          v156 = a2[1];
          v154 = a2[2];
          v157 = a2[5];
          goto LABEL_49;
        }
LABEL_43:
        v154 = 0;
        v155 = 0;
        v156 = 0;
        v157 = 0;
LABEL_49:
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Re/Assoc rejected from: %02x:%02x:%02x:**:**:%02x",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "lim_check_wpa_rsn_ie",
          v155,
          v156,
          v154,
          v157);
        v128 = a4 + 3608;
        v129 = a1;
        v130 = v117;
        goto LABEL_50;
      }
      v97 = (unsigned __int8 *)_qdf_mem_malloc(0x100u, "lim_check_rsn_ie", 931);
      if ( !v97 )
      {
        v117 = 1;
        goto LABEL_47;
      }
      v106 = v97;
      v97[1] = 48;
      v107 = (__int64)(v97 + 1);
      v108 = *(_BYTE *)(a4 + 748);
      v97[2] = v108;
      *v97 = v108 + 2;
      qdf_mem_copy(v97 + 3, (const void *)(a4 + 749), *(unsigned __int8 *)(a4 + 748));
      if ( (unsigned int)wlan_crypto_check_rsn_match(
                           *(_QWORD *)(a1 + 21552),
                           *(unsigned __int8 *)(a3 + 10),
                           v107,
                           *v106,
                           s,
                           (int *)&v174,
                           v109,
                           v110,
                           v111,
                           v112,
                           v113,
                           v114,
                           v115,
                           v116) )
      {
        _qdf_mem_free((__int64)v106);
        v117 = v174;
        if ( !v174 )
          goto LABEL_58;
LABEL_47:
        if ( a2 )
          goto LABEL_48;
        goto LABEL_43;
      }
      if ( (s[38] & 0x80) != 0 && wlan_crypto_vdev_is_pmf_enabled(v88) )
        *a6 = 1;
      _qdf_mem_free((__int64)v106);
      if ( !*(_BYTE *)(a4 + 3160) || (s[1] & 3) == 0 )
      {
LABEL_58:
        v158 = lim_translate_rsn_oui_to_akm_type((char *)&v175[4] + 6);
        *a7 = v158;
        if ( (*(_BYTE *)(a3 + 7024) & 0x10) == 0 )
          goto LABEL_59;
        v167 = v158 == 7;
        result = 1;
        if ( v167 && (SHIBYTE(v176) & 0x80000000) == 0 )
        {
          if ( a2 )
          {
            v168 = *a2;
            v169 = a2[1];
            v170 = a2[2];
            v171 = a2[5];
          }
          else
          {
            v170 = 0;
            v168 = 0;
            v169 = 0;
            v171 = 0;
          }
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Re/Assoc rejected from: %02x:%02x:%02x:**:**:%02x",
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            "lim_check_wpa_rsn_ie",
            v168,
            v169,
            v170,
            v171);
          v128 = a4 + 3608;
          v129 = a1;
          v130 = 31;
          goto LABEL_50;
        }
        goto LABEL_60;
      }
LABEL_56:
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: TKIP/WEP cipher with HT supported client, reject assoc",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "lim_check_crypto_param");
      v117 = 40;
      if ( a2 )
        goto LABEL_48;
      goto LABEL_43;
    }
    goto LABEL_22;
  }
  if ( *(_BYTE *)(a4 + 3266) )
  {
    if ( *(_BYTE *)(a4 + 492) )
    {
      if ( !(unsigned int)dot11f_unpack_ie_wpa(
                            a1,
                            a4 + 497,
                            (unsigned int)*(unsigned __int8 *)(a4 + 492) - 4,
                            v187,
                            0,
                            v43,
                            v44,
                            v45) )
      {
        v174 = 0;
        memset(s, 0, sizeof(s));
        v173 = 0;
        v131 = _qdf_mem_malloc(0xFFu, "lim_check_wpa_ie", 973);
        if ( !v131 )
        {
          v117 = 1;
          if ( a2 )
            goto LABEL_48;
          goto LABEL_43;
        }
        v132 = (const void *)v131;
        v133 = dot11f_pack_ie_wpa(a1, v187, v131, 255, &v174);
        if ( (v133 & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to re-pack the RSN IE (0x%08x)",
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            "lim_check_wpa_ie",
            v133);
          _qdf_mem_free((__int64)v132);
          v117 = 40;
          if ( a2 )
            goto LABEL_48;
          goto LABEL_43;
        }
        v142 = (unsigned __int8 *)_qdf_mem_malloc(0x100u, "lim_check_wpa_ie", 985);
        if ( !v142 )
        {
          _qdf_mem_free((__int64)v132);
          v117 = 1;
          if ( a2 )
            goto LABEL_48;
          goto LABEL_43;
        }
        v143 = v174;
        v144 = v142;
        *v142 = v174;
        qdf_mem_copy(v142 + 1, v132, v143);
        _qdf_mem_free((__int64)v132);
        v153 = wlan_crypto_check_wpa_match(
                 *(_QWORD *)(a1 + 21552),
                 *(unsigned __int8 *)(a3 + 10),
                 (__int64)(v144 + 1),
                 *v144,
                 s,
                 (int *)&v173,
                 v145,
                 v146,
                 v147,
                 v148,
                 v149,
                 v150,
                 v151,
                 v152);
        _qdf_mem_free((__int64)v144);
        if ( v153 )
        {
          v117 = v173;
          if ( v173 )
            goto LABEL_47;
        }
        else if ( *(_BYTE *)(a4 + 3160) && (s[1] & 3) != 0 )
        {
          goto LABEL_56;
        }
        v172 = lim_translate_rsn_oui_to_akm_type((char *)&v187[3] + 6);
        result = 1;
        *a7 = v172;
        goto LABEL_60;
      }
      qdf_trace_msg(0x35u, 2u, "%s: Invalid WPA IE", v76, v77, v78, v79, v80, v81, v82, v83, "lim_check_wpa_rsn_ie");
LABEL_35:
      v128 = a4 + 3608;
      v129 = a1;
      v130 = 40;
      goto LABEL_50;
    }
LABEL_22:
    if ( a2 )
    {
      v84 = *a2;
      v85 = a2[1];
      v86 = a2[2];
      v87 = a2[5];
    }
    else
    {
      v86 = 0;
      v84 = 0;
      v85 = 0;
      v87 = 0;
    }
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Re/Assoc rejected from: %02x:%02x:%02x:**:**:%02x",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_check_wpa_rsn_ie",
      v84,
      v85,
      v86,
      v87);
    goto LABEL_35;
  }
  param = wlan_crypto_get_param(*(_QWORD *)(a3 + 16), 7u);
  result = 1;
  if ( param && (param & 4) == 0 && *(_DWORD *)(a3 + 7036) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: STA does not support RSN and WPA!",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "lim_check_wpa_rsn_ie");
    v128 = a4 + 3608;
    v129 = a1;
    v130 = 13;
LABEL_50:
    lim_send_assoc_rsp_mgmt_frame(v129, v130, 1, a2, a5, 0, a3, 0, v128);
    result = 0;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
