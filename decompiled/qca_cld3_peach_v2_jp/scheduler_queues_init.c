__int64 __fastcall scheduler_queues_init(
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
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
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
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7

  qdf_trace_msg(0x4Au, 8u, "%s: Enter", a2, a3, a4, a5, a6, a7, a8, a9, "scheduler_queues_init");
  if ( !a1 )
    return 16;
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v10, v11, v12, v13, v14, v15, v16, v17, "scheduler_all_queues_init");
  _sched_queue_depth = 0;
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v18, v19, v20, v21, v22, v23, v24, v25, "scheduler_mq_init");
  *(_DWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = a1 + 16;
  *(_QWORD *)(a1 + 24) = a1 + 16;
  *(_QWORD *)(a1 + 32) = 0x3E800000000LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v26, v27, v28, v29, v30, v31, v32, v33, "scheduler_mq_init");
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v34, v35, v36, v37, v38, v39, v40, v41, "scheduler_mq_init");
  *(_DWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = a1 + 64;
  *(_QWORD *)(a1 + 72) = a1 + 64;
  *(_QWORD *)(a1 + 80) = 0x3E800000000LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v42, v43, v44, v45, v46, v47, v48, v49, "scheduler_mq_init");
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v50, v51, v52, v53, v54, v55, v56, v57, "scheduler_mq_init");
  *(_DWORD *)(a1 + 96) = 0;
  *(_QWORD *)(a1 + 104) = 0;
  *(_QWORD *)(a1 + 112) = a1 + 112;
  *(_QWORD *)(a1 + 120) = a1 + 112;
  *(_QWORD *)(a1 + 128) = 0x3E800000000LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v58, v59, v60, v61, v62, v63, v64, v65, "scheduler_mq_init");
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v66, v67, v68, v69, v70, v71, v72, v73, "scheduler_mq_init");
  *(_DWORD *)(a1 + 144) = 0;
  *(_QWORD *)(a1 + 152) = 0;
  *(_QWORD *)(a1 + 160) = a1 + 160;
  *(_QWORD *)(a1 + 168) = a1 + 160;
  *(_QWORD *)(a1 + 176) = 0x3E800000000LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v74, v75, v76, v77, v78, v79, v80, v81, "scheduler_mq_init");
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v82, v83, v84, v85, v86, v87, v88, v89, "scheduler_mq_init");
  *(_DWORD *)(a1 + 192) = 0;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = a1 + 208;
  *(_QWORD *)(a1 + 216) = a1 + 208;
  *(_QWORD *)(a1 + 224) = 0x3E800000000LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v90, v91, v92, v93, v94, v95, v96, v97, "scheduler_mq_init");
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v98, v99, v100, v101, v102, v103, v104, v105, "scheduler_mq_init");
  *(_DWORD *)(a1 + 240) = 0;
  *(_QWORD *)(a1 + 248) = 0;
  *(_QWORD *)(a1 + 256) = a1 + 256;
  *(_QWORD *)(a1 + 264) = a1 + 256;
  *(_QWORD *)(a1 + 272) = 0x3E800000000LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v106, v107, v108, v109, v110, v111, v112, v113, "scheduler_mq_init");
  *(_QWORD *)(a1 + 447) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 432) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 440) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 416) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 424) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 400) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 408) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 384) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 392) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 368) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 376) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 352) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 360) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 336) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 344) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 320) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 328) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 304) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 312) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 288) = 0x606060606060606LL;
  *(_QWORD *)(a1 + 296) = 0x606060606060606LL;
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v114, v115, v116, v117, v118, v119, v120, v121, "scheduler_all_queues_init");
  qdf_trace_msg(
    0x4Au,
    8u,
    "%s: Queue init passed",
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    "scheduler_queues_init");
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v130, v131, v132, v133, v134, v135, v136, v137, "scheduler_queues_init");
  return 0;
}
