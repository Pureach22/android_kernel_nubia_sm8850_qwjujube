__int64 __fastcall dp_print_tsf_tx_delay_hist(__int64 *a1, char a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  const char *v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w0
  __int64 v23; // x25
  int v24; // w0
  __int64 v25; // x25
  int v26; // w0
  __int64 v27; // x25
  int v28; // w0
  __int64 v29; // x25
  int v30; // w0
  __int64 v31; // x25
  int v32; // w0
  __int64 v33; // x25
  int v34; // w0
  __int64 v35; // x25
  int v36; // w0
  __int64 v37; // x25
  int v38; // w0
  __int64 v39; // x25
  int v40; // w0
  __int64 v41; // x25
  int v42; // w0
  __int64 v43; // x25
  int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x9
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x8
  __int64 v59; // x8
  __int64 v60; // x8
  int v61; // w0
  __int64 v62; // x24
  int v63; // w0
  __int64 v64; // x24
  int v65; // w0
  __int64 v66; // x24
  int v67; // w0
  __int64 v68; // x24
  int v69; // w0
  __int64 v70; // x24
  int v71; // w0
  __int64 v72; // x24
  int v73; // w0
  __int64 v74; // x24
  int v75; // w0
  __int64 v76; // x24
  int v77; // w0
  __int64 v78; // x24
  int v79; // w0
  __int64 v80; // x24
  int v81; // w0
  __int64 v82; // x24
  int v83; // w0
  __int64 v84; // x24
  int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 result; // x0
  _BYTE s[512]; // [xsp+8h] [xbp-288h] BYREF
  __int64 v96; // [xsp+208h] [xbp-88h] BYREF
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
  __int64 v112; // [xsp+288h] [xbp-8h]

  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
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
  memset(s, 0, sizeof(s));
  if ( a1 )
  {
    if ( a2 )
      v12 = "%s:  Delay jitter hist polled by STA_INFO cmd";
    else
      v12 = "%s:  Delay hist polled by STA_INFO cmd";
    if ( a2 )
      v13 = "%s:          Pkts_per_jitter_bucket%60s | Min | Max | Avg |";
    else
      v13 = "%s:          Pkts_per_delay_bucket%60s | Min | Max | Avg |";
    qdf_trace_msg(0x45u, 5u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "dp_print_tsf_tx_delay_hist");
    qdf_trace_msg(0x45u, 5u, v13, v14, v15, v16, v17, v18, v19, v20, v21, "dp_print_tsf_tx_delay_hist", &unk_8B9E43);
    scnprintf(s, 512, "%7s", fw_to_hw_delay_bkt_str[0]);
    v23 = v22;
    scnprintf(&s[v22], 512LL - v22, "%7s", off_159A0[0]);
    v25 = v23 + v24;
    scnprintf(&s[v25], 512 - v25, "%7s", off_159A8[0]);
    v27 = v25 + v26;
    scnprintf(&s[v27], 512 - v27, "%7s", off_159B0[0]);
    v29 = v27 + v28;
    scnprintf(&s[v29], 512 - v29, "%7s", off_159B8[0]);
    v31 = v29 + v30;
    scnprintf(&s[v31], 512 - v31, "%9s", off_159C0[0]);
    v33 = v31 + v32;
    scnprintf(&s[v33], 512 - v33, "%9s", off_159C8[0]);
    v35 = v33 + v34;
    scnprintf(&s[v35], 512 - v35, "%9s", off_159D0[0]);
    v37 = v35 + v36;
    scnprintf(&s[v37], 512 - v37, "%9s", off_159D8[0]);
    v39 = v37 + v38;
    scnprintf(&s[v39], 512 - v39, "%9s", off_159E0[0]);
    v41 = v39 + v40;
    scnprintf(&s[v41], 512 - v41, "%9s", off_159E8[0]);
    v43 = v41 + v42;
    scnprintf(&s[v43], 512 - v43, "%9s", off_159F0[0]);
    v45 = scnprintf(&s[v43 + v44], 512 - (v43 + v44), "%9s", off_159F8);
    qdf_trace_msg(0x45u, 5u, "%s: %s", v45, v46, v47, v48, v49, v50, v51, v52, "dp_print_tsf_tx_delay_hist", s);
    qdf_mem_set(&v96, 0x80u, 0);
    v53 = a1[13];
    v108 = a1[12];
    v109 = v53;
    v54 = a1[15];
    v110 = a1[14];
    v111 = v54;
    v55 = a1[9];
    v104 = a1[8];
    v105 = v55;
    v56 = a1[11];
    v106 = a1[10];
    v107 = v56;
    v57 = a1[5];
    v100 = a1[4];
    v101 = v57;
    v58 = a1[7];
    v102 = a1[6];
    v103 = v58;
    v59 = a1[1];
    v96 = *a1;
    v97 = v59;
    v60 = a1[3];
    v98 = a1[2];
    v99 = v60;
    scnprintf(s, 512, "%6u|", v97);
    v62 = v61;
    scnprintf(&s[v61], 512LL - v61, "%6u|", v98);
    v64 = v62 + v63;
    scnprintf(&s[v64], 512 - v64, "%6u|", v99);
    v66 = v64 + v65;
    scnprintf(&s[v66], 512 - v66, "%6u|", v100);
    v68 = v66 + v67;
    scnprintf(&s[v68], 512 - v68, "%6u|", v101);
    v70 = v68 + v69;
    scnprintf(&s[v70], 512 - v70, "%8u|", v102);
    v72 = v70 + v71;
    scnprintf(&s[v72], 512 - v72, "%8u|", v103);
    v74 = v72 + v73;
    scnprintf(&s[v74], 512 - v74, "%8u|", v104);
    v76 = v74 + v75;
    scnprintf(&s[v76], 512 - v76, "%8u|", v105);
    v78 = v76 + v77;
    scnprintf(&s[v78], 512 - v78, "%8u|", v106);
    v80 = v78 + v79;
    scnprintf(&s[v80], 512 - v80, "%8u|", v107);
    v82 = v80 + v81;
    scnprintf(&s[v82], 512 - v82, "%8u|", v108);
    v84 = v82 + v83;
    scnprintf(&s[v84], 512 - v84, "%8u|", v109);
    v86 = scnprintf(&s[v84 + v85], 512 - (v84 + v85), "%10u | %3u | %3u|", HIDWORD(v110), v110, v111);
    result = qdf_trace_msg(0x45u, 5u, "%s: %s", v86, v87, v88, v89, v90, v91, v92, v93, "dp_print_tsf_tx_delay_hist", s);
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: hist_stats is NULL!!",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "dp_print_tsf_tx_delay_hist");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
