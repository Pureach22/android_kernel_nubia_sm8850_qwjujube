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
  __int64 i; // x22
  int v54; // w0
  __int64 v55; // x23
  int v56; // w0
  __int64 v57; // x23
  int v58; // w0
  __int64 v59; // x23
  int v60; // w0
  __int64 v61; // x23
  int v62; // w0
  __int64 v63; // x23
  int v64; // w0
  __int64 v65; // x23
  int v66; // w0
  __int64 v67; // x23
  int v68; // w0
  __int64 v69; // x23
  int v70; // w0
  __int64 v71; // x23
  int v72; // w0
  __int64 v73; // x23
  int v74; // w0
  __int64 v75; // x23
  int v76; // w0
  __int64 v77; // x23
  int v78; // w0
  __int64 v79; // x23
  int v80; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  _BYTE v89[512]; // [xsp+0h] [xbp-290h] BYREF
  __int64 v90; // [xsp+200h] [xbp-90h] BYREF
  __int64 v91; // [xsp+208h] [xbp-88h]
  __int64 v92; // [xsp+210h] [xbp-80h]
  __int64 v93; // [xsp+218h] [xbp-78h]
  __int64 v94; // [xsp+220h] [xbp-70h]
  __int64 v95; // [xsp+228h] [xbp-68h]
  __int64 v96; // [xsp+230h] [xbp-60h]
  __int64 v97; // [xsp+238h] [xbp-58h]
  __int64 v98; // [xsp+240h] [xbp-50h]
  __int64 v99; // [xsp+248h] [xbp-48h]
  __int64 v100; // [xsp+250h] [xbp-40h]
  __int64 v101; // [xsp+258h] [xbp-38h]
  __int64 v102; // [xsp+260h] [xbp-30h]
  __int64 v103; // [xsp+268h] [xbp-28h]
  __int64 v104; // [xsp+270h] [xbp-20h]
  __int64 v105; // [xsp+278h] [xbp-18h]
  __int64 v106; // [xsp+280h] [xbp-10h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)memset(v89, 0, sizeof(v89));
  if ( a1 )
  {
    v11 = *(unsigned __int8 *)(a1 + 59);
    v104 = 0;
    v105 = 0;
    v102 = 0;
    v103 = 0;
    v100 = 0;
    v101 = 0;
    v98 = 0;
    v99 = 0;
    v96 = 0;
    v97 = 0;
    v94 = 0;
    v95 = 0;
    v92 = 0;
    v93 = 0;
    v90 = 0;
    v91 = 0;
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
      &unk_98C763,
      &unk_98C763);
    scnprintf(v89, 512, "%6s", (const char *)&unk_98C763);
    v21 = v20;
    scnprintf(&v89[v20], 512LL - v20, "%7s", delay_jitter_bkt_str[0]);
    v23 = v21 + v22;
    scnprintf(&v89[v23], 512 - v23, "%7s", off_16330[0]);
    v25 = v23 + v24;
    scnprintf(&v89[v25], 512 - v25, "%7s", off_16338[0]);
    v27 = v25 + v26;
    scnprintf(&v89[v27], 512 - v27, "%7s", off_16340[0]);
    v29 = v27 + v28;
    scnprintf(&v89[v29], 512 - v29, "%7s", off_16348[0]);
    v31 = v29 + v30;
    scnprintf(&v89[v31], 512 - v31, "%9s", off_16350[0]);
    v33 = v31 + v32;
    scnprintf(&v89[v33], 512 - v33, "%9s", off_16358[0]);
    v35 = v33 + v34;
    scnprintf(&v89[v35], 512 - v35, "%9s", off_16360[0]);
    v37 = v35 + v36;
    scnprintf(&v89[v37], 512 - v37, "%9s", off_16368[0]);
    v39 = v37 + v38;
    scnprintf(&v89[v39], 512 - v39, "%9s", off_16370[0]);
    v41 = v39 + v40;
    scnprintf(&v89[v41], 512 - v41, "%9s", off_16378[0]);
    v43 = v41 + v42;
    scnprintf(&v89[v43], 512 - v43, "%9s", off_16380[0]);
    v45 = scnprintf(&v89[v43 + v44], 512 - (v43 + v44), "%9s", off_16388);
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
      v89);
    for ( i = 0; i != 9; ++i )
    {
      qdf_mem_set(&v90, 0x80u, 0);
      dp_accumulate_delay_stats(&v90, a1 + 9792);
      dp_accumulate_delay_stats(&v90, a1 + 16560);
      dp_accumulate_delay_stats(&v90, a1 + 23328);
      dp_accumulate_delay_stats(&v90, a1 + 30096);
      dp_accumulate_delay_stats(&v90, a1 + 36864);
      scnprintf(v89, 512, "%4u  ", i);
      v55 = v54;
      scnprintf(&v89[v54], 512LL - v54, "%6u|", v90);
      v57 = v55 + v56;
      scnprintf(&v89[v57], 512 - v57, "%6u|", v91);
      v59 = v57 + v58;
      scnprintf(&v89[v59], 512 - v59, "%6u|", v92);
      v61 = v59 + v60;
      scnprintf(&v89[v61], 512 - v61, "%6u|", v93);
      v63 = v61 + v62;
      scnprintf(&v89[v63], 512 - v63, "%6u|", v94);
      v65 = v63 + v64;
      scnprintf(&v89[v65], 512 - v65, "%8u|", v95);
      v67 = v65 + v66;
      scnprintf(&v89[v67], 512 - v67, "%8u|", v96);
      v69 = v67 + v68;
      scnprintf(&v89[v69], 512 - v69, "%8u|", v97);
      v71 = v69 + v70;
      scnprintf(&v89[v71], 512 - v71, "%8u|", v98);
      v73 = v71 + v72;
      scnprintf(&v89[v73], 512 - v73, "%8u|", v99);
      v75 = v73 + v74;
      scnprintf(&v89[v75], 512 - v75, "%8u|", v100);
      v77 = v75 + v76;
      scnprintf(&v89[v77], 512 - v77, "%8u|", v101);
      v79 = v77 + v78;
      scnprintf(&v89[v79], 512 - v79, "%8u|", v102);
      v81 = scnprintf(&v89[v79 + v80], 512 - (v79 + v80), "%10u | %3u | %3u|", v103, HIDWORD(v103), v104);
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: %s",
                 v81,
                 v82,
                 v83,
                 v84,
                 v85,
                 v86,
                 v87,
                 v88,
                 "dp_vdev_print_tx_delay_jitter_stats",
                 v89);
      a1 += 752;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
