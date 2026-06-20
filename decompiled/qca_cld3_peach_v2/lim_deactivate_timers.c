__int64 __fastcall lim_deactivate_timers(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
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
  __int64 v50; // x20
  unsigned __int64 v51; // x21
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
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

  tx_timer_deactivate(a1 + 1344);
  if ( (tx_timer_running(a1 + 1072) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Join failure timer running call the timeout API",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "lim_deactivate_timers");
    lim_timer_handler(a1, 0x13D2u, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  tx_timer_deactivate(a1 + 1072);
  tx_timer_deactivate(a1 + 2136);
  tx_timer_deactivate(a1 + 2928);
  if ( (tx_timer_running(a1 + 280) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Assoc failure timer running call the timeout API",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "lim_deactivate_timers");
    lim_assoc_failure_timer_handler(a1, 0, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  tx_timer_deactivate(a1 + 280);
  if ( (tx_timer_running(a1 + 808) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Auth failure timer running call the timeout API",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "lim_deactivate_timers");
    lim_timer_handler(a1, 0x13D3u, v42, v43, v44, v45, v46, v47, v48, v49);
  }
  tx_timer_deactivate(a1 + 808);
  v50 = 0;
  v51 = -1;
  do
  {
    tx_timer_deactivate(*(_QWORD *)(a1 + 1336) + v50);
    ++v51;
    v50 += 264;
  }
  while ( v51 < *(unsigned __int16 *)(a1 + 3990) );
  lim_delete_pre_auth_list(a1);
  tx_timer_deactivate(a1 + 1608);
  tx_timer_deactivate(a1 + 16);
  if ( (tx_timer_running(a1 + 2400) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Disassoc timer running call the timeout API",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "lim_deactivate_timers");
    lim_timer_handler(a1, 0x13F6u, v60, v61, v62, v63, v64, v65, v66, v67);
  }
  tx_timer_deactivate(a1 + 2400);
  if ( (tx_timer_running(a1 + 2664) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Deauth timer running call the timeout API",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "lim_deactivate_timers");
    lim_process_deauth_ack_timeout(a1, 0xFFu, v76, v77, v78, v79, v80, v81, v82, v83);
  }
  tx_timer_deactivate(a1 + 2664);
  if ( (tx_timer_running(a1 + 3192) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: SAE Auth failure timer running call the timeout API",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "lim_deactivate_timers");
    lim_timer_handler(a1, 0x13FEu, v92, v93, v94, v95, v96, v97, v98, v99);
  }
  tx_timer_deactivate(a1 + 3192);
  if ( (tx_timer_running(a1 + 3456) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: sta stats resp timer running call the timeout API",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "lim_deactivate_timers");
    lim_timer_handler(a1, 0x13F4u, v108, v109, v110, v111, v112, v113, v114, v115);
  }
  return tx_timer_deactivate(a1 + 3456);
}
