__int64 __fastcall wma_profile_data_report_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int *v10; // x21
  unsigned int v11; // w19
  __int64 result; // x0
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
  int v30; // w8
  _DWORD *v31; // x22
  __int64 v32; // x21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  char s[8]; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v42; // [xsp+28h] [xbp-98h]
  __int64 v43; // [xsp+30h] [xbp-90h]
  __int64 v44; // [xsp+38h] [xbp-88h]
  __int64 v45; // [xsp+40h] [xbp-80h]
  __int64 v46; // [xsp+48h] [xbp-78h]
  __int64 v47; // [xsp+50h] [xbp-70h]
  __int64 v48; // [xsp+58h] [xbp-68h]
  __int64 v49; // [xsp+60h] [xbp-60h]
  __int64 v50; // [xsp+68h] [xbp-58h]
  __int64 v51; // [xsp+70h] [xbp-50h]
  __int64 v52; // [xsp+78h] [xbp-48h]
  __int64 v53; // [xsp+80h] [xbp-40h]
  __int64 v54; // [xsp+88h] [xbp-38h]
  __int64 v55; // [xsp+90h] [xbp-30h]
  __int64 v56; // [xsp+98h] [xbp-28h]
  __int64 v57; // [xsp+A0h] [xbp-20h]
  _WORD v58[7]; // [xsp+A8h] [xbp-18h] BYREF
  __int64 v59; // [xsp+B8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  memset(v58, 0, sizeof(v58));
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  *(_QWORD *)s = 0;
  v42 = 0;
  if ( a10 )
  {
    v10 = *(unsigned int **)a10;
    v11 = *(_DWORD *)(*(_QWORD *)a10 + 28LL);
    if ( v11 <= *(_DWORD *)(a10 + 24) )
    {
      qdf_trace_msg(0x36u, 2u, "Profile data stats\n", a1, a2, a3, a4, a5, a6, a7, a8);
      qdf_trace_msg(
        0x36u,
        2u,
        "TOT: %d\ntx_msdu_cnt: %d\ntx_mpdu_cnt: %d\ntx_ppdu_cnt: %d\nrx_msdu_cnt: %d\nrx_mpdu_cnt: %d\nbin_count: %d\n",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v10[1],
        v10[2],
        v10[3],
        v10[4],
        v10[5],
        v10[6],
        v10[7]);
      qdf_trace_msg(
        0x36u,
        2u,
        "Profile ID: Count: TOT: Min: Max: hist_intvl: hist[0]: hist[1]:hist[2]",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29);
      if ( v11 )
      {
        v30 = v11 - 1;
        if ( v11 - 1 >= 0x1F )
          v30 = 31;
        v31 = (_DWORD *)(*(_QWORD *)(a10 + 16) + 20LL);
        v32 = (unsigned int)(v30 + 1);
        do
        {
          snprintf(
            s,
            0x96u,
            " %d : %d : %d : %d : %d : %d : %d : %d : %d",
            *(v31 - 4),
            *(v31 - 3),
            *(v31 - 2),
            *(v31 - 1),
            *v31,
            v31[1],
            v31[2],
            v31[3],
            v31[4]);
          qdf_trace_msg(0x36u, 2u, "%s", v33, v34, v35, v36, v37, v38, v39, v40, s);
          --v32;
          v31 += 10;
        }
        while ( v32 );
      }
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: FW bin count %d more than data %d in TLV hdr",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "wma_profile_data_report_event_handler",
        v11);
      result = 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid profile data event buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wma_profile_data_report_event_handler");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
