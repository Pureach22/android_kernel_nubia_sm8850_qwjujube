char *__fastcall dp_tx_dump_flow_pool_info_compact(__int64 a1)
{
  char *result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  size_t v21; // x1
  unsigned int v22; // w22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  size_t v31; // x1
  unsigned int v32; // w22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  size_t v41; // x1
  unsigned int v42; // w22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  size_t v51; // x1
  unsigned int v52; // w22
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  size_t v61; // x1
  unsigned int v62; // w8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  size_t v71; // x1
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7

  result = (char *)_qdf_mem_malloc(0x146u, "dp_tx_dump_flow_pool_info_compact", 453);
  if ( result )
  {
    v11 = (__int64)result;
    v12 = qdf_snprintf(
            result,
            0x146u,
            "G:(%d,%d,%d) ",
            v3,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            *(unsigned __int16 *)(a1 + 12928),
            *(unsigned __int16 *)(a1 + 12930),
            *(unsigned __int16 *)(a1 + 12932));
    if ( v12 <= 0x145 )
      v21 = 326 - v12;
    else
      v21 = 0;
    v22 = qdf_snprintf(
            (char *)(v11 + (int)v12),
            v21,
            "| %d %d: (%d,%d,%d)",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            *(unsigned __int8 *)(a1 + 2362),
            *(unsigned int *)(a1 + 2368),
            *(unsigned __int16 *)(a1 + 2360),
            *(unsigned __int16 *)(a1 + 2364),
            *(unsigned __int16 *)(a1 + 2554))
        + v12;
    if ( v22 <= 0x145 )
      v31 = 326 - v22;
    else
      v31 = 0;
    v32 = qdf_snprintf(
            (char *)(v11 + (int)v22),
            v31,
            "| %d %d: (%d,%d,%d)",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            *(unsigned __int8 *)(a1 + 2658),
            *(unsigned int *)(a1 + 2664),
            *(unsigned __int16 *)(a1 + 2656),
            *(unsigned __int16 *)(a1 + 2660),
            *(unsigned __int16 *)(a1 + 2850))
        + v22;
    if ( v32 <= 0x145 )
      v41 = 326 - v32;
    else
      v41 = 0;
    v42 = qdf_snprintf(
            (char *)(v11 + (int)v32),
            v41,
            "| %d %d: (%d,%d,%d)",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            *(unsigned __int8 *)(a1 + 2954),
            *(unsigned int *)(a1 + 2960),
            *(unsigned __int16 *)(a1 + 2952),
            *(unsigned __int16 *)(a1 + 2956),
            *(unsigned __int16 *)(a1 + 3146))
        + v32;
    if ( v42 <= 0x145 )
      v51 = 326 - v42;
    else
      v51 = 0;
    v52 = qdf_snprintf(
            (char *)(v11 + (int)v42),
            v51,
            "| %d %d: (%d,%d,%d)",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            *(unsigned __int8 *)(a1 + 3250),
            *(unsigned int *)(a1 + 3256),
            *(unsigned __int16 *)(a1 + 3248),
            *(unsigned __int16 *)(a1 + 3252),
            *(unsigned __int16 *)(a1 + 3442))
        + v42;
    if ( v52 <= 0x145 )
      v61 = 326 - v52;
    else
      v61 = 0;
    v62 = qdf_snprintf(
            (char *)(v11 + (int)v52),
            v61,
            "| %d %d: (%d,%d,%d)",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            *(unsigned __int8 *)(a1 + 3546),
            *(unsigned int *)(a1 + 3552),
            *(unsigned __int16 *)(a1 + 3544),
            *(unsigned __int16 *)(a1 + 3548),
            *(unsigned __int16 *)(a1 + 3738))
        + v52;
    if ( v62 <= 0x145 )
      v71 = 326 - v62;
    else
      v71 = 0;
    qdf_snprintf(
      (char *)(v11 + (int)v62),
      v71,
      "| %d %d: (%d,%d,%d)",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      *(unsigned __int8 *)(a1 + 3842),
      *(unsigned int *)(a1 + 3848),
      *(unsigned __int16 *)(a1 + 3840),
      *(unsigned __int16 *)(a1 + 3844),
      *(unsigned __int16 *)(a1 + 4034));
    qdf_trace_msg(0x45u, 5u, "FLOW_POOL_STATS %s", v72, v73, v74, v75, v76, v77, v78, v79, v11);
    return (char *)_qdf_mem_free(v11);
  }
  return result;
}
