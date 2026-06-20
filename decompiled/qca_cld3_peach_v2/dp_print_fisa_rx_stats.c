__int64 __fastcall dp_print_fisa_rx_stats(int a1)
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
  unsigned int *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 *v44; // x21
  __int64 *v45; // x19
  __int64 v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x19
  __int64 *v64; // x8
  __int64 v65; // x22
  __int64 v66; // x20
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x23
  __int64 v76; // x27
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  const char *v85; // x5
  unsigned __int64 v86; // x20
  unsigned int *v87; // x22
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
  __int64 v104; // [xsp+0h] [xbp-240h]
  __int64 v105; // [xsp+8h] [xbp-238h]
  _BYTE s[512]; // [xsp+38h] [xbp-208h] BYREF
  __int64 v107; // [xsp+238h] [xbp-8h]

  v107 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = dp_get_context();
  if ( a1 == 2 )
  {
    v63 = result;
    memset(s, 0, sizeof(s));
    v64 = *(__int64 **)(v63 + 1480);
    v65 = *v64;
    v66 = *((unsigned __int16 *)v64 + 16);
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: #flows added %d evicted %d hash collision %d",
               v67,
               v68,
               v69,
               v70,
               v71,
               v72,
               v73,
               v74,
               "dp_rx_dump_fisa_stats",
               *((unsigned int *)v64 + 16),
               *((unsigned int *)v64 + 17),
               *((unsigned int *)v64 + 18));
    if ( v66 )
    {
      v75 = 0;
      do
      {
        v76 = v65 + v75;
        if ( *(_BYTE *)(v65 + v75 + 40) )
        {
          v77 = scnprintf(
                  s,
                  512,
                  "dest 0x%x%x%x%x(0x%x) src 0x%x%x%x%x(0x%x) proto 0x%x",
                  *(_DWORD *)(v76 + 92),
                  *(_DWORD *)(v76 + 96),
                  *(_DWORD *)(v76 + 100),
                  *(_DWORD *)(v76 + 104),
                  *(unsigned __int16 *)(v76 + 124),
                  *(_DWORD *)(v76 + 108),
                  *(_DWORD *)(v76 + 112),
                  *(_DWORD *)(v76 + 116),
                  *(_DWORD *)(v76 + 120),
                  *(unsigned __int16 *)(v76 + 126),
                  *(unsigned __int16 *)(v76 + 128));
          if ( *(_BYTE *)(v76 + 41) )
            v85 = "udp";
          else
            v85 = "tcp";
          LODWORD(v105) = *(_DWORD *)(v76 + 184);
          LODWORD(v104) = *(_DWORD *)(v76 + 188);
          result = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: Flow[%d][%s][%s] ring %d msdu-aggr %d flushes %d bytes-agg %llu avg-bytes-aggr %llu same_mld_vd"
                     "ev_mismatch %llu",
                     v77,
                     v78,
                     v79,
                     v80,
                     v81,
                     v82,
                     v83,
                     v84,
                     "dp_rx_dump_fisa_stats",
                     *(unsigned int *)(v76 + 16),
                     v85,
                     s,
                     *(unsigned __int8 *)(v76 + 144),
                     v104,
                     v105,
                     *(_QWORD *)(v76 + 176),
                     *(_QWORD *)(v76 + 176) / (unsigned __int64)(unsigned int)v105,
                     *(_QWORD *)(v76 + 264));
        }
        v75 += 336;
      }
      while ( 336 * (_DWORD)v66 != (_DWORD)v75 );
    }
  }
  else if ( a1 == 1 )
  {
    if ( (*(_BYTE *)(result + 218) & 1) != 0 )
    {
      v44 = *(__int64 **)(result + 1480);
      if ( (*((_BYTE *)v44 + 609) & 1) != 0 )
      {
        v45 = *(__int64 **)(result + 256);
        v46 = *v44;
        if ( (unsigned int)hif_force_wake_request(*v45) )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Wake up request failed",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "dp_rx_dump_fisa_table");
          result = qdf_check_state_before_panic(v55, v56, v57, v58, v59, v60, v61, v62);
        }
        else
        {
          if ( *((_WORD *)v44 + 16) )
          {
            v86 = 0;
            v87 = (unsigned int *)(v46 + 236);
            do
            {
              hal_rx_dump_cmem_fse(v45, *v87, (unsigned int)v86++);
              v87 += 84;
            }
            while ( v86 < *((unsigned __int16 *)v44 + 16) );
          }
          result = hif_force_wake_release(*v45);
          if ( (_DWORD)result )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Wake up release failed",
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              "dp_rx_dump_fisa_table");
            result = qdf_check_state_before_panic(v96, v97, v98, v99, v100, v101, v102, v103);
          }
        }
      }
      else
      {
        result = hal_rx_dump_fse_table(v44[2]);
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: RX FISA feature is disabled",
                 v3,
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 "dp_rx_dump_fisa_table");
    }
  }
  else if ( !a1 && *(_BYTE *)(result + 218) == 1 )
  {
    v11 = *(unsigned int **)(result + 1480);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: invalid flow index: %u",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_print_fisa_stats",
      v11[80]);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: workqueue update deferred: %u",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_print_fisa_stats",
      v11[81]);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: reo_mismatch: cce_match: %u",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_print_fisa_stats",
      v11[82]);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: reo_mismatch: allow_fse_metdata_mismatch: %u",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "dp_print_fisa_stats",
      v11[83]);
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: reo_mismatch: allow_non_aggr: %u",
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               "dp_print_fisa_stats",
               v11[84]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
