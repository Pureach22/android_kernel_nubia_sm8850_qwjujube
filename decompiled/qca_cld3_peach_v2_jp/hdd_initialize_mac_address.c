__int64 __fastcall hdd_initialize_mac_address(unsigned __int8 *a1)
{
  __int64 v2; // x20
  __int64 wlan_mac_address; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  unsigned int v13; // w8
  int v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x5
  __int64 v32; // x6
  __int64 v33; // x7
  int v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x5
  __int64 v53; // x6
  __int64 v54; // x7
  int v55; // w8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x5
  __int64 v65; // x6
  __int64 v66; // x7
  int v67; // w8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x5
  __int64 v77; // x6
  __int64 v78; // x7
  int v79; // w8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  int v91; // w8
  __int64 v92; // x0
  __int64 v93; // x9
  __int64 wlan_derived_mac_address; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x20
  unsigned int v104; // w8
  int v105; // w9
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x5
  __int64 v123; // x6
  __int64 v124; // x7
  int v125; // w8
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int64 v134; // x5
  __int64 v135; // x6
  __int64 v136; // x7
  int v137; // w8
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  __int64 v146; // x5
  __int64 v147; // x6
  __int64 v148; // x7
  int v149; // w8
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  __int64 v158; // x5
  __int64 v159; // x6
  __int64 v160; // x7
  int v161; // w8
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  __int64 v170; // x5
  __int64 v171; // x6
  __int64 v172; // x7
  int v173; // w8
  unsigned int v174; // w8
  const char *v175; // x2
  int serial_number; // w0
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  unsigned __int64 v186; // x1
  int v187; // w8
  bool v188; // zf
  __int64 v189; // x8
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  __int64 v198; // [xsp+0h] [xbp-30h]
  __int64 v199; // [xsp+0h] [xbp-30h]
  __int64 v200; // [xsp+0h] [xbp-30h]
  __int64 v201; // [xsp+0h] [xbp-30h]
  __int64 v202; // [xsp+0h] [xbp-30h]
  __int64 v203; // [xsp+0h] [xbp-30h]
  _DWORD v204[3]; // [xsp+14h] [xbp-1Ch] BYREF
  unsigned int v205; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v206; // [xsp+24h] [xbp-Ch]
  __int64 v207; // [xsp+28h] [xbp-8h]

  v207 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a1 + 12);
  v204[0] = 0;
  v206 = 0;
  v205 = 0;
  wlan_mac_address = cnss_utils_get_wlan_mac_address(v2, v204);
  if ( !v204[0] || (v12 = wlan_mac_address) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: No mac configured from platform driver",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_platform_wlan_mac");
    v43 = -22;
    goto LABEL_62;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Resetting MAC address lists",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "hdd_free_mac_address_lists");
  qdf_mem_set(a1 + 3751, 0x24u, 0);
  qdf_mem_set(a1 + 3787, 0x24u, 0);
  v13 = v204[0];
  *((_QWORD *)a1 + 480) = 0;
  *((_QWORD *)a1 + 479) = 0;
  *((_QWORD *)a1 + 478) = 0;
  if ( v13 >= 7 )
    v204[0] = 6;
  qdf_mem_copy(&v205, (const void *)v12, 6u);
  v14 = v204[0];
  if ( !v204[0] )
    goto LABEL_28;
  qdf_mem_copy(a1 + 3751, (const void *)v12, 6u);
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_platform_wlan_mac",
    0,
    a1[3751],
    a1[3752],
    a1[3753],
    a1[3756]);
  v14 = v204[0];
  if ( v204[0] <= 1u )
    goto LABEL_28;
  qdf_mem_copy(a1 + 3757, (const void *)(v12 + 6), 6u);
  if ( a1 == (unsigned __int8 *)-3757LL )
  {
    v33 = 0;
    v31 = 0;
    v32 = 0;
    v34 = 0;
  }
  else
  {
    v31 = a1[3757];
    v32 = a1[3758];
    v33 = a1[3759];
    v34 = a1[3762];
  }
  LODWORD(v198) = v34;
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "hdd_platform_wlan_mac",
    1,
    v31,
    v32,
    v33,
    v198);
  v14 = v204[0];
  if ( v204[0] < 3u )
    goto LABEL_28;
  qdf_mem_copy(a1 + 3763, (const void *)(v12 + 12), 6u);
  if ( a1 == (unsigned __int8 *)-3763LL )
  {
    v54 = 0;
    v52 = 0;
    v53 = 0;
    v55 = 0;
  }
  else
  {
    v52 = a1[3763];
    v53 = a1[3764];
    v54 = a1[3765];
    v55 = a1[3768];
  }
  LODWORD(v198) = v55;
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "hdd_platform_wlan_mac",
    2,
    v52,
    v53,
    v54,
    v198);
  v14 = v204[0];
  if ( v204[0] < 4u )
    goto LABEL_28;
  qdf_mem_copy(a1 + 3769, (const void *)(v12 + 18), 6u);
  if ( a1 == (unsigned __int8 *)-3769LL )
  {
    v66 = 0;
    v64 = 0;
    v65 = 0;
    v67 = 0;
  }
  else
  {
    v64 = a1[3769];
    v65 = a1[3770];
    v66 = a1[3771];
    v67 = a1[3774];
  }
  LODWORD(v198) = v67;
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "hdd_platform_wlan_mac",
    3,
    v64,
    v65,
    v66,
    v198);
  v14 = v204[0];
  if ( v204[0] < 5u )
    goto LABEL_28;
  qdf_mem_copy(a1 + 3775, (const void *)(v12 + 24), 6u);
  if ( a1 == (unsigned __int8 *)-3775LL )
  {
    v78 = 0;
    v76 = 0;
    v77 = 0;
    v79 = 0;
  }
  else
  {
    v76 = a1[3775];
    v77 = a1[3776];
    v78 = a1[3777];
    v79 = a1[3780];
  }
  LODWORD(v198) = v79;
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "hdd_platform_wlan_mac",
    4,
    v76,
    v77,
    v78,
    v198);
  v14 = v204[0];
  if ( v204[0] < 6u )
    goto LABEL_28;
  qdf_mem_copy(a1 + 3781, (const void *)(v12 + 30), 6u);
  if ( a1 == (unsigned __int8 *)-3781LL )
  {
    v90 = 0;
    v88 = 0;
    v89 = 0;
    v91 = 0;
  }
  else
  {
    v88 = a1[3781];
    v89 = a1[3782];
    v90 = a1[3783];
    v91 = a1[3786];
  }
  LODWORD(v198) = v91;
  v92 = qdf_trace_msg(
          0x33u,
          4u,
          "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "hdd_platform_wlan_mac",
          5,
          v88,
          v89,
          v90,
          v198);
  v14 = v204[0];
  if ( v204[0] <= 6u )
  {
LABEL_28:
    v93 = *((_QWORD *)a1 + 13);
    *((_DWORD *)a1 + 956) = v14;
    if ( (*(_BYTE *)(v93 + 126) & 1) == 0 )
    {
      v105 = *((_DWORD *)a1 + 957);
LABEL_58:
      v174 = v14 + v105;
      v204[0] = v174;
      if ( v174 <= 5 )
        ((void (__fastcall *)(unsigned __int8 *, _QWORD))hdd_populate_random_mac_addr)(a1, 6 - v174);
      if ( !(unsigned int)sme_set_custom_mac_addr(&v205) )
      {
        v175 = "%s: using MAC address from platform driver";
        goto LABEL_69;
      }
      v43 = -11;
LABEL_62:
      if ( *(_BYTE *)(*((_QWORD *)a1 + 13) + 126LL) == 1 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: getting MAC address from platform driver failed",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_initialize_mac_address");
LABEL_71:
        _ReadStatusReg(SP_EL0);
        return v43;
      }
      if ( (unsigned int)hdd_update_mac_config((__int64)a1, v35, v36, v37, v38, v39, v40, v41, v42) )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: using default MAC address",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_initialize_mac_address");
        if ( *(_DWORD *)(a1 + 3745) | *(unsigned __int16 *)(a1 + 3749) )
        {
          hdd_update_macaddr(
            a1,
            *(unsigned int *)(a1 + 3745) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 3749) << 32),
            0);
        }
        else
        {
          serial_number = pld_socinfo_get_serial_number(*((_QWORD *)a1 + 12));
          if ( serial_number )
          {
            v186 = bswap64(serial_number & 0xFFFFFF | 0xAF5000000LL) >> 16;
          }
          else
          {
            v206 = 0;
            v205 = 0;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: MAC failure from device serial no.",
              v178,
              v179,
              v180,
              v181,
              v182,
              v183,
              v184,
              v185,
              "hdd_initialize_mac_address");
            get_random_bytes(&v205, 6);
            LOBYTE(v205) = 2;
            v186 = v205 | ((unsigned __int64)v206 << 32);
          }
          hdd_update_macaddr(a1, v186, 1);
          v187 = *((_DWORD *)a1 + 956);
          v206 = 0;
          v188 = v187 == 0;
          v189 = 3751;
          v205 = 0;
          if ( v188 )
            v189 = 3787;
          qdf_mem_copy(&v205, &a1[v189], 6u);
          if ( (unsigned int)sme_set_custom_mac_addr(&v205) )
          {
            v43 = -11;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: MAC address out-of-sync, ret:%d",
              v190,
              v191,
              v192,
              v193,
              v194,
              v195,
              v196,
              v197,
              "hdd_initialize_mac_address",
              4294967285LL);
            goto LABEL_71;
          }
        }
        goto LABEL_70;
      }
      v175 = "%s: using MAC address from wlan_mac.bin";
LABEL_69:
      qdf_trace_msg(0x33u, 4u, v175, v35, v36, v37, v38, v39, v40, v41, v42, "hdd_initialize_mac_address");
LABEL_70:
      v43 = 0;
      goto LABEL_71;
    }
    wlan_derived_mac_address = cnss_utils_get_wlan_derived_mac_address(v2, v204);
    v103 = wlan_derived_mac_address;
    if ( v204[0] && wlan_derived_mac_address )
    {
      v104 = 6 - *((_DWORD *)a1 + 956);
      if ( v204[0] > v104 )
      {
        v204[0] = 6 - *((_DWORD *)a1 + 956);
        if ( !v104 )
          goto LABEL_33;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: No derived address from platform driver",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "hdd_platform_wlan_mac");
      if ( !v204[0] )
      {
LABEL_33:
        v105 = 0;
LABEL_57:
        v14 = *((_DWORD *)a1 + 956);
        *((_DWORD *)a1 + 957) = v105;
        goto LABEL_58;
      }
    }
    qdf_mem_copy(a1 + 3787, (const void *)v103, 6u);
    LODWORD(v198) = a1[3792];
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "hdd_platform_wlan_mac",
      0,
      a1[3787],
      a1[3788],
      a1[3789],
      v198);
    v105 = v204[0];
    if ( v204[0] < 2u )
      goto LABEL_57;
    qdf_mem_copy(a1 + 3793, (const void *)(v103 + 6), 6u);
    if ( a1 == (unsigned __int8 *)-3793LL )
    {
      v124 = 0;
      v122 = 0;
      v123 = 0;
      v125 = 0;
    }
    else
    {
      v122 = a1[3793];
      v123 = a1[3794];
      v124 = a1[3795];
      v125 = a1[3798];
    }
    LODWORD(v199) = v125;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      "hdd_platform_wlan_mac",
      1,
      v122,
      v123,
      v124,
      v199);
    v105 = v204[0];
    if ( v204[0] < 3u )
      goto LABEL_57;
    qdf_mem_copy(a1 + 3799, (const void *)(v103 + 12), 6u);
    if ( a1 == (unsigned __int8 *)-3799LL )
    {
      v136 = 0;
      v134 = 0;
      v135 = 0;
      v137 = 0;
    }
    else
    {
      v134 = a1[3799];
      v135 = a1[3800];
      v136 = a1[3801];
      v137 = a1[3804];
    }
    LODWORD(v200) = v137;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      "hdd_platform_wlan_mac",
      2,
      v134,
      v135,
      v136,
      v200);
    v105 = v204[0];
    if ( v204[0] < 4u )
      goto LABEL_57;
    qdf_mem_copy(a1 + 3805, (const void *)(v103 + 18), 6u);
    if ( a1 == (unsigned __int8 *)-3805LL )
    {
      v148 = 0;
      v146 = 0;
      v147 = 0;
      v149 = 0;
    }
    else
    {
      v146 = a1[3805];
      v147 = a1[3806];
      v148 = a1[3807];
      v149 = a1[3810];
    }
    LODWORD(v201) = v149;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      "hdd_platform_wlan_mac",
      3,
      v146,
      v147,
      v148,
      v201);
    v105 = v204[0];
    if ( v204[0] < 5u )
      goto LABEL_57;
    qdf_mem_copy(a1 + 3811, (const void *)(v103 + 24), 6u);
    if ( a1 == (unsigned __int8 *)-3811LL )
    {
      v160 = 0;
      v158 = 0;
      v159 = 0;
      v161 = 0;
    }
    else
    {
      v158 = a1[3811];
      v159 = a1[3812];
      v160 = a1[3813];
      v161 = a1[3816];
    }
    LODWORD(v202) = v161;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      "hdd_platform_wlan_mac",
      4,
      v158,
      v159,
      v160,
      v202);
    v105 = v204[0];
    if ( v204[0] < 6u )
      goto LABEL_57;
    qdf_mem_copy(a1 + 3817, (const void *)(v103 + 30), 6u);
    if ( a1 == (unsigned __int8 *)-3817LL )
    {
      v172 = 0;
      v170 = 0;
      v171 = 0;
      v173 = 0;
    }
    else
    {
      v170 = a1[3817];
      v171 = a1[3818];
      v172 = a1[3819];
      v173 = a1[3822];
    }
    LODWORD(v203) = v173;
    v92 = qdf_trace_msg(
            0x33u,
            8u,
            "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
            v162,
            v163,
            v164,
            v165,
            v166,
            v167,
            v168,
            v169,
            "hdd_platform_wlan_mac",
            5,
            v170,
            v171,
            v172,
            v203);
    v105 = v204[0];
    if ( v204[0] <= 6u )
      goto LABEL_57;
  }
  __break(0x5512u);
  return hdd_psoc_create_vdevs(v92);
}
