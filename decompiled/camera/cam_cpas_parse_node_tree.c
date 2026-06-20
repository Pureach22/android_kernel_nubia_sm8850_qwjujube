__int64 __fastcall cam_cpas_parse_node_tree(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 child_by_name; // x0
  __int64 v6; // x21
  __int64 next_available_child; // x0
  __int64 v8; // x22
  unsigned int variable_u32_array; // w0
  int v10; // w27
  int v11; // w21
  unsigned int v12; // w6
  __int64 v13; // x28
  __int64 v14; // x10
  int v15; // w8
  __int64 v16; // x19
  bool v17; // w25
  __int64 v18; // x0
  unsigned int *v19; // x23
  __int64 v20; // x19
  unsigned int v21; // w0
  __int64 v22; // x6
  unsigned int v23; // w8
  unsigned int string; // w0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w0
  unsigned int v30; // w0
  int v31; // w0
  __int64 v32; // x8
  unsigned int v33; // w6
  char v34; // w8
  __int64 i; // x8
  __int64 v36; // x0
  __int64 v37; // x22
  __int64 v38; // x0
  const char *v39; // x1
  int string_helper; // w6
  int v41; // w8
  __int64 v42; // x20
  __int64 v43; // x19
  __int64 v44; // x25
  unsigned int v45; // w27
  const char **v46; // x21
  unsigned int v47; // w0
  unsigned int v48; // w0
  int v49; // w0
  int v50; // w0
  const char *v51; // x8
  __int64 v52; // x24
  __int64 rsc_dev_for_drv; // x0
  __int64 v54; // x19
  unsigned int v55; // w0
  int v56; // w9
  __int64 node_by_name; // x0
  __int64 v58; // x2
  unsigned int v59; // w0
  __int64 v60; // x8
  int v61; // w25
  __int64 property; // x22
  __int64 v63; // x0
  __int64 v64; // x21
  unsigned int string_index; // w0
  __int64 v66; // x0
  __int64 v67; // x1
  int v68; // w9
  unsigned int v69; // w8
  unsigned int v70; // w6
  unsigned int v71; // w0
  int v72; // w0
  int v73; // w22
  unsigned int v74; // w21
  unsigned int v75; // w0
  unsigned int v76; // w6
  __int64 v77; // x19
  __int64 v78; // x8
  __int64 v79; // x9
  const char *v80; // x3
  const char *v81; // x5
  __int64 v82; // x4
  const char *v83; // x5
  __int64 v84; // x4
  __int64 v85; // x6
  const char *v86; // x5
  __int64 v87; // x4
  const char *v88; // x5
  __int64 v89; // x4
  unsigned int v90; // w24
  int v92; // [xsp+1Ch] [xbp-214h]
  __int64 v93; // [xsp+28h] [xbp-208h]
  __int64 v94; // [xsp+30h] [xbp-200h]
  int v95; // [xsp+38h] [xbp-1F8h]
  int v96; // [xsp+3Ch] [xbp-1F4h]
  __int64 v97; // [xsp+40h] [xbp-1F0h]
  __int64 v98; // [xsp+48h] [xbp-1E8h]
  int v99; // [xsp+50h] [xbp-1E0h]
  bool v100; // [xsp+54h] [xbp-1DCh]
  __int64 v101; // [xsp+58h] [xbp-1D8h]
  __int64 v102; // [xsp+60h] [xbp-1D0h]
  unsigned int v103; // [xsp+6Ch] [xbp-1C4h]
  int v104; // [xsp+70h] [xbp-1C0h]
  __int64 v105; // [xsp+78h] [xbp-1B8h]
  __int64 v106; // [xsp+80h] [xbp-1B0h]
  __int64 v107; // [xsp+88h] [xbp-1A8h]
  __int64 v108; // [xsp+90h] [xbp-1A0h]
  bool v109; // [xsp+9Ch] [xbp-194h]
  __int64 v110; // [xsp+A0h] [xbp-190h]
  __int64 v111; // [xsp+A8h] [xbp-188h]
  __int64 v112; // [xsp+B0h] [xbp-180h]
  __int64 v113; // [xsp+B8h] [xbp-178h] BYREF
  const char *v114; // [xsp+C0h] [xbp-170h] BYREF
  __int64 v115; // [xsp+C8h] [xbp-168h] BYREF
  _QWORD v116[21]; // [xsp+D0h] [xbp-160h] BYREF
  int v117; // [xsp+178h] [xbp-B8h]
  __int64 v118; // [xsp+180h] [xbp-B0h] BYREF
  __int64 v119; // [xsp+188h] [xbp-A8h]
  __int64 v120; // [xsp+190h] [xbp-A0h]
  __int64 v121; // [xsp+198h] [xbp-98h]
  __int64 v122; // [xsp+1A0h] [xbp-90h]
  __int64 v123; // [xsp+1A8h] [xbp-88h]
  __int64 v124; // [xsp+1B0h] [xbp-80h]
  __int64 v125; // [xsp+1B8h] [xbp-78h]
  __int64 v126; // [xsp+1C0h] [xbp-70h]
  __int64 v127; // [xsp+1C8h] [xbp-68h]
  __int64 v128; // [xsp+1D0h] [xbp-60h] BYREF
  __int64 v129; // [xsp+1D8h] [xbp-58h]
  __int64 v130; // [xsp+1E0h] [xbp-50h]
  __int64 v131; // [xsp+1E8h] [xbp-48h]
  __int64 v132; // [xsp+1F0h] [xbp-40h]
  __int64 v133; // [xsp+1F8h] [xbp-38h]
  __int64 v134; // [xsp+200h] [xbp-30h]
  __int64 v135; // [xsp+208h] [xbp-28h]
  __int64 v136; // [xsp+210h] [xbp-20h]
  __int64 v137; // [xsp+218h] [xbp-18h]
  __int64 v138; // [xsp+220h] [xbp-10h]

  v138 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v114 = nullptr;
  v115 = 0;
  v113 = 0;
  v117 = 0;
  memset(v116, 0, sizeof(v116));
  child_by_name = of_get_child_by_name(a2, "camera-bus-nodes");
  if ( !child_by_name )
  {
    v80 = "cam_cpas_parse_node_tree";
    v81 = "Camera Bus node not found in cpas DT node";
    v82 = 564;
    goto LABEL_163;
  }
  v6 = child_by_name;
  *(_QWORD *)(a3 + 864) = child_by_name;
  next_available_child = of_get_next_available_child(child_by_name, 0);
  if ( next_available_child )
  {
    v8 = next_available_child;
    while ( 1 )
    {
      variable_u32_array = of_property_read_variable_u32_array(v8, "level-index", (char *)&v115 + 4, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v90 = variable_u32_array;
        v83 = "Error reading level idx rc: %d";
        v84 = 573;
        goto LABEL_192;
      }
      if ( SHIDWORD(v115) >= 4 )
      {
        v80 = "cam_cpas_parse_node_tree";
        v81 = "Invalid level idx: %d";
        v82 = 577;
        goto LABEL_163;
      }
      if ( HIDWORD(v115) >= 4 )
        break;
      *(_QWORD *)(a3 + 872 + 8LL * HIDWORD(v115)) = v8;
      v8 = of_get_next_available_child(v6, v8);
      if ( !v8 )
        goto LABEL_8;
    }
LABEL_209:
    __break(0x5512u);
  }
LABEL_8:
  if ( *(_BYTE *)(a3 + 1608) == 1 )
    *(_BYTE *)(*(_QWORD *)(a3 + 1616) + 9LL) = 0;
  v10 = 0;
  v11 = 0;
  v12 = 3;
  v99 = *(unsigned __int8 *)(a3 + 1609);
  if ( *(_BYTE *)(a3 + 1609) )
    v13 = 4;
  else
    v13 = 1;
  HIDWORD(v115) = 3;
  v111 = a3 + 872;
  v108 = a3 + 360;
  if ( v99 )
    v14 = 224;
  else
    v14 = 56;
  v110 = a1;
  v105 = (unsigned int)(4 * v13);
  v106 = v14;
  v94 = a1 + 5544;
  v97 = a1 + 3096;
  if ( (unsigned int)v13 <= 2 )
    v15 = 2;
  else
    v15 = v13;
  v96 = v15;
  _ReadStatusReg(SP_EL0);
  v93 = a1 + 320;
  while ( 1 )
  {
    if ( v12 > 3 )
      goto LABEL_209;
    v16 = *(_QWORD *)(v111 + 8LL * v12);
    if ( v16 )
    {
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_parse_node_tree",
          597,
          "Parsing level %d nodes",
          v12);
      v17 = of_find_property(v16, "camnoc-max-needed", 0) != 0;
      v112 = of_get_next_available_child(v16, 0);
      if ( v112 )
        break;
    }
LABEL_20:
    v12 = --HIDWORD(v115);
    if ( v115 < 0 )
    {
      _mutex_init(a1 + 2728, "&cpas_core->tree_lock", &cam_cpas_parse_node_tree___key);
      cam_cpas_util_debug_parse_data(a3);
      v90 = 0;
      goto LABEL_194;
    }
  }
  v100 = v17;
  v98 = v16;
  while ( 1 )
  {
    if ( mem_trace_en == 1 )
      v18 = cam_mem_trace_alloc(152, 0xCC0u, 0, "cam_cpas_parse_node_tree", 0x25Au);
    else
      v18 = _kvmalloc_node_noprof(152, 0, 3520, 0xFFFFFFFFLL);
    v19 = (unsigned int *)v18;
    v20 = v112;
    if ( !v18 )
    {
      v90 = -12;
      goto LABEL_194;
    }
    *(_QWORD *)(v18 + 104) = v112;
    v21 = of_property_read_variable_u32_array(v112, "cell-index", v18, 1, 0);
    if ( (v21 & 0x80000000) != 0 )
    {
      v90 = v21;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_node_tree",
        610,
        "Node index not found");
      goto LABEL_194;
    }
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_parse_node_tree",
        615,
        "Parsing Node with cell index %d",
        *v19);
    v22 = *v19;
    if ( (unsigned int)v22 >= 0x3F )
    {
      v80 = "cam_cpas_parse_node_tree";
      v81 = "Invalid cell idx: %d";
      v82 = 619;
      goto LABEL_163;
    }
    v23 = HIDWORD(v115);
    *(_QWORD *)(v108 + 8 * v22) = v19;
    v19[1] = v23;
    string = of_property_read_string(v112, "node-name", v19 + 6);
    if ( string )
    {
      v90 = string;
      v83 = "failed to read node-name rc=%d";
      v84 = 629;
      goto LABEL_192;
    }
    if ( mem_trace_en == 1 )
    {
      v25 = cam_mem_trace_alloc(v106, 0xCC0u, 0, "cam_cpas_parse_node_tree", 0x27Bu);
      *((_QWORD *)v19 + 6) = v25;
      if ( !v25 )
        goto LABEL_174;
    }
    else
    {
      v26 = _kvmalloc_node_noprof(v106, 0, 3520, 0xFFFFFFFFLL);
      *((_QWORD *)v19 + 6) = v26;
      if ( !v26 )
      {
LABEL_174:
        v86 = "Failed in allocating memory for bw info";
        v87 = 637;
        goto LABEL_176;
      }
    }
    if ( mem_trace_en != 1 )
    {
      v28 = _kvmalloc_node_noprof(v105, 0, 3520, 0xFFFFFFFFLL);
      *((_QWORD *)v19 + 1) = v28;
      if ( v28 )
        goto LABEL_46;
LABEL_175:
      v86 = "Failed in allocating memory for port indices";
      v87 = 645;
LABEL_176:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_node_tree",
        v87,
        v86);
      v90 = -12;
      goto LABEL_194;
    }
    v27 = cam_mem_trace_alloc(v105, 0xCC0u, 0, "cam_cpas_parse_node_tree", 0x283u);
    *((_QWORD *)v19 + 1) = v27;
    if ( !v27 )
      goto LABEL_175;
LABEL_46:
    if ( *(_BYTE *)(a3 + 1608) == 1 && HIDWORD(v115) == 1 && of_find_property(v112, "rt-wr-niu", 0) )
    {
      v29 = of_property_read_variable_u32_array(v112, "priority-lut-low-offset", v19 + 30, 1, 0);
      if ( (v29 & 0x80000000) != 0 )
      {
        v90 = v29;
        v83 = "Invalid priority low offset rc %d";
        v84 = 655;
        goto LABEL_192;
      }
      v30 = of_property_read_variable_u32_array(v112, "priority-lut-high-offset", v19 + 31, 1, 0);
      if ( (v30 & 0x80000000) != 0 )
      {
        v90 = v30;
        v83 = "Invalid priority high offset rc %d";
        v84 = 662;
        goto LABEL_192;
      }
      v31 = of_property_read_variable_u32_array(v112, "niu-size", v19 + 32, 1, 0);
      if ( v31 < 0 || !v19[32] )
      {
        v90 = v31 & (v31 >> 31);
        v83 = "Invalid niu size rc %d";
        v84 = 669;
        goto LABEL_192;
      }
      v32 = *(_QWORD *)(a3 + 1616);
      v33 = *(unsigned __int8 *)(v32 + 9);
      if ( v33 >= 0xA )
      {
        v80 = "cam_cpas_parse_node_tree";
        v81 = "Invalid number of level1 nodes %d";
        v82 = 676;
        goto LABEL_163;
      }
      *(_QWORD *)(v32 + 8LL * *(unsigned __int8 *)(v32 + 9) + 16) = v19;
      v34 = debug_mdl;
      ++*(_BYTE *)(*(_QWORD *)(a3 + 1616) + 9LL);
      if ( (v34 & 4) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v34 & 4,
          4,
          "cam_cpas_parse_node_tree",
          687,
          "level1[%d] : Node %s idx %d priority offset 0x%x, NIU size %dKB",
          v33,
          *((const char **)v19 + 3),
          *v19,
          v19[30],
          v19[32]);
    }
    *((_BYTE *)v19 + 57) = v17;
    if ( (of_property_read_variable_u32_array(v112, "bus-width-factor", v19 + 11, 1, 0) & 0x80000000) != 0 )
      v19[11] = 1;
    if ( (of_property_read_variable_u32_array(v112, "traffic-merge-type", v19 + 10, 1, 0) & 0x80000000) != 0 )
      v19[10] = 0;
    for ( i = 0; i != v13; ++i )
      *(_DWORD *)(*((_QWORD *)v19 + 1) + 4 * i) = -1;
    v36 = of_get_child_by_name(v112, "qcom,axi-port-mnoc");
    if ( !v36 )
    {
      if ( (*(_BYTE *)(a3 + 1036) & 1) != 0 )
        goto LABEL_106;
LABEL_101:
      node_by_name = of_find_node_by_name(v20, "qcom,axi-port-camnoc");
      if ( node_by_name )
      {
        if ( v10 >= 6 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_update_camnoc_node",
            345,
            "CAMNOC axi index overshoot %d",
            v10);
          v90 = -22;
          goto LABEL_207;
        }
        if ( (unsigned int)v10 >= 6 )
          goto LABEL_209;
        v58 = v94 + 408LL * (unsigned int)v10;
        *(_QWORD *)(v58 + 256) = node_by_name;
        v59 = of_property_read_string(v20, "qcom,axi-port-name", v58);
        if ( v59 )
        {
          v90 = v59;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_update_camnoc_node",
            360,
            "fail to read camnoc-port-name rc=%d",
            v59);
LABEL_207:
          v83 = "failed to parse camnoc node info rc=%d";
          v84 = 720;
LABEL_192:
          v85 = v90;
LABEL_193:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_node_tree",
            v84,
            v83,
            v85);
          goto LABEL_194;
        }
        v19[5] = v10++;
        ++*(_DWORD *)(a1 + 2784);
      }
      goto LABEL_106;
    }
    v37 = v36;
    v38 = *((_QWORD *)v19 + 13);
    v136 = 0;
    v137 = 0;
    v134 = 0;
    v135 = 0;
    v132 = 0;
    v133 = 0;
    v130 = 0;
    v131 = 0;
    v128 = 0;
    v129 = 0;
    v126 = 0;
    v127 = 0;
    v124 = 0;
    v125 = 0;
    v122 = 0;
    v123 = 0;
    v120 = 0;
    v121 = 0;
    v118 = 0;
    v119 = 0;
    v109 = of_find_property(v38, "ib-bw-voting-needed", 0) != 0;
    v95 = v10;
    *((_BYTE *)v19 + 56) = of_find_property(*((_QWORD *)v19 + 13), "rt-axi-port", 0) != 0;
    if ( *(_BYTE *)(a3 + 9) != 1 )
    {
      if ( *(_BYTE *)(a3 + 1609) == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_parse_mnoc_node",
          510,
          "DRV not supported for old bus scaling clients");
        v90 = -1;
      }
      else
      {
        if ( v11 >= 6 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            515,
            "Invalid mnoc index: %d",
            v11);
          goto LABEL_190;
        }
        if ( (unsigned int)v11 > 6 )
          goto LABEL_209;
        v54 = v97 + 408LL * (unsigned int)v11;
        *(_QWORD *)(v54 + 256) = v37;
        v55 = of_property_read_string(*((_QWORD *)v19 + 13), "qcom,axi-port-name", v54 + 72);
        if ( !v55 )
        {
          a1 = v110;
          *(_QWORD *)v54 = *(_QWORD *)(v54 + 72);
          **((_DWORD **)v19 + 1) = v11++;
          v56 = *(_DWORD *)(v110 + 2780);
          *(_BYTE *)(v54 + 248) = v109;
          *(_BYTE *)(v54 + 249) = *((_BYTE *)v19 + 56);
          *(_DWORD *)(v110 + 2780) = v56 + 1;
          goto LABEL_100;
        }
        v90 = v55;
        v88 = "failed to read mnoc-port-name rc=%d";
        v89 = 526;
LABEL_196:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_parse_mnoc_node",
          v89,
          v88,
          v90);
      }
LABEL_191:
      v83 = "failed to parse mnoc node info rc=%d";
      v84 = 710;
      goto LABEL_192;
    }
    if ( *(_BYTE *)(a3 + 10) )
      v39 = "cam-icc-path-names";
    else
      v39 = "interconnect-names";
    string_helper = of_property_read_string_helper(v37, v39, 0, 0, 0);
    if ( string_helper <= 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_cpas_parse_mnoc_node",
        391,
        "Missing icc info for camera bus nodes count: %d",
        string_helper);
      goto LABEL_190;
    }
    if ( (unsigned int)string_helper > 4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_mnoc_node",
        395,
        "Number of interconnects %d greater than max ports %d",
        string_helper,
        4);
LABEL_190:
      v90 = -22;
      goto LABEL_191;
    }
    if ( v11 <= 6 )
      v41 = 6;
    else
      v41 = v11;
    v42 = a1 + 408LL * (unsigned int)v11;
    v43 = 0;
    v44 = 0;
    v45 = 1;
    v103 = v11;
    v107 = 408LL * (unsigned int)(v41 - v11);
    v101 = 408LL * (unsigned int)string_helper;
    v102 = a3;
    v104 = v11;
    v92 = string_helper + v11;
    while ( !v43 || *(_BYTE *)(a3 + 1609) == 1 )
    {
      if ( v107 == v43 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_parse_mnoc_node",
          404,
          "Invalid mnoc index: %d",
          v11 + v44);
        goto LABEL_190;
      }
      if ( (unsigned int)v11 >= 7 )
        goto LABEL_209;
      *(_QWORD *)(v42 + v43 + 3352) = v37;
      v46 = (const char **)(v42 + v43 + 3168);
      if ( *(_BYTE *)(a3 + 10) == 1 )
      {
        v47 = of_property_read_string_helper(v37, "cam-icc-path-names", v42 + v43 + 3168, 1, (unsigned int)v44);
        if ( (v47 & 0x80000000) != 0 )
        {
          v90 = v47;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            417,
            "failed to read cam icc name strings mnoc_node: %s i: %d rc=%d",
            *((const char **)v19 + 3),
            v44,
            v47);
          goto LABEL_191;
        }
      }
      else
      {
        v48 = of_property_read_string_helper(v37, "interconnect-names", v42 + v43 + 3168, 1, (unsigned int)v44);
        if ( (v48 & 0x80000000) != 0 )
        {
          v90 = v48;
          v88 = "failed to read interconnect-names rc=%d";
          v89 = 425;
          goto LABEL_196;
        }
        v49 = _of_parse_phandle_with_args(v37, "interconnects", "#interconnect-cells", 0xFFFFFFFFLL, v45 - 1, &v128);
        if ( v49 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            436,
            "failed to read axi bus src info rc=%d",
            v49);
          goto LABEL_190;
        }
        if ( (_DWORD)v129 != 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            444,
            "Invalid number of axi src args: %d",
            v129);
          goto LABEL_190;
        }
        *(_DWORD *)(v42 + v43 + 3176) = HIDWORD(v129);
        v50 = _of_parse_phandle_with_args(v37, "interconnects", "#interconnect-cells", 0xFFFFFFFFLL, v45, &v118);
        if ( v50 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            456,
            "failed to read axi bus dst info rc=%d",
            v50);
          goto LABEL_190;
        }
        if ( (_DWORD)v119 != 1 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            464,
            "Invalid number of axi dst args: %d",
            v119);
          goto LABEL_190;
        }
        *(_DWORD *)(v42 + v43 + 3180) = HIDWORD(v119);
      }
      v51 = *v46;
      v52 = v42 + v43;
      *(_DWORD *)(v52 + 3188) = 2;
      *(_QWORD *)(v42 + v43 + 3096) = v51;
      *(_DWORD *)(v52 + 3360) = v44;
      if ( v43 )
      {
        *(_BYTE *)(v52 + 3184) = 1;
        *(_DWORD *)(v52 + 3384) = 1;
        *(_DWORD *)(v52 + 3448) = 1;
        rsc_dev_for_drv = cam_cpas_get_rsc_dev_for_drv((int)v44 - 1);
        *(_QWORD *)(v52 + 3368) = rsc_dev_for_drv;
        if ( !rsc_dev_for_drv )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_parse_mnoc_node",
            486,
            "Port[%s][%d] Failed to get rsc device drv_idx:%d",
            *(const char **)(v110 + 408LL * v103 + v43 + 3096),
            v103 + v44,
            v44);
          v90 = -19;
          goto LABEL_191;
        }
      }
      *(_DWORD *)(*((_QWORD *)v19 + 1) + 4 * v44) = v104 + v44;
      *(_BYTE *)(v52 + 3344) = v109;
      *(_BYTE *)(v52 + 3345) = *((_BYTE *)v19 + 56);
      if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000004,
          4,
          "cam_cpas_parse_mnoc_node",
          504,
          "Adding Bus Client=[%s] : src=%d, dst=%d mnoc_idx:%d",
          *v46,
          *(_DWORD *)(v42 + v43 + 3176),
          *(_DWORD *)(v42 + v43 + 3180),
          v104 + v44);
      a3 = v102;
      v43 += 408;
      v11 = v103;
      ++v44;
      v45 += 2;
      ++*(_DWORD *)(v110 + 2780);
      if ( v101 == v43 )
      {
        a1 = v110;
        v11 = v92;
        goto LABEL_100;
      }
    }
    a1 = v110;
    v11 = v104 + v44;
LABEL_100:
    v10 = v95;
    v17 = v100;
    v20 = v112;
    if ( (*(_BYTE *)(a3 + 1036) & 1) == 0 )
      goto LABEL_101;
LABEL_106:
    if ( !HIDWORD(v115) )
      break;
LABEL_107:
    if ( *(_BYTE *)(a3 + 1609) == 1 )
    {
      if ( v99 )
      {
        *(_DWORD *)(*((_QWORD *)v19 + 6) + 56LL) = 1;
        if ( v96 != 2 )
        {
          *(_DWORD *)(*((_QWORD *)v19 + 6) + 112LL) = 1;
          *(_DWORD *)(*((_QWORD *)v19 + 6) + 168LL) = 1;
          if ( (v99 & 1) == 0 )
            *(_DWORD *)(*((_QWORD *)v19 + 6) + 224LL) = 1;
        }
      }
    }
    v136 = 0;
    v137 = 0;
    v134 = 0;
    v135 = 0;
    v132 = 0;
    v133 = 0;
    v130 = 0;
    v131 = 0;
    v128 = 0;
    v129 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v20, "parent-node", 0, 0, 0, &v128) || !v128 )
    {
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_parse_node_tree",
          858,
          "no parent node at this level");
    }
    else
    {
      of_property_read_variable_u32_array(v128, "cell-index", &v113, 1, 0);
      if ( (unsigned int)v113 > 0x3E )
        goto LABEL_209;
      v17 = v100;
      v60 = *(_QWORD *)(v108 + 8LL * (unsigned int)v113);
      *((_QWORD *)v19 + 14) = v60;
      *((_BYTE *)v19 + 56) = *(_BYTE *)(v60 + 56);
    }
    v112 = of_get_next_available_child(v98, v112);
    if ( !v112 )
      goto LABEL_20;
  }
  v61 = v11;
  property = of_find_property(v20, "traffic-data", 0);
  v63 = of_find_property(v20, "constituent-paths", 0);
  if ( !(property | v63) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_parse_node_tree",
      739,
      "Essential path identifier property missing, traffic-data:%s constituent-paths:%s",
      "N",
      "N");
    v90 = -22;
    goto LABEL_194;
  }
  v64 = v63;
  if ( (unsigned int)of_property_read_string(v20, "client-name", &v114) )
  {
    v80 = "cam_cpas_parse_node_tree";
    v81 = "Client name not found";
    v82 = 746;
    goto LABEL_163;
  }
  string_index = cam_common_util_get_string_index(a3 + 16, *(_DWORD *)(a3 + 12), v114, (int *)&v113 + 1);
  if ( string_index )
  {
    v90 = string_index;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_parse_node_tree",
      754,
      "client name not found in list: %s",
      v114);
    goto LABEL_194;
  }
  if ( HIDWORD(v113) >= 0x2B )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_cpas_parse_node_tree",
      760,
      "Client idx:%d exceeds max:%d",
      HIDWORD(v113),
      43);
    v90 = -22;
    goto LABEL_194;
  }
  v66 = of_property_read_variable_u32_array(v20, "traffic-data", v19 + 8, 1, 0);
  if ( (v66 & 0x80000000) != 0 && !v64 )
  {
    v90 = v66;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_parse_node_tree",
      767,
      "Path Data type not found");
    goto LABEL_194;
  }
  if ( !v64 )
  {
    v69 = v19[8];
LABEL_132:
    if ( v69 <= 0xFF )
      v70 = v69 & 0x1F;
    else
      v70 = v69 & 0x1F | 0x20;
    v19[8] = v70;
    if ( v70 >= 0x2A )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_path_type_to_idx",
        322,
        "index Invalid: %u",
        v70);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_node_tree",
        784,
        "Incorrect path type for client: %s",
        v114);
      v90 = -22;
      goto LABEL_194;
    }
    v71 = of_property_read_variable_u32_array(v20, "traffic-transaction-type", v19 + 9, 1, 0);
    if ( (v71 & 0x80000000) != 0 )
    {
      v90 = v71;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_node_tree",
        791,
        "Path Transac type not found");
      goto LABEL_194;
    }
    if ( v19[9] >= 2 )
    {
      v80 = "cam_cpas_parse_node_tree";
      v81 = "Invalid transac type: %d";
      v82 = 797;
      goto LABEL_163;
    }
    v72 = of_property_count_elems_of_size(v20, "constituent-paths", 4);
    if ( v72 >= 1 )
    {
      v73 = v72;
      v74 = 0;
      while ( 1 )
      {
        v75 = of_property_read_u32_index(v112, "constituent-paths", v74, &v115);
        if ( v75 )
        {
          v90 = v75;
          v83 = "No constituent path at %d";
          v84 = 806;
          v85 = v74;
          goto LABEL_193;
        }
        v76 = (unsigned int)v115 <= 0xFF ? v115 & 0x1F : v115 & 0x1F | 0x20;
        LODWORD(v115) = v76;
        if ( v76 >= 0x2A )
          break;
        ++v74;
        *((_BYTE *)v19 + v76 + 58) = 1;
        if ( v73 == v74 )
          goto LABEL_146;
      }
      v80 = "cam_cpas_util_path_type_to_idx";
      v81 = "index Invalid: %u";
      v82 = 322;
LABEL_163:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        v80,
        v82,
        v81);
      v90 = -22;
LABEL_194:
      _ReadStatusReg(SP_EL0);
      return v90;
    }
LABEL_146:
    if ( HIDWORD(v113) > 0x2A )
      goto LABEL_209;
    v77 = *(_QWORD *)(v93 + 8LL * HIDWORD(v113));
    *(_BYTE *)(v77 + 170) = 1;
    v78 = v19[8];
    if ( (unsigned int)v78 > 0x29 )
      goto LABEL_209;
    v79 = v19[9];
    if ( (unsigned int)v79 > 1 )
      goto LABEL_209;
    v11 = v61;
    *(_QWORD *)(v77 + 16 * v78 + 8 * v79 + 1040) = v19;
    if ( *(_BYTE *)(a3 + 1609) == 1 )
    {
      if ( (of_property_read_variable_u32_array(v112, "drv-voting-index", v19 + 4, 1, 0) & 0x80000000) != 0 )
        v19[10] = 0;
      if ( v19[4] == 32 )
      {
        *(_BYTE *)(v77 + 171) = 1;
        if ( v19[4] == 32 )
          goto LABEL_159;
        goto LABEL_158;
      }
      if ( (*(_BYTE *)(v77 + 171) & 1) != 0 )
LABEL_158:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_parse_node_tree",
          836,
          "Invalid config for drv dyn client: %s drv_idx: %d",
          v114);
    }
LABEL_159:
    v17 = v100;
    v20 = v112;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_parse_node_tree",
        844,
        "Node Added: Client[%s] DataType[%d] TransType[%d] DRV idx[%d]",
        v114,
        v19[8],
        v19[9],
        v19[4]);
    goto LABEL_107;
  }
  if ( HIDWORD(v113) > 0x2B )
    goto LABEL_209;
  if ( HIDWORD(v113) != 43 )
  {
    v20 = v112;
    v68 = *((_DWORD *)v116 + HIDWORD(v113));
    *((_DWORD *)v116 + HIDWORD(v113)) = v68 + 1;
    v69 = v68 + 257;
    goto LABEL_132;
  }
  __break(1u);
  return cam_cpas_parse_sys_cache_uids(v66, v67);
}
