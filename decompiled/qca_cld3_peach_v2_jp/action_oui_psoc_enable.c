__int64 __fastcall action_oui_psoc_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  __int64 *v20; // x20
  __int64 *v21; // x22
  __int64 v22; // x0
  char action_oui_v2_cap; // w0
  const char *v24; // x2
  const char *v25; // x2
  __int64 values; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  int v50; // w24
  __int64 v51; // x8
  unsigned __int64 v52; // x21
  __int64 *v53; // x23
  __int64 v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x20
  int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x20
  _DWORD *v83; // x24
  _BYTE *v84; // x22
  __int64 i; // x22
  __int64 v86; // x24
  const char *v87; // x3
  const char *v88; // x2
  unsigned int v89; // w1
  __int64 v90; // x0
  __int64 v91; // x20
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned int j; // w21
  unsigned int v101; // w1

  qdf_trace_msg(0x63u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "action_oui_psoc_enable");
  comp_private_obj = (__int64 *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v24 = "%s: psoc priv is NULL";
    goto LABEL_36;
  }
  v19 = *comp_private_obj;
  v20 = comp_private_obj;
  v21 = comp_private_obj + 2560;
  if ( !*comp_private_obj )
  {
    v25 = "%s: Invalid psoc";
LABEL_9:
    qdf_trace_msg(0x63u, 2u, v25, v11, v12, v13, v14, v15, v16, v17, v18, "wlan_action_oui_v2_enabled");
    goto LABEL_10;
  }
  v22 = wlan_objmgr_psoc_get_comp_private_obj(*comp_private_obj, 0x1Cu);
  if ( !v22 )
  {
    v25 = "%s: psoc priv is NULL";
    goto LABEL_9;
  }
  if ( *(_BYTE *)(v22 + 8) != 2 )
  {
LABEL_10:
    action_oui_v2_cap = 0;
    goto LABEL_11;
  }
  action_oui_v2_cap = target_if_get_action_oui_v2_cap(*(_QWORD *)v22);
LABEL_11:
  *((_BYTE *)v21 + 3296) = action_oui_v2_cap & 1;
  values = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 9, values + 11465, 840);
  v27 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 849, v27 + 13988, 840);
  v28 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 1689, v28 + 10624, 840);
  v29 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 2529, v29 + 13147, 840);
  v30 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 3369, v30 + 17352, 840);
  v31 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 4209, v31 + 12306, 840);
  v32 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 5049, v32 + 14829, 840);
  v33 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 18489, v33 + 15670, 840);
  v34 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 6729, v34 + 16511, 840);
  v35 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 5889, v35 + 19034, 840);
  v36 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 15969, v36 + 18193, 840);
  v37 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 16809, v37 + 19875, 840);
  v38 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 7569, v38 + 20716, 840);
  v39 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 8409, v39 + 21557, 840);
  v40 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 9249, v40 + 23239, 840);
  v41 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 19329, v41 + 22398, 840);
  v42 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 10089, v42 + 24921, 840);
  v43 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 13449, v43 + 24080, 840);
  v44 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 14289, v44 + 25762, 840);
  v45 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 17649, v45 + 26603, 840);
  v46 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 20169, v46 + 27444, 840);
  v47 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 10929, v47 + 28285, 840);
  v48 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 21009, v48 + 29967, 840);
  v49 = cfg_psoc_get_values(v19);
  sized_strscpy((char *)v20 + 21849, v49 + 30808, 840);
  v50 = *((unsigned __int8 *)v21 + 3296);
  v51 = cfg_psoc_get_values(v19);
  if ( v50 == 1 )
  {
    sized_strscpy((char *)v20 + 15129, v51 + 31656, 840);
    *((_BYTE *)v21 + 3315) = 1;
  }
  else
  {
    sized_strscpy((char *)v20 + 15129, v51 + 29126, 840);
  }
  v52 = 0;
  v53 = v20 + 2943;
  do
  {
    v54 = _qdf_mem_malloc(0x60u, "action_oui_allocate", 49);
    if ( !v54 )
    {
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Mem alloc failed for oui_priv id: %u",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "action_oui_allocate",
        (unsigned int)v52);
      if ( (_DWORD)v52 )
      {
        for ( i = 0; i != v52; ++i )
        {
          v86 = v53[i];
          if ( v86 )
          {
            if ( *(_DWORD *)(v86 + 24) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: list length not equal to zero",
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                "qdf_list_destroy");
            qdf_mutex_destroy(v86 + 32);
            v53[i] = 0;
          }
        }
      }
      v24 = "%s: Failed to alloc action_oui";
LABEL_36:
      v87 = "action_oui_psoc_enable";
LABEL_54:
      v101 = 2;
      goto LABEL_55;
    }
    *(_DWORD *)v54 = v52;
    *(_QWORD *)(v54 + 8) = v54 + 8;
    v63 = v54;
    *(_QWORD *)(v54 + 16) = v54 + 8;
    if ( v52 >= 0x13 )
      v64 = 100;
    else
      v64 = 10;
    *(_DWORD *)(v54 + 24) = 0;
    *(_DWORD *)(v54 + 28) = v64;
    qdf_mutex_create(v54 + 32);
    v53[v52++] = v63;
  }
  while ( v52 != 28 );
  if ( !a1 )
  {
    qdf_trace_msg(0x63u, 2u, "%s: Invalid psoc", v65, v66, v67, v68, v69, v70, v71, v72, "action_oui_parse_config");
    v24 = "%s: psoc is NULL";
LABEL_53:
    v87 = "action_oui_send_config";
    goto LABEL_54;
  }
  v73 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !v73 )
  {
    v88 = "%s: psoc priv is NULL";
    v89 = 2;
LABEL_41:
    qdf_trace_msg(0x63u, v89, v88, v74, v75, v76, v77, v78, v79, v80, v81, "action_oui_parse_config");
    goto LABEL_42;
  }
  if ( !*(_BYTE *)(v73 + 8) )
  {
    v88 = "%s: action_oui is not enable";
    v89 = 8;
    goto LABEL_41;
  }
  v82 = 0;
  v83 = (_DWORD *)(v73 + 20480);
  v84 = (_BYTE *)(v73 + 9);
  do
  {
    if ( *v84 && (unsigned int)action_oui_parse_string(a1, v84, (unsigned int)v82) )
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Failed to parse action_oui str: %u",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "action_oui_parse_config",
        (unsigned int)v82);
    ++v82;
    v84 += 840;
  }
  while ( v82 != 28 );
  v83[765] = v83[763] - v83[764] + 10;
  qdf_trace_msg(
    0x63u,
    8u,
    "%s: Extensions - Max: %d Total: %d host_only %d",
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    "action_oui_parse_config");
LABEL_42:
  v90 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !v90 )
  {
    v24 = "%s: psoc priv is NULL";
    goto LABEL_53;
  }
  v91 = v90;
  if ( !*(_BYTE *)(v90 + 8) )
  {
    v24 = "%s: action_oui is not enable";
    v87 = "action_oui_send_config";
    v101 = 8;
LABEL_55:
    qdf_trace_msg(0x63u, v101, v24, v11, v12, v13, v14, v15, v16, v17, v18, v87);
    return qdf_trace_msg(0x63u, 8u, "%s: exit", v92, v93, v94, v95, v96, v97, v98, v99, "action_oui_psoc_enable");
  }
  if ( !policy_mgr_is_hw_dbs_2x2_capable(a1) && (unsigned int)action_oui_send(v91, 0) )
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Failed to send: %u",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "action_oui_send_config",
      0);
  for ( j = 1; j != 28; ++j )
  {
    if ( j <= 0x12 && (unsigned int)action_oui_send(v91, j) )
      qdf_trace_msg(
        0x63u,
        2u,
        "%s: Failed to send: %u",
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        "action_oui_send_config",
        j);
  }
  return qdf_trace_msg(0x63u, 8u, "%s: exit", v92, v93, v94, v95, v96, v97, v98, v99, "action_oui_psoc_enable");
}
