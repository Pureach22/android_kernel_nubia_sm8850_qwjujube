__int64 __fastcall policy_mgr_wait_for_set_link_update(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x21
  int v14; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v42; // x3
  int v43; // w21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x0
  int v61; // w22
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int v70; // w21
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x0
  int v88; // w20
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w20
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v42 = "policy_mgr_wait_for_set_link_update";
LABEL_18:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, v42);
    return 4;
  }
  v11 = context;
  v12 = policy_mgr_get_context(a1);
  if ( !v12 )
    goto LABEL_17;
  v13 = v12;
  qdf_mutex_acquire(v12 + 56);
  v14 = *(_DWORD *)(v13 + 2664);
  qdf_mutex_release(v13 + 56);
  if ( !v14 )
    goto LABEL_20;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: set_link_in_progress %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_get_link_in_progress",
    1);
  v23 = qdf_wait_for_event_completion(v13 + 2672, 0x36B0u);
  if ( v23 )
  {
LABEL_5:
    v32 = v23;
    policy_mgr_set_link_in_progress(v13, 0);
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: wait for set_link_in_progress failed",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "policy_mgr_single_wait_for_set_link");
    return v32;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: complete wait for set_link_in_progress",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "policy_mgr_single_wait_for_set_link");
  qdf_mutex_acquire(v11 + 56);
  v43 = *(_DWORD *)(v11 + 2664);
  qdf_mutex_release(v11 + 56);
  if ( !v43 )
    return 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: set_link_in_progress %d",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "policy_mgr_get_link_in_progress",
    1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: retry %d",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "policy_mgr_wait_for_set_link_update",
    2);
  v60 = policy_mgr_get_context(a1);
  if ( !v60 )
  {
LABEL_17:
    v42 = "policy_mgr_single_wait_for_set_link";
    goto LABEL_18;
  }
  v13 = v60;
  qdf_mutex_acquire(v60 + 56);
  v61 = *(_DWORD *)(v13 + 2664);
  qdf_mutex_release(v13 + 56);
  if ( !v61 )
    goto LABEL_20;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: set_link_in_progress %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_get_link_in_progress",
    1);
  v23 = qdf_wait_for_event_completion(v13 + 2672, 0x36B0u);
  if ( v23 )
    goto LABEL_5;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: complete wait for set_link_in_progress",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    "policy_mgr_single_wait_for_set_link");
  qdf_mutex_acquire(v11 + 56);
  v70 = *(_DWORD *)(v11 + 2664);
  qdf_mutex_release(v11 + 56);
  if ( !v70 )
    return 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: set_link_in_progress %d",
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    "policy_mgr_get_link_in_progress",
    1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: retry %d",
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    "policy_mgr_wait_for_set_link_update",
    1);
  v87 = policy_mgr_get_context(a1);
  if ( !v87 )
    goto LABEL_17;
  v13 = v87;
  qdf_mutex_acquire(v87 + 56);
  v88 = *(_DWORD *)(v13 + 2664);
  qdf_mutex_release(v13 + 56);
  if ( v88 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: set_link_in_progress %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_get_link_in_progress",
      1);
    v23 = qdf_wait_for_event_completion(v13 + 2672, 0x36B0u);
    if ( v23 )
      goto LABEL_5;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: complete wait for set_link_in_progress",
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      "policy_mgr_single_wait_for_set_link");
    qdf_mutex_acquire(v11 + 56);
    v97 = *(_DWORD *)(v11 + 2664);
    qdf_mutex_release(v11 + 56);
    if ( v97 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: set_link_in_progress %d",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "policy_mgr_get_link_in_progress",
        1);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: retry %d",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "policy_mgr_wait_for_set_link_update",
        0);
      return 4;
    }
    return 0;
  }
LABEL_20:
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: link is not in progress",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_single_wait_for_set_link");
  return 35;
}
