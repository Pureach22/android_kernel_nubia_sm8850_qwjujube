__int64 __fastcall ml_nlink_update_force_state_on_link_delete(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w9
  int v22; // w22
  __int16 v23; // w10
  __int16 v24; // w11
  __int16 v25; // w5
  int v26; // w10
  int v27; // w9
  __int16 v28; // w4
  int v29; // w8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int16 v39; // w10
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  __int16 v49; // w10
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  __int16 v59; // w10
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x8
  __int16 v69; // w10
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  const char *v79; // x2
  __int64 v80; // [xsp+0h] [xbp-20h]
  __int64 v81; // [xsp+8h] [xbp-18h]
  __int64 v82; // [xsp+10h] [xbp-10h]

  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 && *(_QWORD *)(v10 + 2224) )
  {
    if ( a2 != -1 )
    {
      qdf_mutex_acquire(v10 + 1656);
      v12 = *(_QWORD *)(v10 + 2224);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%xcur, del bitmap 0x%x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "ml_nlink_update_force_state_on_link_delete",
        *(unsigned __int16 *)(v12 + 1350),
        *(unsigned __int16 *)(v12 + 1348),
        *(unsigned __int8 *)(v12 + 1356),
        *(unsigned __int16 *)(v12 + 1358),
        *(unsigned __int8 *)(v12 + 1352),
        *(unsigned __int16 *)(v12 + 1354),
        *(unsigned __int16 *)(v12 + 1360),
        1 << a2);
      v21 = *(unsigned __int16 *)(v12 + 1360);
      v22 = (unsigned __int16)~(1 << a2);
      v23 = *(_WORD *)(v12 + 1348);
      v24 = *(_WORD *)(v12 + 1364);
      *(_WORD *)(v12 + 1362) &= ~(unsigned __int16)(1 << a2);
      v25 = v23 & v22;
      v26 = *(unsigned __int16 *)(v12 + 1354);
      v27 = v21 & v22;
      v28 = *(_WORD *)(v12 + 1350) & v22;
      v29 = *(unsigned __int8 *)(v12 + 1352);
      *(_WORD *)(v12 + 1360) = v27;
      *(_WORD *)(v12 + 1364) = v24 & ~(unsigned __int16)(1 << a2);
      *(_WORD *)(v12 + 1348) = v25;
      *(_WORD *)(v12 + 1350) = v28;
      LODWORD(v82) = v27;
      LODWORD(v81) = v26;
      LODWORD(v80) = v29;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%xupdated",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "ml_nlink_update_force_state_on_link_delete",
        v80,
        v81,
        v82);
      v38 = *(_QWORD *)(v10 + 2224);
      v39 = *(_WORD *)(v38 + 1378);
      *(_WORD *)(v38 + 1376) &= v22;
      *(_WORD *)(v38 + 1378) = v39 & v22;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: source %d act 0x%x inact 0x%x",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "ml_nlink_update_force_state_on_link_delete",
        0);
      v48 = *(_QWORD *)(v10 + 2224);
      v49 = *(_WORD *)(v48 + 1398);
      *(_WORD *)(v48 + 1396) &= v22;
      *(_WORD *)(v48 + 1398) = v49 & v22;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: source %d act 0x%x inact 0x%x",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "ml_nlink_update_force_state_on_link_delete",
        1);
      v58 = *(_QWORD *)(v10 + 2224);
      v59 = *(_WORD *)(v58 + 1418);
      *(_WORD *)(v58 + 1416) &= v22;
      *(_WORD *)(v58 + 1418) = v59 & v22;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: source %d act 0x%x inact 0x%x",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "ml_nlink_update_force_state_on_link_delete",
        2);
      v68 = *(_QWORD *)(v10 + 2224);
      v69 = *(_WORD *)(v68 + 1438);
      *(_WORD *)(v68 + 1436) &= v22;
      *(_WORD *)(v68 + 1438) = v69 & v22;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: source %d act 0x%x inact 0x%x",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "ml_nlink_update_force_state_on_link_delete",
        3);
      return qdf_mutex_release(v10 + 1656);
    }
    v79 = "%s: invalid link id";
  }
  else
  {
    v79 = "%s: mlo_ctx or sta_ctx null";
  }
  return qdf_trace_msg(0x8Fu, 2u, v79, a3, a4, a5, a6, a7, a8, a9, a10, "ml_nlink_update_force_state_on_link_delete");
}
