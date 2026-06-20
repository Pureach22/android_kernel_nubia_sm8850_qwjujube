__int64 __fastcall dp_vdev_print_tx_delay_jitter_stats(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x4
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w0
  __int64 v21; // x22
  int v22; // w0
  __int64 v23; // x22
  int v24; // w0
  __int64 v25; // x22
  int v26; // w0
  __int64 v27; // x22
  int v28; // w0
  __int64 v29; // x22
  int v30; // w0
  __int64 v31; // x22
  int v32; // w0
  __int64 v33; // x22
  int v34; // w0
  __int64 v35; // x22
  int v36; // w0
  __int64 v37; // x22
  int v38; // w0
  __int64 v39; // x22
  int v40; // w0
  __int64 v41; // x22
  int v42; // w0
  __int64 v43; // x22
  int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x23
  __int64 v54; // x21
  __int64 v55; // x27
  __int64 v56; // x24
  __int64 v57; // x25
  __int64 v58; // x19
  int v59; // w0
  __int64 v60; // x28
  int v61; // w0
  __int64 v62; // x28
  int v63; // w0
  __int64 v64; // x28
  int v65; // w0
  __int64 v66; // x28
  int v67; // w0
  __int64 v68; // x28
  int v69; // w0
  __int64 v70; // x28
  int v71; // w0
  __int64 v72; // x28
  int v73; // w0
  __int64 v74; // x28
  int v75; // w0
  __int64 v76; // x28
  int v77; // w0
  __int64 v78; // x28
  int v79; // w0
  __int64 v80; // x28
  int v81; // w0
  __int64 v82; // x28
  int v83; // w0
  __int64 v84; // x28
  int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  _BYTE v94[512]; // [xsp+0h] [xbp-290h] BYREF
  __int64 v95; // [xsp+200h] [xbp-90h] BYREF
  __int64 v96; // [xsp+208h] [xbp-88h]
  __int64 v97; // [xsp+210h] [xbp-80h]
  __int64 v98; // [xsp+218h] [xbp-78h]
  __int64 v99; // [xsp+220h] [xbp-70h]
  __int64 v100; // [xsp+228h] [xbp-68h]
  __int64 v101; // [xsp+230h] [xbp-60h]
  __int64 v102; // [xsp+238h] [xbp-58h]
  __int64 v103; // [xsp+240h] [xbp-50h]
  __int64 v104; // [xsp+248h] [xbp-48h]
  __int64 v105; // [xsp+250h] [xbp-40h]
  __int64 v106; // [xsp+258h] [xbp-38h]
  __int64 v107; // [xsp+260h] [xbp-30h]
  __int64 v108; // [xsp+268h] [xbp-28h]
  __int64 v109; // [xsp+270h] [xbp-20h]
  __int64 v110; // [xsp+278h] [xbp-18h]
  __int64 v111; // [xsp+280h] [xbp-10h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)memset(v94, 0, sizeof(v94));
  if ( a1 )
  {
    v11 = *(unsigned __int8 *)(a1 + 59);
    v109 = 0;
    v110 = 0;
    v107 = 0;
    v108 = 0;
    v105 = 0;
    v106 = 0;
    v103 = 0;
    v104 = 0;
    v101 = 0;
    v102 = 0;
    v99 = 0;
    v100 = 0;
    v97 = 0;
    v98 = 0;
    v95 = 0;
    v96 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: vdev_id: %d Per TID HW Tx completion Jitter Stats:",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_vdev_print_tx_delay_jitter_stats",
      v11);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s:   Tid%32sPkts_per_jitter_bucket%60s | Min | Max | Avg |",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_vdev_print_tx_delay_jitter_stats",
      &unk_8B9E43,
      &unk_8B9E43);
    scnprintf(v94, 512, "%6s", (const char *)&unk_8B9E43);
    v21 = v20;
    scnprintf(&v94[v20], 512LL - v20, "%7s", delay_jitter_bkt_str[0]);
    v23 = v21 + v22;
    scnprintf(&v94[v23], 512 - v23, "%7s", off_15A10[0]);
    v25 = v23 + v24;
    scnprintf(&v94[v25], 512 - v25, "%7s", off_15A18[0]);
    v27 = v25 + v26;
    scnprintf(&v94[v27], 512 - v27, "%7s", off_15A20[0]);
    v29 = v27 + v28;
    scnprintf(&v94[v29], 512 - v29, "%7s", off_15A28[0]);
    v31 = v29 + v30;
    scnprintf(&v94[v31], 512 - v31, "%9s", off_15A30[0]);
    v33 = v31 + v32;
    scnprintf(&v94[v33], 512 - v33, "%9s", off_15A38[0]);
    v35 = v33 + v34;
    scnprintf(&v94[v35], 512 - v35, "%9s", off_15A40[0]);
    v37 = v35 + v36;
    scnprintf(&v94[v37], 512 - v37, "%9s", off_15A48[0]);
    v39 = v37 + v38;
    scnprintf(&v94[v39], 512 - v39, "%9s", off_15A50[0]);
    v41 = v39 + v40;
    scnprintf(&v94[v41], 512 - v41, "%9s", off_15A58[0]);
    v43 = v41 + v42;
    scnprintf(&v94[v43], 512 - v43, "%9s", off_15A60[0]);
    v45 = scnprintf(&v94[v43 + v44], 512 - (v43 + v44), "%9s", off_15A68);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: %s",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "dp_vdev_print_tx_delay_jitter_stats",
      v94);
    v53 = a1 + 8968;
    v54 = 0;
    v55 = a1 + 29272;
    v56 = a1 + 15736;
    v57 = a1 + 22504;
    v58 = a1 + 36040;
    do
    {
      qdf_mem_set(&v95, 0x80u, 0);
      dp_accumulate_delay_stats(&v95, v53);
      dp_accumulate_delay_stats(&v95, v56);
      dp_accumulate_delay_stats(&v95, v57);
      dp_accumulate_delay_stats(&v95, v55);
      dp_accumulate_delay_stats(&v95, v58);
      scnprintf(v94, 512, "%4u  ", v54);
      v60 = v59;
      scnprintf(&v94[v59], 512LL - v59, "%6u|", v95);
      v62 = v60 + v61;
      scnprintf(&v94[v62], 512 - v62, "%6u|", v96);
      v64 = v62 + v63;
      scnprintf(&v94[v64], 512 - v64, "%6u|", v97);
      v66 = v64 + v65;
      scnprintf(&v94[v66], 512 - v66, "%6u|", v98);
      v68 = v66 + v67;
      scnprintf(&v94[v68], 512 - v68, "%6u|", v99);
      v70 = v68 + v69;
      scnprintf(&v94[v70], 512 - v70, "%8u|", v100);
      v72 = v70 + v71;
      scnprintf(&v94[v72], 512 - v72, "%8u|", v101);
      v74 = v72 + v73;
      scnprintf(&v94[v74], 512 - v74, "%8u|", v102);
      v76 = v74 + v75;
      scnprintf(&v94[v76], 512 - v76, "%8u|", v103);
      v78 = v76 + v77;
      scnprintf(&v94[v78], 512 - v78, "%8u|", v104);
      v80 = v78 + v79;
      scnprintf(&v94[v80], 512 - v80, "%8u|", v105);
      v82 = v80 + v81;
      scnprintf(&v94[v82], 512 - v82, "%8u|", v106);
      v84 = v82 + v83;
      scnprintf(&v94[v84], 512 - v84, "%8u|", v107);
      v86 = scnprintf(&v94[v84 + v85], 512 - (v84 + v85), "%10u | %3u | %3u|", v108, HIDWORD(v108), v109);
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: %s",
                 v86,
                 v87,
                 v88,
                 v89,
                 v90,
                 v91,
                 v92,
                 v93,
                 "dp_vdev_print_tx_delay_jitter_stats",
                 v94);
      ++v54;
      v53 += 752;
      v56 += 752;
      v57 += 752;
      v55 += 752;
      v58 += 752;
    }
    while ( v54 != 9 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
