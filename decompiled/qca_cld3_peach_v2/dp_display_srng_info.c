__int64 __fastcall dp_display_srng_info(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 v19; // x20
  _QWORD *v20; // x25
  __int64 v21; // x26
  unsigned int v22; // w8
  int v23; // w10
  unsigned int v24; // w9
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x8
  unsigned int *v28; // x9
  unsigned int v29; // w8
  int v30; // w10
  unsigned int v31; // w9
  __int64 v32; // x5
  __int64 v33; // x6
  unsigned __int64 v34; // x21
  __int64 *v35; // x25
  unsigned int v36; // w20
  __int64 v37; // t1
  unsigned int v38; // w8
  int v39; // w10
  unsigned int v40; // w9
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x8
  unsigned int *v44; // x9
  unsigned int v45; // w8
  int v46; // w10
  unsigned int v47; // w9
  __int64 v48; // x4
  __int64 v49; // x5
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  unsigned int *v59; // x9
  unsigned int v60; // w8
  int v61; // w10
  unsigned int v62; // w9
  __int64 v63; // x4
  __int64 v64; // x5
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x8
  unsigned int *v74; // x9
  unsigned int v75; // w8
  int v76; // w10
  unsigned int v77; // w9
  __int64 v78; // x4
  __int64 v79; // x5

  v10 = qdf_trace_msg(0x45u, 5u, "%s: SRNG HP-TP data:", a2, a3, a4, a5, a6, a7, a8, a9, "dp_display_srng_info");
  if ( *(_BYTE *)(a1 + 7201) )
  {
    v19 = 0;
    v20 = (_QWORD *)(a1 + 6800);
    v21 = 1;
    while ( v21 != 21 )
    {
      v23 = *(_DWORD *)(*v20 + 116LL);
      v22 = *(_DWORD *)(*v20 + 120LL);
      v24 = **(_DWORD **)(*v20 + 128LL);
      if ( v23 )
        v25 = v24;
      else
        v25 = v22;
      if ( v23 )
        v26 = v22;
      else
        v26 = v24;
      v10 = qdf_trace_msg(
              0x45u,
              5u,
              "%s: TCL DATA ring[%d]: hp=0x%x, tp=0x%x",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              "dp_display_srng_info",
              (unsigned int)v19,
              v25,
              v26);
      if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 776LL) + v21) != 15 )
      {
        v27 = v20[71];
        v28 = *(unsigned int **)(v27 + 128);
        v30 = *(_DWORD *)(v27 + 116);
        v29 = *(_DWORD *)(v27 + 120);
        v31 = *v28;
        if ( v30 )
          v32 = v31;
        else
          v32 = v29;
        if ( v30 )
          v33 = v29;
        else
          v33 = v31;
        v10 = qdf_trace_msg(
                0x45u,
                5u,
                "%s: TX comp ring[%d]: hp=0x%x, tp=0x%x",
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                "dp_display_srng_info",
                (unsigned int)v19,
                v32,
                v33);
      }
      ++v19;
      v21 += 4;
      v20 += 10;
      if ( v19 >= *(unsigned __int8 *)(a1 + 7201) )
        goto LABEL_19;
    }
    goto LABEL_50;
  }
LABEL_19:
  if ( *(_BYTE *)(a1 + 12896) )
  {
    v34 = 0;
    v35 = (__int64 *)(a1 + 5760);
    LOBYTE(v36) = 1;
    while ( v34 != 8 )
    {
      v37 = *v35;
      v35 += 10;
      v39 = *(_DWORD *)(v37 + 116);
      v38 = *(_DWORD *)(v37 + 120);
      v40 = **(_DWORD **)(v37 + 128);
      if ( v39 )
        v41 = v40;
      else
        v41 = v38;
      if ( v39 )
        v42 = v38;
      else
        v42 = v40;
      v36 = (v38 == v40) & (unsigned __int8)v36;
      v10 = qdf_trace_msg(
              0x45u,
              5u,
              "%s: REO DST ring[%d]: hp=0x%x, tp=0x%x",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              "dp_display_srng_info",
              (unsigned int)v34++,
              v41,
              v42);
      if ( v34 >= *(unsigned __int8 *)(a1 + 12896) )
        goto LABEL_31;
    }
LABEL_50:
    __break(0x5512u);
    return dp_set_pdev_pcp_tid_map_wifi3(v10);
  }
  v36 = 1;
LABEL_31:
  v43 = *(_QWORD *)(a1 + 6400);
  v44 = *(unsigned int **)(v43 + 128);
  v46 = *(_DWORD *)(v43 + 116);
  v45 = *(_DWORD *)(v43 + 120);
  v47 = *v44;
  if ( v46 )
    v48 = v47;
  else
    v48 = v45;
  if ( v46 )
    v49 = v45;
  else
    v49 = v47;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: REO exception ring: hp=0x%x, tp=0x%x",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "dp_display_srng_info",
    v48,
    v49);
  v58 = *(_QWORD *)(a1 + 6720);
  v59 = *(unsigned int **)(v58 + 128);
  v61 = *(_DWORD *)(v58 + 116);
  v60 = *(_DWORD *)(v58 + 120);
  v62 = *v59;
  if ( v61 )
    v63 = v62;
  else
    v63 = v60;
  if ( v61 )
    v64 = v60;
  else
    v64 = v62;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: WBM RX release ring: hp=0x%x, tp=0x%x",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "dp_display_li_be_only_srng_info",
    v63,
    v64);
  v73 = *(_QWORD *)(a1 + 7768);
  v74 = *(unsigned int **)(v73 + 128);
  v76 = *(_DWORD *)(v73 + 116);
  v75 = *(_DWORD *)(v73 + 120);
  v77 = *v74;
  if ( v76 )
    v78 = v77;
  else
    v78 = v75;
  if ( v76 )
    v79 = v75;
  else
    v79 = v77;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: WBM desc release ring: hp=0x%x, tp=0x%x",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "dp_display_srng_info",
    v78,
    v79);
  return v36;
}
