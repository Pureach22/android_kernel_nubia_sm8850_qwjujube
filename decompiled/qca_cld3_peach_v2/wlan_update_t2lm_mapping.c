__int64 __fastcall wlan_update_t2lm_mapping(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  const void *v12; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v32; // x22
  __int64 v33; // x24
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x22
  __int64 v83; // x24
  int v84; // w0
  __int64 v85; // x8
  __int64 v86; // x22
  __int64 v87; // x24
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  const char *v112; // x2
  int v113; // w8
  int v114; // w9
  unsigned __int64 v115; // x8
  unsigned __int64 v116; // x10
  __int64 v117; // x21
  __int64 v118; // x22
  unsigned __int64 v119; // x21
  unsigned __int64 v120; // x8
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7

  if ( !a1 )
    return 29;
  v11 = *(_QWORD *)(a1 + 1360);
  if ( !v11 )
    return 29;
  v12 = (const void *)(a2 + 60);
  if ( *(_DWORD *)(a2 + 60) == 4 && *(_DWORD *)(a2 + 4) == 4 )
  {
    if ( (*(_BYTE *)(v11 + 2248) & 1) == 0 )
    {
      qdf_mem_set((void *)(v11 + 2240), 0x38u, 0);
      qdf_mem_set((void *)(v11 + 2296), 0x38u, 0);
      *(_BYTE *)(v11 + 2248) = 1;
      *(_QWORD *)(v11 + 3064) = 0;
      *(_QWORD *)(v11 + 3056) = 0;
      *(_DWORD *)(v11 + 2244) = 2;
      *(_BYTE *)(v11 + 2293) = 0;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: initialize to default T2LM mapping",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_update_t2lm_mapping");
      wlan_mlo_dev_t2lm_notify_link_update(a1, v11 + 2244, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    return 0;
  }
  if ( *(_DWORD *)(a2 + 16) && (*(_BYTE *)(a2 + 9) & 1) == 0 && *(_DWORD *)(a2 + 72) && *(_BYTE *)(a2 + 65) == 1 )
  {
    v32 = a3;
    v33 = a2;
    if ( !(unsigned int)qdf_mem_cmp((const void *)(v11 + 2260), (const void *)(a2 + 20), 0x10u) )
      goto LABEL_26;
    qdf_mem_copy((void *)(v11 + 2244), (const void *)(v33 + 4), 0x34u);
    *(_DWORD *)(v11 + 2256) = 0;
    *(_WORD *)(v11 + 2252) = 0;
    *(_WORD *)(v11 + 2249) = 0;
    wlan_mlo_dev_t2lm_notify_link_update(a1, v11 + 2244, v42, v43, v44, v45, v46, v47, v48, v49);
    wlan_clear_peer_level_tid_to_link_mapping(a1);
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Update T2LM established mapping to FW",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wlan_update_t2lm_mapping");
    wlan_send_tid_to_link_mapping(a1, v11 + 2244, v58, v59, v60, v61, v62, v63, v64, v65);
    if ( !(unsigned int)qdf_mem_cmp((const void *)(v11 + 2316), (const void *)(v33 + 76), 0x10u) )
    {
LABEL_43:
      v112 = "%s: Ongoing mapping is already established";
      goto LABEL_44;
    }
    qdf_mem_copy((void *)(v11 + 2300), v12, 0x34u);
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Update T2LM upcoming mapping to FW",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "wlan_update_t2lm_mapping");
    wlan_send_tid_to_link_mapping(a1, v11 + 2300, v74, v75, v76, v77, v78, v79, v80, v81);
    a3 = v32;
    a2 = v33;
  }
  if ( (*(_BYTE *)(v11 + 2250) & 1) == 0 || (*(_BYTE *)(a2 + 10) & 1) == 0 )
  {
    if ( (*(_BYTE *)(a2 + 10) & 1) == 0 || (*(_BYTE *)(a2 + 9) & 1) != 0 )
      goto LABEL_34;
    v86 = a3;
    v87 = a2;
    if ( (unsigned int)qdf_mem_cmp((const void *)(v11 + 2260), (const void *)(a2 + 20), 0x10u) )
    {
      *(_QWORD *)(v11 + 3056) = v86;
      *(_QWORD *)(v11 + 3064) = (unsigned int)(*(_DWORD *)(v87 + 16) << 10) + v86;
      qdf_mem_copy((void *)(v11 + 2244), (const void *)(v87 + 4), 0x34u);
      wlan_mlo_dev_t2lm_notify_link_update(a1, v11 + 2244, v88, v89, v90, v91, v92, v93, v94, v95);
      wlan_clear_peer_level_tid_to_link_mapping(a1);
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: MST expired, update established T2LM mapping to FW",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "wlan_update_t2lm_mapping");
      wlan_send_tid_to_link_mapping(a1, v11 + 2244, v104, v105, v106, v107, v108, v109, v110, v111);
      a2 = v87;
      a3 = v86;
      goto LABEL_34;
    }
LABEL_26:
    v112 = "%s: T2LM mapping is already configured";
LABEL_44:
    qdf_trace_msg(0x99u, 8u, v112, v34, v35, v36, v37, v38, v39, v40, v41, "wlan_update_t2lm_mapping");
    return 6;
  }
  v82 = a2;
  v83 = a3;
  v84 = qdf_mem_cmp((const void *)(v11 + 2260), (const void *)(a2 + 20), 0x10u);
  a2 = v82;
  a3 = v83;
  if ( !v84 )
  {
    if ( *(_QWORD *)(v11 + 3056) )
    {
      v85 = *(_QWORD *)(v11 + 3064);
    }
    else
    {
      v113 = *(_DWORD *)(v82 + 16);
      *(_QWORD *)(v11 + 3056) = v83;
      v85 = (unsigned int)(v113 << 10) + v83;
      *(_QWORD *)(v11 + 3064) = v85;
    }
    if ( v85
      && (v114 = *(_DWORD *)(v82 + 16),
          v115 = v85 + 204800,
          v116 = (unsigned int)(v114 << 10) + v83,
          v116 < v115 - 409600)
      && v116 > v115 )
    {
      *(_DWORD *)(v11 + 2256) = v114;
      wlan_send_tid_to_link_mapping(a1, v11 + 2244, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    else
    {
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: T2LM exp duration in range",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_update_t2lm_mapping");
    }
    a2 = v82;
    a3 = v83;
  }
LABEL_34:
  if ( *(_BYTE *)(a2 + 65) == 1 )
  {
    v117 = a3;
    v118 = a2;
    if ( (unsigned int)qdf_mem_cmp((const void *)(v11 + 2316), (const void *)(a2 + 76), 0x10u) )
    {
      if ( *(_WORD *)(v118 + 68) )
      {
        v119 = v117 & 0xFFFFFFFFFC0003FFLL | ((unsigned __int64)*(unsigned __int16 *)(v118 + 68) << 10);
        v120 = v119 + *(unsigned int *)(v118 + 72);
        *(_QWORD *)(v11 + 3056) = v119;
        *(_QWORD *)(v11 + 3064) = v120;
      }
      qdf_mem_copy((void *)(v11 + 2300), v12, 0x34u);
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Update T2LM upcoming mapping to FW",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "wlan_update_t2lm_mapping");
      wlan_send_tid_to_link_mapping(a1, v11 + 2300, v129, v130, v131, v132, v133, v134, v135, v136);
      return 0;
    }
    goto LABEL_43;
  }
  if ( *(_DWORD *)(v11 + 2244) == 4 && *(_DWORD *)(v11 + 2300) != 4 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Copy upcoming T2LM mapping to expected T2LM",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_update_t2lm_mapping");
    qdf_mem_copy((void *)(v11 + 2240), (const void *)(v11 + 2296), 0x38u);
  }
  qdf_mem_set((void *)(v11 + 2296), 0x38u, 0);
  *(_DWORD *)(v11 + 2300) = 4;
  return 0;
}
